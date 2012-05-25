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
%}

%token id
%token num_integer
%token num_real
%token begin_
%token const_
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
programa: program_ id ponto_virgula corpo ponto ;
corpo: while_ repeat_ else_;
%%

int main (int argc, char *argv[])
{
	register int i=0;
	extern FILE *yyin;
	++argv; 
	--argc;
	yyin = fopen( argv[0], "r" );
	yydebug = 1;
	yyparse();
	printf ( "Parse Completed\n" );
	return 0;
}

void yyerror (char *s)
{
fprintf (stderr, "%s\n", s);
}
