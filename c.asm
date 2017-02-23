
SECTION .text
global  _start
_start:

lb10:
        mov    eax, 1
        mov    [x], eax
        int    0x80
lb20:
        mov    eax, 2
        mov    [n], eax
        int    0x80
lb30:
        mov    eax, [x]
        mov    ebx, [n]
        add    eax,  ebx
        mov    [ires5], eax
        mov    eax, [ires5]
        mov    [ires15], eax
        mov    eax, [ires15]
        mov    ebx, 5
        mul    ebx
        mov    [ires9], eax
        mov    eax, [ires9]
        mov    [y], eax
        int    0x80
lb40:
        mov    eax, 48
        mov    [m], eax
        int    0x80
lb50:
        mov eax, [x]
        cmp    eax, 2
        jl lb70
lb60:
        call    exiting
lb70:
        mov    eax, [y]
        call    print
        call    printLF
lb80:
        call    exiting

print:
        push    ebx
        push    ecx
        push    edx
        push    esi
        mov    ecx, 0

divloop:
        inc    ecx
        mov    edx, 0
        mov    esi, 10
        idiv    esi
        add    edx, 48
        push    edx
        cmp    eax, 0
        jnz    divloop

prinloop:
        dec    ecx
        mov    eax, esp
        call    sprint
        pop    eax
        cmp    ecx, 0
        jnz    prinloop
        pop    esi
        pop    edx
        pop    ecx
        pop    eax
        ret  
sprint:
        push    edx
        push    ecx
        push    ebx
        push    eax
        call    slen

        mov    edx, eax
        pop    eax
        mov    ecx, eax
        mov    ebx, 1
        mov    eax, 4
        int    80h

        pop    ebx
        pop    ecx
        pop    edx
        ret  
slen:
        push    ebx
        mov    ebx, eax

nextchar:
        cmp    byte [eax], 0
        jz    finish
        inc    eax
        jmp    nextchar

finish:
        sub    eax, ebx
        pop    ebx
        ret

exiting:

        mov    ebx, 0 
        mov    eax, 1 
        int    80h
        ret

atoi:
        mov    eax, 0
        mov    esi, buf

atiloop:
        mov    ebx, [esi]
        and    ebx, 0xff
        cmp    ebx, 10
        jz    finret
        inc    esi
        mov    ecx, 10
        mul    ecx
        sub    ebx, 48
        add    eax, ebx
        jmp    atiloop

finret:
        ret

printLF:
        push    eax
        mov    eax, 0Ah
        push    eax
        mov    eax, esi
        call    sprint
        pop    eax
        pop    eax
        ret
SECTION .bss

res    resb    64
buf    resb    64
x    resb    64
n    resb    64
y    resb    64
m    resb    64
ires1    resb    64
ires2    resb    64
ires3    resb    64
ires4    resb    64
ires5    resb    64
ires6    resb    64
ires7    resb    64
ires8    resb    64
ires9    resb    64
ires10    resb    64
ires11    resb    64
ires12    resb    64
ires13    resb    64
ires14    resb    64
ires15    resb    64