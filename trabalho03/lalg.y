/* 	Declaração de cabeçalho do bison */
%{
	
	#define YYDEBUG 1 /* For Debugging */
	#define NUM_RESERVADAS 16
	#define TAM_MAX_PALAVRA 16

// Categorias da Tabela de Simbolos
#define NUM_INT 0 
#define NUM_REAL 1 
#define PROGRAM 2
#define PROCEDURE 3 
#define CONST_INT 4
#define CONST_REAL 5 
#define VAR_INT 6 
#define VAR_REAL 7 
#define PARAM_INT 8
#define PARAM_REAL 9

//Tipos de dados
#define INTEGER 100
#define REAL 101
#define PROCEDURE_TRUE 102
#define CONSTANTE_INTEGER 103
#define CONSTANTE_REAL 104
#define TNULL 199

//Tipos de tipos esperados
#define ATTR 200
#define EXPRESSAO 201 

//Retornos ao inserir
#define OK 300
#define REDECLARACAO 301
#define CONFLITO 302
#define REDECLARACAO_PARAM 303

//Tipos de erros
#define NAO_EXISTE -1
#define CONST_FALSE -2
#define PROCEDURE_FALSE -3
#define VAR_FALSE -4

//Tipos de relação
#define CPME 400
#define CPMA 401
#define CPIG 402
#define CDES 403
#define CPMI 404
#define CMAI 405

	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	int yylex (void);
	void yyerror (char *);
	int numerrors=0;
	int contexto=0;
	int ret, contparametros;
	int retorno_if=0;
	int linha_desvio;
	extern int num_lines;
	char listavar[400];
	char *str;
	char *cpystr;
	char lastprocedure[30];
	char msg[300];
	char **code_vet; //responsavel pela geração de codigo
	char *comando;
	int num_procedimento=0;
	int prox_linha_vet=0;
	int posicaoPusher=0;
	int comeco_repeat[64], i_repeat=0;
	int comeco_while[64], retorno_while[64], i_com_while=0, i_ret_while=0;
	

	FILE *code_file;

	typedef struct
	{
	    char *nome;
	    int tipo;
	    double valorf;
	    int valori;
	    unsigned int end_relativo;
	    int contexto;
		char *procedure;
		int ordem;
	}simbolo;

	void insereVetor(char *comando, int posicao)
	{
		register int i=0;
		if(numerrors==0)
		{
			for(i=prox_linha_vet; i>posicao; i--)
			{
				strcpy(code_vet[i],code_vet[i-1]);
			}
			strcpy(code_vet[posicao],comando);
			prox_linha_vet++;
			//printf("%s\n",comando);
		}
		
	}
	
	void gravaVetor()
	{
		FILE *p;
		register int i=0;

		p = fopen("code.p","w");
		
		for(i=0; i<prox_linha_vet; i++)
		{
			fprintf(p,"%s\n",code_vet[i]);
		}
		fclose(p);
	}
	
	void imprimeVetor()
	{
		register i=0;
		for(i=0; i< prox_linha_vet; i++)
			printf("%s\n",code_vet[i]);
		fflush(stdout);
	}
	

	void carregaSimbolo(char *nome, int contexto, char *procedure){
		if(numerrors==0){
			if(contexto==0){
				simbolo *p;
				p = malloc (sizeof(simbolo));
				p->nome=nome;
				p->contexto=contexto;
				p->procedure=procedure;
				buscaSimbolo(p);
				if(p->tipo==CONST_INT){
					sprintf(comando,"CRCT %d", p->valori);
					insereVetor(comando,prox_linha_vet);
				}
				else if(p->tipo==CONST_REAL){
					sprintf(comando,"CRCT %f", p->valorf);
					insereVetor(comando,prox_linha_vet);
				}else if(p->tipo==VAR_INT || p->tipo==VAR_REAL){
					sprintf(comando,"CRVL %d", p->end_relativo);
					insereVetor(comando,prox_linha_vet);
				}
			}
		}
	}
	void armazenaSimbolo(char *nome, int contexto, char *procedure){
		if(numerrors==0){
			if(contexto==0){
				simbolo *p;
				p = malloc (sizeof(simbolo));
				p->nome=nome;
				p->contexto=contexto;
				p->procedure=procedure;
				buscaSimbolo(p);
				if(p->tipo==VAR_INT || p->tipo==VAR_REAL){
					sprintf(comando,"ARMZ %d", p->end_relativo);
					insereVetor(comando,prox_linha_vet);
				}
			}
			if(contexto==1){
				simbolo *p;
				p = malloc (sizeof(simbolo));
				p->nome=nome;
				p->contexto=contexto;
				p->procedure=procedure;
				buscaSimbolo(p);
				if(p->tipo==VAR_INT || p->tipo==VAR_REAL || p->tipo==PARAM_INT || p->tipo==PARAM_REAL){
					sprintf(comando,"ARMZ %d", p->end_relativo);
					insereVetor(comando,prox_linha_vet);
				}
			}
		}
	}
	void strcatinv(char *l1, char* l2){
		char *aux;
		aux = malloc(400 * sizeof(char));
		strcat(aux, l2);
		strcat(aux,l1);
		strcpy(l1, aux);
	}
	int isVarOrConst(int type){
		if(type==VAR_INT || type==VAR_REAL || type==CONST_INT || type==CONST_REAL) return 1;
		return 0;
	}

	int getNumLinha(int posicao)
	{
		char caracter = 0;
		int num_linha = 0;
		FILE *arquivo;

		arquivo =  fopen("code.p","r");

 		do
 		{
 			caracter = fgetc(arquivo);
			if(caracter == '\n') num_linha++;
 		} while(ftell(arquivo) < posicao);
		fclose(arquivo);
		return num_linha;
	}

	int getNumCaracteres(int linha)
	{
		char caracter = 0;
		int num_linha=0;
		int num_caracter = 0;
		FILE *arquivo;

		arquivo =  fopen("code.p","r");

 		do
 		{
 			caracter = fgetc(arquivo);
			if(caracter == '\n') num_linha++;
 		} while(num_linha<linha);

		num_caracter=ftell(arquivo);
		fclose(arquivo);
		return num_caracter-1;//para tirar o \n inserido no lugar do procedure
	}

	void escreveNaLinha(int linha_escrita,char *cmd, int linha_desvio){
		/*char *restoArquivo;
 		int num_linha = 0;
 		int posicaoFim = ftell(code_file);

		fseek(code_file,linha_escrita,SEEK_SET);
		int posicaoInicio = ftell(code_file);
		restoArquivo=malloc((posicaoFim-posicaoInicio)*sizeof(char));

		fread(restoArquivo, sizeof(char),posicaoFim-posicaoInicio,code_file);
		fseek(code_file,linha_escrita,SEEK_SET);

 		fprintf(code_file,"%s %d\n",comando,linha_desvio);
		fprintf(code_file,"%s",restoArquivo);
 		fseek(code_file,0,SEEK_END);*/
		sprintf(comando,"%s %d",cmd,linha_desvio);
		insereVetor(comando,linha_escrita);
 	}

	void escreveProcedimentos(int enderecoPrincipal)
	{
 		int i=0;
 		int tamanho = retornaTamanhoTabela();
 		int posicao;
 		
 		while(i<tamanho)
 		{
 			posicao = buscaProcedure(i);
 			if(posicao !=-1)
 			{
				sprintf(comando,"DSVI %d",enderecoPrincipal);
 				strcpy(code_vet[posicao-1],comando);
 			}
 			++i;
 		}

	}
	
%}
/* 	Declaração de tokens de bison  */
%union YYSTYPE{
	int i_number;
	double r_number;
	char* name;
	int type;
	struct symbol {
		int i_value;
		double f_value;
		int type;
		char* name;
		char math_op;
	} symbol;
	char math_op;
}

%token<name> id
%token<i_number> num_integer
%token<r_number> num_real
%token begin_
%token const_
%token do_
%token else_
%token end_
%token if_
%token integer_
%token procedure_
%token program_
%token readln_
%token real_
%token repeat_
%token then_
%token until_
%token var_
%token while_
%token writeln_
%token ponto_virgula 
%token virgula 
%token<i_number> atribuicao 
%token doispontos
%token ponto 
%token abre_par 
%token fecha_par 
%token operador_mat_soma 
%token operador_mat_sub 
%token operador_mat_mult 
%token operador_mat_div 
%token operador_comp_igual 
%token operador_comp_maiorigual
%token operador_comp_maior 
%token operador_comp_diff 
%token operador_comp_menorigual 
%token operador_comp_menor
%token invalido

%type <symbol> numero
%type <symbol> fator
%type <symbol> termo
%type <symbol> outros_termos
%type <symbol> mais_fatores
%type <symbol> expressao
%type <i_number> tipo_var
%type <i_number> relacao
/* %type <name> parametros */
/* %type <name> lista_par */
%type <math_op> op_un
%type <math_op> op_ad
%type <math_op> op_mult
/* %type <name> abre_par */
/* %type <name> fecha_par */
/* %type <i_number> pos_id */
/* %type <i_number> cmd */
%nonassoc error
%% /* Delaração de Regras de gramática do Bison */

//{escreveProcedimentos(prox_linha_vet);

programa: program_ id { insereProgram ($2); } ponto_virgula corpo ponto 
	  | error id ponto_virgula { yyerror("Expected: program"); yyclearin; } corpo ponto
	  | error id error { yyerror("Expected: program"); yyclearin; } corpo ponto
	  | program_ id error { yyerror("Expected: ';' before begin or declaration of variables and constants"); yyclearin; } corpo  ponto
	  | program_ id { insereProgram ($2); } ponto_virgula corpo error { yyerror("Expected: '.'"); } ;

corpo: dc {escreveProcedimentos(prox_linha_vet);} begin_ comandos end_
	| dc {escreveProcedimentos(prox_linha_vet);}  error { yyerror("Expected: begin or declaration of variables and constants");yyclearin; } comandos end_
	| dc {escreveProcedimentos(prox_linha_vet);}  begin_ comandos error { yyerror("Expected: end"); };

dc: dc_c dc_v dc_p;

dc_c: | const_ id operador_comp_igual numero ponto_virgula dc_c { int retorno;
																	if($4.type==INTEGER)
																	{ 
																		retorno = insereConstInt ($2, $4.i_value, contexto);
																		if(retorno==REDECLARACAO)
																			yyerror("Redeclaration of constants");
																		else if(retorno ==CONFLITO)
																			yyerror("Conflicting types");
																	} 
																	else if($4.type==REAL) 
																	{ 
																		retorno = insereConstReal ($2, $4.f_value, contexto);
																		if(retorno==REDECLARACAO) 
																			yyerror("Redeclaration of constants");
																		else if(retorno ==CONFLITO)
																			yyerror("Conflicting types");
																	} 	
																}

      | const_ id error { yyerror("Expected: '='"); } numero ponto_virgula dc_c
      | const_ id operador_comp_igual numero error { yyerror("Expected: ';'"); } dc_c; 

dc_v: | var_ variaveis doispontos tipo_var ponto_virgula {		int retorno;
																str=malloc(400 * sizeof(char));
																str=strtok(listavar,",");
																while(str!=NULL){
																	cpystr=malloc(400 * sizeof(char));
																	strcpy(cpystr,str);
																	if($4==INTEGER)
																	{ 
																		retorno = insereVarInt (cpystr, contexto);
																		if(retorno==REDECLARACAO)
																			yyerror("Redeclaration of variables");
																		else if(retorno ==CONFLITO)
																			yyerror("Conflicting types");
																		else if(retorno == REDECLARACAO_PARAM)
																		{
																			sprintf(msg, "Variable %s already declared as a parameter",cpystr );
																			yyerror(msg);
																		}	
																		AlocaMemoria();
																	} else if($4==REAL) 
																	{ 
																		retorno = insereVarReal (cpystr, contexto);
																		if(retorno==REDECLARACAO)
																			yyerror("Redeclaration of variables");
																		else if(retorno ==CONFLITO)
																			yyerror("Conflicting types");
																		else if(retorno == REDECLARACAO_PARAM)
																		{
																			sprintf(msg, "Variable %s already declared as a parameter",cpystr );
																			yyerror(msg);
																		}
																		AlocaMemoria();
																	} 
																	str=strtok(NULL,",");
																}
																listavar[0]='\0';
																
														   } dc_v

	  | var_ error { yyerror("Expected an identifier"); } doispontos tipo_var ponto_virgula dc_v
      | var_ variaveis error { yyerror("Expected: ':'");yyclearin; } tipo_var ponto_virgula dc_v
      | var_ variaveis doispontos tipo_var error { yyerror("Expected: ';'");yyclearin; } dc_v;

tipo_var: real_ { $$ = REAL; } | integer_ { $$ = INTEGER; }
	  | error { yyerror("Incorrect type: Expected integer or real"); yyclearin; };

variaveis: id mais_var { strcatinv(listavar,$1); strcatinv(listavar,","); };

mais_var: | virgula variaveis;

dc_p: | procedure_ id { ++num_procedimento; insereVetor("DSVI",prox_linha_vet); atualizaPosicaoProcedure($2,prox_linha_vet); contexto=1; if(insereProcedure ($2,contexto,prox_linha_vet)!=OK) 
										{
											yyerror("Redefinition of procedure"); 
										}
									 else
									{
										strcpy(lastprocedure,$2);
									}
						} parametros ponto_virgula corpo_p { contexto=0;removeLocalVars($2);lastprocedure[0]='\0';	insereVetor("RTPR",prox_linha_vet);
														   } dc_p;

parametros: | abre_par lista_par fecha_par;

lista_par: variaveis doispontos tipo_var 	{	
												str=malloc(400 * sizeof(char));
												str=strtok(listavar,",");
												int ordem=1;
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													if($3==INTEGER){
														ret=insereParamInt (cpystr, contexto, lastprocedure, ordem);
														insereVetor("COPVL",prox_linha_vet);
													} else if($3==REAL) { 
														ret=insereParamReal (cpystr, contexto, lastprocedure, ordem);
														insereVetor("COPVL",prox_linha_vet);
													} 
													if(ret == REDECLARACAO_PARAM)
													{
														sprintf(msg, "Parameter %s already declared",cpystr );
														yyerror(msg);
													}else if(ret == CONFLITO)
													{
														sprintf(msg, "Parameter %s already declared as a constant",cpystr );
														yyerror(msg);
													}
													str=strtok(NULL,",");
													ordem++;
												}
												listavar[0]='\0';
												
										   }	mais_par | variaveis error tipo_var { yyerror("Expected: ':'"); yyclearin; } tipo_var mais_par;

mais_par: | ponto_virgula lista_par;

corpo_p: dc_loc begin_ comandos end_ ponto_virgula;

dc_loc: dc_v;

lista_arg: | abre_par argumentos fecha_par;

argumentos: id { strcatinv(listavar,$1); strcatinv(listavar,","); contparametros++; } mais_ident;

mais_ident: | ponto_virgula argumentos;

pfalse: { 
		sprintf(comando,"DSVF %d",prox_linha_vet+2);
		insereVetor(comando,retorno_if);} 
| else_ { sprintf(comando,"DSVF %d",prox_linha_vet+2); insereVetor(comando,retorno_if); retorno_if = prox_linha_vet; } cmd  { sprintf(comando,"DSVF %d",prox_linha_vet+2); insereVetor(comando,retorno_if+2);}; 

comandos: | cmd ponto_virgula comandos | error ponto_virgula { yyerror("Command not recognized"); yyclearin; }  comandos;

cmd: readln_ abre_par variaveis fecha_par {
											str=malloc(400 * sizeof(char));
											str=strtok(listavar,",");
											ret=busca(str,ATTR,contexto);
											if(ret==INTEGER){
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													ret=busca(cpystr,ATTR,contexto);
													if(ret==NAO_EXISTE) {
														sprintf(msg, "Identifier %s not previously declared", str);
														yyerror(msg);
														break;
													}else if(ret==CONST_FALSE){
														sprintf(msg, "Identifier %s declared as a constant", str);
														yyerror(msg);
														break;
													}
													else if(ret!=INTEGER) {
														yyerror("Conflicting types between 'readln' parameters");
														break;
													}else{
														insereVetor("LEIT",prox_linha_vet);	
														armazenaSimbolo(str, contexto, lastprocedure);
													}
													str=strtok(NULL,",");
												}
											}else if(ret==REAL){
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													ret=busca(cpystr,ATTR,contexto);
													if(ret==NAO_EXISTE) {
														sprintf(msg, "Identifier %s not previously declared", str);
														yyerror(msg);
														break;
													}else if(ret==CONST_FALSE){
														sprintf(msg, "Identifier %s declared as a constant", str);
														yyerror(msg);
														break;
													}else if(ret!=REAL) {
														yyerror("Conflicting types between 'readln' parameters");
														break;
													}else{
														insereVetor("LEIT",prox_linha_vet);
														armazenaSimbolo(str, contexto, lastprocedure);
													}
													str=strtok(NULL,",");
												}
											} else if(ret==CONST_FALSE){
												sprintf(msg, "Identifier %s declared as a constant", str);
												yyerror(msg);
											}else{
												sprintf(msg, "Identifier %s not previously declared", str);
												yyerror(msg);
											}
											listavar[0]='\0';	
										 } | 
	writeln_ abre_par variaveis fecha_par {
											str=malloc(400 * sizeof(char));
											str=strtok(listavar,",");
											ret=busca(str,EXPRESSAO,contexto);
											if(ret==INTEGER){
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													ret=busca(cpystr,EXPRESSAO,contexto);
													if(ret==NAO_EXISTE) {
														sprintf(msg, "Identifier %s not previously declared", str);
														yyerror(msg);
														break;
													}else if(ret!=INTEGER) {
														yyerror("Conflicting types between 'writeln' parameters");
														break;
													}else{
														carregaSimbolo(str, contexto, lastprocedure);
														insereVetor("IMPR",prox_linha_vet);	
													}
													str=strtok(NULL,",");
												}
											}else if(ret==REAL){
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													ret=busca(cpystr,EXPRESSAO,contexto);
													if(ret==NAO_EXISTE) {
														sprintf(msg, "Identifier %s not previously declared", str);
														yyerror(msg);
														break;
													}else if(ret!=REAL) {
														yyerror("Conflicting types between 'writeln' parameters");
														break;
													}else{
														carregaSimbolo(str, contexto, lastprocedure);
														insereVetor("IMPR",prox_linha_vet);	
													}
													str=strtok(NULL,",");
												}
											} else {
												sprintf(msg, "Identifier %s not previously declared", str);
												yyerror(msg);
											}
											listavar[0]='\0';	
										 } |
	repeat_ { comeco_repeat[i_repeat++] = prox_linha_vet; } comandos until_ condicao {
										sprintf(comando,"DSVF %d",comeco_repeat[--i_repeat]);
										insereVetor(comando,prox_linha_vet);
										} |
	repeat_ { comeco_repeat[i_repeat++] = prox_linha_vet; } comandos error condicao { yyerror("Expected: 'until'"); yyclearin; } |

	if_ condicao then_ { retorno_if = prox_linha_vet; } cmd pfalse |
	id atribuicao expressao { 
								if(busca($1,ATTR,contexto)==CONST_FALSE){
									sprintf(msg, "Identifier %s declared as a constant", $1);
									yyerror(msg);
								}
								if(busca($1,ATTR,contexto)==NAO_EXISTE){
									sprintf(msg, "Identifier %s not previously declared", $1);
									yyerror(msg);
								}
/* 								printf("Var: %d Recebe: %d\n ", busca($1,ATTR,contexto),$3.type);  */
								if(busca($1,ATTR,contexto)==INTEGER && ($3.type==REAL || $3.type==VAR_REAL)){
									sprintf(msg, "Conflicting types,try to assign a REAL to INTEGER %s", $1);
									yyerror(msg);
								}
								armazenaSimbolo($1,contexto,lastprocedure);
							  } |
	id { contparametros=0; } lista_arg 
				{   
					ret=busca($1,PROCEDURE,contexto);//retorna o numero de parametros se declarado
					if(ret==NAO_EXISTE){
						sprintf(msg, "Procedure %s not previously declared", $1);
						yyerror(msg);
					}else{
						str=malloc(400 * sizeof(char));
						str=strtok(listavar,",");
						if(ret>contparametros){
							sprintf(msg, "Too few arguments to procedure %s", $1);
							yyerror(msg);
						}else if(ret<contparametros){
							sprintf(msg, "Too many arguments to procedure %s", $1);
							yyerror(msg);
						}else{
							int retvar,retparam,argpos=1;
							posicaoPusher = prox_linha_vet;
							insereVetor("PUSHER",prox_linha_vet);
							while(str!=NULL){
								int endereco = buscaEndRelativoVar(str, contexto, $1);
								sprintf(comando,"PARAM %d",endereco);
								insereVetor(comando,prox_linha_vet);
								cpystr=malloc(400 * sizeof(char));
								strcpy(cpystr,str);
								retvar=busca(str,ATTR,contexto);
								if(retvar==NAO_EXISTE){
									sprintf(msg, "Identifier %s not previously declared", $1);
									yyerror(msg);
								}
								endereco = getPosicaoProcedure($1);
								sprintf(comando,"CHPR %d",(endereco));
								insereVetor(comando,prox_linha_vet);
								sprintf(comando,"PUSHER %d",prox_linha_vet);
								strcpy(code_vet[posicaoPusher],comando);

								retparam=buscaTipoParam($1,argpos);
								if(retvar==REAL && retparam==INTEGER){
									sprintf(msg, "Conflicting types,try to assign a REAL to expected INTEGER parameter %d in procedure %s", argpos, $1);
									yyerror(msg);
								}
								argpos++;
								str=strtok(NULL,",");
							}
						}
						listavar[0]='\0';
					}
				 } |
while_ {comeco_while[i_com_while++] = prox_linha_vet;} cont_while  | 
	if_ condicao error { yyerror("Expected: 'then'"); yyclearin; } cmd pfalse |
	while_ {comeco_while[i_com_while] = prox_linha_vet;} condicao error { yyerror("Expected: 'do'"); yyclearin; } cmd |
	begin_ comandos end_;

cont_while: condicao do_ {retorno_while[i_ret_while++] = prox_linha_vet;} cmd 
					{
						sprintf(comando,"DSVF %d",prox_linha_vet+3+i_ret_while);
						insereVetor(comando,retorno_while[--i_ret_while]);
						
						sprintf(comando,"DSVI %d",comeco_while[--i_com_while]+2+i_com_while);
						insereVetor(comando,prox_linha_vet);/*Escreve na linha atual o retorno do while*/
					} |
	    condicao error { yyerror("Expected: 'do'"); yyclearin; } cmd;

condicao: expressao relacao expressao {
											if($2==CPIG) insereVetor("CPIG",prox_linha_vet);
											if($2==CMAI) insereVetor("CMAI",prox_linha_vet);
											if($2==CPMA) insereVetor("CPMA",prox_linha_vet);
											if($2==CDES) insereVetor("CDES",prox_linha_vet);
											if($2==CPMI) insereVetor("CPMI",prox_linha_vet);
											if($2==CPME) insereVetor("CPME",prox_linha_vet);
									   } | error {yyclearin;} ;

relacao: 	operador_comp_igual { $$=CPIG; } |
			operador_comp_maiorigual { $$=CMAI; } |
			operador_comp_maior { $$=CPMA; } |
			operador_comp_diff { $$=CDES; } |
			operador_comp_menorigual { $$=CPMI; } |
			operador_comp_menor { $$=CPME; }
			| error { yyerror("Expected any operator: '=', '>', '<', '>=', '<=', '<>' "); yyclearin; }; 

expressao: termo outros_termos { 
								if($2.type==TNULL){
									$$.type = $1.type; 
									if($1.type==INTEGER) { $$.i_value=$1.i_value;  }
									if($1.type==REAL) { $$.f_value=$1.f_value;  }
									if($1.type==VAR_INT || $1.type==VAR_REAL) { $$.name=$1.name;  };  
									
								}else{
									$$.type=TNULL;
									if($2.type==REAL || $1.type==REAL){
										$$.type=REAL;
									} else if ($2.type==INTEGER && $1.type==INTEGER){
										$$.type=INTEGER;
									} 
								}
							};

op_un: { $$='0'; } | operador_mat_soma { $$='+'; } |
		operador_mat_sub { $$='-'; } ;

outros_termos: { $$.type=TNULL; } | op_ad termo outros_termos { 
								      if($3.type==TNULL){
									      $$.type = $2.type; 
								      }else{
									      if($2.type==REAL || $3.type==REAL || $2.type==VAR_REAL || $2.type==CONST_REAL || $3.type==VAR_REAL || $3.type==CONST_REAL){
										      $$.type=REAL;
									      } else {
										      $$.type=INTEGER;
									      }
									      
								      }
								      if($1=='+') insereVetor("SOMA",prox_linha_vet);
								      if($1=='-') insereVetor("SUBT",prox_linha_vet);
								      $$.math_op=$1;
								};

op_ad: 	operador_mat_soma { $$='+'; } |
		operador_mat_sub { $$='-'; };

termo: op_un fator { 
		      if($2.type==INTEGER)
		      {
			      sprintf(comando,"CRCT %d",$2.i_value );
			      insereVetor(comando,prox_linha_vet);
		      }
		      if($2.type==REAL)
		      {
			      sprintf(comando,"CRCT %f",$2.f_value);
			      insereVetor(comando,prox_linha_vet);
		      }
		      if(isVarOrConst($2.type)) carregaSimbolo($2.name,contexto,lastprocedure);
		    } mais_fatores { 
				    if($4.type==TNULL){
					    $$.type = $2.type;
				    }
				    if($4.type!=TNULL){
					    if($4.math_op=='/' && ($4.type==REAL || $2.type==REAL)){
						    yyerror("Division only avaiable between integers");
					    }
					    $$.type=$2.type;
				    }
		    };

mais_fatores: { $$.type=TNULL; } | op_mult fator { 
						      if($2.type==INTEGER)
						      {
							      sprintf(comando,"CRCT %d",$2.i_value );
							      insereVetor(comando,prox_linha_vet);
						      }
						      if($2.type==REAL)
						      {
							      sprintf(comando,"CRCT %f",$2.f_value);
							      insereVetor(comando,prox_linha_vet);
						      } 
						      if(isVarOrConst($2.type)) carregaSimbolo($2.name,contexto,lastprocedure);
						    } mais_fatores { 
									$$.type=$2.type;
									if($4.type!=TNULL){
										$$.type=$4.type;
									} 
									if($2.type==REAL || $2.type==INTEGER){
										$$.type=$2.type;
									}
									$$.math_op=$1;
									if($1=='*') insereVetor("MULT",prox_linha_vet);
								        if($1=='/') insereVetor("DIVI",prox_linha_vet);
						   };	

op_mult:  	operador_mat_mult { $$='*'; } | 
			operador_mat_div { $$='/'; };

fator: id { 
			ret=busca($1,EXPRESSAO,contexto);
			if(ret==NAO_EXISTE){
				sprintf(msg, "Identifier %s not previously declared", $1);
				yyerror(msg);
			}else{
				$$.name=$1; 
				$$.type=buscaTipoVarCons($1,contexto, lastprocedure);
			}
		  } | numero { $$.type = $1.type; 
						if($1.type==INTEGER) $$.i_value=$1.i_value; 
						if($1.type==REAL) $$.f_value=$1.f_value;  
					  } | abre_par expressao fecha_par;

numero: num_integer { $$.type = INTEGER; $$.i_value = $1; } | num_real { $$.type = REAL; $$.f_value = $1; } | error { yyerror("Expected a number"); yyclearin; };

%%
int AlocaMemoria(){
	if(numerrors==0){
		insereVetor("ALME 1",prox_linha_vet);
	return 1;
	}
	return 0;
}

int main (int argc, char *argv[])
{
	register int i=0;
	extern FILE *yyin;
	++argv; 
	--argc;
	yyin = fopen( argv[0], "r" ); /*Passa a entrada pelo arquivo de parametro*/
/*  	yydebug = 1;  Utilizado para Degub */
	alocaTabelaSimbolos();
	//Inicia escrita do código
	code_file = fopen("code.p", "w+");

	code_vet =  (char **) malloc(500*sizeof(char *));
	for(i=0; i<500; i++)
		code_vet[i] = (char *) malloc(32*sizeof(char));
	comando =  (char *) malloc(32*sizeof(char));
	insereVetor("INPP",prox_linha_vet);

	yyparse();
	insereVetor("PARA",prox_linha_vet);
	gravaVetor();
	fclose(code_file);

	if(numerrors==0)
		printf ( "Parse Completed\n" );
	else{
		remove("code.p");
		printf ( "Parse Completed with %d errors\n", numerrors);
	}
	printTabela();


	return 0;
}

void yyerror (char *s)
{
 	if(strcmp(s,"syntax error")){ /*Descartamos as mensagens padrões "syntax error do Bison*/
		fprintf (stderr, "Line %d: ERROR: %s\n",num_lines, s);
		numerrors++;
 	} 
}
