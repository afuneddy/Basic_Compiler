
#define NSYMS   1024

typedef struct symtableentry {
  char *name;
  int val;
} SYMTABENTRY;

typedef struct symtab {
  SYMTABENTRY sym[NSYMS];
  int n;
} SYMTAB;

