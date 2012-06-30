/* 	Declaração de cabeçalho do bison */
%{
	
	#define YYDEBUG 1 /* For Debugging */
	#define NUM_RESERVADAS 16
	#define TAM_MAX_PALAVRA 16
	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "estrutura_lista.h"
	int yylex (void);
	void yyerror (char *);
	int numerrors=0;
	extern int num_lines;

/*	typedef struct{
		char *nome;
		char *tipo;
		double valor;
		struct simbolo *ant, *prox;
	} simbolo;
*/

	typedef struct
	{
        char *nome;
        int tipo;
		float valorf;
		int valori;
        unsigned int end_relativo;
		int contexto;
	}simbolo;

	
%}
/* 	Declaração de tokens de bison  */
%union YYSTYPE{
	int i_number;
	float r_number;
	char* name;
	int type;
	struct symbol {
		int i_value;
		float f_value;
		int type;
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
%token atribuicao 
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
%nonassoc error
%% /* Delaração de Regras de gramática do Bison */

programa: program_ id ponto_virgula corpo ponto
	  | error id ponto_virgula { yyerror("Expected: program"); yyclearin; } corpo ponto
	  | error id error { yyerror("Expected: program"); yyclearin; } corpo ponto
	  | program_ id error { yyerror("Expected: ';' before begin or declaration of variables and constants"); yyclearin; } corpo  ponto
	  | program_ id ponto_virgula corpo error { yyerror("Expected: '.'"); } 
corpo: dc begin_ comandos end_
	| dc error { yyerror("Expected: begin or declaration of variables and constants");yyclearin; } comandos end_
	| dc begin_ comandos error { yyerror("Expected: end"); };
dc: dc_c dc_v dc_p;
dc_c: | const_ id operador_comp_igual numero ponto_virgula dc_c { printf("%s %d %f", $2, $4.i_value, $4.f_value); }
      | const_ id error { yyerror("Expected: '='"); } numero ponto_virgula dc_c
      | const_ id operador_comp_igual numero error { yyerror("Expected: ';'"); } dc_c; 
dc_v: | var_ variaveis doispontos tipo_var ponto_virgula dc_v
	  | var_ error { yyerror("Expected an identifier"); } doispontos tipo_var ponto_virgula dc_v
      | var_ variaveis error { yyerror("Expected: ':'");yyclearin; } tipo_var ponto_virgula dc_v
      | var_ variaveis doispontos tipo_var error { yyerror("Expected: ';'");yyclearin; } dc_v;
tipo_var: real_ | integer_
	  | error { yyerror("Incorrect type: Expected integer or real"); yyclearin; };
variaveis: id mais_var;
mais_var: | virgula variaveis;
dc_p: | procedure_ id parametros ponto_virgula corpo_p dc_p;
parametros: | abre_par lista_par fecha_par;
lista_par: variaveis doispontos tipo_var mais_par | variaveis error tipo_var { yyerror("Expected: ':'"); yyclearin; } tipo_var mais_par;
mais_par: | ponto_virgula lista_par;
corpo_p: dc_loc begin_ comandos end_ ponto_virgula;
dc_loc: dc_v;
lista_arg: | abre_par argumentos fecha_par;
argumentos: id mais_ident;
mais_ident: | ponto_virgula argumentos;
pfalse: | else_ cmd; 
comandos: | cmd ponto_virgula comandos | error ponto_virgula { yyerror("Comando não reconhecido"); yyclearin; }  comandos;
cmd: readln_ abre_par variaveis fecha_par | 
	writeln_ abre_par variaveis fecha_par |
	repeat_ comandos until_ condicao |
	repeat_ comandos error condicao { yyerror("Expected: 'until'"); yyclearin; } |
	if_ condicao then_ cmd pfalse |
	id pos_id |
	while_ condicao do_ cmd |
	if_ condicao error { yyerror("Expected: 'then'"); yyclearin; } cmd pfalse |
	while_ condicao error { yyerror("Expected: 'do'"); yyclearin; } cmd |
	begin_ comandos end_;
pos_id: atribuicao expressao | lista_arg;
condicao: expressao relacao expressao | error {yyclearin;} ;
relacao: 	operador_comp_igual  |
			operador_comp_maiorigual |
			operador_comp_maior  |
			operador_comp_diff |
			operador_comp_menorigual |
			operador_comp_menor
			| error { yyerror("Expected any operator: '=', '>', '<', '>=', '<=', '<>' "); yyclearin; }; 
expressao: termo outros_termos;
op_un: | operador_mat_soma |
		operador_mat_sub;
outros_termos: | op_ad termo outros_termos;
op_ad: 	operador_mat_soma |
		operador_mat_sub;
termo: op_un fator mais_fatores;
mais_fatores: | op_mult fator mais_fatores;
op_mult:  	operador_mat_mult | 
			operador_mat_div;
fator: id | numero | abre_par expressao fecha_par;
numero: num_integer | num_real | error { yyerror("Expected a number"); yyclearin; };

%%

int main (int argc, char *argv[])
{
	register int i=0;
	extern FILE *yyin;
	++argv; 
	--argc;
	yyin = fopen( argv[0], "r" ); /*Passa a entrada pelo arquivo de parametro*/
/*  	yydebug = 1;  Utilizado para Degub */
	yyparse();
	if(numerrors==0)
		printf ( "Parse Completed\n" );
	else
		printf ( "Parse Completed with %d errors\n", numerrors);

	return 0;
}

void yyerror (char *s)
{
 	if(strcmp(s,"syntax error")){ /*Descartamos as mensagens padrões "syntax error do Bison*/
		fprintf (stderr, "Line %d: ERROR: %s\n",num_lines, s);
		numerrors++;
 	} 
}
