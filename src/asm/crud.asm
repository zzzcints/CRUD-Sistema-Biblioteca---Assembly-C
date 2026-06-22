section .bss
    ; até 100 livros
    books resb 100 * (64 + 64 + 20 + 4 + 4)
    book_count resd 1

section .text
    global inserir



; Registradores da função de inserção

; rdi = título 
; rsi = autor 
; rdx = isbn 
; rcx = ano 
; r8d = quantidade 

inserir:
    push rbp
    mov rbp, rsp


    mov eax, [book_count]
    cmp eax, 100
    jge .full   ; Conferir se >100

    ; Calculando a posição 
    
    mov rbx, eax
    imul rbx, (64+64+20+4+4)
    lea r9, [books + rbx]   ; ponteiro para início

    ; copiar título (64 bytes)

    mov rdi, r9             
    mov rsi, [rbp+16]       
    mov rcx, 64
.copy_title:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    loop .copy_title

    ; copiar autor

    mov rsi, [rbp+24]       
    mov rcx, 64
.copy_author:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    loop .copy_author

    ; copiar isbn 

    mov rsi, [rbp+32]       
    mov rcx, 20
.copy_isbn:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    loop .copy_isbn

    ; salvar ano 

    mov eax, [rbp+40]
    mov [rdi], eax
    add rdi, 4

    ; salvar quantidade 

    mov eax, [rbp+48]
