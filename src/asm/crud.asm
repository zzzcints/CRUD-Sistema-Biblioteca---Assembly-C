section .bss
    books resb 100 * (64 + 64 + 20 + 4 + 4)
    book_count resd 1

section .text
    global inserir

; -----------------------------------------------------------------------------
; Inserir livro (cdecl, 32-bit)
; Parâmetros na pilha:
; [ebp+8]  = título (char*)
; [ebp+12] = autor (char*)
; [ebp+16] = isbn (char*)
; [ebp+20] = ano (int)
; [ebp+24] = quantidade (int)
; -----------------------------------------------------------------------------
inserir:
    push ebp
    mov ebp, esp

    mov eax, [book_count]
    cmp eax, 100
    jge .full

    ; calcular posição base
    mov ebx, eax
    imul ebx, (64+64+20+4+4)
    lea edi, [books + ebx]   ; destino

    ; copiar título (64 bytes)
    mov esi, [ebp+8]         ; fonte = título
    mov ecx, 64
.copy_title:
    mov al, [esi]
    mov [edi], al
    inc esi
    inc edi
    loop .copy_title

    ; copiar autor (64 bytes)
    mov esi, [ebp+12]
    mov ecx, 64
.copy_author:
    mov al, [esi]
    mov [edi], al
    inc esi
    inc edi
    loop .copy_author

    ; copiar isbn (20 bytes)
    mov esi, [ebp+16]
    mov ecx, 20
.copy_isbn:
    mov al, [esi]
    mov [edi], al
    inc esi
    inc edi
    loop .copy_isbn

    ; salvar ano
    mov eax, [ebp+20]
    mov [edi], eax
    add edi, 4

    ; salvar quantidade
    mov eax, [ebp+24]
    mov [edi], eax
    add edi, 4

    ; incrementar contador
    mov eax, [book_count]
    inc eax
    mov [book_count], eax

    jmp .done

.full:
.done:
    pop ebp
    ret
