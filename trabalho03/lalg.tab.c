/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "lalg.y"

	
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
	


/* Line 268 of yacc.c  */
#line 342 "lalg.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     id = 258,
     num_integer = 259,
     num_real = 260,
     begin_ = 261,
     const_ = 262,
     do_ = 263,
     else_ = 264,
     end_ = 265,
     if_ = 266,
     integer_ = 267,
     procedure_ = 268,
     program_ = 269,
     readln_ = 270,
     real_ = 271,
     repeat_ = 272,
     then_ = 273,
     until_ = 274,
     var_ = 275,
     while_ = 276,
     writeln_ = 277,
     ponto_virgula = 278,
     virgula = 279,
     atribuicao = 280,
     doispontos = 281,
     ponto = 282,
     abre_par = 283,
     fecha_par = 284,
     operador_mat_soma = 285,
     operador_mat_sub = 286,
     operador_mat_mult = 287,
     operador_mat_div = 288,
     operador_comp_igual = 289,
     operador_comp_maiorigual = 290,
     operador_comp_maior = 291,
     operador_comp_diff = 292,
     operador_comp_menorigual = 293,
     operador_comp_menor = 294,
     invalido = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union 
/* Line 293 of yacc.c  */
#line 272 "lalg.y"
YYSTYPE
{

/* Line 293 of yacc.c  */
#line 272 "lalg.y"

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



/* Line 293 of yacc.c  */
#line 438 "lalg.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 450 "lalg.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  221

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    11,    12,    19,    20,    27,    28,
      35,    36,    43,    44,    50,    51,    52,    59,    60,    66,
      70,    71,    78,    79,    87,    88,    96,    97,    98,   106,
     107,   115,   116,   124,   125,   133,   135,   137,   139,   142,
     143,   146,   147,   148,   149,   158,   159,   163,   164,   170,
     171,   178,   179,   182,   188,   190,   191,   195,   196,   200,
     201,   204,   205,   206,   210,   211,   215,   216,   221,   226,
     231,   232,   238,   239,   245,   246,   253,   257,   258,   262,
     263,   267,   268,   275,   276,   277,   284,   288,   289,   294,
     295,   300,   304,   306,   308,   310,   312,   314,   316,   318,
     320,   323,   324,   326,   328,   329,   333,   335,   337,   338,
     343,   344,   345,   350,   352,   354,   356,   358,   362,   364,
     366
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    14,     3,    43,    23,    48,    27,
      -1,    -1,     1,     3,    23,    44,    48,    27,    -1,    -1,
       1,     3,     1,    45,    48,    27,    -1,    -1,    14,     3,
       1,    46,    48,    27,    -1,    -1,    14,     3,    47,    23,
      48,     1,    -1,    -1,    53,    49,     6,    81,    10,    -1,
      -1,    -1,    53,    50,     1,    51,    81,    10,    -1,    -1,
      53,    52,     6,    81,     1,    -1,    54,    57,    65,    -1,
      -1,     7,     3,    34,   107,    23,    54,    -1,    -1,     7,
       3,     1,    55,   107,    23,    54,    -1,    -1,     7,     3,
      34,   107,     1,    56,    54,    -1,    -1,    -1,    20,    63,
      26,    62,    23,    58,    57,    -1,    -1,    20,     1,    59,
      26,    62,    23,    57,    -1,    -1,    20,    63,     1,    60,
      62,    23,    57,    -1,    -1,    20,    63,    26,    62,     1,
      61,    57,    -1,    16,    -1,    12,    -1,     1,    -1,     3,
      64,    -1,    -1,    24,    63,    -1,    -1,    -1,    -1,    13,
       3,    66,    68,    23,    73,    67,    65,    -1,    -1,    28,
      69,    29,    -1,    -1,    63,    26,    62,    70,    72,    -1,
      -1,    63,     1,    62,    71,    62,    72,    -1,    -1,    23,
      69,    -1,    74,     6,    81,    10,    23,    -1,    57,    -1,
      -1,    28,    76,    29,    -1,    -1,     3,    77,    78,    -1,
      -1,    23,    76,    -1,    -1,    -1,     9,    80,    83,    -1,
      -1,    83,    23,    81,    -1,    -1,     1,    23,    82,    81,
      -1,    15,    28,    63,    29,    -1,    22,    28,    63,    29,
      -1,    -1,    17,    84,    81,    19,    95,    -1,    -1,    17,
      85,    81,     1,    95,    -1,    -1,    11,    95,    18,    86,
      83,    79,    -1,     3,    25,    97,    -1,    -1,     3,    87,
      75,    -1,    -1,    21,    88,    92,    -1,    -1,    11,    95,
       1,    89,    83,    79,    -1,    -1,    -1,    21,    90,    95,
       1,    91,    83,    -1,     6,    81,    10,    -1,    -1,    95,
       8,    93,    83,    -1,    -1,    95,     1,    94,    83,    -1,
      97,    96,    97,    -1,     1,    -1,    34,    -1,    35,    -1,
      36,    -1,    37,    -1,    38,    -1,    39,    -1,     1,    -1,
     101,    99,    -1,    -1,    30,    -1,    31,    -1,    -1,   100,
     101,    99,    -1,    30,    -1,    31,    -1,    -1,    98,   106,
     102,   103,    -1,    -1,    -1,   105,   106,   104,   103,    -1,
      32,    -1,    33,    -1,     3,    -1,   107,    -1,    28,    97,
      29,    -1,     4,    -1,     5,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   348,   348,   348,   349,   349,   350,   350,   351,   351,
     352,   352,   354,   354,   355,   355,   355,   356,   356,   358,
     360,   360,   379,   379,   380,   380,   382,   382,   382,   421,
     421,   422,   422,   423,   423,   425,   425,   426,   428,   430,
     430,   432,   432,   440,   432,   443,   443,   445,   445,   473,
     473,   475,   475,   477,   479,   481,   481,   483,   483,   485,
     485,   487,   490,   490,   492,   492,   492,   492,   494,   552,
     598,   598,   602,   602,   604,   604,   605,   621,   621,   669,
     669,   670,   670,   671,   671,   671,   672,   674,   674,   682,
     682,   684,   691,   693,   694,   695,   696,   697,   698,   699,
     701,   718,   718,   719,   721,   721,   737,   738,   740,   740,
     764,   764,   764,   789,   790,   792,   801,   804,   806,   806,
     806
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "id", "num_integer", "num_real",
  "begin_", "const_", "do_", "else_", "end_", "if_", "integer_",
  "procedure_", "program_", "readln_", "real_", "repeat_", "then_",
  "until_", "var_", "while_", "writeln_", "ponto_virgula", "virgula",
  "atribuicao", "doispontos", "ponto", "abre_par", "fecha_par",
  "operador_mat_soma", "operador_mat_sub", "operador_mat_mult",
  "operador_mat_div", "operador_comp_igual", "operador_comp_maiorigual",
  "operador_comp_maior", "operador_comp_diff", "operador_comp_menorigual",
  "operador_comp_menor", "invalido", "$accept", "programa", "$@1", "$@2",
  "$@3", "$@4", "$@5", "corpo", "$@6", "$@7", "$@8", "$@9", "dc", "dc_c",
  "$@10", "$@11", "dc_v", "$@12", "$@13", "$@14", "$@15", "tipo_var",
  "variaveis", "mais_var", "dc_p", "$@16", "$@17", "parametros",
  "lista_par", "$@18", "$@19", "mais_par", "corpo_p", "dc_loc",
  "lista_arg", "argumentos", "$@20", "mais_ident", "pfalse", "$@21",
  "comandos", "$@22", "cmd", "$@23", "$@24", "$@25", "$@26", "$@27",
  "$@28", "$@29", "$@30", "cont_while", "$@31", "$@32", "condicao",
  "relacao", "expressao", "op_un", "outros_termos", "op_ad", "termo",
  "$@33", "mais_fatores", "$@34", "op_mult", "fator", "numero", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    42,    44,    42,    45,    42,    46,    42,
      47,    42,    49,    48,    50,    51,    48,    52,    48,    53,
      54,    54,    55,    54,    56,    54,    57,    58,    57,    59,
      57,    60,    57,    61,    57,    62,    62,    62,    63,    64,
      64,    65,    66,    67,    65,    68,    68,    70,    69,    71,
      69,    72,    72,    73,    74,    75,    75,    77,    76,    78,
      78,    79,    80,    79,    81,    81,    82,    81,    83,    83,
      84,    83,    85,    83,    86,    83,    83,    87,    83,    88,
      83,    89,    83,    90,    91,    83,    83,    93,    92,    94,
      92,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      97,    98,    98,    98,    99,    99,   100,   100,   102,   101,
     103,   104,   103,   105,   105,   106,   106,   106,   107,   107,
     107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     5,     0,     0,     6,     0,     5,     3,
       0,     6,     0,     7,     0,     7,     0,     0,     7,     0,
       7,     0,     7,     0,     7,     1,     1,     1,     2,     0,
       2,     0,     0,     0,     8,     0,     3,     0,     5,     0,
       6,     0,     2,     5,     1,     0,     3,     0,     3,     0,
       2,     0,     0,     3,     0,     3,     0,     4,     4,     4,
       0,     5,     0,     5,     0,     6,     3,     0,     3,     0,
       3,     0,     6,     0,     0,     6,     3,     0,     4,     0,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     1,     1,     0,     3,     1,     1,     0,     4,
       0,     0,     4,     1,     1,     1,     1,     3,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     6,     4,     8,
       0,     0,    20,    20,    20,    20,    20,     0,     0,    12,
      26,     0,     0,     0,     0,     0,     7,     0,     0,     0,
       0,    41,     5,     9,     3,    11,    22,     0,     0,    15,
       0,    29,    39,     0,     0,    19,     0,   120,   118,   119,
       0,     0,    77,     0,     0,     0,    70,    79,     0,     0,
       0,     0,     0,     0,     0,    38,    31,     0,    42,     0,
      24,    20,    66,   101,    55,     0,    92,   102,   103,     0,
       0,     0,   104,     0,     0,     0,     0,     0,     0,    13,
       0,     0,    18,     0,    40,     0,    37,    36,    35,     0,
      45,    20,    20,    21,     0,    76,     0,    78,    86,    81,
      74,    99,    93,    94,    95,    96,    97,    98,   101,   115,
     101,   108,   116,   106,   107,   100,   101,     0,     0,     0,
      80,     0,     0,     0,    65,    16,     0,     0,    33,    27,
       0,     0,    23,    25,    67,    57,     0,     0,     0,    91,
       0,   110,   104,    68,     0,     0,    89,    87,    84,    69,
      26,    26,    26,    26,     0,     0,    26,    59,    56,    61,
      61,   117,   113,   114,   109,     0,   105,    71,    73,     0,
       0,     0,    30,    32,    34,    28,     0,     0,    46,    54,
      43,     0,     0,    58,    62,    82,    75,   111,    90,    88,
      85,    49,    47,    41,     0,    60,     0,   110,     0,    51,
      44,     0,    63,   112,    51,     0,    48,     0,    50,    52,
      53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    10,    13,    12,    14,    11,    18,    27,    28,
      61,    29,    19,    20,    46,   102,    31,   163,    63,    95,
     162,    99,   164,    65,    45,   100,   203,   141,   165,   209,
     208,   216,   190,   191,   107,   146,   167,   193,   195,   206,
      59,   104,    60,    84,    85,   148,    74,    86,   147,    87,
     181,   130,   180,   179,    79,   118,    80,    81,   125,   126,
      82,   151,   174,   207,   175,   121,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -142
static const yytype_int16 yypact[] =
{
      13,    29,    80,    17,    14,    30,  -142,  -142,  -142,  -142,
      67,    70,    90,    90,    90,    90,    90,   104,    91,   120,
     103,    97,   100,   113,   124,     7,  -142,   136,   145,   142,
      15,   138,  -142,  -142,  -142,  -142,  -142,    84,    98,  -142,
     128,  -142,   129,     9,   151,  -142,    84,  -142,  -142,  -142,
      56,   132,   134,    98,    21,   133,  -142,  -142,   137,   147,
     143,    98,   159,   144,   164,  -142,  -142,    18,  -142,   146,
    -142,    90,  -142,    16,   140,   161,  -142,  -142,  -142,    10,
      32,    58,    75,   164,   111,   128,    21,    21,   164,  -142,
      81,   162,  -142,    18,  -142,    18,  -142,  -142,  -142,    57,
     148,    90,    90,  -142,    81,  -142,   170,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,    16,  -142,
      16,  -142,  -142,  -142,  -142,  -142,    16,   149,   155,   174,
    -142,    73,   176,   150,  -142,  -142,   157,   158,  -142,  -142,
     164,   160,  -142,  -142,  -142,  -142,   153,   141,   141,  -142,
     156,    78,    75,  -142,    21,    21,  -142,  -142,  -142,  -142,
     103,   103,   103,   103,    22,   163,   103,   165,  -142,   175,
     175,  -142,  -142,  -142,  -142,    58,  -142,  -142,  -142,   141,
     141,   141,  -142,  -142,  -142,  -142,    18,    18,  -142,  -142,
    -142,   180,   170,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,   138,    98,  -142,   141,    78,    18,   166,
    -142,   177,  -142,  -142,   166,   164,  -142,   167,  -142,  -142,
    -142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,  -142,  -142,  -142,  -142,    62,  -142,  -142,
    -142,  -142,  -142,   -59,  -142,  -142,   -25,  -142,  -142,  -142,
    -142,   -92,   -28,  -142,   -12,  -142,  -142,  -142,   -22,  -142,
    -142,   -20,  -142,  -142,  -142,     3,  -142,  -142,    26,  -142,
     -40,  -142,  -141,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,   -82,  -142,   -64,  -142,    45,  -142,
      72,  -142,    -8,  -142,  -142,    25,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
      62,   136,    43,   137,   131,   132,   169,   170,    36,   105,
      66,   109,   103,    75,     1,     7,    41,     6,    42,    96,
      50,    91,    76,   186,  -101,  -101,  -101,     2,   110,    69,
      97,     9,     4,   111,    98,    67,    94,     8,   198,   199,
     200,    37,   142,   143,   128,   129,    77,    78,   187,  -101,
     134,    77,    78,    -2,   149,   127,   150,    70,   138,    47,
     133,   119,    48,    49,   144,   212,   112,   113,   114,   115,
     116,   117,   177,   178,   156,    21,    22,    23,    24,    71,
     139,   157,    51,     5,    52,    47,   120,    53,    48,    49,
      15,   -64,    54,    16,   201,   202,    55,    17,    56,    51,
     -64,    52,    57,    58,    53,   123,   124,    25,   -64,    54,
     172,   173,    51,    55,    52,    56,   214,    53,    26,    57,
      58,   -14,    54,    30,    32,    35,    55,    33,    56,    51,
     -64,    52,    57,    58,    53,   182,   183,   184,   185,    54,
      34,   189,    38,    55,    52,    56,    39,    53,    40,    57,
      58,    44,    54,    64,    68,    72,    55,    89,    56,    73,
      92,    83,    57,    58,   211,    88,    90,    42,   106,   101,
      93,   108,   135,   145,   154,   155,   140,   158,   153,   159,
     160,   161,   168,   166,   194,   171,   204,   217,   192,   215,
     220,   210,   188,   219,   218,   205,   196,   176,   152,   213,
     197
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-142))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      40,    93,    30,    95,    86,    87,   147,   148,     1,    73,
       1,     1,    71,    53,     1,     1,     1,     0,     3,     1,
      37,    61,     1,     1,     3,     4,     5,    14,    18,    46,
      12,     1,     3,     1,    16,    26,    64,    23,   179,   180,
     181,    34,   101,   102,    84,    85,    30,    31,    26,    28,
      90,    30,    31,    23,   118,    83,   120,     1,     1,     1,
      88,     3,     4,     5,   104,   206,    34,    35,    36,    37,
      38,    39,   154,   155,     1,    13,    14,    15,    16,    23,
      23,     8,     1,     3,     3,     1,    28,     6,     4,     5,
      23,    10,    11,    23,   186,   187,    15,     7,    17,     1,
      19,     3,    21,    22,     6,    30,    31,     3,    10,    11,
      32,    33,     1,    15,     3,    17,   208,     6,    27,    21,
      22,     1,    11,    20,    27,     1,    15,    27,    17,     1,
      19,     3,    21,    22,     6,   160,   161,   162,   163,    11,
      27,   166,     6,    15,     3,    17,     1,     6,     6,    21,
      22,    13,    11,    24,     3,    23,    15,    10,    17,    25,
       1,    28,    21,    22,   204,    28,    23,     3,    28,    23,
      26,    10,    10,     3,    19,     1,    28,     1,    29,    29,
      23,    23,    29,    23,     9,    29,     6,    10,    23,    23,
      23,   203,    29,   215,   214,   192,   170,   152,   126,   207,
     175
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    14,    42,     3,     3,     0,     1,    23,     1,
      43,    47,    45,    44,    46,    23,    23,     7,    48,    53,
      54,    48,    48,    48,    48,     3,    27,    49,    50,    52,
      20,    57,    27,    27,    27,     1,     1,    34,     6,     1,
       6,     1,     3,    63,    13,    65,    55,     1,     4,     5,
     107,     1,     3,     6,    11,    15,    17,    21,    22,    81,
      83,    51,    81,    59,    24,    64,     1,    26,     3,   107,
       1,    23,    23,    25,    87,    81,     1,    30,    31,    95,
      97,    98,   101,    28,    84,    85,    88,    90,    28,    10,
      23,    81,     1,    26,    63,    60,     1,    12,    16,    62,
      66,    23,    56,    54,    82,    97,    28,    75,    10,     1,
      18,     1,    34,    35,    36,    37,    38,    39,    96,     3,
      28,   106,   107,    30,    31,    99,   100,    63,    81,    81,
      92,    95,    95,    63,    81,    10,    62,    62,     1,    23,
      28,    68,    54,    54,    81,     3,    76,    89,    86,    97,
      97,   102,   101,    29,    19,     1,     1,     8,     1,    29,
      23,    23,    61,    58,    63,    69,    23,    77,    29,    83,
      83,    29,    32,    33,   103,   105,    99,    95,    95,    94,
      93,    91,    57,    57,    57,    57,     1,    26,    29,    57,
      73,    74,    23,    78,     9,    79,    79,   106,    83,    83,
      83,    62,    62,    67,     6,    76,    80,   104,    71,    70,
      65,    81,    83,   103,    62,    23,    72,    10,    72,    69,
      23
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 348 "lalg.y"
    { insereProgram ((yyvsp[(2) - (2)].name)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 349 "lalg.y"
    { yyerror("Expected: program"); yyclearin; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 350 "lalg.y"
    { yyerror("Expected: program"); yyclearin; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 351 "lalg.y"
    { yyerror("Expected: ';' before begin or declaration of variables and constants"); yyclearin; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 352 "lalg.y"
    { insereProgram ((yyvsp[(2) - (2)].name)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 352 "lalg.y"
    { yyerror("Expected: '.'"); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 354 "lalg.y"
    {escreveProcedimentos(prox_linha_vet);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 355 "lalg.y"
    {escreveProcedimentos(prox_linha_vet);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 355 "lalg.y"
    { yyerror("Expected: begin or declaration of variables and constants");yyclearin; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 356 "lalg.y"
    {escreveProcedimentos(prox_linha_vet);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 356 "lalg.y"
    { yyerror("Expected: end"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 360 "lalg.y"
    { int retorno;
																	if((yyvsp[(4) - (6)].symbol).type==INTEGER)
																	{ 
																		retorno = insereConstInt ((yyvsp[(2) - (6)].name), (yyvsp[(4) - (6)].symbol).i_value, contexto);
																		if(retorno==REDECLARACAO)
																			yyerror("Redeclaration of constants");
																		else if(retorno ==CONFLITO)
																			yyerror("Conflicting types");
																	} 
																	else if((yyvsp[(4) - (6)].symbol).type==REAL) 
																	{ 
																		retorno = insereConstReal ((yyvsp[(2) - (6)].name), (yyvsp[(4) - (6)].symbol).f_value, contexto);
																		if(retorno==REDECLARACAO) 
																			yyerror("Redeclaration of constants");
																		else if(retorno ==CONFLITO)
																			yyerror("Conflicting types");
																	} 	
																}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 379 "lalg.y"
    { yyerror("Expected: '='"); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 380 "lalg.y"
    { yyerror("Expected: ';'"); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 382 "lalg.y"
    {		int retorno;
																str=malloc(400 * sizeof(char));
																str=strtok(listavar,",");
																while(str!=NULL){
																	cpystr=malloc(400 * sizeof(char));
																	strcpy(cpystr,str);
																	if((yyvsp[(4) - (5)].i_number)==INTEGER)
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
																	} else if((yyvsp[(4) - (5)].i_number)==REAL) 
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
																
														   }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 421 "lalg.y"
    { yyerror("Expected an identifier"); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 422 "lalg.y"
    { yyerror("Expected: ':'");yyclearin; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 423 "lalg.y"
    { yyerror("Expected: ';'");yyclearin; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 425 "lalg.y"
    { (yyval.i_number) = REAL; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 425 "lalg.y"
    { (yyval.i_number) = INTEGER; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 426 "lalg.y"
    { yyerror("Incorrect type: Expected integer or real"); yyclearin; }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 428 "lalg.y"
    { strcatinv(listavar,(yyvsp[(1) - (2)].name)); strcatinv(listavar,","); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 432 "lalg.y"
    { ++num_procedimento; insereVetor("DSVI",prox_linha_vet); atualizaPosicaoProcedure((yyvsp[(2) - (2)].name),prox_linha_vet); contexto=1; if(insereProcedure ((yyvsp[(2) - (2)].name),contexto,prox_linha_vet)!=OK) 
										{
											yyerror("Redefinition of procedure"); 
										}
									 else
									{
										strcpy(lastprocedure,(yyvsp[(2) - (2)].name));
									}
						}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 440 "lalg.y"
    { contexto=0;removeLocalVars((yyvsp[(2) - (6)].name));lastprocedure[0]='\0';	insereVetor("RTPR",prox_linha_vet);
														   }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 445 "lalg.y"
    {	
												str=malloc(400 * sizeof(char));
												str=strtok(listavar,",");
												int ordem=1;
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													if((yyvsp[(3) - (3)].i_number)==INTEGER){
														ret=insereParamInt (cpystr, contexto, lastprocedure, ordem);
														insereVetor("COPVL",prox_linha_vet);
													} else if((yyvsp[(3) - (3)].i_number)==REAL) { 
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
												
										   }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 473 "lalg.y"
    { yyerror("Expected: ':'"); yyclearin; }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 483 "lalg.y"
    { strcatinv(listavar,(yyvsp[(1) - (1)].name)); strcatinv(listavar,","); contparametros++; }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 487 "lalg.y"
    { 
		sprintf(comando,"DSVF %d",prox_linha_vet+2);
		insereVetor(comando,retorno_if);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 490 "lalg.y"
    { sprintf(comando,"DSVF %d",prox_linha_vet+2); insereVetor(comando,retorno_if); retorno_if = prox_linha_vet; }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 490 "lalg.y"
    { sprintf(comando,"DSVF %d",prox_linha_vet+2); insereVetor(comando,retorno_if+2);}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 492 "lalg.y"
    { yyerror("Command not recognized"); yyclearin; }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 494 "lalg.y"
    {
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
										 }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 552 "lalg.y"
    {
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
										 }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 598 "lalg.y"
    { comeco_repeat[i_repeat++] = prox_linha_vet; }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 598 "lalg.y"
    {
										sprintf(comando,"DSVF %d",comeco_repeat[--i_repeat]);
										insereVetor(comando,prox_linha_vet);
										}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 602 "lalg.y"
    { comeco_repeat[i_repeat++] = prox_linha_vet; }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 602 "lalg.y"
    { yyerror("Expected: 'until'"); yyclearin; }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 604 "lalg.y"
    { retorno_if = prox_linha_vet; }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 605 "lalg.y"
    { 
								if(busca((yyvsp[(1) - (3)].name),ATTR,contexto)==CONST_FALSE){
									sprintf(msg, "Identifier %s declared as a constant", (yyvsp[(1) - (3)].name));
									yyerror(msg);
								}
								if(busca((yyvsp[(1) - (3)].name),ATTR,contexto)==NAO_EXISTE){
									sprintf(msg, "Identifier %s not previously declared", (yyvsp[(1) - (3)].name));
									yyerror(msg);
								}
/* 								printf("Var: %d Recebe: %d\n ", busca($1,ATTR,contexto),$3.type);  */
								if(busca((yyvsp[(1) - (3)].name),ATTR,contexto)==INTEGER && ((yyvsp[(3) - (3)].symbol).type==REAL || (yyvsp[(3) - (3)].symbol).type==VAR_REAL)){
									sprintf(msg, "Conflicting types,try to assign a REAL to INTEGER %s", (yyvsp[(1) - (3)].name));
									yyerror(msg);
								}
								armazenaSimbolo((yyvsp[(1) - (3)].name),contexto,lastprocedure);
							  }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 621 "lalg.y"
    { contparametros=0; }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 622 "lalg.y"
    {   
					ret=busca((yyvsp[(1) - (3)].name),PROCEDURE,contexto);//retorna o numero de parametros se declarado
					if(ret==NAO_EXISTE){
						sprintf(msg, "Procedure %s not previously declared", (yyvsp[(1) - (3)].name));
						yyerror(msg);
					}else{
						str=malloc(400 * sizeof(char));
						str=strtok(listavar,",");
						if(ret>contparametros){
							sprintf(msg, "Too few arguments to procedure %s", (yyvsp[(1) - (3)].name));
							yyerror(msg);
						}else if(ret<contparametros){
							sprintf(msg, "Too many arguments to procedure %s", (yyvsp[(1) - (3)].name));
							yyerror(msg);
						}else{
							int retvar,retparam,argpos=1;
							posicaoPusher = prox_linha_vet;
							insereVetor("PUSHER",prox_linha_vet);
							while(str!=NULL){
								int endereco = buscaEndRelativoVar(str, contexto, (yyvsp[(1) - (3)].name));
								sprintf(comando,"PARAM %d",endereco);
								insereVetor(comando,prox_linha_vet);
								cpystr=malloc(400 * sizeof(char));
								strcpy(cpystr,str);
								retvar=busca(str,ATTR,contexto);
								if(retvar==NAO_EXISTE){
									sprintf(msg, "Identifier %s not previously declared", (yyvsp[(1) - (3)].name));
									yyerror(msg);
								}
								endereco = getPosicaoProcedure((yyvsp[(1) - (3)].name));
								sprintf(comando,"CHPR %d",(endereco));
								insereVetor(comando,prox_linha_vet);
								sprintf(comando,"PUSHER %d",prox_linha_vet);
								strcpy(code_vet[posicaoPusher],comando);

								retparam=buscaTipoParam((yyvsp[(1) - (3)].name),argpos);
								if(retvar==REAL && retparam==INTEGER){
									sprintf(msg, "Conflicting types,try to assign a REAL to expected INTEGER parameter %d in procedure %s", argpos, (yyvsp[(1) - (3)].name));
									yyerror(msg);
								}
								argpos++;
								str=strtok(NULL,",");
							}
						}
						listavar[0]='\0';
					}
				 }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 669 "lalg.y"
    {comeco_while[i_com_while++] = prox_linha_vet;}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 670 "lalg.y"
    { yyerror("Expected: 'then'"); yyclearin; }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 671 "lalg.y"
    {comeco_while[i_com_while] = prox_linha_vet;}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 671 "lalg.y"
    { yyerror("Expected: 'do'"); yyclearin; }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 674 "lalg.y"
    {retorno_while[i_ret_while++] = prox_linha_vet;}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 675 "lalg.y"
    {
						sprintf(comando,"DSVF %d",prox_linha_vet+3+i_ret_while);
						insereVetor(comando,retorno_while[--i_ret_while]);
						
						sprintf(comando,"DSVI %d",comeco_while[--i_com_while]+2+i_com_while);
						insereVetor(comando,prox_linha_vet);/*Escreve na linha atual o retorno do while*/
					}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 682 "lalg.y"
    { yyerror("Expected: 'do'"); yyclearin; }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 684 "lalg.y"
    {
											if((yyvsp[(2) - (3)].i_number)==CPIG) insereVetor("CPIG",prox_linha_vet);
											if((yyvsp[(2) - (3)].i_number)==CMAI) insereVetor("CMAI",prox_linha_vet);
											if((yyvsp[(2) - (3)].i_number)==CPMA) insereVetor("CPMA",prox_linha_vet);
											if((yyvsp[(2) - (3)].i_number)==CDES) insereVetor("CDES",prox_linha_vet);
											if((yyvsp[(2) - (3)].i_number)==CPMI) insereVetor("CPMI",prox_linha_vet);
											if((yyvsp[(2) - (3)].i_number)==CPME) insereVetor("CPME",prox_linha_vet);
									   }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 691 "lalg.y"
    {yyclearin;}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 693 "lalg.y"
    { (yyval.i_number)=CPIG; }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 694 "lalg.y"
    { (yyval.i_number)=CMAI; }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 695 "lalg.y"
    { (yyval.i_number)=CPMA; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 696 "lalg.y"
    { (yyval.i_number)=CDES; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 697 "lalg.y"
    { (yyval.i_number)=CPMI; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 698 "lalg.y"
    { (yyval.i_number)=CPME; }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 699 "lalg.y"
    { yyerror("Expected any operator: '=', '>', '<', '>=', '<=', '<>' "); yyclearin; }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 701 "lalg.y"
    { 
								if((yyvsp[(2) - (2)].symbol).type==TNULL){
									(yyval.symbol).type = (yyvsp[(1) - (2)].symbol).type; 
									if((yyvsp[(1) - (2)].symbol).type==INTEGER) { (yyval.symbol).i_value=(yyvsp[(1) - (2)].symbol).i_value;  }
									if((yyvsp[(1) - (2)].symbol).type==REAL) { (yyval.symbol).f_value=(yyvsp[(1) - (2)].symbol).f_value;  }
									if((yyvsp[(1) - (2)].symbol).type==VAR_INT || (yyvsp[(1) - (2)].symbol).type==VAR_REAL) { (yyval.symbol).name=(yyvsp[(1) - (2)].symbol).name;  };  
									
								}else{
									(yyval.symbol).type=TNULL;
									if((yyvsp[(2) - (2)].symbol).type==REAL || (yyvsp[(1) - (2)].symbol).type==REAL){
										(yyval.symbol).type=REAL;
									} else if ((yyvsp[(2) - (2)].symbol).type==INTEGER && (yyvsp[(1) - (2)].symbol).type==INTEGER){
										(yyval.symbol).type=INTEGER;
									} 
								}
							}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 718 "lalg.y"
    { (yyval.math_op)='0'; }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 718 "lalg.y"
    { (yyval.math_op)='+'; }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 719 "lalg.y"
    { (yyval.math_op)='-'; }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 721 "lalg.y"
    { (yyval.symbol).type=TNULL; }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 721 "lalg.y"
    { 
								      if((yyvsp[(3) - (3)].symbol).type==TNULL){
									      (yyval.symbol).type = (yyvsp[(2) - (3)].symbol).type; 
								      }else{
									      if((yyvsp[(2) - (3)].symbol).type==REAL || (yyvsp[(3) - (3)].symbol).type==REAL || (yyvsp[(2) - (3)].symbol).type==VAR_REAL || (yyvsp[(2) - (3)].symbol).type==CONST_REAL || (yyvsp[(3) - (3)].symbol).type==VAR_REAL || (yyvsp[(3) - (3)].symbol).type==CONST_REAL){
										      (yyval.symbol).type=REAL;
									      } else {
										      (yyval.symbol).type=INTEGER;
									      }
									      
								      }
								      if((yyvsp[(1) - (3)].math_op)=='+') insereVetor("SOMA",prox_linha_vet);
								      if((yyvsp[(1) - (3)].math_op)=='-') insereVetor("SUBT",prox_linha_vet);
								      (yyval.symbol).math_op=(yyvsp[(1) - (3)].math_op);
								}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 737 "lalg.y"
    { (yyval.math_op)='+'; }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 738 "lalg.y"
    { (yyval.math_op)='-'; }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 740 "lalg.y"
    { 
		      if((yyvsp[(2) - (2)].symbol).type==INTEGER)
		      {
			      sprintf(comando,"CRCT %d",(yyvsp[(2) - (2)].symbol).i_value );
			      insereVetor(comando,prox_linha_vet);
		      }
		      if((yyvsp[(2) - (2)].symbol).type==REAL)
		      {
			      sprintf(comando,"CRCT %f",(yyvsp[(2) - (2)].symbol).f_value);
			      insereVetor(comando,prox_linha_vet);
		      }
		      if(isVarOrConst((yyvsp[(2) - (2)].symbol).type)) carregaSimbolo((yyvsp[(2) - (2)].symbol).name,contexto,lastprocedure);
		    }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 752 "lalg.y"
    { 
				    if((yyvsp[(4) - (4)].symbol).type==TNULL){
					    (yyval.symbol).type = (yyvsp[(2) - (4)].symbol).type;
				    }
				    if((yyvsp[(4) - (4)].symbol).type!=TNULL){
					    if((yyvsp[(4) - (4)].symbol).math_op=='/' && ((yyvsp[(4) - (4)].symbol).type==REAL || (yyvsp[(2) - (4)].symbol).type==REAL)){
						    yyerror("Division only avaiable between integers");
					    }
					    (yyval.symbol).type=(yyvsp[(2) - (4)].symbol).type;
				    }
		    }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 764 "lalg.y"
    { (yyval.symbol).type=TNULL; }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 764 "lalg.y"
    { 
						      if((yyvsp[(2) - (2)].symbol).type==INTEGER)
						      {
							      sprintf(comando,"CRCT %d",(yyvsp[(2) - (2)].symbol).i_value );
							      insereVetor(comando,prox_linha_vet);
						      }
						      if((yyvsp[(2) - (2)].symbol).type==REAL)
						      {
							      sprintf(comando,"CRCT %f",(yyvsp[(2) - (2)].symbol).f_value);
							      insereVetor(comando,prox_linha_vet);
						      } 
						      if(isVarOrConst((yyvsp[(2) - (2)].symbol).type)) carregaSimbolo((yyvsp[(2) - (2)].symbol).name,contexto,lastprocedure);
						    }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 776 "lalg.y"
    { 
									(yyval.symbol).type=(yyvsp[(2) - (4)].symbol).type;
									if((yyvsp[(4) - (4)].symbol).type!=TNULL){
										(yyval.symbol).type=(yyvsp[(4) - (4)].symbol).type;
									} 
									if((yyvsp[(2) - (4)].symbol).type==REAL || (yyvsp[(2) - (4)].symbol).type==INTEGER){
										(yyval.symbol).type=(yyvsp[(2) - (4)].symbol).type;
									}
									(yyval.symbol).math_op=(yyvsp[(1) - (4)].math_op);
									if((yyvsp[(1) - (4)].math_op)=='*') insereVetor("MULT",prox_linha_vet);
								        if((yyvsp[(1) - (4)].math_op)=='/') insereVetor("DIVI",prox_linha_vet);
						   }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 789 "lalg.y"
    { (yyval.math_op)='*'; }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 790 "lalg.y"
    { (yyval.math_op)='/'; }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 792 "lalg.y"
    { 
			ret=busca((yyvsp[(1) - (1)].name),EXPRESSAO,contexto);
			if(ret==NAO_EXISTE){
				sprintf(msg, "Identifier %s not previously declared", (yyvsp[(1) - (1)].name));
				yyerror(msg);
			}else{
				(yyval.symbol).name=(yyvsp[(1) - (1)].name); 
				(yyval.symbol).type=buscaTipoVarCons((yyvsp[(1) - (1)].name),contexto, lastprocedure);
			}
		  }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 801 "lalg.y"
    { (yyval.symbol).type = (yyvsp[(1) - (1)].symbol).type; 
						if((yyvsp[(1) - (1)].symbol).type==INTEGER) (yyval.symbol).i_value=(yyvsp[(1) - (1)].symbol).i_value; 
						if((yyvsp[(1) - (1)].symbol).type==REAL) (yyval.symbol).f_value=(yyvsp[(1) - (1)].symbol).f_value;  
					  }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 806 "lalg.y"
    { (yyval.symbol).type = INTEGER; (yyval.symbol).i_value = (yyvsp[(1) - (1)].i_number); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 806 "lalg.y"
    { (yyval.symbol).type = REAL; (yyval.symbol).f_value = (yyvsp[(1) - (1)].r_number); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 806 "lalg.y"
    { yyerror("Expected a number"); yyclearin; }
    break;



/* Line 1806 of yacc.c  */
#line 2782 "lalg.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 808 "lalg.y"

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

