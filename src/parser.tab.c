/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <string>
    #include <queue>
    #include <vector>
    #include <iostream>
    #include <regex>
    #include "token.hpp"
    #include "ast.hpp"
    #include "symbol_table.hpp"
    using namespace std;

    extern int yylex(void);
    extern int yylineno;
    extern int yycolumn;
    extern char *yytext;

    // queues for tokens and errors
    extern queue<string> errors;
    queue<string> st_errors;
    vector<Token*> detectedTokens;
    
    void yyerror(const char *s);
    void redeclared_variable_error(string id);
    bool check_id_exists(string id);
    
    regex extension("(.*)\\.eula");

    NodeStart* root_ast;
    sym_table st;

#line 102 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_DOT = 5,                        /* DOT  */
  YYSYMBOL_DTWODOTS = 6,                   /* DTWODOTS  */
  YYSYMBOL_SOFORTH = 7,                    /* SOFORTH  */
  YYSYMBOL_ASSIGN = 8,                     /* ASSIGN  */
  YYSYMBOL_LET = 9,                        /* LET  */
  YYSYMBOL_TINT = 10,                      /* TINT  */
  YYSYMBOL_TBOOL = 11,                     /* TBOOL  */
  YYSYMBOL_TFLOAT = 12,                    /* TFLOAT  */
  YYSYMBOL_TCHAR = 13,                     /* TCHAR  */
  YYSYMBOL_TSTR = 14,                      /* TSTR  */
  YYSYMBOL_TSTRUCT = 15,                   /* TSTRUCT  */
  YYSYMBOL_TUNION = 16,                    /* TUNION  */
  YYSYMBOL_TLIST = 17,                     /* TLIST  */
  YYSYMBOL_TILDE = 18,                     /* TILDE  */
  YYSYMBOL_DEREF = 19,                     /* DEREF  */
  YYSYMBOL_ROOF = 20,                      /* ROOF  */
  YYSYMBOL_FUNC = 21,                      /* FUNC  */
  YYSYMBOL_PROC = 22,                      /* PROC  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELIF = 24,                      /* ELIF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_IN = 27,                        /* IN  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_PRINT = 30,                     /* PRINT  */
  YYSYMBOL_INPUT = 31,                     /* INPUT  */
  YYSYMBOL_NEW = 32,                       /* NEW  */
  YYSYMBOL_VENGEANCE = 33,                 /* VENGEANCE  */
  YYSYMBOL_OCURLYBRACKET = 34,             /* OCURLYBRACKET  */
  YYSYMBOL_CCURLYBRACKET = 35,             /* CCURLYBRACKET  */
  YYSYMBOL_OBRACKET = 36,                  /* OBRACKET  */
  YYSYMBOL_CBRACKET = 37,                  /* CBRACKET  */
  YYSYMBOL_OPAR = 38,                      /* OPAR  */
  YYSYMBOL_CPAR = 39,                      /* CPAR  */
  YYSYMBOL_ADD = 40,                       /* ADD  */
  YYSYMBOL_SUB = 41,                       /* SUB  */
  YYSYMBOL_MUL = 42,                       /* MUL  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_MOD = 44,                       /* MOD  */
  YYSYMBOL_POW = 45,                       /* POW  */
  YYSYMBOL_PLUSPLUS = 46,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 47,                /* MINUSMINUS  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_OR = 49,                        /* OR  */
  YYSYMBOL_AND = 50,                       /* AND  */
  YYSYMBOL_EQUALS = 51,                    /* EQUALS  */
  YYSYMBOL_NEQUALS = 52,                   /* NEQUALS  */
  YYSYMBOL_GREATER = 53,                   /* GREATER  */
  YYSYMBOL_LESS = 54,                      /* LESS  */
  YYSYMBOL_GEQ = 55,                       /* GEQ  */
  YYSYMBOL_LEQ = 56,                       /* LEQ  */
  YYSYMBOL_BREAK = 57,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_NUMBER = 59,                    /* NUMBER  */
  YYSYMBOL_DECIMAL = 60,                   /* DECIMAL  */
  YYSYMBOL_ID = 61,                        /* ID  */
  YYSYMBOL_CHAR = 62,                      /* CHAR  */
  YYSYMBOL_STRING = 63,                    /* STRING  */
  YYSYMBOL_TRUE = 64,                      /* TRUE  */
  YYSYMBOL_FALSE = 65,                     /* FALSE  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_Start = 67,                     /* Start  */
  YYSYMBOL_Inst = 68,                      /* Inst  */
  YYSYMBOL_InstAux = 69,                   /* InstAux  */
  YYSYMBOL_Action = 70,                    /* Action  */
  YYSYMBOL_FuncBody = 71,                  /* FuncBody  */
  YYSYMBOL_Definition = 72,                /* Definition  */
  YYSYMBOL_Type = 73,                      /* Type  */
  YYSYMBOL_TypeAux = 74,                   /* TypeAux  */
  YYSYMBOL_TypePrimitive = 75,             /* TypePrimitive  */
  YYSYMBOL_TypeComposite = 76,             /* TypeComposite  */
  YYSYMBOL_VarInst = 77,                   /* VarInst  */
  YYSYMBOL_VarDef = 78,                    /* VarDef  */
  YYSYMBOL_OptAssign = 79,                 /* OptAssign  */
  YYSYMBOL_Assign = 80,                    /* Assign  */
  YYSYMBOL_RValue = 81,                    /* RValue  */
  YYSYMBOL_InputType = 82,                 /* InputType  */
  YYSYMBOL_OptExp = 83,                    /* OptExp  */
  YYSYMBOL_Exp = 84,                       /* Exp  */
  YYSYMBOL_LValue = 85,                    /* LValue  */
  YYSYMBOL_FuncSignature = 86,             /* FuncSignature  */
  YYSYMBOL_DefFunc = 87,                   /* DefFunc  */
  YYSYMBOL_Func = 88,                      /* Func  */
  YYSYMBOL_FuncPar = 89,                   /* FuncPar  */
  YYSYMBOL_ParList = 90,                   /* ParList  */
  YYSYMBOL_OptRoof = 91,                   /* OptRoof  */
  YYSYMBOL_CallFunc = 92,                  /* CallFunc  */
  YYSYMBOL_ArgElems = 93,                  /* ArgElems  */
  YYSYMBOL_ArgList = 94,                   /* ArgList  */
  YYSYMBOL_DefProc = 95,                   /* DefProc  */
  YYSYMBOL_Proc = 96,                      /* Proc  */
  YYSYMBOL_Array = 97,                     /* Array  */
  YYSYMBOL_ArrExp = 98,                    /* ArrExp  */
  YYSYMBOL_ArrElems = 99,                  /* ArrElems  */
  YYSYMBOL_DefUnion = 100,                 /* DefUnion  */
  YYSYMBOL_Union = 101,                    /* Union  */
  YYSYMBOL_UnionBody = 102,                /* UnionBody  */
  YYSYMBOL_DefStruct = 103,                /* DefStruct  */
  YYSYMBOL_Struct = 104,                   /* Struct  */
  YYSYMBOL_StructBody = 105,               /* StructBody  */
  YYSYMBOL_Selection = 106,                /* Selection  */
  YYSYMBOL_If = 107,                       /* If  */
  YYSYMBOL_OptElif = 108,                  /* OptElif  */
  YYSYMBOL_Elif = 109,                     /* Elif  */
  YYSYMBOL_OptElse = 110,                  /* OptElse  */
  YYSYMBOL_Else = 111,                     /* Else  */
  YYSYMBOL_For = 112,                      /* For  */
  YYSYMBOL_LoopFor = 113,                  /* LoopFor  */
  YYSYMBOL_IdFor = 114,                    /* IdFor  */
  YYSYMBOL_Range = 115,                    /* Range  */
  YYSYMBOL_While = 116,                    /* While  */
  YYSYMBOL_LoopWhile = 117                 /* LoopWhile  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   742

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   257


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   153,   153,   154,   156,   157,   159,   160,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   181,   191,
     193,   194,   196,   197,   198,   199,   200,   204,   205,   206,
     207,   210,   211,   214,   215,   216,   217,   220,   221,   225,
     226,   228,   231,   232,   234,   236,   237,   238,   239,   241,
     242,   244,   245,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   277,
     279,   280,   282,   286,   288,   291,   296,   297,   300,   302,
     306,   307,   310,   314,   315,   318,   319,   323,   326,   332,
     335,   336,   339,   340,   344,   349,   352,   354,   359,   363,
     366,   367,   371,   373,   376,   377,   379,   382,   383,   385,
     389,   391,   393,   397,   398,   402,   404
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "DOT", "DTWODOTS", "SOFORTH", "ASSIGN", "LET", "TINT", "TBOOL", "TFLOAT",
  "TCHAR", "TSTR", "TSTRUCT", "TUNION", "TLIST", "TILDE", "DEREF", "ROOF",
  "FUNC", "PROC", "IF", "ELIF", "ELSE", "FOR", "IN", "WHILE", "RETURN",
  "PRINT", "INPUT", "NEW", "VENGEANCE", "OCURLYBRACKET", "CCURLYBRACKET",
  "OBRACKET", "CBRACKET", "OPAR", "CPAR", "ADD", "SUB", "MUL", "DIV",
  "MOD", "POW", "PLUSPLUS", "MINUSMINUS", "NOT", "OR", "AND", "EQUALS",
  "NEQUALS", "GREATER", "LESS", "GEQ", "LEQ", "BREAK", "CONTINUE",
  "NUMBER", "DECIMAL", "ID", "CHAR", "STRING", "TRUE", "FALSE", "$accept",
  "Start", "Inst", "InstAux", "Action", "FuncBody", "Definition", "Type",
  "TypeAux", "TypePrimitive", "TypeComposite", "VarInst", "VarDef",
  "OptAssign", "Assign", "RValue", "InputType", "OptExp", "Exp", "LValue",
  "FuncSignature", "DefFunc", "Func", "FuncPar", "ParList", "OptRoof",
  "CallFunc", "ArgElems", "ArgList", "DefProc", "Proc", "Array", "ArrExp",
  "ArrElems", "DefUnion", "Union", "UnionBody", "DefStruct", "Struct",
  "StructBody", "Selection", "If", "OptElif", "Elif", "OptElse", "Else",
  "For", "LoopFor", "IdFor", "Range", "While", "LoopWhile", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63
};
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     445,    -7,  -124,  -124,  -124,  -124,  -124,  -124,   -10,   -40,
    -124,  -124,  -124,   239,   -15,   -10,    27,    30,    -6,    25,
     445,  -124,  -124,  -124,    15,    32,  -124,  -124,    23,  -124,
    -124,     8,    35,  -124,     9,  -124,   -19,  -124,   -11,  -124,
      11,  -124,    20,  -124,    41,  -124,    42,  -124,    -9,     1,
    -124,  -124,  -124,    56,  -124,   239,   239,   239,  -124,  -124,
      63,  -124,  -124,  -124,  -124,   109,    24,  -124,   239,    21,
    -124,  -124,   497,    65,    77,  -124,  -124,    43,  -124,    46,
     497,   239,    -7,  -124,    -7,    75,    79,   239,    50,   239,
      -7,   106,  -124,   239,   574,    40,    22,  -124,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   592,  -124,    81,    -7,   497,  -124,   663,
      76,   113,  -124,  -124,  -124,    88,  -124,  -124,   499,    98,
      89,   127,    99,   128,   130,   610,  -124,   114,   628,   103,
     497,  -124,   529,  -124,    40,    40,   100,   100,   100,   100,
     680,   680,    80,    80,   686,   686,   686,   686,   439,   140,
     239,  -124,  -124,   470,   107,   142,  -124,   497,    -7,  -124,
    -124,    86,   121,    -7,   122,    -7,     4,   154,    13,   132,
     527,   133,  -124,  -124,  -124,   239,  -124,   131,   663,   239,
    -124,   497,  -124,   135,  -124,   445,    98,   445,   108,    -7,
    -124,  -124,  -124,   168,   445,   663,  -124,   136,   445,   556,
     166,   663,  -124,   173,   445,   143,   118,   145,   178,   123,
    -124,   260,   148,   297,  -124,    60,  -124,  -124,  -124,  -124,
    -124,   180,   161,   445,  -124,  -124,  -124,  -124,  -124,  -124,
     162,   150,   334,  -124,  -124,   152,   239,  -124,   445,   646,
     371,   156,  -124,   445,   408,   161,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    35,    33,    36,    34,   109,   105,     0,     0,
     113,   121,   126,     0,     0,     0,     0,     0,    79,     0,
       2,     4,     6,     7,     0,     0,    39,    40,     0,    26,
      25,     0,     0,    24,     0,    22,     0,    23,     0,    10,
       0,    12,     0,    11,     0,    37,     0,    38,     0,    27,
      31,    32,    79,    82,    98,     0,     0,     0,    53,    54,
      79,    58,    59,    56,    57,     0,    55,    60,     0,     0,
      16,    15,    94,     0,     0,     1,     5,     0,     8,     0,
       0,     0,    87,     9,    87,     0,     0,     0,     0,     0,
       0,    43,    30,     0,     0,    66,    77,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,    95,    45,
       0,    93,    46,    17,    18,     0,    81,    44,     0,    91,
       0,    86,     0,     0,     0,     0,   122,     0,     0,     0,
       0,    41,     0,    68,    61,    62,    63,    64,    65,    67,
      70,    69,    71,    72,    73,    74,    75,    76,     0,     0,
      52,    47,   103,    45,     0,   100,    92,     0,    87,    80,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    42,    29,     0,    14,     0,    51,     0,
      99,     0,    96,     0,    89,    21,    91,    21,     0,     0,
     104,   110,   108,     0,     0,   123,   124,     0,     0,     0,
       0,   101,   102,     0,    20,     0,     0,     0,     0,     0,
     111,     0,     0,     0,    78,     0,    83,    84,    88,    97,
     106,     0,   115,     0,   125,    50,    49,    48,   107,   116,
     118,     0,     0,   119,   112,     0,     0,   120,     0,     0,
       0,     0,   117,     0,     0,   115,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -124,  -124,    12,   -18,  -124,    -5,  -124,    16,  -124,    26,
    -124,  -124,  -123,  -124,  -124,   -64,  -124,  -124,   -12,     0,
    -124,  -124,  -124,   -66,  -124,    -3,    14,  -124,  -124,  -124,
    -124,    18,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,   -55,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,   214,    21,    22,   215,    23,   129,    49,    24,
      51,    25,    26,   141,    27,   118,   237,   187,   119,    66,
      29,    30,    31,   130,   131,   171,    67,   120,   121,    33,
      34,   122,   164,   165,    35,    36,   176,    37,    38,   178,
      39,    40,   240,   241,   244,   245,    41,    42,   137,   207,
      43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    65,    76,     2,     3,     4,     5,    45,    53,     8,
      46,   177,    20,   199,    32,    69,   127,    48,   132,    92,
      28,    54,     1,    68,   114,    75,    79,    50,    79,    79,
      70,    80,    72,    71,    32,    78,    77,    93,    83,   200,
      73,    74,    85,    94,    95,    96,    82,    84,   202,    87,
      86,    52,    91,   162,    47,   203,   113,    81,    88,    81,
     112,    79,    98,    99,   100,   101,   102,   103,   123,   128,
       2,     3,     4,     5,   235,   135,   183,   138,    90,    89,
     124,   142,   100,   101,   102,   103,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    72,   193,   192,   125,   163,   139,   126,    50,   133,
      50,   136,    97,   134,   140,   166,    50,   167,   170,   160,
      98,    99,   100,   101,   102,   103,   168,   212,   172,   104,
     105,   173,   161,   108,   109,   110,   111,   175,   174,     1,
     182,   180,    50,   186,   190,   103,   191,   194,   188,    98,
      99,   100,   101,   102,   103,   195,   197,   201,   104,   105,
     106,   107,   108,   109,   110,   111,   204,   208,   205,   218,
     210,   220,   225,   209,   213,   222,   226,   211,   227,   228,
     229,   230,   233,   238,   231,   239,   248,   243,   246,   196,
     253,   198,   217,   216,    50,    28,    76,    28,   206,    50,
     256,    50,     0,    76,    28,    76,     0,     0,    28,    32,
       0,    32,     0,     0,    28,   219,   221,     0,    32,     0,
     223,    28,    32,    28,    76,    50,     0,     0,    32,     0,
       0,     0,    76,    28,   249,    32,    76,    32,     0,     0,
       0,     0,    28,     0,     0,   242,     0,    32,    28,     0,
      28,   236,     0,    28,    28,     0,    32,     0,     8,     0,
     250,     0,    32,     0,    32,   254,     0,    32,    32,     1,
       2,     3,     4,     5,     0,     6,     7,    55,     0,     8,
      56,     0,     9,    10,     0,     0,    11,    57,    12,    13,
      14,     0,     0,    15,     0,   232,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     0,     1,     2,     3,     4,
       5,     0,     6,     7,     0,     0,     8,    16,    17,     9,
      10,    18,     0,    11,     0,    12,    13,    14,     0,     0,
      15,     0,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,     6,
       7,     0,     0,     8,    16,    17,     9,    10,    18,     0,
      11,     0,    12,    13,    14,     0,     0,    15,     0,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     0,     6,     7,     0,     0,
       8,    16,    17,     9,    10,    18,     0,    11,     0,    12,
      13,    14,     0,     0,    15,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     0,     6,     7,     0,     0,     8,    16,    17,
       9,    10,    18,     0,    11,     0,    12,    13,    14,     0,
       0,    15,     0,   255,     0,     0,   185,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     0,
       6,     7,     0,     0,     8,    16,    17,     9,    10,    18,
       0,    11,     0,    12,    13,    14,   169,   189,    15,    98,
      99,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    18,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     8,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   115,   116,
       0,     0,     0,   117,     0,    55,   169,     0,    56,    98,
      99,   100,   101,   102,   103,    57,     8,     0,   104,   105,
     106,   107,   108,   109,   110,   111,    58,    59,    60,    61,
      62,    63,    64,   117,     0,    55,   184,     0,    56,    98,
      99,   100,   101,   102,   103,    57,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,    58,    59,    60,    61,
      62,    63,    64,   224,     0,     0,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,   143,    98,    99,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   159,    98,    99,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   111,   179,
      98,    99,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,   111,   181,    98,    99,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   251,    98,    99,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,   111,    98,    99,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
      98,    99,   100,   101,   102,   103,    98,    99,   100,   101,
     102,   103,     0,   108,   109,   110,   111,     0,     0,    -1,
      -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
       0,    13,    20,    10,    11,    12,    13,    14,     8,    19,
      17,   134,     0,     9,     0,    15,    80,     1,    84,    18,
      20,    61,     9,    38,     3,     0,     5,     1,     5,     5,
       3,     8,    38,     3,    20,     3,    21,    36,     3,    35,
      46,    47,    61,    55,    56,    57,    38,    38,    35,    38,
      61,    61,    61,   117,    61,   178,    68,    36,    38,    36,
      36,     5,    40,    41,    42,    43,    44,    45,     3,    81,
      10,    11,    12,    13,    14,    87,   140,    89,    36,    38,
       3,    93,    42,    43,    44,    45,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    38,   168,   167,    61,   117,    90,    61,    82,    34,
      84,    61,     3,    34,     8,    39,    90,     4,    20,    38,
      40,    41,    42,    43,    44,    45,    38,   191,    39,    49,
      50,     4,   116,    53,    54,    55,    56,     9,    39,     9,
      37,    27,   116,     3,    37,    45,     4,    61,   160,    40,
      41,    42,    43,    44,    45,    34,    34,     3,    49,    50,
      51,    52,    53,    54,    55,    56,    34,    34,   180,    61,
      39,     3,     6,   185,    39,    39,     3,   189,    35,    61,
      35,     3,    34,     3,    61,    24,    34,    25,    38,   173,
      34,   175,   197,   196,   168,   195,   214,   197,   180,   173,
     255,   175,    -1,   221,   204,   223,    -1,    -1,   208,   195,
      -1,   197,    -1,    -1,   214,   199,   204,    -1,   204,    -1,
     208,   221,   208,   223,   242,   199,    -1,    -1,   214,    -1,
      -1,    -1,   250,   233,   246,   221,   254,   223,    -1,    -1,
      -1,    -1,   242,    -1,    -1,   233,    -1,   233,   248,    -1,
     250,   225,    -1,   253,   254,    -1,   242,    -1,    19,    -1,
     248,    -1,   248,    -1,   250,   253,    -1,   253,   254,     9,
      10,    11,    12,    13,    -1,    15,    16,    38,    -1,    19,
      41,    -1,    22,    23,    -1,    -1,    26,    48,    28,    29,
      30,    -1,    -1,    33,    -1,    35,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    -1,     9,    10,    11,    12,
      13,    -1,    15,    16,    -1,    -1,    19,    57,    58,    22,
      23,    61,    -1,    26,    -1,    28,    29,    30,    -1,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,    15,
      16,    -1,    -1,    19,    57,    58,    22,    23,    61,    -1,
      26,    -1,    28,    29,    30,    -1,    -1,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    13,    -1,    15,    16,    -1,    -1,
      19,    57,    58,    22,    23,    61,    -1,    26,    -1,    28,
      29,    30,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    -1,    15,    16,    -1,    -1,    19,    57,    58,
      22,    23,    61,    -1,    26,    -1,    28,    29,    30,    -1,
      -1,    33,    -1,    35,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,
      15,    16,    -1,    -1,    19,    57,    58,    22,    23,    61,
      -1,    26,    -1,    28,    29,    30,    37,     7,    33,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    19,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    31,    32,
      -1,    -1,    -1,    36,    -1,    38,    37,    -1,    41,    40,
      41,    42,    43,    44,    45,    48,    19,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    59,    60,    61,    62,
      63,    64,    65,    36,    -1,    38,    37,    -1,    41,    40,
      41,    42,    43,    44,    45,    48,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    59,    60,    61,    62,
      63,    64,    65,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      40,    41,    42,    43,    44,    45,    40,    41,    42,    43,
      44,    45,    -1,    53,    54,    55,    56,    -1,    -1,    53,
      54,    55,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    15,    16,    19,    22,
      23,    26,    28,    29,    30,    33,    57,    58,    61,    67,
      68,    69,    70,    72,    75,    77,    78,    80,    85,    86,
      87,    88,    92,    95,    96,   100,   101,   103,   104,   106,
     107,   112,   113,   116,   117,    14,    17,    61,    73,    74,
      75,    76,    61,    85,    61,    38,    41,    48,    59,    60,
      61,    62,    63,    64,    65,    84,    85,    92,    38,    85,
       3,     3,    38,    46,    47,     0,    69,    21,     3,     5,
       8,    36,    38,     3,    38,    61,    61,    38,    38,    38,
      36,    61,    18,    36,    84,    84,    84,     3,    40,    41,
      42,    43,    44,    45,    49,    50,    51,    52,    53,    54,
      55,    56,    36,    84,     3,    31,    32,    36,    81,    84,
      93,    94,    97,     3,     3,    61,    61,    81,    84,    73,
      89,    90,    89,    34,    34,    84,    61,   114,    84,    73,
       8,    79,    84,    39,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    39,
      38,    73,    81,    84,    98,    99,    39,     4,    38,    37,
      20,    91,    39,     4,    39,     9,   102,    78,   105,    39,
      27,    39,    37,    81,    37,     7,     3,    83,    84,     7,
      37,     4,    81,    89,    61,    34,    73,    34,    73,     9,
      35,     3,    35,    78,    34,    84,    97,   115,    34,    84,
      39,    84,    81,    39,    68,    71,    91,    71,    61,    73,
       3,    68,    39,    68,    37,     6,     3,    35,    61,    35,
       3,    61,    35,    34,    35,    14,    75,    82,     3,    24,
     108,   109,    68,    25,   110,   111,    38,    35,    34,    84,
      68,    39,    35,    34,    68,    35,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    79,    79,    80,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    86,    87,    88,    89,    89,    90,    90,
      91,    91,    92,    93,    93,    94,    94,    95,    96,    97,
      98,    98,    99,    99,   100,   101,   102,   102,   103,   104,
     105,   105,   106,   107,   108,   108,   109,   110,   110,   111,
     112,   113,   114,   115,   115,   116,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     3,     5,     2,     2,     3,     3,     3,
       1,     0,     1,     1,     1,     1,     1,     1,     4,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     0,     3,     1,     1,     2,     6,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     6,     1,
       4,     3,     2,     7,     7,     3,     1,     0,     5,     3,
       1,     0,     4,     1,     0,     1,     3,     7,     2,     3,
       1,     3,     3,     1,     5,     1,     4,     5,     5,     1,
       2,     3,     9,     1,     8,     0,     1,     4,     0,     1,
       9,     1,     1,     1,     1,     7,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          goto yyexhaustedlab;                                          \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}





/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* Start: Inst  */
#line 153 "parser.y"
                                      { (yyval.ns) = new NodeStart((yyvsp[0].ast)); root_ast = (yyval.ns);}
#line 1821 "parser.tab.c"
    break;

  case 3: /* Start: %empty  */
#line 154 "parser.y"
                                      { (yyval.ns) = NULL; }
#line 1827 "parser.tab.c"
    break;

  case 4: /* Inst: InstAux  */
#line 156 "parser.y"
                                      { (yyval.ast) = new NodeInst((yyvsp[0].ast)); }
#line 1833 "parser.tab.c"
    break;

  case 5: /* Inst: Inst InstAux  */
#line 157 "parser.y"
                                      { (yyval.ast) = new NodeInst((yyvsp[0].ast), (yyvsp[-1].ast)); }
#line 1839 "parser.tab.c"
    break;

  case 6: /* InstAux: Action  */
#line 159 "parser.y"
                                      { (yyval.ast) = (yyvsp[0].ast); }
#line 1845 "parser.tab.c"
    break;

  case 7: /* InstAux: Definition  */
#line 160 "parser.y"
                                          { (yyval.ast) = (yyvsp[0].ast); }
#line 1851 "parser.tab.c"
    break;

  case 8: /* Action: VarInst SEMICOLON  */
#line 162 "parser.y"
                                                { (yyval.ast) = (yyvsp[-1].ast); }
#line 1857 "parser.tab.c"
    break;

  case 9: /* Action: CallFunc SEMICOLON  */
#line 163 "parser.y"
                                                { (yyval.ast) = (yyvsp[-1].ast); }
#line 1863 "parser.tab.c"
    break;

  case 10: /* Action: Selection  */
#line 164 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1869 "parser.tab.c"
    break;

  case 11: /* Action: While  */
#line 165 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1875 "parser.tab.c"
    break;

  case 12: /* Action: For  */
#line 166 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1881 "parser.tab.c"
    break;

  case 13: /* Action: VENGEANCE LValue SEMICOLON  */
#line 167 "parser.y"
                                                { (yyval.ast) = new NodeVengeance((yyvsp[-1].ast)); }
#line 1887 "parser.tab.c"
    break;

  case 14: /* Action: PRINT OPAR Exp CPAR SEMICOLON  */
#line 168 "parser.y"
                                                { (yyval.ast) = new NodePrint((yyvsp[-2].ast)); }
#line 1893 "parser.tab.c"
    break;

  case 15: /* Action: CONTINUE SEMICOLON  */
#line 169 "parser.y"
                                                { (yyval.ast) = new NodeContinue(); }
#line 1899 "parser.tab.c"
    break;

  case 16: /* Action: BREAK SEMICOLON  */
#line 170 "parser.y"
                                                { (yyval.ast) = new NodeBreak(); }
#line 1905 "parser.tab.c"
    break;

  case 17: /* Action: ID PLUSPLUS SEMICOLON  */
#line 171 "parser.y"
                                                { t_type* tipo;
                                                  if (check_id_exists((yyvsp[-2].str))){
                                                    string s = st.lookup((yyvsp[-2].str))->type->name;
                                                    if (s == "int") tipo = new t_type_int();
                                                    else if (s == "float") tipo = new t_type_float();
                                                    else tipo = new t_type_error();
                                                  }
                                                  else tipo = new t_type_error();
                                                  (yyval.ast) = new NodeAssign(new NodeIDLValue((yyvsp[-2].str)), new NodeBinaryOperator(new NodeIDLValue((yyvsp[-2].str)), "+", new NodeINT(1), tipo));
                                                }
#line 1920 "parser.tab.c"
    break;

  case 18: /* Action: ID MINUSMINUS SEMICOLON  */
#line 181 "parser.y"
                                                { t_type* tipo;
                                                  if (check_id_exists((yyvsp[-2].str))){
                                                    string s = st.lookup((yyvsp[-2].str))->type->name;
                                                    if (s == "int") tipo = new t_type_int();
                                                    else if (s == "float") tipo = new t_type_float();
                                                    else tipo = new t_type_error();
                                                  }
                                                  else tipo = new t_type_error();
                                                  (yyval.ast) = new NodeAssign(new NodeIDLValue((yyvsp[-2].str)), new NodeBinaryOperator(new NodeIDLValue((yyvsp[-2].str)), "-", new NodeINT(1), tipo));
                                                }
#line 1935 "parser.tab.c"
    break;

  case 19: /* Action: RETURN Exp SEMICOLON  */
#line 191 "parser.y"
                                                { (yyval.ast) = new NodeReturn((yyvsp[-1].ast)); }
#line 1941 "parser.tab.c"
    break;

  case 20: /* FuncBody: Inst  */
#line 193 "parser.y"
                                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1947 "parser.tab.c"
    break;

  case 21: /* FuncBody: %empty  */
#line 194 "parser.y"
                                        { (yyval.ast) = NULL; }
#line 1953 "parser.tab.c"
    break;

  case 22: /* Definition: DefUnion  */
#line 196 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1959 "parser.tab.c"
    break;

  case 23: /* Definition: DefStruct  */
#line 197 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1965 "parser.tab.c"
    break;

  case 24: /* Definition: DefProc  */
#line 198 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1971 "parser.tab.c"
    break;

  case 25: /* Definition: DefFunc  */
#line 199 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1977 "parser.tab.c"
    break;

  case 26: /* Definition: FuncSignature  */
#line 200 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1983 "parser.tab.c"
    break;

  case 27: /* Type: TypeAux  */
#line 204 "parser.y"
                                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1989 "parser.tab.c"
    break;

  case 28: /* Type: TLIST OBRACKET Type CBRACKET  */
#line 205 "parser.y"
                                                        { (yyval.ast) = new NodeTypeList((yyvsp[-1].ast));}
#line 1995 "parser.tab.c"
    break;

  case 29: /* Type: TypeAux OBRACKET Exp CBRACKET  */
#line 206 "parser.y"
                                                        { (yyval.ast) = new NodeTypeArrayDef((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2001 "parser.tab.c"
    break;

  case 30: /* Type: TypeAux TILDE  */
#line 207 "parser.y"
                                                            { (yyval.ast) = new NodeTypePointerDef((yyvsp[-1].ast)); }
#line 2007 "parser.tab.c"
    break;

  case 31: /* TypeAux: TypePrimitive  */
#line 210 "parser.y"
                                                   { (yyval.ast) = (yyvsp[0].ast); }
#line 2013 "parser.tab.c"
    break;

  case 32: /* TypeAux: TypeComposite  */
#line 211 "parser.y"
                                                   { (yyval.ast) = (yyvsp[0].ast); }
#line 2019 "parser.tab.c"
    break;

  case 33: /* TypePrimitive: TBOOL  */
#line 214 "parser.y"
                                                   { (yyval.ast) = new NodeTypePrimitiveDef(new t_type_bool()); }
#line 2025 "parser.tab.c"
    break;

  case 34: /* TypePrimitive: TCHAR  */
#line 215 "parser.y"
                                                   { (yyval.ast) = new NodeTypePrimitiveDef(new t_type_char()); }
#line 2031 "parser.tab.c"
    break;

  case 35: /* TypePrimitive: TINT  */
#line 216 "parser.y"
                                                   { (yyval.ast) = new NodeTypePrimitiveDef(new t_type_int()); }
#line 2037 "parser.tab.c"
    break;

  case 36: /* TypePrimitive: TFLOAT  */
#line 217 "parser.y"
                                                   { (yyval.ast) = new NodeTypePrimitiveDef(new t_type_float()); }
#line 2043 "parser.tab.c"
    break;

  case 37: /* TypeComposite: TSTR  */
#line 220 "parser.y"
                                                   { (yyval.ast) = new NodeTypePrimitiveDef(new t_type_str()); }
#line 2049 "parser.tab.c"
    break;

  case 38: /* TypeComposite: ID  */
#line 221 "parser.y"
                                                   { (yyval.ast) = new NodeTypePrimitiveDef(new t_type((yyvsp[0].str))); }
#line 2055 "parser.tab.c"
    break;

  case 39: /* VarInst: VarDef  */
#line 225 "parser.y"
                                          { (yyval.ast) = (yyvsp[0].ast); }
#line 2061 "parser.tab.c"
    break;

  case 40: /* VarInst: Assign  */
#line 226 "parser.y"
                                              { (yyval.ast) = (yyvsp[0].ast); }
#line 2067 "parser.tab.c"
    break;

  case 41: /* VarDef: LET Type ID OptAssign  */
#line 228 "parser.y"
                                          { (yyval.ast) = new NodeVarDef((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));
                                            if(!st.insert((yyvsp[-1].str),"var",(yyvsp[-2].ast)->return_type(), (yyvsp[0].ast) != NULL )) redeclared_variable_error((yyvsp[-1].str));}
#line 2074 "parser.tab.c"
    break;

  case 42: /* OptAssign: ASSIGN RValue  */
#line 231 "parser.y"
                                          { (yyval.ast) = (yyvsp[0].ast); }
#line 2080 "parser.tab.c"
    break;

  case 43: /* OptAssign: %empty  */
#line 232 "parser.y"
                                              { (yyval.ast) = NULL; }
#line 2086 "parser.tab.c"
    break;

  case 44: /* Assign: LValue ASSIGN RValue  */
#line 234 "parser.y"
                                          { (yyval.ast) = new NodeAssign((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2092 "parser.tab.c"
    break;

  case 45: /* RValue: Exp  */
#line 236 "parser.y"
                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 2098 "parser.tab.c"
    break;

  case 46: /* RValue: Array  */
#line 237 "parser.y"
                                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 2104 "parser.tab.c"
    break;

  case 47: /* RValue: NEW Type  */
#line 238 "parser.y"
                                                                { (yyval.ast) = new NodeNew((yyvsp[0].ast)); }
#line 2110 "parser.tab.c"
    break;

  case 48: /* RValue: INPUT OPAR OptExp CPAR DTWODOTS InputType  */
#line 239 "parser.y"
                                                                { (yyval.ast) = new NodeInput((yyvsp[0].ast), (yyvsp[-3].ast)); }
#line 2116 "parser.tab.c"
    break;

  case 49: /* InputType: TypePrimitive  */
#line 241 "parser.y"
                                { (yyval.ast) = (yyvsp[0].ast); }
#line 2122 "parser.tab.c"
    break;

  case 50: /* InputType: TSTR  */
#line 242 "parser.y"
                                { (yyval.ast) = new NodeTypePrimitiveDef(new t_type_str()); }
#line 2128 "parser.tab.c"
    break;

  case 51: /* OptExp: Exp  */
#line 244 "parser.y"
                                     { (yyval.ast) = (yyvsp[0].ast); }
#line 2134 "parser.tab.c"
    break;

  case 52: /* OptExp: %empty  */
#line 245 "parser.y"
                                     { (yyval.ast) = NULL; }
#line 2140 "parser.tab.c"
    break;

  case 53: /* Exp: NUMBER  */
#line 248 "parser.y"
                                     { (yyval.ast) = new NodeINT((yyvsp[0].integer)); }
#line 2146 "parser.tab.c"
    break;

  case 54: /* Exp: DECIMAL  */
#line 249 "parser.y"
                                     { (yyval.ast) = new NodeFLOAT((yyvsp[0].flot)); }
#line 2152 "parser.tab.c"
    break;

  case 55: /* Exp: LValue  */
#line 250 "parser.y"
                                     { (yyval.ast) = (yyvsp[0].ast); }
#line 2158 "parser.tab.c"
    break;

  case 56: /* Exp: TRUE  */
#line 251 "parser.y"
                                     { (yyval.ast) = new NodeBOOL(true); }
#line 2164 "parser.tab.c"
    break;

  case 57: /* Exp: FALSE  */
#line 252 "parser.y"
                                     { (yyval.ast) = new NodeBOOL(false); }
#line 2170 "parser.tab.c"
    break;

  case 58: /* Exp: CHAR  */
#line 253 "parser.y"
                                     { (yyval.ast) = new NodeCHAR((yyvsp[0].ch)); }
#line 2176 "parser.tab.c"
    break;

  case 59: /* Exp: STRING  */
#line 254 "parser.y"
                                     { (yyval.ast) = new NodeSTRING((yyvsp[0].str)); }
#line 2182 "parser.tab.c"
    break;

  case 60: /* Exp: CallFunc  */
#line 255 "parser.y"
                                     { (yyval.ast) = (yyvsp[0].ast); }
#line 2188 "parser.tab.c"
    break;

  case 61: /* Exp: Exp ADD Exp  */
#line 256 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2194 "parser.tab.c"
    break;

  case 62: /* Exp: Exp SUB Exp  */
#line 257 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2200 "parser.tab.c"
    break;

  case 63: /* Exp: Exp MUL Exp  */
#line 258 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2206 "parser.tab.c"
    break;

  case 64: /* Exp: Exp DIV Exp  */
#line 259 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2212 "parser.tab.c"
    break;

  case 65: /* Exp: Exp MOD Exp  */
#line 260 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2218 "parser.tab.c"
    break;

  case 66: /* Exp: SUB Exp  */
#line 261 "parser.y"
                                     { (yyval.ast) = new NodeUnaryOperator((yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2224 "parser.tab.c"
    break;

  case 67: /* Exp: Exp POW Exp  */
#line 262 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2230 "parser.tab.c"
    break;

  case 68: /* Exp: OPAR Exp CPAR  */
#line 263 "parser.y"
                                     { (yyval.ast) = (yyvsp[-1].ast); }
#line 2236 "parser.tab.c"
    break;

  case 69: /* Exp: Exp AND Exp  */
#line 264 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2242 "parser.tab.c"
    break;

  case 70: /* Exp: Exp OR Exp  */
#line 265 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2248 "parser.tab.c"
    break;

  case 71: /* Exp: Exp EQUALS Exp  */
#line 266 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2254 "parser.tab.c"
    break;

  case 72: /* Exp: Exp NEQUALS Exp  */
#line 267 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2260 "parser.tab.c"
    break;

  case 73: /* Exp: Exp GREATER Exp  */
#line 268 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2266 "parser.tab.c"
    break;

  case 74: /* Exp: Exp LESS Exp  */
#line 269 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2272 "parser.tab.c"
    break;

  case 75: /* Exp: Exp GEQ Exp  */
#line 270 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2278 "parser.tab.c"
    break;

  case 76: /* Exp: Exp LEQ Exp  */
#line 271 "parser.y"
                                     { (yyval.ast) = new NodeBinaryOperator((yyvsp[-2].ast), (yyvsp[-1].str), (yyvsp[0].ast));; }
#line 2284 "parser.tab.c"
    break;

  case 77: /* Exp: NOT Exp  */
#line 272 "parser.y"
                                     { (yyval.ast) = new NodeUnaryOperator((yyvsp[-1].str), (yyvsp[0].ast)); }
#line 2290 "parser.tab.c"
    break;

  case 78: /* Exp: LValue OBRACKET Exp SOFORTH Exp CBRACKET  */
#line 273 "parser.y"
                                                            { (yyval.ast) = new NodeSubArray((yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2296 "parser.tab.c"
    break;

  case 79: /* LValue: ID  */
#line 277 "parser.y"
                                               { check_id_exists((yyvsp[0].str));
                                                (yyval.ast) = new NodeIDLValue((yyvsp[0].str)); }
#line 2303 "parser.tab.c"
    break;

  case 80: /* LValue: LValue OBRACKET Exp CBRACKET  */
#line 279 "parser.y"
                                               { (yyval.ast) = new NodeArrayLValue((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2309 "parser.tab.c"
    break;

  case 81: /* LValue: LValue DOT ID  */
#line 280 "parser.y"
                                               { check_id_exists((yyvsp[0].str));
                                                  (yyval.ast) = new NodeLValueDot((yyvsp[-2].ast), (yyvsp[0].str)); }
#line 2316 "parser.tab.c"
    break;

  case 82: /* LValue: DEREF LValue  */
#line 282 "parser.y"
                                               { (yyval.ast) = new NodePointerLValue((yyvsp[0].ast)); }
#line 2322 "parser.tab.c"
    break;

  case 83: /* FuncSignature: TypePrimitive FUNC ID OPAR FuncPar CPAR SEMICOLON  */
#line 286 "parser.y"
                                                                  { if(!st.insert((yyvsp[-4].str),"func", (yyvsp[-6].ast)->return_type(),false)) redeclared_variable_error((yyvsp[-4].str)); (yyval.ast) = new NodeFuncSignature((yyvsp[-4].str),(yyvsp[-2].ast),(yyvsp[-6].ast)); }
#line 2328 "parser.tab.c"
    break;

  case 84: /* DefFunc: Func OPAR FuncPar CPAR OCURLYBRACKET FuncBody CCURLYBRACKET  */
#line 288 "parser.y"
                                                                             { (yyval.ast) = new NodeFuncDef((yyvsp[-6].str), (yyvsp[-4].ast), (yyvsp[-1].ast));
                                                                                                        st.exit_scope(); }
#line 2335 "parser.tab.c"
    break;

  case 85: /* Func: TypePrimitive FUNC ID  */
#line 291 "parser.y"
                                        { if(!st.insert((yyvsp[0].str),"func",(yyvsp[-2].ast)->return_type(),true)) redeclared_variable_error((yyvsp[0].str));
                            st.new_scope();
                            (yyval.str) = (yyvsp[0].str); }
#line 2343 "parser.tab.c"
    break;

  case 86: /* FuncPar: ParList  */
#line 296 "parser.y"
                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 2349 "parser.tab.c"
    break;

  case 87: /* FuncPar: %empty  */
#line 297 "parser.y"
                                        { (yyval.ast) = NULL; }
#line 2355 "parser.tab.c"
    break;

  case 88: /* ParList: ParList COMMA Type OptRoof ID  */
#line 300 "parser.y"
                                                { (yyval.ast) = new NodeRoutineArgsDef((yyvsp[-2].ast), (yyvsp[-1].boolean), (yyvsp[0].str), (yyvsp[-4].ast)); 
                                                  if(!st.insert((yyvsp[0].str), "var", (yyvsp[-2].ast)->return_type(), true)) redeclared_variable_error((yyvsp[0].str));}
#line 2362 "parser.tab.c"
    break;

  case 89: /* ParList: Type OptRoof ID  */
#line 302 "parser.y"
                                                { (yyval.ast) = new NodeRoutineArgsDef((yyvsp[-2].ast), (yyvsp[-1].boolean), (yyvsp[0].str)); 
                                                  if(!st.insert((yyvsp[0].str), "var", (yyvsp[-2].ast)->return_type(), true)) redeclared_variable_error((yyvsp[0].str));}
#line 2369 "parser.tab.c"
    break;

  case 90: /* OptRoof: ROOF  */
#line 306 "parser.y"
                                        { (yyval.boolean) = true; }
#line 2375 "parser.tab.c"
    break;

  case 91: /* OptRoof: %empty  */
#line 307 "parser.y"
                                        { (yyval.boolean) = false; }
#line 2381 "parser.tab.c"
    break;

  case 92: /* CallFunc: ID OPAR ArgElems CPAR  */
#line 310 "parser.y"
                                      { check_id_exists((yyvsp[-3].str));
                                        (yyval.ast) = new NodeCallFunction((yyvsp[-3].str), (yyvsp[-1].ast)); }
#line 2388 "parser.tab.c"
    break;

  case 93: /* ArgElems: ArgList  */
#line 314 "parser.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 2394 "parser.tab.c"
    break;

  case 94: /* ArgElems: %empty  */
#line 315 "parser.y"
                                                    { (yyval.ast) = NULL; }
#line 2400 "parser.tab.c"
    break;

  case 95: /* ArgList: RValue  */
#line 318 "parser.y"
                                                { (yyval.ast) = new NodeCallFunctionArgs((yyvsp[0].ast)); }
#line 2406 "parser.tab.c"
    break;

  case 96: /* ArgList: ArgList COMMA RValue  */
#line 319 "parser.y"
                                                { (yyval.ast) = new NodeCallFunctionArgs((yyvsp[0].ast), (yyvsp[-2].ast)); }
#line 2412 "parser.tab.c"
    break;

  case 97: /* DefProc: Proc OPAR FuncPar CPAR OCURLYBRACKET FuncBody CCURLYBRACKET  */
#line 323 "parser.y"
                                                                            { (yyval.ast) = new NodeProcDef((yyvsp[-6].str), (yyvsp[-4].ast), (yyvsp[-1].ast));
                                                                                 st.exit_scope(); }
#line 2419 "parser.tab.c"
    break;

  case 98: /* Proc: PROC ID  */
#line 326 "parser.y"
                          { if(!st.insert((yyvsp[0].str), "proc", new t_type_no_type(), true)) redeclared_variable_error((yyvsp[0].str));
                            st.new_scope();
                            (yyval.str) = (yyvsp[0].str); }
#line 2427 "parser.tab.c"
    break;

  case 99: /* Array: OBRACKET ArrExp CBRACKET  */
#line 332 "parser.y"
                                           { (yyval.ast) = new NodeArray((yyvsp[-1].ast)); }
#line 2433 "parser.tab.c"
    break;

  case 100: /* ArrExp: ArrElems  */
#line 335 "parser.y"
                                        { (yyval.ast) = (yyvsp[0].ast); }
#line 2439 "parser.tab.c"
    break;

  case 101: /* ArrExp: Exp SOFORTH Exp  */
#line 336 "parser.y"
                                        { (yyval.ast) = new NodeArrayRange((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2445 "parser.tab.c"
    break;

  case 102: /* ArrElems: ArrElems COMMA RValue  */
#line 339 "parser.y"
                                         { (yyval.ast) = new NodeArrayElems((yyvsp[0].ast), (yyvsp[-2].ast)); }
#line 2451 "parser.tab.c"
    break;

  case 103: /* ArrElems: RValue  */
#line 340 "parser.y"
                                                 { (yyval.ast) = new NodeArrayElems((yyvsp[0].ast)); }
#line 2457 "parser.tab.c"
    break;

  case 104: /* DefUnion: Union ID OCURLYBRACKET UnionBody CCURLYBRACKET  */
#line 344 "parser.y"
                                                                 { (yyval.ast) = new NodeUnionDef((yyvsp[-3].str), (yyvsp[-1].ast));
                                                                    st.exit_scope();
                                                                    if(!st.insert((yyvsp[-3].str), "union", new t_type_union(), true)) redeclared_variable_error((yyvsp[-3].str)); }
#line 2465 "parser.tab.c"
    break;

  case 105: /* Union: TUNION  */
#line 349 "parser.y"
                            { st.new_scope(); }
#line 2471 "parser.tab.c"
    break;

  case 106: /* UnionBody: LET Type ID SEMICOLON  */
#line 352 "parser.y"
                                                      { (yyval.ast) = new NodeUnionFields((yyvsp[-1].str), (yyvsp[-2].ast)); 
                                                        if(!st.insert((yyvsp[-1].str), "var", (yyvsp[-2].ast)->return_type(), false)) redeclared_variable_error((yyvsp[-1].str)); }
#line 2478 "parser.tab.c"
    break;

  case 107: /* UnionBody: UnionBody LET Type ID SEMICOLON  */
#line 354 "parser.y"
                                                              { (yyval.ast) = new NodeUnionFields((yyvsp[-1].str), (yyvsp[-2].ast), (yyvsp[-4].ast)); 
                                                        if(!st.insert((yyvsp[-1].str), "var", (yyvsp[-2].ast)->return_type(), false)) redeclared_variable_error((yyvsp[-1].str)); }
#line 2485 "parser.tab.c"
    break;

  case 108: /* DefStruct: Struct ID OCURLYBRACKET StructBody CCURLYBRACKET  */
#line 359 "parser.y"
                                                                 { (yyval.ast) = new NodeStructDef((yyvsp[-3].str), (yyvsp[-1].ast)); 
                                                                    st.exit_scope();
                                                                    if(!st.insert((yyvsp[-3].str), "struct", new t_type_struct(), true)) redeclared_variable_error((yyvsp[-3].str)); }
#line 2493 "parser.tab.c"
    break;

  case 109: /* Struct: TSTRUCT  */
#line 363 "parser.y"
                            { st.new_scope(); }
#line 2499 "parser.tab.c"
    break;

  case 110: /* StructBody: VarDef SEMICOLON  */
#line 366 "parser.y"
                                                { (yyval.ast) = new NodeStructFields((yyvsp[-1].ast)); }
#line 2505 "parser.tab.c"
    break;

  case 111: /* StructBody: StructBody VarDef SEMICOLON  */
#line 367 "parser.y"
                                                        { (yyval.ast) = new NodeStructFields((yyvsp[-1].ast), (yyvsp[-2].ast)); }
#line 2511 "parser.tab.c"
    break;

  case 112: /* Selection: If OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET OptElif OptElse  */
#line 371 "parser.y"
                                                                                  { (yyval.ast) = new NodeConditional((yyvsp[-6].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast)); st.exit_scope(); }
#line 2517 "parser.tab.c"
    break;

  case 113: /* If: IF  */
#line 373 "parser.y"
                        { st.new_scope(); }
#line 2523 "parser.tab.c"
    break;

  case 114: /* OptElif: Elif OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET OptElif  */
#line 376 "parser.y"
                                                                                { (yyval.ast) = new NodeElif((yyvsp[-5].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); st.exit_scope(); }
#line 2529 "parser.tab.c"
    break;

  case 115: /* OptElif: %empty  */
#line 377 "parser.y"
                                                                                { (yyval.ast) = NULL; }
#line 2535 "parser.tab.c"
    break;

  case 116: /* Elif: ELIF  */
#line 379 "parser.y"
                        { st.new_scope(); }
#line 2541 "parser.tab.c"
    break;

  case 117: /* OptElse: Else OCURLYBRACKET Inst CCURLYBRACKET  */
#line 382 "parser.y"
                                                        { (yyval.ast) = new NodeElse((yyvsp[-1].ast)); st.exit_scope(); }
#line 2547 "parser.tab.c"
    break;

  case 118: /* OptElse: %empty  */
#line 383 "parser.y"
                                                                { (yyval.ast) = NULL; }
#line 2553 "parser.tab.c"
    break;

  case 119: /* Else: ELSE  */
#line 385 "parser.y"
                        { st.new_scope(); }
#line 2559 "parser.tab.c"
    break;

  case 120: /* For: LoopFor OPAR IdFor IN Range CPAR OCURLYBRACKET Inst CCURLYBRACKET  */
#line 389 "parser.y"
                                                                                     { (yyval.ast) = new NodeFor((yyvsp[-6].str), (yyvsp[-4].ast), (yyvsp[-1].ast)); st.exit_scope(); }
#line 2565 "parser.tab.c"
    break;

  case 121: /* LoopFor: FOR  */
#line 391 "parser.y"
                        { st.new_scope(); }
#line 2571 "parser.tab.c"
    break;

  case 122: /* IdFor: ID  */
#line 393 "parser.y"
                        { (yyval.str) = (yyvsp[0].str); 
                          if(!st.insert((yyvsp[0].str), "var", new t_type_int(),true)) redeclared_variable_error((yyvsp[0].str));}
#line 2578 "parser.tab.c"
    break;

  case 123: /* Range: Exp  */
#line 397 "parser.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 2584 "parser.tab.c"
    break;

  case 124: /* Range: Array  */
#line 398 "parser.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 2590 "parser.tab.c"
    break;

  case 125: /* While: LoopWhile OPAR Exp CPAR OCURLYBRACKET Inst CCURLYBRACKET  */
#line 402 "parser.y"
                                                                            { (yyval.ast) = new NodeWhile((yyvsp[-4].ast), (yyvsp[-1].ast)); st.exit_scope(); }
#line 2596 "parser.tab.c"
    break;

  case 126: /* LoopWhile: WHILE  */
#line 404 "parser.y"
                        { st.new_scope(); }
#line 2602 "parser.tab.c"
    break;


#line 2606 "parser.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);

  return yyresult;
}

#line 406 "parser.y"


void yyerror(const char *s)
{
    fprintf(stderr, "Error: %s, unexpected token %s at line %d, column %d\n", s, yytext,yylineno, yycolumn);
}

void redeclared_variable_error(string id)
{
    string e = "Error: redeclared variable " + id + " at line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
    st_errors.push(e);
}

bool check_id_exists(string id)
{
    if(st.lookup(id) == NULL)
    {
        string e = "Error: " + id + " not declared. At line " + to_string(yylineno) + ", column " + to_string(yycolumn) + "\n";
        st_errors.push(e);
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    bool lex = false;
    bool ast = false;
    bool stp = false;
    int flags = 0;
    for(int i = 1; i < argc -1; ++i) {
        if(string(argv[i]) == "-lex") {
            lex = true;
            flags++;
        }

        else if(string(argv[i]) == "-ast") {
            ast = true;
            flags++;
        }
        else if(string(argv[i]) == "-st") {
            stp = true;
            flags++;
        }

        else{
            cout << "Unexpected argument: " << argv[i] <<endl;
            return 0;
        }
    }

    // Look for input line
    if(argc < 2 + flags)
    {
        cout << "No input file" << endl;
        return -1;
    }

    if(!regex_match(argv[argc-1], extension))
    {
        cout << "File extension doesn't match." << endl;
        return -1;
    }

    // open file to extract the tokens
    extern FILE *yyin;
    yyin = fopen(argv[argc-1], "r");

    // check if file was succesfully opened.
    if (!yyin) 
    {
        cout << "There was an error opening the file" << endl;
        return -1;
    }

    // apply lexing
    int tok;
    while(tok = yylex())
    {
        switch(tok)
        {
            case ID:
                detectedTokens.push_back(new TIdentifier(yylval.str, tok, yylineno, yylloc.first_column));
                break;
            case NUMBER:
                detectedTokens.push_back(new TInteger(yylval.integer, tok, yylineno, yylloc.first_column));
                break;
            case DECIMAL:
                detectedTokens.push_back(new TFloat(yylval.flot, tok, yylineno, yylloc.first_column));
                break;
            case STRING:
                detectedTokens.push_back(new TIdentifier(yylval.str, tok, yylineno, yylloc.first_column));
                break;
            case CHAR:
                detectedTokens.push_back(new TChar(yylval.ch, tok, yylineno, yylloc.first_column));
                break;
            default:
                detectedTokens.push_back(new Token(tok, yylineno, yylloc.first_column));
                break;
        }
    };

    fclose(yyin);
    yyin = fopen(argv[argc-1], "r");

    // If error on lexer, show them
    if(!errors.empty()){
        show_queue(errors);
    }

    // Print tokens
    if (lex){
        print_tokens(detectedTokens);
    }
    
    // reset lines and columns
    yylineno = 1;
    yycolumn = 1;

    // start parsing
    yyparse();

    if(ast) root_ast->print(0);
    if(stp) st.print();

    if(!st_errors.empty()) show_queue(st_errors);

    return 0;
}
