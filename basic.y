
%union {
  int varnum;
  int val;
  int rel;
  char *addr;
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
%type <addr> VB
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

%}


%%

P:
   P S '\n' |
   P '\n'   |
   ;
S:
   LAB PRINT VAR {

                 printf("%6s  mov %2s eax, [%s]\n", "","", tab.sym[$3].name);
                 printf("%6s  call %2s print\n","","");
                 printf("%6s  call %2s printLF\n","","");
              }
   | LAB READ VAR  {
                 printf("%6s  mov %2s edx, %d\n","","",DATALEN);
                 printf("%6s  mov %2s ecx, buf\n","","");
                 printf("%6s  mov %2s ebx, 0\n","","");
                 printf("%6s  mov %2s eax, 3\n","","");
                 printf("%6s  int 0x80\n\n","");
                  
                 printf("%6s  call %2s atoi\n","","");
                 printf("%6s  mov %2s [%s], eax\n","","", tab.sym[$3].name);
                  }
   | LAB STOP  {
                 printf("%6s  call %2s exiting\n","","");
               }
   | LAB GOTO NUM {
                  printf("%6s  jmp lb%d\n","", $3);
               }
   | LAB VAR '=' VB {

                 printf("%6s  mov %2s eax, [%s]\n","","",$4);
                 printf("%6s  mov%3s [%s], eax\n","","", tab.sym[$2].name );
                 printf("%6s  int %2s 0x80\n","",""); 
               }
   | LAB IF  E REL E  THEN  NUM  {
                                   printjump1($3, $5, $4, $7);
                                    }
   | LAB IF  VB  REL E  THEN  NUM  {
                                   printjump2($3, $5, $4, $7);
                                    }
   | LAB IF  E REL  VB  THEN  NUM  {
                                   printjump3($3, $5, $4, $7);
                                    }
   | LAB IF  VB REL VB  THEN  NUM  {
                                   printjump4($3, $5, $4, $7);
                                    }

   | LAB VAR '=' E  {
                 
                    tab.sym[$2].val = $4;
  
                 printf("%6s  mov %2s eax, %d\n","","",tab.sym[$2].val);
                 printf("%6s  mov%3s [%s], eax\n","","", tab.sym[$2].name );
                 printf("%6s  int %2s 0x80\n","",""); 
               }
LAB:
   LNUM      {
                 printf("lb%d:\n", $1);
             }

E:   //Handle expressions that result directly to numerical values:
 
   NUM       {
                $$ = $1;
               }
 
 |  E '+' E       {
                           $$ = $1 + $3;               
     
                 printf("%6s  mov%3s eax, %d\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  add%3s eax,  ebx\n","","");

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

                $$ = $1 / $3;
                if($3 == 0){
                fprintf(stderr, "Division by zero!");
                exit(0);}
                 printf("%6s  mov%3s eax, %d\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  div%3s ebx\n\n","","");
               }
   | '(' E ')' { $$ = $2; }


VB:   /*Defines expressions that don't result directly to numerical values:*/
     /* Also, ires{digit} refers to a variable at the .bss SECTION that holds intemediate results*/
    /* depending on the nature of VB*/
                
  VAR       {     
                 $$ = tab.sym[$1].name;
             }
 | VB '+' E  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  add%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires2], eax\n","","");
                 
                 $$ = "ires2";
               }
 | E '+' VB  {

                 printf("%6s  mov%3s eax, [%s]\n","","",$3);
                 printf("%6s  mov%3s ebx, %d\n","","",$1);
                 printf("%6s  add%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires3], eax\n","","");
                 
                 $$ = "ires3";

               }
 | VB '+' VB  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, [%s]\n","","",$3);
                 printf("%6s  add%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires5], eax\n","","");
                 
                 $$ = "ires5";

               }
 | VB '-' E  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  sub%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires6], eax\n","","");
                 
                 $$ = "ires6";

               }
 | E '-' VB  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$3);
                 printf("%6s  mov%3s ebx, %d\n","","",$1);
                 printf("%6s  sub%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires7], eax\n","","");
                 
                 $$ = "ires7";

               }
 | VB '-' VB  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, [%s]\n","","",$3);
                 printf("%6s  sub%3s eax,  ebx\n","","");
                 printf("%6s  mov%3s [ires8], eax\n","","");
                 
                 $$ = "ires8";

               }
 | VB '*' E  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  mul%3s ebx\n","","");
                 printf("%6s  mov%3s [ires9], eax\n","","");
                 
                 $$ = "ires9";

               }
 | E '*' VB  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$3);
                 printf("%6s  mov%3s ebx, %d\n","","",$1);
                 printf("%6s  mul%3s ebx\n","","");
                 printf("%6s  mov%3s [ires10], eax\n","","");
                 
                 $$ = "ires10";

               }
 | VB '*' VB  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, [%s]\n","","",$3);
                 printf("%6s  mul%3s ebx\n","","");
                 printf("%6s  mov%3s [ires11], eax\n","","");
                 
                 $$ = "ires11";

               }
 | VB '/' E  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, %d\n","","",$3);
                 printf("%6s  div%3s ebx\n","","");
                 printf("%6s  mov%3s [ires12], eax\n","","");
                 
                 $$ = "ires12";

               }
 | E '/' VB  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$3);
                 printf("%6s  mov%3s ebx, %d\n","","",$1);
                 printf("%6s  div%3s ebx\n","","");
                 printf("%6s  mov%3s [ires13], eax\n","","");
                 
                 $$ = "ires13";

               }
 | VB '/' VB  {
                 printf("%6s  mov%3s eax, [%s]\n","","",$1);
                 printf("%6s  mov%3s ebx, [%s]\n","","",$3);
                 printf("%6s  div%3s  ebx\n","","");
                 printf("%6s  mov%3s [ires14], eax\n","","");
                 
                 $$ = "ires14";

               }

| '(' VB ')' {
                 
                 printf("%6s  mov%3s eax, [%s]\n","","",$2);
                 printf("%6s  mov%3s [ires15], eax\n","","");
                 $$ = "ires15";

                    }

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
