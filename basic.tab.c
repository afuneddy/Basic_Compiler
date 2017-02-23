/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 371 of yacc.c  */
#line 68 "basic.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "basic.tab.h".  */
#ifndef YY_YY_BASIC_TAB_H_INCLUDED
# define YY_YY_BASIC_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     GOTO = 258,
     IF = 259,
     PRINT = 260,
     READ = 261,
     STOP = 262,
     THEN = 263,
     REL = 264,
     LNUM = 265,
     NUM = 266,
     VAR = 267
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 2 "basic.y"

  int varnum;
  int val;
  int rel;
  char *addr;


/* Line 387 of yacc.c  */
#line 131 "basic.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_BASIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
/* Line 390 of yacc.c  */
#line 24 "basic.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "symtab.h"
  #include "relations.h"
  #include <string.h>
  #define DATALEN 64 
  #define VARSIZE 1024

  int yylex();
  SYMTAB tab;

  void yyerror(char *s);
  void printlabel();
  void printjump1(int l, int r, int rnum, int linenm); /* char * takes name of variable defined at .bss SECTION */
  void printjump2(char *l, int r, int rnum, int linenm);
  void printjump3(int l, char *r, int rnum, int linenm);
  void printjump4(char *l, char *r, int rnum, int linenm);
  extern FILE *yyin;

  void header();
  int readinput();
  void sprint();
  void exiting();
  void printLF();
  void vprint(char *var, int val);
  void divloop();
  void prinloop();
  void print();
  void slen();
  void finret();

  void astoi();
  void atiloop();
  void atipop();
  void finish();
  void nextchar();

  char *varbss,  *vars;


/* Line 390 of yacc.c  */
#line 201 "basic.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  21
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNRULES -- Number of states.  */
#define YYNSTATES  67

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   267

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    20,    15,    13,     2,    14,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    11,    15,    19,    22,    26,
      31,    39,    47,    55,    63,    68,    70,    72,    76,    80,
      84,    88,    92,    94,    98,   102,   106,   110,   114,   118,
     122,   126,   130,   134,   138,   142
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      22,     0,    -1,    22,    23,    17,    -1,    22,    17,    -1,
      -1,    24,     5,    12,    -1,    24,     6,    12,    -1,    24,
       7,    -1,    24,     3,    11,    -1,    24,    12,    18,    26,
      -1,    24,     4,    25,     9,    25,     8,    11,    -1,    24,
       4,    26,     9,    25,     8,    11,    -1,    24,     4,    25,
       9,    26,     8,    11,    -1,    24,     4,    26,     9,    26,
       8,    11,    -1,    24,    12,    18,    25,    -1,    10,    -1,
      11,    -1,    25,    13,    25,    -1,    25,    14,    25,    -1,
      25,    15,    25,    -1,    25,    16,    25,    -1,    19,    25,
      20,    -1,    12,    -1,    26,    13,    25,    -1,    25,    13,
      26,    -1,    26,    13,    26,    -1,    26,    14,    25,    -1,
      25,    14,    26,    -1,    26,    14,    26,    -1,    26,    15,
      25,    -1,    25,    15,    26,    -1,    26,    15,    26,    -1,
      26,    16,    25,    -1,    25,    16,    26,    -1,    26,    16,
      26,    -1,    19,    26,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    71,    71,    74,    80,    90,    93,    96,
     102,   105,   108,   111,   115,   124,   130,   134,   142,   148,
     154,   164,   171,   174,   182,   192,   201,   210,   219,   228,
     237,   246,   255,   264,   273,   283
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GOTO", "IF", "PRINT", "READ", "STOP",
  "THEN", "REL", "LNUM", "NUM", "VAR", "'+'", "'-'", "'*'", "'/'", "'\\n'",
  "'='", "'('", "')'", "$accept", "P", "S", "LAB", "E", "VB", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    43,    45,    42,    47,    10,    61,    40,
      41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    21,    22,    22,    22,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    24,    25,    25,    25,    25,
      25,    25,    26,    26,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     3,     3,     2,     3,     4,
       7,     7,     7,     7,     4,     1,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,    15,     3,     0,     0,     2,     0,     0,
       0,     0,     7,     0,     8,    16,    22,     0,     0,     0,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,     9,    21,    35,     0,
       0,    17,    24,    18,    27,    19,    30,    20,    33,     0,
       0,    23,    25,    26,    28,    29,    31,    32,    34,     0,
       0,     0,     0,    10,    12,    11,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     6,    18,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -18
static const yytype_int8 yypact[] =
{
     -18,    36,   -18,   -18,   -18,    20,    35,   -18,    34,    32,
      38,    40,   -18,    30,   -18,   -18,   -18,    32,    71,    79,
     -18,   -18,    32,    83,    91,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,   -12,     6,   -18,   -18,    41,
      50,    -9,     9,    -9,     9,   -18,   -18,   -18,   -18,    54,
      63,    -9,     9,    -9,     9,   -18,   -18,   -18,   -18,    48,
      49,    61,    62,   -18,   -18,   -18,   -18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -18,   -18,   -18,   -18,   -17,     1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      23,    26,    27,    28,    29,    35,    28,    29,    39,    41,
      43,    45,    47,    49,    51,    53,    55,    57,    24,    31,
      32,    33,    34,    36,    33,    34,    40,    42,    44,    46,
      48,    50,    52,    54,    56,    58,     2,     7,     8,     9,
      10,    11,    12,    15,    16,    14,     3,    13,    22,    59,
      20,    17,    21,     4,    26,    27,    28,    29,    60,    63,
      64,     0,    61,    31,    32,    33,    34,    26,    27,    28,
      29,    62,    65,    66,     0,     0,    31,    32,    33,    34,
      25,     0,     0,     0,    26,    27,    28,    29,    30,     0,
       0,     0,    31,    32,    33,    34,    26,    27,    28,    29,
       0,     0,     0,    37,    31,    32,    33,    34,     0,     0,
       0,    38
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-18)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      17,    13,    14,    15,    16,    22,    15,    16,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    17,    13,
      14,    15,    16,    22,    15,    16,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,     0,    17,     3,     4,
       5,     6,     7,    11,    12,    11,    10,    12,    18,     8,
      12,    19,    12,    17,    13,    14,    15,    16,     8,    11,
      11,    -1,     8,    13,    14,    15,    16,    13,    14,    15,
      16,     8,    11,    11,    -1,    -1,    13,    14,    15,    16,
       9,    -1,    -1,    -1,    13,    14,    15,    16,     9,    -1,
      -1,    -1,    13,    14,    15,    16,    13,    14,    15,    16,
      -1,    -1,    -1,    20,    13,    14,    15,    16,    -1,    -1,
      -1,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,     0,    10,    17,    23,    24,    17,     3,     4,
       5,     6,     7,    12,    11,    11,    12,    19,    25,    26,
      12,    12,    18,    25,    26,     9,    13,    14,    15,    16,
       9,    13,    14,    15,    16,    25,    26,    20,    20,    25,
      26,    25,    26,    25,    26,    25,    26,    25,    26,    25,
      26,    25,    26,    25,    26,    25,    26,    25,    26,     8,
       8,     8,     8,    11,    11,    11,    11
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 5:
/* Line 1792 of yacc.c  */
#line 74 "basic.y"
    {

                 printf("%6s  mov %2s eax, [%s]\n", "","", tab.sym[(yyvsp[(3) - (3)].varnum)].name);
                 printf("%6s  call %2s print\n","","");
                 printf("%6s  call %2s printLF\n","","");
              }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 80 "basic.y"
    {
                 printf("%6s  mov %2s edx, %d\n","","",DATALEN);
                 printf("%6s  mov %2s ecx, buf\n","","");
                 printf("%6s  mov %2s ebx, 0\n","","");
                 printf("%6s  mov %2s eax, 3\n","","");
                 printf("%6s  int 0x80\n\n","");
                  
                 printf("%6s  call %2s atoi\n","","");
                 printf("%6s  mov %2s [%s], eax\n","","", tab.sym[(yyvsp[(3) - (3)].varnum)].name);
                  }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 90 "basic.y"
    {
                 printf("%6s  call %2s exiting\n","","");
               }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 93 "basic.y"
    {
                  printf("%6s  jmp lb%d\n","", (yyvsp[(3) - (3)].val));
               }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 96 "basic.y"
    {

                 printf("%6s  mov %2s eax, [%s]\n","","",(yyvsp[(4) - (4)].addr));
                 printf("%6s  mov%3s [%s], eax\n","","", tab.sym[(yyvsp[(2) - (4)].varnum)].name );
                 printf("%6s  int %2s 0x80\n","",""); 
               }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 102 "basic.y"
    {
                                   printjump1((yyvsp[(3) - (7)].val), (yyvsp[(5) - (7)].val), (yyvsp[(4) - (7)].rel), (yyvsp[(7) - (7)].val));
                                    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 105 "basic.y"
    {
                                   printjump2((yyvsp[(3) - (7)].addr), (yyvsp[(5) - (7)].val), (yyvsp[(4) - (7)].rel), (yyvsp[(7) - (7)].val));
                                    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 108 "basic.y"
    {
                                   printjump3((yyvsp[(3) - (7)].val), (yyvsp[(5) - (7)].addr), (yyvsp[(4) - (7)].rel), (yyvsp[(7) - (7)].val));
                                    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 111 "basic.y"
    {
                                   printjump4((yyvsp[(3) - (7)].addr), (yyvsp[(5) - (7)].addr), (yyvsp[(4) - (7)].rel), (yyvsp[(7) - (7)].val));
                                    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 115 "basic.y"
    {
                 
                    tab.sym[(yyvsp[(2) - (4)].varnum)].val = (yyvsp[(4) - (4)].val);
  
                 printf("%6s  mov %2s eax, %d\n","","",tab.sym[(yyvsp[(2) - (4)].varnum)].val);
                 printf("%6s  mov%3s [%s], eax\n","","", tab.sym[(yyvsp[(2) - (4)].varnum)].name );
                 printf("%6s  int %2s 0x80\n","",""); 
               }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 124 "basic.y"
    {
                 printf("lb%d:\n", (yyvsp[(1) - (1)].val));
             }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 130 "basic.y"
    {
                (yyval.val) = (yyvsp[(1) - (1)].val);
               }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 134 "basic.y"
    {
                           (yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val);               
     
                 printf("%6s  mov%3s eax, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  add%3s eax,  ebx\n","","");

               }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 142 "basic.y"
    {
                (yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val); 
                 printf("%6s  mov%3s eax, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  sub%3s eax,  ebx\n\n","","");
               }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 148 "basic.y"
    {
               (yyval.val) = (yyvsp[(1) - (3)].val) * (yyvsp[(3) - (3)].val);
                 printf("%6s  mov%3s eax, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  mul%3s ebx\n\n","","");
               }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 154 "basic.y"
    {

                (yyval.val) = (yyvsp[(1) - (3)].val) / (yyvsp[(3) - (3)].val);
                if((yyvsp[(3) - (3)].val) == 0){
                fprintf(stderr, "Division by zero!");
                exit(0);}
                 printf("%6s  mov%3s eax, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  div%3s ebx\n\n","","");
               }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 164 "basic.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 171 "basic.y"
    {     
                 (yyval.addr) = tab.sym[(yyvsp[(1) - (1)].varnum)].name;
             }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 174 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  add%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires2], eax\n","","");
                 
                 (yyval.addr) = "ires2";
               }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 182 "basic.y"
    {

                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  add%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires3], eax\n","","");
                 
                 (yyval.addr) = "ires3";

               }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 192 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  add%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires5], eax\n","","");
                 
                 (yyval.addr) = "ires5";

               }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 201 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  sub%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires6], eax\n","","");
                 
                 (yyval.addr) = "ires6";

               }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 210 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  sub%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires7], eax\n","","");
                 
                 (yyval.addr) = "ires7";

               }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 219 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  sub%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires8], eax\n","","");
                 
                 (yyval.addr) = "ires8";

               }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 228 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  mul%3s ebx\n","","");
                 printf("%6s  mov%3s [ires9], eax\n","","");
                 
                 (yyval.addr) = "ires9";

               }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 237 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  mul%3s ebx\n","","");
                 printf("%6s  mov%3s [ires10], eax\n","","");
                 
                 (yyval.addr) = "ires10";

               }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 246 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  mul%3s ebx\n","","");
                 printf("%6s  mov%3s [ires11], eax\n","","");
                 
                 (yyval.addr) = "ires11";

               }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 255 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(3) - (3)].val));
                 printf("%6s  div%3s ebx\n","","");
                 printf("%6s  mov%3s [ires12], eax\n","","");
                 
                 (yyval.addr) = "ires12";

               }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 264 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  mov%3s ebx, %d\n","","",(yyvsp[(1) - (3)].val));
                 printf("%6s  div%3s ebx\n","","");
                 printf("%6s  mov%3s [ires13], eax\n","","");
                 
                 (yyval.addr) = "ires13";

               }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 273 "basic.y"
    {
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(1) - (3)].addr));
                 printf("%6s  mov%3s ebx, [%s]\n","","",(yyvsp[(3) - (3)].addr));
                 printf("%6s  div%3s  ebx\n","","");
                 printf("%6s  mov%3s [ires14], eax\n","","");
                 
                 (yyval.addr) = "ires14";

               }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 283 "basic.y"
    {
                 
                 printf("%6s  mov%3s eax, [%s]\n","","",(yyvsp[(2) - (3)].addr));
                 printf("%6s  mov%3s [ires15], eax\n","","");
                 (yyval.addr) = "ires15";

                    }
    break;


/* Line 1792 of yacc.c  */
#line 1804 "basic.tab.c"
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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


/* Line 2055 of yacc.c  */
#line 291 "basic.y"


int main(int argc, char *argv[])
{
  FILE *fd;
 vars = malloc(sizeof(char)*VARSIZE);
 varbss = malloc(sizeof(char)*VARSIZE);

  header();
  if(argc != 2){
    fprintf(stderr,"usage: %s basicfile\n", argv[0]);
    exit(0);
  }
  fd = fopen(argv[1],"r");
  if(fd == NULL){
    fprintf(stderr,"cannot open %s\n",argv[1]);
    exit(0);
  }
  int i;  
  yyin = fd;
  tab.n = 0;
  yyparse();
  
  print(); 
  divloop();
  prinloop();
  sprint();
  slen();
  nextchar();
  finish();
  exiting();
  astoi();
  atiloop();
  finret();
  printLF();
 fprintf(stdout, "\nSECTION .bss\n%s", varbss); 
 fprintf(stdout, "\nres    resb    %d", DATALEN);
 fprintf(stdout, "\nbuf    resb    %d", DATALEN);
 for(i=0; i<tab.n; i++)
   fprintf(stdout, "\n%s    resb    %d", tab.sym[i].name, DATALEN);
 for(i=1; i<16; i++)
   fprintf(stdout, "\nires%d    resb    %d", i, DATALEN);
  return 0;
}

void yyerror(char *s)
{
  fprintf(stderr,"%s\n", s);
}

void header(){
printf(
"\nSECTION .text"
"\nglobal  _start"   
"\n_start:\n\n");

}

int readinput(){
int a;

fscanf(stdin, "%d", &a);
return a;

}


void printjump1(int l, int r, int rnum, int linenum)
{
 printf("%6s  mov eax, %d \n", "", l); 

  printf("%6s  cmp %2s byte [eax], %d\n", "", "", r);
  switch(rnum){
    case REL_JEQ: printf("%6s  je lb%d\n", "", linenum); return;
    case REL_JNE: printf("%6s  jne lb%d\n", "", linenum); return;
    case REL_JLT: printf("%6s  jl lb%d\n", "", linenum); return;
    case REL_JLE: printf("%6s  jle lb%d\n", "", linenum); return;
    case REL_JGT: printf("%6s  jg lb%d\n", "", linenum); return;
    case REL_JGE: printf("%6s  jge lb%d\n", "", linenum); return;
    default:
      fprintf(stderr,"Huh in printjump %d,%d\n", rnum, linenum);
  }
}
void printjump2(char *l, int r, int rnum, int linenum)
{
 printf("%6s  mov eax, [%s]\n", "", l); 
 printf("%6s  call print\n", ""); 

  printf("%6s  cmp %2s byte [eax], %d\n", "", "", r);
  switch(rnum){
    case REL_JEQ: printf("%6s  je lb%d\n", "", linenum); return;
    case REL_JNE: printf("%6s  jne lb%d\n", "", linenum); return;
    case REL_JLT: printf("%6s  jl lb%d\n", "", linenum); return;
    case REL_JLE: printf("%6s  jle lb%d\n", "", linenum); return;
    case REL_JGT: printf("%6s  jg lb%d\n", "", linenum); return;
    case REL_JGE: printf("%6s  jge lb%d\n", "", linenum); return;
    default:
      fprintf(stderr,"Huh in printjump %d,%d\n", rnum, linenum);
  }
}
void printjump3(int l, char *r, int rnum, int linenum)
{
 printf("%6s  mov eax, %d \n", "", l); 

  printf("%6s  cmp %2s byte [eax], [%s]\n", "", "", r);
  switch(rnum){
    case REL_JEQ: printf("%6s  je lb%d\n", "", linenum); return;
    case REL_JNE: printf("%6s  jne lb%d\n", "", linenum); return;
    case REL_JLT: printf("%6s  jl lb%d\n", "", linenum); return;
    case REL_JLE: printf("%6s  jle lb%d\n", "", linenum); return;
    case REL_JGT: printf("%6s  jg lb%d\n", "", linenum); return;
    case REL_JGE: printf("%6s  jge lb%d\n", "", linenum); return;
    default:
      fprintf(stderr,"Huh in printjump %d,%d\n", rnum, linenum);
  }
}
void printjump4(char *l, char *r, int rnum, int linenum)
{
 printf("%6s  mov eax, [%s] \n", "", l); 

  printf("%6s  cmp %2s byte [eax], [%s]\n", "", "", r);
  switch(rnum){
    case REL_JEQ: printf("%6s  je lb%d\n", "", linenum); return;
    case REL_JNE: printf("%6s  jne lb%d\n", "", linenum); return;
    case REL_JLT: printf("%6s  jl lb%d\n", "", linenum); return;
    case REL_JLE: printf("%6s  jle lb%d\n", "", linenum); return;
    case REL_JGT: printf("%6s  jg lb%d\n", "", linenum); return;
    case REL_JGE: printf("%6s  jge lb%d\n", "", linenum); return;
    default:
      fprintf(stderr,"Huh in printjump %d,%d\n", rnum, linenum);
  }
}

void exiting(){
      printf("\nexiting:\n");
      printf("\n%6s  mov %2s ebx, 0 \n", "","");
      printf("%6s  mov %2s eax, 1 \n", "","");
      printf("%6s  int %2s 80h\n", "","");
      printf("%6s  ret\n","");

 }


void astoi(){
      printf("\natoi:\n");
      printf("%6s  mov %2s eax, 0\n", "","");
      printf("%6s  mov %2s esi, buf\n", "","");
  }
void atiloop(){
      printf("\natiloop:\n");
      printf("%6s  mov %2s ebx, [esi]\n", "","");
      printf("%6s  and %2s ebx, 0xff\n", "","");
      printf("%6s  cmp %2s ebx, 10\n", "","");
      printf("%6s  jz %2s finret\n", "","");
      printf("%6s  inc %2s esi\n", "","");
      printf("%6s  mov %2s ecx, 10\n", "","");
      printf("%6s  mul %2s ecx\n", "","");
      printf("%6s  sub %2s ebx, 48\n", "","");
      printf("%6s  add %2s eax, ebx\n", "","");
      printf("%6s  jmp %2s atiloop\n", "","");
  }
      

void atipop(){

      printf("\natipop:\n");
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  pop %2s ebx\n", "","");
      printf("%6s  pop %2s ecx\n", "","");
      printf("%6s  call  %2s finish\n", "","");
  }


void printLF(){
      printf("\nprintLF:\n");
      printf("%6s  push %2s eax\n", "","");
      printf("%6s  mov %2s eax, 0Ah\n", "","");
      printf("%6s  push %2s eax\n", "","");
      printf("%6s  mov %2s eax, esi\n", "","");
      printf("%6s  call %2s sprint\n","","");
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  ret","");
  }

void print(){

      printf("\nprint:\n");
      printf("%6s  push %2s ebx\n", "","");
      printf("%6s  push %2s ecx\n", "","");
      printf("%6s  push %2s edx\n", "","");
      printf("%6s  push %2s esi\n", "","");
      printf("%6s  mov %2s ecx, 0\n", "","");

}  
void divloop(){

      printf("\ndivloop:\n");
      printf("%6s  inc %2s ecx\n", "","");
      printf("%6s  mov %2s edx, 0\n", "","");
      printf("%6s  mov %2s esi, 10\n", "","");
      printf("%6s  idiv %2s esi\n", "","");
      printf("%6s  add %2s edx, 48\n", "","");
      printf("%6s  push %2s edx\n", "","");
      printf("%6s  cmp %2s eax, 0\n", "","");
      printf("%6s  jnz %2s divloop\n", "","");

}  
void prinloop(){

      printf("\nprinloop:\n");
      printf("%6s  dec %2s ecx\n", "","");
      printf("%6s  mov %2s eax, esp\n", "","");
      printf("%6s  call %2s sprint\n", "","");
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  cmp %2s ecx, 0\n", "","");
      printf("%6s  jnz %2s prinloop\n", "","");
      printf("%6s  pop %2s esi\n", "","");
      printf("%6s  pop %2s edx\n", "","");
      printf("%6s  pop %2s ecx\n", "","");
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  ret  ","");

}  
void sprint(){

      printf("\nsprint:\n");
      printf("%6s  push %2s edx\n", "","");
      printf("%6s  push %2s ecx\n", "","");
      printf("%6s  push %2s ebx\n", "","");
      printf("%6s  push %2s eax\n", "","");
      printf("%6s  call %2s slen\n\n", "","");
      printf("%6s  mov %2s edx, eax\n", "","");
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  mov %2s ecx, eax\n", "","");
      printf("%6s  mov %2s ebx, 1\n", "","");
      printf("%6s  mov %2s eax, 4\n", "","");
      printf("%6s  int %2s 80h\n\n", "","");
      printf("%6s  pop %2s ebx\n", "","");
      printf("%6s  pop %2s ecx\n", "","");
      printf("%6s  pop %2s edx\n", "","");
      printf("%6s  ret  ","");

} 

 
void slen(){

      printf("\nslen:\n");
      printf("%6s  push %2s ebx\n", "","");
      printf("%6s  mov %2s ebx, eax\n", "","");
}  
void nextchar(){

      printf("\nnextchar:\n");
      printf("%6s  cmp %2s byte [eax], 0\n", "","");
      printf("%6s  jz %2s finish\n", "","");
      printf("%6s  inc %2s eax\n", "","");
      printf("%6s  jmp %2s nextchar\n", "","");
}  
void finish(){

      printf("\nfinish:\n");
      printf("%6s  sub %2s eax, ebx\n", "","");
      printf("%6s  pop %2s ebx\n", "","");
      printf("%6s  ret\n", "");
}  
void finret(){
      printf("\nfinret:\n");
      printf("%6s  ret\n", "");
}  
