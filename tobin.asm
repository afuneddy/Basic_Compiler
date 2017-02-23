
section  .text
      global _start

_start:
      mov      edx,64    ;length
      mov      ecx,buf   ;buffer
      mov      ebx,0     ;stdin
      mov      eax,3     ;read
      int      0x80

      call     atoi
      mov      [num],eax
      cmp      eax,0
      jz       adios
      call     itob

      mov      edx,eax   ;itob leaves the number of bytes in the eax register
      mov      ecx,buf   ;buffer
      mov      ebx,1     ;stdout
      mov      eax,4     ;write
      int      0x80

adios:
      mov      ebx,0     ;exit(0)
      mov      eax,1     ;exit
      int      0x80
      ret

; atoi subroutine: result returned in eax

atoi:
      mov      eax,0
      mov      esi,buf
aloop:
      mov      ebx,[esi]
      and      ebx,0xff
      cmp      ebx,10
      jz       fini
      inc      esi
      mov      ecx,10
      mul      ecx
      sub      ebx,48
      add      eax,ebx
      jmp      aloop
fini:
      ret

; itob subroutine converted int at num to binary string at buf

itob:
      mov      esi,buf
      mov      eax,[num]
      mov      ecx,0x80000000      ; first find leftmost one bit
find:
      mov      ebx,eax
      and      ebx,ecx
      jnz      found
      shr      ecx,1
      jmp      find
found:
      mov      edx,0               ; start converting bits to chars, and counting them
loop:
      inc      edx                 ; edx counts bytes in output string
      mov      ebx,eax
      and      ebx,ecx
      jz       next
      mov      byte [esi],49       ; 49 = '1'
      jmp      shift
next:
      mov      byte [esi],48       ; 48 = '0'
shift:
      inc      esi
      shr      ecx,1
      jnz      loop
      inc      edx                 ; terminate string with a newline
      mov      byte [esi],10
      ret

section .data

section .bss

num:  resb      64
buf:  resb      64

