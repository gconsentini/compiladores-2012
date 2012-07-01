%{
 #include<stdio.h>
 #include<string.h>
 #include "lalg.tab.h"

 #define NUM_RESERVADAS 17
 #define TAM_MAX_PALAVRA 16
 #define TAM_MAX_ID 32
 /*Definicao baseada em int e float de 4bytes*/
 #define MAXLEN_INTEGER 10
 /*IEEE 754-2008 - alterada para ausencia de sinal*/
 #define MAXLEN_FLOAT_INTPART 5
 #define MAXLEN_FLOAT_DECPART 6
 
 int num_lines = 1;
 extern YYSTYPE yylval;

%}
%option yylineno

DIGIT [0-9]
IDENT [a-zA-Z][a-zA-Z0-9]*
	int num_token = 1, inibusca=1;
	char **palavras_reservadas;
	char err_msg[200];

 void iniciaListaPalavras()
 {
 /*Inicializa o vetor de palavras reservadas
	por possuir poucas palavras prefiriu-se atribuí-las
	dinamicamente do que lê-las de um arquivos*/
	int i;
	palavras_reservadas = (char **) malloc(NUM_RESERVADAS*sizeof(char *));
	for(i=0; i<NUM_RESERVADAS; i++)
	palavras_reservadas[i] = (char *) malloc(TAM_MAX_PALAVRA*sizeof(char));
	strcpy(palavras_reservadas[0],"begin");
	strcpy(palavras_reservadas[1],"const");
	strcpy(palavras_reservadas[2],"do");
	strcpy(palavras_reservadas[3],"else");
	strcpy(palavras_reservadas[4],"end");
	strcpy(palavras_reservadas[5],"if");
	strcpy(palavras_reservadas[6],"integer");
	strcpy(palavras_reservadas[7],"procedure");
	strcpy(palavras_reservadas[8],"program");
	strcpy(palavras_reservadas[9],"readln");
	strcpy(palavras_reservadas[10],"real");
	strcpy(palavras_reservadas[11],"repeat");
	strcpy(palavras_reservadas[12],"then");
	strcpy(palavras_reservadas[13],"until");
	strcpy(palavras_reservadas[14],"var");
	strcpy(palavras_reservadas[15],"while");
	strcpy(palavras_reservadas[16],"writeln");
 }
 /**
   * Função que busca no vetor de palavras reservadas o identificador atual
   * utilizando busca binária.
   *
   * @param palavras_reservadas: ponteiro duplo para o vetor de strings contendo as palavras reservadas.
   * @param ident: ponteiro para a cadeia atual.
   * @param tamanho: tamanho do vetor de palavras reservadas.
   *
   * @return
   * A posição da palavra no vetor de palavras reservadas palavras_reservadas, caso não encontre retorna -1.
   */
 int buscaBinaria (char **palavras_reservadas, char* ident, int tamanho)
 {
   int inf = 0;
   int sup = tamanho-1;
   int meio;
   while (inf <= sup)
   {
 	meio = (inf + sup)/2;
 	if (strcmp (ident,palavras_reservadas[meio])==0)
   	return meio;
 	else if (strcmp (ident,palavras_reservadas[meio])>0)
   	inf = meio+1;
 	else
   	sup = meio-1;
   }
   return -1;
 }
%%

{IDENT} {
          	if(strlen(yytext) > TAM_MAX_ID){
				sprintf(err_msg,"Max id length exceeded: %s\n",yytext);
				yyerror(err_msg);
			}
			if(inibusca==1){
				iniciaListaPalavras();
				inibusca=0;
			}
			int pos;
			pos=buscaBinaria(palavras_reservadas,yytext,17);
			if(pos==-1){
				//printf("token %d: %s-id\n",num_token++, yytext);
				yylval.name = strdup( yytext );
				return(id);
          	}else{
              	//printf("token %d: %s-%s\n",num_token++, yytext,yytext);
				if(pos==0) return(begin_);
				if(pos==1) return(const_);
				if(pos==2) return(do_);
				if(pos==3) return(else_);
				if(pos==4) return(end_);
				if(pos==5) return(if_);
				if(pos==6) return(integer_);
				if(pos==7) return(procedure_);
				if(pos==8) return(program_);
				if(pos==9) return(readln_);
				if(pos==10) return(real_);
				if(pos==11) return(repeat_);
				if(pos==12) return(then_);
				if(pos==13) return(until_);
				if(pos==14) return(var_);
				if(pos==15) return(while_);
				if(pos==16) return(writeln_);
			}
   	}

{DIGIT}+  	{
			if(strlen(yytext) > MAXLEN_INTEGER){
					sprintf(err_msg,"Max integer length exceeded: %s\n",yytext);
					yyerror(err_msg);
			}
			else{
				//printf("token %d: %s-num_integer\n",num_token++,yytext);
				yylval.i_number = atoi(yytext);
				return(num_integer);
			}
	}

{DIGIT}+"."{DIGIT}+ {
                 	int n_dot = strchr(yytext,'.') - yytext;
                 	if(n_dot > MAXLEN_FLOAT_INTPART){
						sprintf(err_msg,"Max integer part length of real number exceeded: %s\n",yytext);
						yyerror(err_msg);
					}
                 	else if ((strlen(yytext)-n_dot-1)>MAXLEN_FLOAT_DECPART){
						sprintf(err_msg,"Max decimal part length of real number exceeded: %s\n",yytext);
						yyerror(err_msg);
					}
                 	else{
						//printf("token %d: %s-num_real\n",num_token++,yytext);
						yylval.r_number = atof(yytext);
						return(num_real);
					}
				}


"="   { return(operador_comp_igual); }
">="  { return(operador_comp_maiorigual); }
">"   { return(operador_comp_maior); }
"<>"  { return(operador_comp_diff); }
"<="  { return(operador_comp_menorigual); }
"<"   { return(operador_comp_menor); }

"+" { return(operador_mat_soma); }
"-" { return(operador_mat_sub); }
"*" { return(operador_mat_mult); }
"/" { return(operador_mat_div); }

";"   { return(ponto_virgula); }
","   { return(virgula); }
":="  { return(atribuicao); }
":"   { return(doispontos); }
"\."  { return(ponto); }
"\("  { return(abre_par ); }
"\)"  { return(fecha_par ); }

\n	num_lines++; /*conta o numero de linhas*/

[ \t]+ /*consome espacos em branco, tabulacao*/

"{" { /*consome comentario de multiplas linhas*/
 	register int c;
	 
 	for ( ; ; )
 	{
   	while ( (c = input()) != '}' && c != EOF );	/* eat up text of comment */
   	if ( c == '}' )   
     	break;	/* found the end */
   	if ( c == EOF )   
   	{
     	printf("Comment not closed. EOF reached");
     	break;
   	}  	 
 	}
   }

({IDENT}[^0-9\n\t ;{\/\*\+\-<>"<="">=""<>"\)=\.\:\,\(":="]*)+ {
            sprintf(err_msg,"Identifier malformed %s",yytext);
			yyerror(err_msg);
			return(invalido);
}

({DIGIT}+[^0-9\n;{\/\*\+\-\<\>"<="">=""<>"\)\=\.\ ]+)+{DIGIT}*  {
   				 sprintf(err_msg,"Number malformed %s",yytext);
				 yyerror(err_msg);
				 return(invalido);
}

({DIGIT}+[^0-9\n;{\/\*\+\-\<\>"<="">=""<>"\)\=\ ]*)+[\.]({DIGIT}*[^0-9\n;{\/\*\+\-<>"<="">=""<>"\)=\.]*)*  { 
   				 sprintf(err_msg,"Number malformed %s",yytext);
				 yyerror(err_msg);
				 return(invalido);
}

. {				 sprintf(err_msg,"Unrecognized character : %s", yytext);
				 yyerror(err_msg);
				 return(invalido);
 }
%%

int yywrap(void){}
