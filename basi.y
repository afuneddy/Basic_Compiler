
%union {
  int varnum;
  int val;
  int rel;
}

%token GOTO
%token IF
%token PRINT
%token READ
%token STOP
%token THEN
%token <rel> REL
%token <val> LNUM
%token <val> NUM
%token <varnum> VAR
%type <val> E   
%left '+' '-'
%left '*' '/'

%{
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
  void printjump(char *l, char *r, int rnum, int linenm);
  extern FILE *yyin;

  void header();
  int readinput();
  void sprint(char *var);
  void exiting();
  void lfprint();
  void vbssprint(char *var, int val);
  void vprint(char *var, int val);

void astoi();
void atiloop();
void atipop();
void fini();
void intob(char *v);
void find(char *v);
void found();
void italoop();
void next();
void shift();
void printLF();

  char *varbss,  *vars;

%}


%%

P:
   P S '\n' |
   P '\n'   |
   ;
S:
   LAB PRINT VAR {
                 sprint(tab.sym[$3].name);
               }
   | LAB READ VAR  {
                 //vbssprint(tab.sym[$3].name, DATALEN); 
                 printf("%6s  mov %2s edx, %d\n","","",DATALEN);
                 printf("%6s  mov %2s ecx, buf\n","","");
                 printf("%6s  mov %2s ebx, 0\n","","");
                 printf("%6s  mov %2s eax, 3\n","","");
                 printf("%6s  int 0x80\n\n","");
                  
                 printf("%6s  call %2s atoi\n","","");
                 printf("%6s  mov %2s [%s], eax\n","","", tab.sym[$3].var);
                  }
   | LAB STOP  {
                  exiting(); 
               }
   | LAB GOTO NUM {
                  printf("%6s  jmp lb%d\n","", $3);
               }
   | LAB VAR '=' NUM {
                  
                  //vbssprint(tab.sym[$2].name, DATALEN);
                 printf("%6s  mov%3s [%s], %d\n","","", tab.sym[$2].name, $4 );
               }
   | LAB VAR '=' E {
                  
                  //vbssprint(tab.sym[$2].name, DATALEN);
                 printf("%6s  mov%3s [%s], res\n","","", tab.sym[$2].name );
   printf("%6s  int %2s 0x80\n","",""); 
               }
   | LAB IF  VAR REL VAR  THEN GOTO  NUM  {
                                   printjump(tab.sym[$3].name, tab.sym[$5].name, $4, $8);
                                    }
LAB:
   LNUM      {
                 printf("lb%d:\n", $1);
             }
E:
  
   VAR '+' NUM       {
                
                 printf("%6s  mov%3s eax, %s\n","","", tab.sym[$1].name);
               //  printf("%6s  sub%3s eax, '0'\n","","");
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  add%3s eax,  ebx\n","","");
                // printf("%6s  add%3s eax,  '0'\n","","");
                 printf("%6s  mov%3s dword[res], eax\n","","");
               

               }
   | E '-' E   {
                $$ = $1 - $3; 
                 printf("%6s  mov%3s eax, %d\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  sub%3s eax,  ebx\n\n","","");
               }
   | E '*' E   {
               $$ = $1 * $3;
                 printf("%6s  mov%3s eax, %d\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  mul%3s ebx\n\n","","");
               }
   | E '/' E   {

                $$ = $1 + $3;
                if($3 == 0){
                fprintf(stderr, "Division by zero!");
                exit(0);}
                 printf("%6s  mov%3s eax, %d\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  div%3s ebx\n\n","","");
               }
   | '(' E ')' { $$ = $2; }

%%

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
  yyin = fd;
  tab.n = 0;
  yyparse();
  exiting();
// fprintf(stdout, "\nSECTION .data\n%s", vars); 
 fprintf(stdout, "\nSECTION .bss\n%s", varbss); 
 fprintf(stdout, "\nres    resb    %d", DATALEN);
 fprintf(stdout, "\nbuf    resb    %d", DATALEN);
  for(i=0; i<tab.n; i++)
 fprintf(stdout, "\n%s    resb    %d", DATALEN, tab.sym[i].var);
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


void printjump(char *l, char* r, int rnum, int linenum)
{
 printf("%6s  mov eax, %s\n", "", l); 

  printf("%6s  cmp %2s eax, %s\n", "", "", r);
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
void lfprint(){
printf("\n"
    
   "%6s  push %2s edx\n" 
   "%6s  push %2s ecx\n" 
   "%6s  push %2s ebx\n" 
   "%6s  push %2s eax\n" 
   "%6s  mov %2s edx, 5\n" 
   "%6s  mov %2s ecx, 10 \n"
   "%6s  mov %2s ebx, 1\n"
   "%6s  mov %2s eax, 4\n"
   "%6s  int %2s 80h\n" 
   ,"" ,"","","","","","","","","","","","","","","","","");

}


void exiting(){
      lfprint(); 
      printf("\n%6s  mov %2s ebx, 0 \n", "","");
      printf("%6s  mov %2s eax, 1 \n", "","");
      printf("%6s  int %2s 0x80\n", "","");

 }


void vprint(char *var, int val){

                  char str[20];
                  sprintf(str, "%d", val);
                  strcat(vars, var);     
                  strcat(vars, "    dw    ");     
                  strcat(vars, str);     
                  strcat(vars, "\n");     


}
void vbssprint(char *var, int val){

                  char str[20];
                  sprintf(str, "%d", val);
                  strcat(varbss, var);     
                  strcat(varbss, "    resb    ");     
                  strcat(varbss, str);     
                  strcat(varbss, "\n");     


}

void astoi(){
      printf("\natoi:\n");
      printf("%6s  push %2s eax\n", "","");
      printf("%6s  push %2s ebx\n", "","");
      printf("%6s  push %2s ecx\n", "","");
      printf("%6s  mov %2s eax, 0\n", "","");
      printf("%6s  mov %2s eax, buf\n", "","");
  }
void atiloop(){
      printf("\natiloop:\n");
      printf("%6s  mov %2s eax, [esi]\n", "","");
      printf("%6s  and %2s ebx, 0xff\n", "","");
      printf("%6s  cmp %2s ebx, 10\n", "","");
      printf("%6s  jz %2s atipop\n", "","");
      printf("%6s  inc %2s esi\n", "","");
      printf("%6s  mov %2s ecx, 10\n", "","");
      printf("%6s  mul %2s ecx\n", "","");
      printf("%6s  sub %2s ebx, 48\n", "","");
      printf("%6s  add %2s eax, ebx\n", "","");
      printf("%6s  jmp %2s atiloop\n", "","");
  }
      

void atipop(){
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  pop %2s ebx\n", "","");
      printf("%6s  pop %2s ecx\n", "","");
      printf("%6s  jmp %2s fini\n", "","");
  }
void fini(){
      printf("fini:\n");
      printf("%6s  ret\n","");
  }
void intob(char *v){
      printf("\nitob:\n");
      printf("%6s  mov %2s esi, buf\n", "","");
      printf("%6s  mov %2s eax, [%s]\n", "","", v);
      printf("%6s  mov %2s ecx, 0x80000000\n", "","");
  }
void find(char *v){
      printf("\nfind:\n");
      printf("%6s  mov %2s ebx, eax\n", "","");
      printf("%6s  and %2s ebx, ecx\n", "","");
      printf("%6s  jnz %2s found\n", "","");
      printf("%6s  shr %2s ebx, 1\n", "","");
      printf("%6s  jmp %2s find\n", "","");
  }
void found(){
      printf("found:\n");
      printf("%6s  mov %2s edx, 0\n", "","");
  }

void italoop(){
      printf("\nitaloop:\n");
      printf("%6s  inc %2s edx\n","","");
      printf("%6s  mov %2s ebx, eax\n", "","");
      printf("%6s  and %2s ebx, ecx\n", "","");
      printf("%6s  jz %2s next\n", "","");
      printf("%6s  mov %2s byte [esi], 49\n", "","");
      printf("%6s  jz %2s shift\n", "","");
  }
void next(){
      printf("next:\n");
      printf("%6s  mov %2s edx, 0\n", "","");
  }
void shift(){
      printf("\nshift:\n");
      printf("%6s  inc %2s esi\n","","");
      printf("%6s  shr %2s ecx, 1\n", "","");
      printf("%6s  jnz %2s italoop, ecx\n", "","");
      printf("%6s  inc %2s edx\n","","");
      printf("%6s  mov %2s byte [esi], 10\n", "","");
      printf("%6s  ret","");
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
      printf("%6s  push %2s eax\n", "","");
      printf("%6s  push %2s ecx\n", "","");
      printf("%6s  push %2s edx\n", "","");
      printf("%6s  push %2s esi\n", "","");
      printf("%6s  mov %2s eax, 0\n", "","");

}  
void divloop(){

      printf("\ndivloop:\n");
      rintf("%6s  inc %2s ecx\n", "","");
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
      printf("%6s  push %2s eax\n", "","");
      printf("%6s  push %2s ebx\n", "","");
      printf("%6s  push %2s ecx\n", "","");
      printf("%6s  push %2s edx\n", "","");
      printf("%6s  call %2s slen\n", "","");
      printf("%6s  mov %2s ebx, eax\n", "","");
      printf("%6s  pop %2s eax\n", "","");
      printf("%6s  mov %2s ecx, eax\n", "","");
      printf("%6s  mov %2s ebx, 1\n", "","");
      printf("%6s  mov %2s eax, 4\n", "","");
      printf("%6s  int %2s 80h\n", "","");
      printf("%6s  pop %2s edx\n", "","");
      printf("%6s  pop %2s ecx\n", "","");
      printf("%6s  pop %2s ebx\n", "","");
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
