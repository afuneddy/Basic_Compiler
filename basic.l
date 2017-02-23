
%{

#include "basic.tab.h"
#include "symtab.h"
#include "relations.h"

extern SYMTAB tab;

int findsymbol(char *s);
int findrelation(char *s);

%}

letter   [a-z]
digit    [0-9]
lod      [0-9a-z]

%%

goto   { return GOTO; }
print  { return PRINT;}
read   { return READ; }
if     { return IF;   }
then   { return THEN; }
stop   { return STOP; }

==|!=|<=|<|>=|> {
                  yylval.rel = findrelation(yytext);
                  return REL;
                }
^{digit}+      {
                 yylval.val = atoi(yytext);
                 return LNUM;
               }
{letter}{lod}* {
                 yylval.varnum = findsymbol(yytext);
                 return VAR;
               }
{digit}+       {
                 yylval.val = atoi(yytext);
                 return NUM;
               }
[+*/%\-=()\n]  { return *yytext; }
[ \t]          ;
.              { yyerror("illegal character\n"); }

%%

int yywrap()
{
  return 1;
}

int findsymbol(char *s)
{
  int i,n;

  for(i=0;i<tab.n;i++)
    if(strcmp(tab.sym[i].name, s) == 0)
      return i;
  n = tab.n++;
  tab.sym[n].name = strdup(s);
  tab.sym[n].val = 0;
  return n;
}
int findrelation(char *s)
{
  if(strcmp(s,"==") == 0) return REL_JEQ;
  if(strcmp(s,"!=") == 0) return REL_JNE;
  if(strcmp(s,">=") == 0) return REL_JGE;
  if(strcmp(s,">" ) == 0) return REL_JGT;
  if(strcmp(s,"<=") == 0) return REL_JLE;
  if(strcmp(s,"<" ) == 0) return REL_JLT;
  fprintf(stderr,"Huh in findrelation: %s?\n", s);
}
