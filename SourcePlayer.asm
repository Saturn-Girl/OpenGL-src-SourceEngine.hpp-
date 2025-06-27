[BITS 64]

section .data
    index dq 32
    data dq 24

section .text
    global _start
    global _dll


_start:
    mov rax,[index]
    mov rcx,[data]
    call _dll

_dll:
    mov rax,[index]
    mov rcx,[data]
    ret




