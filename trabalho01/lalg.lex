%{
 #include<stdio.h>
 #include<string.h>

 #define NUM_RESERVADAS 16
 #define TAM_MAX_PALAVRA 16
 #define TAM_MAX_ID 32
 /*Definicao baseada em int e float de 4bytes*/
 #define MAXLEN_INTEGER 10
 /*IEEE 754-2008 - alterada para ausencia de sinal*/
 #define MAXLEN_FLOAT_INTPART 5
 #define MAXLEN_FLOAT_DECPART 6
%}

DIGIT [0-9]
IDENT [a-zA-Z][a-zA-Z0-9]*
	int num_lines = 1, num_token = 1;
 char **palavras_reservadas;
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
          	if(strlen(yytext) > TAM_MAX_ID)
       	printf("token %d: %s-ERRO\nError at line %d: Max id length exceeded: %s\n",num_token++,yytext,num_lines, yytext);
     	if(buscaBinaria(palavras_reservadas,yytext,16)==-1)
              	printf("token %d: %s-id\n",num_token++, yytext);
          	else
              	printf("token %d: %s-%s\n",num_token++, yytext,yytext);
   	}

{DIGIT}+  {
       	if(strlen(yytext) > MAXLEN_INTEGER)
         	printf("token %d: %s-ERRO\nError at line %d: Max integer length exceeded: %s\n",num_token++,yytext,num_lines, yytext);
       	else
         	printf("token %d: %s-num_integer\n",num_token++,yytext);
     	}

{DIGIT}+"."{DIGIT}+ {
                 	int n_dot = strchr(yytext,'.') - yytext;
                 	if(n_dot > MAXLEN_FLOAT_INTPART)
                   	printf("token %d: %s-ERRO\nError at line %d: Max integer part length of real number exceeded: %s\n",num_token++,yytext,num_lines,yytext);
                 	else if ((strlen(yytext)-n_dot-1)>MAXLEN_FLOAT_DECPART)
                   	printf("token %d: %s-ERRO\nError at line %d: Max decimal part length of real number exceeded: %s\n",num_token++,yytext,num_lines,yytext);
                 	else
                   	printf("token %d: %s-num_real\n",num_token++,yytext);
               	}


"="|">="|">"|"<>"|"<="|"<"   printf("token %d: %s-operador-comp\n", num_token++,yytext);

"+"|"-"|"*"|"/" printf("token %d: %s-operador-mat\n",num_token++, yytext);

";"   printf("token %d: %s-;\n", num_token++,yytext);
","   printf("token %d: %s-,\n", num_token++,yytext);
":="  printf("token %d: %s-:=\n", num_token++,yytext);
":"   printf("token %d: %s-:\n", num_token++,yytext);
"\."  printf("token %d: %s-.\n", num_token++,yytext);
"\("  printf("token %d: %s-(\n", num_token++,yytext);
"\)"  printf("token %d: %s-)\n", num_token++,yytext);

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
     	printf("error-Error at line %d: Comment not closed. EOF reached",num_lines);
     	break;
   	}  	 
 	}
   }

({IDENT}[^0-9\n\t ;{\/\*\+\-<>"<="">=""<>"\)=\.\:\,\(":="]*)+ {
            printf("token %d: %s-ERRO\nError at line %d: Identifier malformed %s\n",num_token++,yytext,num_lines,yytext);
}

({DIGIT}+[^0-9\n;{\/\*\+\-<>"<="">=""<>"\)=\.]+)+{DIGIT}*  {
   				 printf("token %d: %s-ERRO\nError at line %d: Number malformed %s\n",num_token++,yytext,num_lines,yytext);
}

({DIGIT}+[^0-9\n;{\/\*\+\-<>"<="">=""<>"\)=]*)+[\.]({DIGIT}*[^0-9\n;{\/\*\+\-<>"<="">=""<>"\)=\.]*)*  { 
   				 printf("token %d: %s-ERRO\nError at line %d: Number malformed %s\n",num_token++,yytext,num_lines,yytext);
}

. printf( "token %d: %s-ERRO\nError at line %d: Unrecognized character : %s\n",num_token++,yytext,num_lines, yytext);

%%

int main()
{
 register int i=0;

 /*Inicializa o vetor de palavras reservadas
   por possuir poucas palavras prefiriu-se atribuí-las
   dinamicamente do que lê-las de um arquivos*/
 palavras_reservadas = (char **) malloc(NUM_RESERVADAS*sizeof(char *));
 for(i=0; i<NUM_RESERVADAS; i++)
   palavras_reservadas[i] = (char *) malloc(TAM_MAX_PALAVRA*sizeof(char));

 strcpy(palavras_reservadas[0],"begin");
 strcpy(palavras_reservadas[1],"const");
 strcpy(palavras_reservadas[2],"else");
 strcpy(palavras_reservadas[3],"end");
 strcpy(palavras_reservadas[4],"if");
 strcpy(palavras_reservadas[5],"integer");
 strcpy(palavras_reservadas[6],"procedure");
 strcpy(palavras_reservadas[7],"program");
 strcpy(palavras_reservadas[8],"readln");
 strcpy(palavras_reservadas[9],"real");
 strcpy(palavras_reservadas[10],"repeat");
 strcpy(palavras_reservadas[11],"then");
 strcpy(palavras_reservadas[12],"until");
 strcpy(palavras_reservadas[13],"var");
 strcpy(palavras_reservadas[14],"while");
 strcpy(palavras_reservadas[15],"writeln");

 yylex(); /*começa a rotina do lexico*/
 return 0;
}
