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

	#define INTEGER 0
	#define REAL 1 

	#include <math.h>
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	
	int yylex (void);
	void yyerror (char *);
	int numerrors=0;
	int contexto=0;
	extern int num_lines;
	char listavar[400];
	char *str;
	char *cpystr;

	


/* Line 268 of yacc.c  */
#line 98 "lalg.tab.c"

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
#line 28 "lalg.y"
YYSTYPE
{

/* Line 293 of yacc.c  */
#line 28 "lalg.y"

	int i_number;
	double r_number;
	char* name;
	int type;
	struct symbol {
		int i_value;
		double f_value;
		int type;
	} symbol;
	struct variavel{
		char* name;
		int type;
	} variavel;
	char math_op;



/* Line 293 of yacc.c  */
#line 196 "lalg.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 208 "lalg.tab.c"

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
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

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
     176,   182,   184,   185,   189,   192,   193,   196,   197,   200,
     201,   205,   206,   211,   216,   221,   226,   231,   237,   240,
     245,   246,   253,   254,   260,   264,   267,   269,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   292,   293,   295,
     297,   298,   302,   304,   306,   310,   311,   315,   317,   319,
     321,   323,   327,   329,   331
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    14,     3,    43,    23,    48,    27,
      -1,    -1,     1,     3,    23,    44,    48,    27,    -1,    -1,
       1,     3,     1,    45,    48,    27,    -1,    -1,    14,     3,
       1,    46,    48,    27,    -1,    -1,    14,     3,    47,    23,
      48,     1,    -1,    50,     6,    76,    10,    -1,    -1,    50,
       1,    49,    76,    10,    -1,    50,     6,    76,     1,    -1,
      51,    54,    62,    -1,    -1,     7,     3,    34,    92,    23,
      51,    -1,    -1,     7,     3,     1,    52,    92,    23,    51,
      -1,    -1,     7,     3,    34,    92,     1,    53,    51,    -1,
      -1,    -1,    20,    60,    26,    59,    23,    55,    54,    -1,
      -1,    20,     1,    56,    26,    59,    23,    54,    -1,    -1,
      20,    60,     1,    57,    59,    23,    54,    -1,    -1,    20,
      60,    26,    59,     1,    58,    54,    -1,    16,    -1,    12,
      -1,     1,    -1,     3,    61,    -1,    -1,    24,    60,    -1,
      -1,    -1,    -1,    13,    63,     3,    65,    23,    70,    64,
      62,    -1,    -1,    28,    66,    29,    -1,    -1,    60,    26,
      59,    67,    69,    -1,    -1,    60,     1,    59,    68,    59,
      69,    -1,    -1,    23,    66,    -1,    71,     6,    76,    10,
      23,    -1,    54,    -1,    -1,    28,    73,    29,    -1,     3,
      74,    -1,    -1,    23,    73,    -1,    -1,     9,    78,    -1,
      -1,    78,    23,    76,    -1,    -1,     1,    23,    77,    76,
      -1,    15,    28,    60,    29,    -1,    22,    28,    60,    29,
      -1,    17,    76,    19,    82,    -1,    17,    76,     1,    82,
      -1,    11,    82,    18,    78,    75,    -1,     3,    81,    -1,
      21,    82,     8,    78,    -1,    -1,    11,    82,     1,    79,
      78,    75,    -1,    -1,    21,    82,     1,    80,    78,    -1,
       6,    76,    10,    -1,    25,    84,    -1,    72,    -1,    84,
      83,    84,    -1,     1,    -1,    34,    -1,    35,    -1,    36,
      -1,    37,    -1,    38,    -1,    39,    -1,     1,    -1,    88,
      86,    -1,    -1,    30,    -1,    31,    -1,    -1,    87,    88,
      86,    -1,    30,    -1,    31,    -1,    85,    91,    89,    -1,
      -1,    90,    91,    89,    -1,    32,    -1,    33,    -1,     3,
      -1,    92,    -1,    28,    84,    29,    -1,     4,    -1,     5,
      -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    95,    96,    96,    97,    99,   101,   101,   109,
     109,   110,   110,   112,   112,   112,   129,   129,   130,   130,
     131,   131,   133,   133,   134,   136,   138,   138,   140,   140,
     140,   140,   142,   142,   144,   144,   159,   159,   161,   161,
     163,   165,   167,   167,   169,   171,   171,   173,   173,   175,
     175,   175,   175,   177,   178,   179,   180,   181,   182,   183,
     184,   184,   185,   185,   186,   188,   188,   190,   190,   192,
     193,   194,   195,   196,   197,   198,   200,   202,   202,   203,
     205,   205,   207,   208,   210,   212,   212,   214,   215,   217,
     217,   217,   219,   219,   219
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
  "mais_par", "corpo_p", "dc_loc", "lista_arg", "argumentos", "mais_ident",
  "pfalse", "comandos", "$@17", "cmd", "$@18", "$@19", "pos_id",
  "condicao", "relacao", "expressao", "op_un", "outros_termos", "op_ad",
  "termo", "mais_fatores", "op_mult", "fator", "numero", 0
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
      70,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      76,    77,    76,    78,    78,    78,    78,    78,    78,    78,
      79,    78,    80,    78,    78,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    85,    85,
      86,    86,    87,    87,    88,    89,    89,    90,    90,    91,
      91,    91,    92,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     4,     0,     5,     4,     3,     0,     6,     0,
       7,     0,     7,     0,     0,     7,     0,     7,     0,     7,
       0,     7,     1,     1,     1,     2,     0,     2,     0,     0,
       0,     8,     0,     3,     0,     5,     0,     6,     0,     2,
       5,     1,     0,     3,     2,     0,     2,     0,     2,     0,
       3,     0,     4,     4,     4,     4,     4,     5,     2,     4,
       0,     6,     0,     5,     3,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     1,     1,
       0,     3,     1,     1,     3,     0,     3,     1,     1,     1,
       1,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     6,     4,     8,
       0,     0,    17,    17,    17,    17,    17,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     7,    13,     0,     0,
      38,     5,     9,     3,    11,    19,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    36,
       0,    39,    16,     0,   104,   102,   103,     0,     0,    61,
      87,     0,    76,    68,     0,    78,    88,    89,     0,     0,
       0,    90,     0,     0,     0,     0,    15,    12,     0,     0,
       0,    35,    28,     0,     0,     0,    21,    17,    14,     0,
      75,    55,     0,    74,    70,     0,    85,    79,    80,    81,
      82,    83,    84,    87,    99,    87,    95,   100,    92,    93,
      86,    87,     0,     0,     0,    72,     0,     0,    60,     0,
      37,     0,    34,    33,    32,     0,    42,    17,    17,    18,
      62,     0,    54,    53,     0,    57,    77,     0,    97,    98,
      94,     0,    90,    63,    66,    65,     0,    69,    64,     0,
       0,    30,    24,     0,     0,    20,    22,    56,    57,     0,
      67,   101,    95,    91,    73,    23,    23,    23,    23,     0,
       0,    23,    71,    58,    96,    27,    29,    31,    25,     0,
       0,    43,    51,    40,     0,    46,    44,    38,     0,     0,
      48,    41,     0,    48,     0,    45,     0,    47,    49,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    10,    13,    12,    14,    11,    18,    37,    19,
      20,    53,   128,    30,   168,    79,   121,   167,   125,   169,
      81,    52,    84,   187,   154,   170,   190,   189,   195,   183,
     184,    62,    92,   132,   160,    46,    89,    47,   134,   146,
      63,    68,   103,    69,    70,   110,   111,    71,   140,   141,
     106,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -118
static const yytype_int16 yypact[] =
{
      20,    24,    57,    61,    16,    28,  -118,  -118,  -118,  -118,
      71,    79,    73,    73,    73,    73,    73,    83,    77,    30,
      88,    97,    99,   110,   112,     8,  -118,  -118,    95,    64,
     102,  -118,  -118,  -118,  -118,  -118,    86,    95,   118,     0,
      95,    15,    94,   108,    15,   111,    23,   122,  -118,   126,
       9,  -118,  -118,    86,  -118,  -118,  -118,    31,   146,  -118,
      90,   115,  -118,  -118,   147,  -118,  -118,  -118,    65,    39,
      10,   113,   155,    63,    22,   155,  -118,  -118,    78,   133,
     155,  -118,  -118,    91,   157,   138,  -118,    73,  -118,    78,
    -118,   140,   135,  -118,  -118,   125,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,    90,  -118,    90,   116,  -118,  -118,  -118,
    -118,    90,   136,    15,    15,  -118,   125,   137,  -118,    91,
    -118,    91,  -118,  -118,  -118,    36,   134,    73,    73,  -118,
    -118,   115,  -118,  -118,   125,   158,  -118,   141,  -118,  -118,
    -118,    10,   113,  -118,  -118,  -118,   125,  -118,  -118,   145,
     148,  -118,  -118,   155,   149,  -118,  -118,  -118,   158,   125,
    -118,  -118,   116,  -118,  -118,    88,    88,    88,    88,    21,
     144,    88,  -118,  -118,  -118,  -118,  -118,  -118,  -118,    91,
      91,  -118,  -118,  -118,   163,  -118,  -118,   102,    95,    91,
     151,  -118,   165,   151,   155,  -118,   153,  -118,  -118,  -118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,  -118,  -118,  -118,   139,  -118,  -118,
     -79,  -118,  -118,   -33,  -118,  -118,  -118,  -118,  -117,   -22,
    -118,   -10,  -118,  -118,  -118,   -16,  -118,  -118,   -14,  -118,
    -118,  -118,    49,  -118,    25,   -37,  -118,   -90,  -118,  -118,
    -118,   -43,  -118,   -48,  -118,    40,  -118,    70,    26,  -118,
      43,    32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      58,    74,   149,    64,   150,   135,    73,    50,   129,    35,
      82,    54,    90,   104,    55,    56,    65,     7,   -87,   -87,
     -87,     1,   179,   115,    76,    60,   147,     4,    61,     9,
     116,    27,    86,    77,     2,    83,    28,   151,   105,     8,
      96,   118,    36,   -87,   158,    66,    67,   180,   155,   156,
     112,    -2,   130,   117,    87,   136,   164,   137,   120,   152,
       5,     6,   185,   186,   113,    48,    94,    49,    57,   173,
     144,   145,   193,    97,    98,    99,   100,   101,   102,    38,
      17,    39,   114,    95,    40,    85,    25,    54,   -59,    41,
      55,    56,   122,    42,    15,    43,    38,   -59,    39,    44,
      45,    40,    16,   123,    26,   -59,    41,   124,    29,    38,
      42,    39,    43,    34,    40,    51,    44,    45,    91,    41,
      66,    67,    72,    42,    31,    43,    32,   -59,    39,    44,
      45,    40,   175,   176,   177,   178,    41,    33,   182,    75,
      42,    59,    43,   108,   109,    78,    44,    45,   138,   139,
      80,   192,    21,    22,    23,    24,    88,    93,    49,   119,
     126,   127,   153,   131,   133,   143,   148,   159,   165,   188,
     161,   166,   171,   181,   194,   196,   199,   191,   198,   197,
     157,   142,   163,   172,   162,     0,     0,     0,   174
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-118))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      37,    44,   119,    40,   121,    95,    43,    29,    87,     1,
       1,     1,    60,     3,     4,     5,     1,     1,     3,     4,
       5,     1,     1,     1,     1,    25,   116,     3,    28,     1,
       8,     1,     1,    10,    14,    26,     6,     1,    28,    23,
       1,    78,    34,    28,   134,    30,    31,    26,   127,   128,
      72,    23,    89,    75,    23,   103,   146,   105,    80,    23,
       3,     0,   179,   180,     1,     1,     1,     3,    36,   159,
     113,   114,   189,    34,    35,    36,    37,    38,    39,     1,
       7,     3,    19,    18,     6,    53,     3,     1,    10,    11,
       4,     5,     1,    15,    23,    17,     1,    19,     3,    21,
      22,     6,    23,    12,    27,    10,    11,    16,    20,     1,
      15,     3,    17,     1,     6,    13,    21,    22,     3,    11,
      30,    31,    28,    15,    27,    17,    27,    19,     3,    21,
      22,     6,   165,   166,   167,   168,    11,    27,   171,    28,
      15,    23,    17,    30,    31,    23,    21,    22,    32,    33,
      24,   188,    13,    14,    15,    16,    10,    10,     3,    26,
       3,    23,    28,    23,    29,    29,    29,     9,    23,     6,
      29,    23,    23,    29,    23,    10,    23,   187,   194,   193,
     131,   111,   142,   158,   141,    -1,    -1,    -1,   162
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    14,    42,     3,     3,     0,     1,    23,     1,
      43,    47,    45,    44,    46,    23,    23,     7,    48,    50,
      51,    48,    48,    48,    48,     3,    27,     1,     6,    20,
      54,    27,    27,    27,     1,     1,    34,    49,     1,     3,
       6,    11,    15,    17,    21,    22,    76,    78,     1,     3,
      60,    13,    62,    52,     1,     4,     5,    92,    76,    23,
      25,    28,    72,    81,    76,     1,    30,    31,    82,    84,
      85,    88,    28,    76,    82,    28,     1,    10,    23,    56,
      24,    61,     1,    26,    63,    92,     1,    23,    10,    77,
      84,     3,    73,    10,     1,    18,     1,    34,    35,    36,
      37,    38,    39,    83,     3,    28,    91,    92,    30,    31,
      86,    87,    60,     1,    19,     1,     8,    60,    76,    26,
      60,    57,     1,    12,    16,    59,     3,    23,    53,    51,
      76,    23,    74,    29,    79,    78,    84,    84,    32,    33,
      89,    90,    88,    29,    82,    82,    80,    78,    29,    59,
      59,     1,    23,    28,    65,    51,    51,    73,    78,     9,
      75,    29,    91,    86,    78,    23,    23,    58,    55,    60,
      66,    23,    75,    78,    89,    54,    54,    54,    54,     1,
      26,    29,    54,    70,    71,    59,    59,    64,     6,    68,
      67,    62,    76,    59,    23,    69,    10,    69,    66,    23
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
#line 89 "lalg.y"
    { insereProgram ((yyvsp[(2) - (2)].name)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 90 "lalg.y"
    { yyerror("Expected: program"); yyclearin; }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 91 "lalg.y"
    { yyerror("Expected: program"); yyclearin; }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 92 "lalg.y"
    { yyerror("Expected: ';' before begin or declaration of variables and constants"); yyclearin; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 93 "lalg.y"
    { insereProgram ((yyvsp[(2) - (2)].name)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 93 "lalg.y"
    { yyerror("Expected: '.'"); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 96 "lalg.y"
    { yyerror("Expected: begin or declaration of variables and constants");yyclearin; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 97 "lalg.y"
    { yyerror("Expected: end"); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 101 "lalg.y"
    { 
																	if((yyvsp[(4) - (6)].symbol).type==INTEGER){ 
																		insereConstInt ((yyvsp[(2) - (6)].name), (yyvsp[(4) - (6)].symbol).i_value, contexto); 
																	} else if((yyvsp[(4) - (6)].symbol).type==REAL) { 
																		insereConstReal ((yyvsp[(2) - (6)].name), (yyvsp[(4) - (6)].symbol).f_value, contexto); 
																	} 
																}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 109 "lalg.y"
    { yyerror("Expected: '='"); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 110 "lalg.y"
    { yyerror("Expected: ';'"); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 112 "lalg.y"
    {	
																str=malloc(400 * sizeof(char));
																str=strtok(listavar,",");
																while(str!=NULL){
																	cpystr=malloc(400 * sizeof(char));
																	strcpy(cpystr,str);
																	if((yyvsp[(4) - (5)].i_number)==INTEGER){ 
																		insereVarInt (cpystr, contexto);
																	} else if((yyvsp[(4) - (5)].i_number)==REAL) { 
																		insereVarReal (cpystr, contexto);
																	} 
																	str=strtok(NULL,",");
																}
																listavar[0]='\0';
																
														   }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 129 "lalg.y"
    { yyerror("Expected an identifier"); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 130 "lalg.y"
    { yyerror("Expected: ':'");yyclearin; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 131 "lalg.y"
    { yyerror("Expected: ';'");yyclearin; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 133 "lalg.y"
    { (yyval.i_number) = REAL; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 133 "lalg.y"
    { (yyval.i_number) = INTEGER; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 134 "lalg.y"
    { yyerror("Incorrect type: Expected integer or real"); yyclearin; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 136 "lalg.y"
    { strcat(listavar,(yyvsp[(1) - (2)].name)); strcat(listavar,","); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 140 "lalg.y"
    { contexto=1; }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 140 "lalg.y"
    { contexto=0; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 144 "lalg.y"
    {	
												str=malloc(400 * sizeof(char));
												str=strtok(listavar,",");
												while(str!=NULL){
													cpystr=malloc(400 * sizeof(char));
													strcpy(cpystr,str);
													if((yyvsp[(3) - (3)].i_number)==INTEGER){ 
														insereParamInt (cpystr, contexto);
													} else if((yyvsp[(3) - (3)].i_number)==REAL) { 
														insereParamReal (cpystr, contexto);
													} 
													str=strtok(NULL,",");
												}
												listavar[0]='\0';
												
										   }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 159 "lalg.y"
    { yyerror("Expected: ':'"); yyclearin; }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 175 "lalg.y"
    { yyerror("Comando não reconhecido"); yyclearin; }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 180 "lalg.y"
    { yyerror("Expected: 'until'"); yyclearin; }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 184 "lalg.y"
    { yyerror("Expected: 'then'"); yyclearin; }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 185 "lalg.y"
    { yyerror("Expected: 'do'"); yyclearin; }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 190 "lalg.y"
    {yyclearin;}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 198 "lalg.y"
    { yyerror("Expected any operator: '=', '>', '<', '>=', '<=', '<>' "); yyclearin; }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 219 "lalg.y"
    { (yyval.symbol).type = INTEGER; (yyval.symbol).i_value = (yyvsp[(1) - (1)].i_number); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 219 "lalg.y"
    { (yyval.symbol).type = REAL; (yyval.symbol).f_value = (yyvsp[(1) - (1)].r_number); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 219 "lalg.y"
    { yyerror("Expected a number"); yyclearin; }
    break;



/* Line 1806 of yacc.c  */
#line 1875 "lalg.tab.c"
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
#line 221 "lalg.y"


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

