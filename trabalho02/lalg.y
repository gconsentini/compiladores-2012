%{
	#define YYSTYPE double
	#define YYDEBUG 1 /* For Debugging */
	#define NUM_RESERVADAS 16
	#define TAM_MAX_PALAVRA 16
	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int yylex (void);
	void yyerror (char *);
	int numerrors=0;
%}

%token id
%token num_integer
%token num_real
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


%% /* Grammar rules and actions follow.  */

/* programa::= program ident ; <corpo> . */
programa: program_ id ponto_virgula corpo ponto;
corpo: dc begin_ comandos end_;
dc: dc_c dc_v dc_p;
dc_c: | const_ id operador_comp_igual numero ponto_virgula dc_c;
dc_v: | var_ variaveis doispontos tipo_var ponto_virgula dc_v;
tipo_var: real_ | integer_;
variaveis: id mais_var;
mais_var: | virgula variaveis;
dc_p: | procedure_ id parametros ponto_virgula corpo_p dc_p;
parametros: | abre_par lista_par fecha_par;
lista_par: variaveis doispontos tipo_var mais_par;
mais_par: | ponto_virgula lista_par;
corpo_p: dc_loc begin_ comandos end_ ponto_virgula;
dc_loc: dc_v;
lista_arg: | abre_par argumentos fecha_par;
argumentos: id mais_ident;
mais_ident: | ponto_virgula argumentos;
pfalse: | else_ cmd;
comandos: | cmd ponto_virgula comandos;
cmd: readln_ abre_par variaveis fecha_par | 
	writeln_ abre_par variaveis fecha_par |
	repeat_ comandos until_ condicao |
	if_ condicao then_ cmd pfalse |
	id atribuicao expressao |
	id lista_arg |
	while_ condicao do_ cmd |
	begin_ comandos end_;
condicao: expressao relacao expressao /* | error { yyerror("Erro na condição do laço while"); }  */;
relacao: 	operador_comp_igual  |
			operador_comp_maiorigual |
			operador_comp_maior  |
			operador_comp_diff |
			operador_comp_menorigual |
			operador_comp_menor; 
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
numero: num_integer | num_real;


%%

int main (int argc, char *argv[])
{
	register int i=0;
	extern FILE *yyin;
	++argv; 
	--argc;
	yyin = fopen( argv[0], "r" );
	/*yydebug = 1; */ 
	yyparse();
	if(numerrors==0)
		printf ( "Parse Completed\n" );
	else
		printf ( "Parse Completed with %d errors\n", numerrors);

	return 0;
}

void yyerror (char *s)
{
fprintf (stderr, "ERROR: Line number , %s\n", s);
numerrors++;
}
