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


	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	int yylex (void);
	void yyerror (char *);
	int numerrors=0;
	int contexto=0;
	int ret, contparametros;
	extern int num_lines;
	char listavar[400];
	char *str;
	char *cpystr;
	char *lastprocedure;
	char msg[300];

	


/* Line 268 of yacc.c  */
#line 132 "lalg.tab.c"

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
#line 62 "lalg.y"
YYSTYPE
{

/* Line 293 of yacc.c  */
#line 62 "lalg.y"

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
#line 228 "lalg.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 240 "lalg.tab.c"

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
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  201

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
      35,    36,    43,    48,    49,    55,    60,    64,    65,    72,
      73,    81,    82,    90,    91,    92,   100,   101,   109,   110,
     118,   119,   127,   129,   131,   133,   136,   137,   140,   141,
     142,   143,   152,   153,   157,   158,   164,   165,   172,   173,
     176,   182,   184,   185,   189,   190,   194,   195,   198,   199,
     202,   203,   207,   208,   213,   218,   223,   228,   233,   239,
     243,   244,   248,   253,   254,   261,   262,   268,   272,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   295,   296,
     298,   300,   301,   305,   307,   309,   313,   314,   318,   320,
     322,   324,   326,   330,   332,   334
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    14,     3,    43,    23,    48,    27,
      -1,    -1,     1,     3,    23,    44,    48,    27,    -1,    -1,
       1,     3,     1,    45,    48,    27,    -1,    -1,    14,     3,
       1,    46,    48,    27,    -1,    -1,    14,     3,    47,    23,
      48,     1,    -1,    50,     6,    77,    10,    -1,    -1,    50,
       1,    49,    77,    10,    -1,    50,     6,    77,     1,    -1,
      51,    54,    62,    -1,    -1,     7,     3,    34,    93,    23,
      51,    -1,    -1,     7,     3,     1,    52,    93,    23,    51,
      -1,    -1,     7,     3,    34,    93,     1,    53,    51,    -1,
      -1,    -1,    20,    60,    26,    59,    23,    55,    54,    -1,
      -1,    20,     1,    56,    26,    59,    23,    54,    -1,    -1,
      20,    60,     1,    57,    59,    23,    54,    -1,    -1,    20,
      60,    26,    59,     1,    58,    54,    -1,    16,    -1,    12,
      -1,     1,    -1,     3,    61,    -1,    -1,    24,    60,    -1,
      -1,    -1,    -1,    13,     3,    63,    65,    23,    70,    64,
      62,    -1,    -1,    28,    66,    29,    -1,    -1,    60,    26,
      59,    67,    69,    -1,    -1,    60,     1,    59,    68,    59,
      69,    -1,    -1,    23,    66,    -1,    71,     6,    77,    10,
      23,    -1,    54,    -1,    -1,    28,    73,    29,    -1,    -1,
       3,    74,    75,    -1,    -1,    23,    73,    -1,    -1,     9,
      79,    -1,    -1,    79,    23,    77,    -1,    -1,     1,    23,
      78,    77,    -1,    15,    28,    60,    29,    -1,    22,    28,
      60,    29,    -1,    17,    77,    19,    83,    -1,    17,    77,
       1,    83,    -1,    11,    83,    18,    79,    76,    -1,     3,
      25,    85,    -1,    -1,     3,    80,    72,    -1,    21,    83,
       8,    79,    -1,    -1,    11,    83,     1,    81,    79,    76,
      -1,    -1,    21,    83,     1,    82,    79,    -1,     6,    77,
      10,    -1,    85,    84,    85,    -1,     1,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,
       1,    -1,    89,    87,    -1,    -1,    30,    -1,    31,    -1,
      -1,    88,    89,    87,    -1,    30,    -1,    31,    -1,    86,
      92,    90,    -1,    -1,    91,    92,    90,    -1,    32,    -1,
      33,    -1,     3,    -1,    93,    -1,    28,    85,    29,    -1,
       4,    -1,     5,    -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   135,   136,   136,   137,   137,   138,   138,
     139,   139,   141,   142,   142,   143,   145,   147,   147,   166,
     166,   167,   167,   169,   169,   169,   207,   207,   208,   208,
     209,   209,   211,   211,   212,   214,   216,   216,   218,   218,
     218,   218,   220,   220,   222,   222,   239,   239,   241,   241,
     243,   245,   247,   247,   249,   249,   251,   251,   253,   253,
     255,   255,   255,   255,   257,   310,   350,   351,   352,   353,
     368,   368,   404,   405,   405,   406,   406,   407,   411,   411,
     413,   414,   415,   416,   417,   418,   419,   421,   439,   439,
     440,   442,   442,   458,   459,   461,   476,   476,   483,   484,
     486,   494,   497,   499,   499,   499
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
  "$@3", "$@4", "$@5", "corpo", "$@6", "dc", "dc_c", "$@7", "$@8", "dc_v",
  "$@9", "$@10", "$@11", "$@12", "tipo_var", "variaveis", "mais_var",
  "dc_p", "$@13", "$@14", "parametros", "lista_par", "$@15", "$@16",
  "mais_par", "corpo_p", "dc_loc", "lista_arg", "argumentos", "$@17",
  "mais_ident", "pfalse", "comandos", "$@18", "cmd", "$@19", "$@20",
  "$@21", "condicao", "relacao", "expressao", "op_un", "outros_termos",
  "op_ad", "termo", "mais_fatores", "op_mult", "fator", "numero", 0
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
      47,    42,    48,    49,    48,    48,    50,    51,    51,    52,
      51,    53,    51,    54,    55,    54,    56,    54,    57,    54,
      58,    54,    59,    59,    59,    60,    61,    61,    62,    63,
      64,    62,    65,    65,    67,    66,    68,    66,    69,    69,
      70,    71,    72,    72,    74,    73,    75,    75,    76,    76,
      77,    77,    78,    77,    79,    79,    79,    79,    79,    79,
      80,    79,    79,    81,    79,    82,    79,    79,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    85,    86,    86,
      86,    87,    87,    88,    88,    89,    90,    90,    91,    91,
      92,    92,    92,    93,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     4,     0,     5,     4,     3,     0,     6,     0,
       7,     0,     7,     0,     0,     7,     0,     7,     0,     7,
       0,     7,     1,     1,     1,     2,     0,     2,     0,     0,
       0,     8,     0,     3,     0,     5,     0,     6,     0,     2,
       5,     1,     0,     3,     0,     3,     0,     2,     0,     2,
       0,     3,     0,     4,     4,     4,     4,     4,     5,     3,
       0,     3,     4,     0,     6,     0,     5,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     0,     3,     1,     1,     3,     0,     3,     1,     1,
       1,     1,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     6,     4,     8,
       0,     0,    17,    17,    17,    17,    17,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     7,    13,     0,     0,
      38,     5,     9,     3,    11,    19,     0,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    36,
       0,     0,    16,     0,   105,   103,   104,     0,     0,    62,
      88,    52,     0,    79,    89,    90,     0,     0,     0,    91,
       0,     0,     0,     0,    15,    12,     0,     0,     0,    35,
      28,     0,    39,     0,    21,    17,    14,     0,    69,     0,
      71,    77,    73,     0,    86,    80,    81,    82,    83,    84,
      85,    88,   100,    88,    96,   101,    93,    94,    87,    88,
       0,     0,     0,    75,     0,     0,    61,     0,    37,     0,
      34,    33,    32,     0,    42,    17,    17,    18,    63,    54,
       0,     0,    58,    78,     0,    98,    99,    95,     0,    91,
      64,    67,    66,     0,    72,    65,     0,     0,    30,    24,
       0,     0,    20,    22,    56,    53,    58,     0,    68,   102,
      96,    92,    76,    23,    23,    23,    23,     0,     0,    23,
       0,    55,    74,    59,    97,    27,    29,    31,    25,     0,
       0,    43,    51,    40,     0,    57,    46,    44,    38,     0,
       0,    48,    41,     0,    48,     0,    45,     0,    47,    49,
      50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    10,    13,    12,    14,    11,    18,    37,    19,
      20,    53,   126,    30,   166,    77,   119,   165,   123,   167,
      79,    52,   124,   188,   151,   168,   191,   190,   196,   183,
     184,    90,   130,   154,   171,   158,    46,    87,    47,    61,
     131,   143,    66,   101,    67,    68,   108,   109,    69,   137,
     138,   104,   105
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
      20,    28,    32,    47,    15,    21,  -116,  -116,  -116,  -116,
      -4,    44,    73,    73,    73,    73,    73,    79,    81,    88,
      76,    91,    94,    95,   100,     7,  -116,  -116,   109,    26,
      93,  -116,  -116,  -116,  -116,  -116,    87,   109,   104,   107,
     109,    69,   101,   122,    69,   106,    23,   112,  -116,   114,
      16,   137,  -116,    87,  -116,  -116,  -116,    25,   126,  -116,
      48,   123,   143,  -116,  -116,  -116,    19,    24,     8,    74,
     152,    13,    75,   152,  -116,  -116,    92,   131,   152,  -116,
    -116,    65,  -116,   135,  -116,    73,  -116,    92,  -116,   156,
    -116,  -116,  -116,   139,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,    48,  -116,    48,    84,  -116,  -116,  -116,  -116,    48,
     134,    69,    69,  -116,   139,   136,  -116,    65,  -116,    65,
    -116,  -116,  -116,    29,   138,    73,    73,  -116,  -116,  -116,
     140,   139,   153,  -116,   141,  -116,  -116,  -116,     8,    74,
    -116,  -116,  -116,   139,  -116,  -116,   144,   145,  -116,  -116,
     152,   148,  -116,  -116,   149,  -116,   153,   139,  -116,  -116,
      84,  -116,  -116,    76,    76,    76,    76,    17,   146,    76,
     156,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,    65,
      65,  -116,  -116,  -116,   158,  -116,  -116,  -116,    93,   109,
      65,   150,  -116,   164,   150,   152,  -116,   154,  -116,  -116,
    -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,  -116,  -116,  -116,   133,  -116,  -116,
     -70,  -116,  -116,   -79,  -116,  -116,  -116,  -116,  -115,   -24,
    -116,   -12,  -116,  -116,  -116,   -17,  -116,  -116,   -15,  -116,
    -116,  -116,    10,  -116,  -116,    27,   -37,  -116,   -86,  -116,
    -116,  -116,   -43,  -116,   -50,  -116,    42,  -116,    77,    22,
    -116,    46,   -13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -89
static const yytype_int16 yytable[] =
{
      58,    72,   146,    62,   147,    50,    71,   132,    35,    54,
      88,   102,    55,    56,   111,   127,     7,    80,   179,    15,
      92,     1,     9,    57,    74,    94,    84,    48,   144,    49,
     148,     4,   112,    75,     2,     5,   103,    93,     8,   116,
      83,    36,    81,   180,    -2,   156,   110,     6,    85,   115,
     128,   133,   149,   134,   118,   152,   153,   162,    95,    96,
      97,    98,    99,   100,   186,   187,   120,    16,   141,   142,
      63,   173,   -88,   -88,   -88,   194,   113,   121,    64,    65,
      17,   122,    25,   114,   175,   176,   177,   178,    54,    27,
     182,    55,    56,    38,    28,    39,    29,   -88,    40,    64,
      65,    34,   -60,    41,   106,   107,    51,    42,    26,    43,
      38,   -60,    39,    44,    45,    40,   135,   136,    31,   -60,
      41,    32,    33,    38,    42,    39,    43,    59,    40,    70,
      44,    45,    60,    41,    73,    76,    86,    42,    78,    43,
      82,   -60,    39,    44,    45,    40,    21,    22,    23,    24,
      41,    89,   193,    91,    42,    49,    43,   117,   125,   129,
      44,    45,   157,   140,   189,   145,   150,   163,   164,   155,
     159,   169,   170,   195,   197,   181,   192,   200,   199,   198,
     185,   161,   174,   172,   160,     0,   139
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-116))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      37,    44,   117,    40,   119,    29,    43,    93,     1,     1,
      60,     3,     4,     5,     1,    85,     1,     1,     1,    23,
       1,     1,     1,    36,     1,     1,     1,     1,   114,     3,
       1,     3,    19,    10,    14,     3,    28,    18,    23,    76,
      53,    34,    26,    26,    23,   131,    70,     0,    23,    73,
      87,   101,    23,   103,    78,   125,   126,   143,    34,    35,
      36,    37,    38,    39,   179,   180,     1,    23,   111,   112,
       1,   157,     3,     4,     5,   190,     1,    12,    30,    31,
       7,    16,     3,     8,   163,   164,   165,   166,     1,     1,
     169,     4,     5,     1,     6,     3,    20,    28,     6,    30,
      31,     1,    10,    11,    30,    31,    13,    15,    27,    17,
       1,    19,     3,    21,    22,     6,    32,    33,    27,    10,
      11,    27,    27,     1,    15,     3,    17,    23,     6,    28,
      21,    22,    25,    11,    28,    23,    10,    15,    24,    17,
       3,    19,     3,    21,    22,     6,    13,    14,    15,    16,
      11,    28,   189,    10,    15,     3,    17,    26,    23,     3,
      21,    22,     9,    29,     6,    29,    28,    23,    23,    29,
      29,    23,    23,    23,    10,    29,   188,    23,   195,   194,
     170,   139,   160,   156,   138,    -1,   109
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    14,    42,     3,     3,     0,     1,    23,     1,
      43,    47,    45,    44,    46,    23,    23,     7,    48,    50,
      51,    48,    48,    48,    48,     3,    27,     1,     6,    20,
      54,    27,    27,    27,     1,     1,    34,    49,     1,     3,
       6,    11,    15,    17,    21,    22,    77,    79,     1,     3,
      60,    13,    62,    52,     1,     4,     5,    93,    77,    23,
      25,    80,    77,     1,    30,    31,    83,    85,    86,    89,
      28,    77,    83,    28,     1,    10,    23,    56,    24,    61,
       1,    26,     3,    93,     1,    23,    10,    78,    85,    28,
      72,    10,     1,    18,     1,    34,    35,    36,    37,    38,
      39,    84,     3,    28,    92,    93,    30,    31,    87,    88,
      60,     1,    19,     1,     8,    60,    77,    26,    60,    57,
       1,    12,    16,    59,    63,    23,    53,    51,    77,     3,
      73,    81,    79,    85,    85,    32,    33,    90,    91,    89,
      29,    83,    83,    82,    79,    29,    59,    59,     1,    23,
      28,    65,    51,    51,    74,    29,    79,     9,    76,    29,
      92,    87,    79,    23,    23,    58,    55,    60,    66,    23,
      23,    75,    76,    79,    90,    54,    54,    54,    54,     1,
      26,    29,    54,    70,    71,    73,    59,    59,    64,     6,
      68,    67,    62,    77,    59,    23,    69,    10,    69,    66,
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
#line 135 "lalg.y"
    { insereProgram ((yyvsp[(2) - (2)].name)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 136 "lalg.y"
    { yyerror("Expected: program"); yyclearin; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 137 "lalg.y"
    { yyerror("Expected: program"); yyclearin; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 138 "lalg.y"
    { yyerror("Expected: ';' before begin or declaration of variables and constants"); yyclearin; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 139 "lalg.y"
    { insereProgram ((yyvsp[(2) - (2)].name)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 139 "lalg.y"
    { yyerror("Expected: '.'"); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 142 "lalg.y"
    { yyerror("Expected: begin or declaration of variables and constants");yyclearin; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 143 "lalg.y"
    { yyerror("Expected: end"); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 147 "lalg.y"
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

  case 19:

/* Line 1806 of yacc.c  */
#line 166 "lalg.y"
    { yyerror("Expected: '='"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 167 "lalg.y"
    { yyerror("Expected: ';'"); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 169 "lalg.y"
    {		int retorno;
																str=malloc(400 * sizeof(char));
																str=strtok(listavar,",");
																while(str!=NULL){
																	cpystr=malloc(400 * sizeof(char));
																	strcpy(cpystr,str);
																	if((yyvsp[(4) - (5)].i_number)==INTEGER)
																	{ 
																		retorno = insereVarInt (cpystr, contexto);
/* 																		printf("Insere retorna: %d inserindo %s \n", retorno, cpystr);  */
																		if(retorno==REDECLARACAO)
																			yyerror("Redeclaration of variables");
																		else if(retorno ==CONFLITO)
																			yyerror("Conflicting types");
																		else if(retorno == REDECLARACAO_PARAM)
																		{
																			sprintf(msg, "Variable %s already declared as a parameter",cpystr );
																			yyerror(msg);
																		}
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
																	} 
																	str=strtok(NULL,",");
																}
																listavar[0]='\0';
																
														   }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 207 "lalg.y"
    { yyerror("Expected an identifier"); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 208 "lalg.y"
    { yyerror("Expected: ':'");yyclearin; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 209 "lalg.y"
    { yyerror("Expected: ';'");yyclearin; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 211 "lalg.y"
    { (yyval.i_number) = REAL; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 211 "lalg.y"
    { (yyval.i_number) = INTEGER; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 212 "lalg.y"
    { yyerror("Incorrect type: Expected integer or real"); yyclearin; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 214 "lalg.y"
    { strcat(listavar,(yyvsp[(1) - (2)].name)); strcat(listavar,","); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 218 "lalg.y"
    { contexto=1; if(insereProcedure ((yyvsp[(2) - (2)].name),contexto)!=OK) yyerror("Redefinition of procedure"); lastprocedure=(yyvsp[(2) - (2)].name); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 218 "lalg.y"
    { contexto=0;removeLocalVars((yyvsp[(2) - (6)].name)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 222 "lalg.y"
    {	
												str=malloc(400 * sizeof(char));
												str=strtok(listavar,",");
												int ordem=1;
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													if((yyvsp[(3) - (3)].i_number)==INTEGER){ 
														insereParamInt (cpystr, contexto, lastprocedure, ordem);
													} else if((yyvsp[(3) - (3)].i_number)==REAL) { 
														insereParamReal (cpystr, contexto, lastprocedure, ordem);
													} 
													str=strtok(NULL,",");
													ordem++;
												}
												listavar[0]='\0';
												
										   }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 239 "lalg.y"
    { yyerror("Expected: ':'"); yyclearin; }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 249 "lalg.y"
    { strcat(listavar,(yyvsp[(1) - (1)].name)); strcat(listavar,","); contparametros++; }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 255 "lalg.y"
    { yyerror("Command not recognized"); yyclearin; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 257 "lalg.y"
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
													}
													else if(ret!=REAL) {
														yyerror("Conflicting types between 'readln' parameters");
														break;
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

  case 65:

/* Line 1806 of yacc.c  */
#line 310 "lalg.y"
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

  case 67:

/* Line 1806 of yacc.c  */
#line 351 "lalg.y"
    { yyerror("Expected: 'until'"); yyclearin; }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 353 "lalg.y"
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
							  }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 368 "lalg.y"
    { contparametros=0; }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 368 "lalg.y"
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
							while(str!=NULL){
								cpystr=malloc(400 * sizeof(char));
								strcpy(cpystr,str);
								retvar=busca(str,ATTR,contexto);
								if(retvar==NAO_EXISTE){
									sprintf(msg, "Identifier %s not previously declared", (yyvsp[(1) - (3)].name));
									yyerror(msg);
								}
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

  case 73:

/* Line 1806 of yacc.c  */
#line 405 "lalg.y"
    { yyerror("Expected: 'then'"); yyclearin; }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 406 "lalg.y"
    { yyerror("Expected: 'do'"); yyclearin; }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 411 "lalg.y"
    {yyclearin;}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 419 "lalg.y"
    { yyerror("Expected any operator: '=', '>', '<', '>=', '<=', '<>' "); yyclearin; }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 421 "lalg.y"
    { 
								if((yyvsp[(2) - (2)].symbol).type==TNULL){
									(yyval.symbol).type = (yyvsp[(1) - (2)].symbol).type; 
									if((yyvsp[(1) - (2)].symbol).type==INTEGER) (yyval.symbol).i_value=(yyvsp[(1) - (2)].symbol).i_value; 
									if((yyvsp[(1) - (2)].symbol).type==REAL) (yyval.symbol).f_value=(yyvsp[(1) - (2)].symbol).f_value;
									if((yyvsp[(1) - (2)].symbol).type==VAR_INT || (yyvsp[(1) - (2)].symbol).type==VAR_REAL) { (yyval.symbol).name=(yyvsp[(1) - (2)].symbol).name; };  
								}else{
									(yyval.symbol).type=TNULL;
									if((yyvsp[(2) - (2)].symbol).type==REAL || (yyvsp[(1) - (2)].symbol).type==REAL){
										(yyval.symbol).type=REAL;
									} else if ((yyvsp[(2) - (2)].symbol).type==INTEGER && (yyvsp[(1) - (2)].symbol).type==INTEGER){
										(yyval.symbol).type=INTEGER;
									} else {
										yyerror("Conflicting types, Try to assign a REAL to INTEGER");
									}
								}
							}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 439 "lalg.y"
    { (yyval.math_op)='0'; }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 439 "lalg.y"
    { (yyval.math_op)='+'; }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 440 "lalg.y"
    { (yyval.math_op)='-'; }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 442 "lalg.y"
    { (yyval.symbol).type=TNULL; }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 442 "lalg.y"
    { 
																	if((yyvsp[(3) - (3)].symbol).type==TNULL){
																		(yyval.symbol).type = (yyvsp[(2) - (3)].symbol).type; 
																		if((yyvsp[(2) - (3)].symbol).type==INTEGER) (yyval.symbol).i_value=(yyvsp[(2) - (3)].symbol).i_value; 
																		if((yyvsp[(2) - (3)].symbol).type==REAL) (yyval.symbol).f_value=(yyvsp[(2) - (3)].symbol).f_value;
																		if((yyvsp[(2) - (3)].symbol).type==VAR_INT || (yyvsp[(2) - (3)].symbol).type==VAR_REAL) (yyval.symbol).name=(yyvsp[(2) - (3)].symbol).name;  
																	}else{
																		(yyval.symbol).type=TNULL;
																		if((yyvsp[(2) - (3)].symbol).type==REAL || (yyvsp[(3) - (3)].symbol).type==REAL){
																			(yyval.symbol).type=REAL;
																		} else if ((yyvsp[(2) - (3)].symbol).type==INTEGER || (yyvsp[(3) - (3)].symbol).type==INTEGER){
																			(yyval.symbol).type=INTEGER;
																		}
																	}
																 }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 458 "lalg.y"
    { (yyval.math_op)='+'; }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 459 "lalg.y"
    { (yyval.math_op)='-'; }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 461 "lalg.y"
    { 
									if((yyvsp[(3) - (3)].symbol).type==TNULL){
										(yyval.symbol).type = (yyvsp[(2) - (3)].symbol).type; 
										if((yyvsp[(2) - (3)].symbol).type==INTEGER) (yyval.symbol).i_value=(yyvsp[(2) - (3)].symbol).i_value; 
										if((yyvsp[(2) - (3)].symbol).type==REAL) (yyval.symbol).f_value=(yyvsp[(2) - (3)].symbol).f_value;  
										if((yyvsp[(2) - (3)].symbol).type==VAR_INT || (yyvsp[(2) - (3)].symbol).type==VAR_REAL) (yyval.symbol).name=(yyvsp[(2) - (3)].symbol).name;  
									}
									if((yyvsp[(3) - (3)].symbol).type!=TNULL){
										(yyval.symbol).math_op=(yyvsp[(3) - (3)].symbol).math_op;
										if((yyvsp[(3) - (3)].symbol).math_op=='/' && ((yyvsp[(3) - (3)].symbol).type==REAL || (yyvsp[(2) - (3)].symbol).type==REAL)){
											yyerror("Division only avaiable between integers");
										}
									}
								}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 476 "lalg.y"
    { (yyval.symbol).type=TNULL; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 476 "lalg.y"
    { 
																	if((yyvsp[(3) - (3)].symbol).type==TNULL){
																		(yyval.symbol).math_op=(yyvsp[(1) - (3)].math_op); 
																		(yyval.symbol).type=(yyvsp[(2) - (3)].symbol).type;
																	}
																}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 483 "lalg.y"
    { (yyval.math_op)='*'; }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 484 "lalg.y"
    { (yyval.math_op)='/'; }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 486 "lalg.y"
    { 
			ret=busca((yyvsp[(1) - (1)].name),EXPRESSAO,contexto);
			if(ret==NAO_EXISTE){
				sprintf(msg, "Identifier %s not previously declared", (yyvsp[(1) - (1)].name));
				yyerror(msg);
			}else{
				(yyval.symbol).name=(yyvsp[(1) - (1)].name); (yyval.symbol).type=ret;
			}
		  }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 494 "lalg.y"
    { (yyval.symbol).type = (yyvsp[(1) - (1)].symbol).type; 
						if((yyvsp[(1) - (1)].symbol).type==INTEGER) (yyval.symbol).i_value=(yyvsp[(1) - (1)].symbol).i_value; 
						if((yyvsp[(1) - (1)].symbol).type==REAL) (yyval.symbol).f_value=(yyvsp[(1) - (1)].symbol).f_value;  
					  }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 499 "lalg.y"
    { (yyval.symbol).type = INTEGER; (yyval.symbol).i_value = (yyvsp[(1) - (1)].i_number); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 499 "lalg.y"
    { (yyval.symbol).type = REAL; (yyval.symbol).f_value = (yyvsp[(1) - (1)].r_number); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 499 "lalg.y"
    { yyerror("Expected a number"); yyclearin; }
    break;



/* Line 1806 of yacc.c  */
#line 2290 "lalg.tab.c"
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
#line 501 "lalg.y"


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

