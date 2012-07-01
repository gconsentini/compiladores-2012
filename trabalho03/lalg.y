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
#define TNULL 199

//Tipos de tipos esperados
#define ATTR 200
#define EXPRESSAO 201 

//Tipos de erros
#define NAO_EXISTE -1
#define CONST_FALSE -2
#define PROCEDURE_FALSE -3
#define VAR_FALSE -4


	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	int yylex (void);
	void yyerror (char *);
	int numerrors=0;
	int contexto=0;
	int ret;
	extern int num_lines;
	char listavar[400];
	char *str;
	char *cpystr;
	char msg[300];

	
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
%type <math_op> op_un
%type <math_op> op_ad
/* %type <i_number> pos_id */
/* %type <i_number> cmd */
%nonassoc error
%% /* Delaração de Regras de gramática do Bison */

programa: program_ id { insereProgram ($2); } ponto_virgula corpo ponto 
	  | error id ponto_virgula { yyerror("Expected: program"); yyclearin; } corpo ponto
	  | error id error { yyerror("Expected: program"); yyclearin; } corpo ponto
	  | program_ id error { yyerror("Expected: ';' before begin or declaration of variables and constants"); yyclearin; } corpo  ponto
	  | program_ id { insereProgram ($2); } ponto_virgula corpo error { yyerror("Expected: '.'"); } ;

corpo: dc begin_ comandos end_
	| dc error { yyerror("Expected: begin or declaration of variables and constants");yyclearin; } comandos end_
	| dc begin_ comandos error { yyerror("Expected: end"); };

dc: dc_c dc_v dc_p;

dc_c: | const_ id operador_comp_igual numero ponto_virgula dc_c { int retorno;
																	if($4.type==INTEGER)
																	{ 
																		retorno = insereConstInt ($2, $4.i_value, contexto);
																		if(retorno==0)
																			yyerror("Redeclaration of constants");
																		else if(retorno ==-1)
																			yyerror("Conflicting types");
																	} 
																	else if($4.type==REAL) 
																	{ 
																		retorno = insereConstReal ($2, $4.f_value, contexto);
																		if(retorno==0) 
																			yyerror("Redeclaration of constants");
																		else if(retorno ==-1)
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
																		if(retorno==0)
																			yyerror("Redeclaration of variables");
																		else if(retorno ==-1)
																			yyerror("Conflicting types");
																	} else if($4==REAL) 
																	{ 
																		retorno = insereVarReal (cpystr, contexto);
																		if(retorno==0)
																			yyerror("Redeclaration of variables");
																		else if(retorno ==-1)
																			yyerror("Conflicting types");
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

variaveis: id mais_var { strcat(listavar,$1); strcat(listavar,","); };

mais_var: | virgula variaveis;

dc_p: | procedure_ id { contexto=1; int retorno; if(insereProcedure ($2,contexto)!=1) yyerror("Redefinition of procedure");} parametros ponto_virgula corpo_p { contexto=0; } dc_p;

parametros: | abre_par lista_par fecha_par;

lista_par: variaveis doispontos tipo_var 	{	
												str=malloc(400 * sizeof(char));
												str=strtok(listavar,",");
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													if($3==INTEGER){ 
														insereParamInt (cpystr, contexto);
													} else if($3==REAL) { 
														insereParamReal (cpystr, contexto);
													} 
													str=strtok(NULL,",");
												}
												listavar[0]='\0';
												
										   }	mais_par | variaveis error tipo_var { yyerror("Expected: ':'"); yyclearin; } tipo_var mais_par;

mais_par: | ponto_virgula lista_par;

corpo_p: dc_loc begin_ comandos end_ ponto_virgula;

dc_loc: dc_v;

lista_arg: | abre_par argumentos fecha_par;

argumentos: id mais_ident;

mais_ident: | ponto_virgula argumentos;

pfalse: | else_ cmd; 

comandos: | cmd ponto_virgula comandos | error ponto_virgula { yyerror("Command not recognized"); yyclearin; }  comandos;

cmd: readln_ abre_par variaveis fecha_par | 
	writeln_ { printf("Write"); } abre_par variaveis fecha_par {
																	
																	str=malloc(400 * sizeof(char));
																	str=strtok(listavar,",");
																	while(str!=NULL){
																		cpystr=malloc(400 * sizeof(char));
																		strcpy(cpystr,str);
																		
																		
																		
																		str=strtok(NULL,",");
																	}
																	listavar[0]='\0';	
																	
																	
																	
																	
																 } |
	repeat_ comandos until_ condicao |
	repeat_ comandos error condicao { yyerror("Expected: 'until'"); yyclearin; } |
	if_ condicao then_ cmd pfalse |
	id atribuicao expressao { 
								if(busca($1,ATTR,contexto)==CONST_FALSE){
									sprintf(msg, "Identifier %s declared as a constant", $1);
									yyerror(msg);
								}
								if(busca($1,ATTR,contexto)==NAO_EXISTE){
									sprintf(msg, "Identifier %s not previously declared", $1);
									yyerror(msg);
								}
								if(busca($1,ATTR,contexto)!=$3.type && $3.type!=TNULL){
									sprintf(msg, "Conflicting types, ", $1);
									if($3.type==INTEGER || $3.type==VAR_INT) strcat(msg, "try to assign a INTEGER to REAL");
									if($3.type==REAL || $3.type==VAR_REAL) strcat(msg, "try to assign a REAL to INTEGER");
									yyerror(msg);
								}
							  } |
	id lista_arg {
					if(busca($1,PROCEDURE,contexto)==NAO_EXISTE){
						sprintf(msg, "Procedure %s not previously declared", $1);
						yyerror(msg);
					}
				 } |
	while_ condicao do_ cmd |
	if_ condicao error { yyerror("Expected: 'then'"); yyclearin; } cmd pfalse |
	while_ condicao error { yyerror("Expected: 'do'"); yyclearin; } cmd |
	begin_ comandos end_;

/* pos_id: atribuicao { insereProgram ("Aqui"); $<i_number>$=ATTR; } expressao | lista_arg { insereProgram ("Aqui"); $<i_number>$=PROCEDURE; }; */

condicao: expressao relacao expressao | error {yyclearin;} ;

relacao: 	operador_comp_igual  |
			operador_comp_maiorigual |
			operador_comp_maior  |
			operador_comp_diff |
			operador_comp_menorigual |
			operador_comp_menor
			| error { yyerror("Expected any operator: '=', '>', '<', '>=', '<=', '<>' "); yyclearin; }; 

expressao: termo outros_termos { 
								if($2.type==TNULL){
									$$.type = $1.type; 
									if($1.type==INTEGER) $$.i_value=$1.i_value; 
									if($1.type==REAL) $$.f_value=$1.f_value;
									if($1.type==VAR_INT || $1.type==VAR_REAL) $$.name=$1.name;  
								}else{
									$$.type=TNULL;
									if($2.type==REAL || $1.type==REAL){
										$$.type=REAL;
									} else if ($2.type==INTEGER || $1.type==INTEGER){
										$$.type=INTEGER;
									}
								}
							};

op_un: { $$.math_op='0'; } | operador_mat_soma { $$.math_op='+'; } |
		operador_mat_sub { $$.math_op='-'; } ;

outros_termos: { $$.type==TNULL; } | op_ad termo outros_termos { 
																	$$.type==$2.type; 
																	if($3.type==TNULL){
																		$$.type = $2.type; 
																		if($2.type==INTEGER) $$.i_value=$2.i_value; 
																		if($2.type==REAL) $$.f_value=$2.f_value;
																		if($2.type==VAR_INT || $2.type==VAR_REAL) $$.name=$2.name;  
																	}else{
																		$$.type=TNULL;
																		if($2.type==REAL || $3.type==REAL){
																			$$.type=REAL;
																		} else if ($2.type==INTEGER || $3.type==INTEGER){
																			$$.type=INTEGER;
																		}
																	}
																 };

op_ad: 	operador_mat_soma { $$.math_op='+'; } |
		operador_mat_sub { $$.math_op='-'; };

termo: op_un fator mais_fatores { 
									if($3.type==TNULL){
										$$.type = $2.type; 
										if($2.type==INTEGER) $$.i_value=$2.i_value; 
										if($2.type==REAL) $$.f_value=$2.f_value;  
										if($2.type==VAR_INT || $2.type==VAR_REAL) $$.name=$2.name;  
									}
								};

mais_fatores: { $$.type==TNULL; } | op_mult fator mais_fatores;

op_mult:  	operador_mat_mult { $$.math_op='*'; } | 
			operador_mat_div { $$.math_op='/'; };

fator: id { 
			ret=busca($1,ATTR,contexto);
			if(ret==NAO_EXISTE){
				sprintf(msg, "Identifier %s not previously declared", $1);
				yyerror(msg);
			}else{
				$$.name=$1; $$.type=ret;
			}
		  } | numero { $$.type = $1.type; if($1.type==INTEGER) $$.i_value=$1.i_value; if($1.type==REAL) $$.f_value=$1.f_value;  } | abre_par expressao fecha_par;

numero: num_integer { $$.type = INTEGER; $$.i_value = $1; } | num_real { $$.type = REAL; $$.f_value = $1; } | error { yyerror("Expected a number"); yyclearin; };

%%

int main (int argc, char *argv[])
{
	register int i=0;
	extern FILE *yyin;
	++argv; 
	--argc;
	yyin = fopen( argv[0], "r" ); /*Passa a entrada pelo arquivo de parametro*/
/*  	yydebug = 1;  Utilizado para Degub */
	alocaTabelaSimbolos();
	yyparse();
	if(numerrors==0)
		printf ( "Parse Completed\n" );
	else
		printf ( "Parse Completed with %d errors\n", numerrors);
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
