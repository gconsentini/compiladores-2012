%{
	#define YYSTYPE double
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
%token begin
%token constante
%token senao
%token end
%token se
%token integer
%token procedure
%token program
%token readln
%token real
%token repeat
%token then
%token until
%token var
%token enquanto
%token writeln
%token ponto_virgula ";"
%token virgula ","
%token atribuicao ":="
%token doispontos ":"
%token ponto "."
%token abre_par "("
%token fecha_par ")"
%token operador-mat-soma "+"
%token operador-mat-sub "-"
%token operador-mat-mult "*"
%token operador-mat-div "/"
%token operador-comp-igual "="
%token operador-comp-maiorigual ">="
%token operador-comp-maior ">"
%token operador-comp-diff "<>"
%token operador-comp-menorigual "<="
%token operador-comp-menor "<"  


%% /* Grammar rules and actions follow.  */

/* programa::= program ident ; <corpo> . */
programa: program id ponto_virgula corpo ponto ;
corpo: enquanto repeat senao;
%%

int main (void)
{
register int i=0;
	yyparse();
	printf ( "Parse Completed\n" );
	return 0;
}

void yyerror (char *s)
{
fprintf (stderr, "%s\n", s);
}
