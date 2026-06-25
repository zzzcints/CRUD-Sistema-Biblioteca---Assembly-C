section .data
    global book_count
    book_count dd 0

section .bss
    global books
    books resb 100 * (64 + 64 + 20 + 4 + 4)


section .text
    global inserir
    global buscar
   


inserir:
    push ebp
    mov ebp, esp

    mov eax, [book_count]
    cmp eax, 100
    jge .full

    ; calcular posição base
    mov ebx, eax
    imul ebx, (64+64+20+4+4)
    lea edi, [books + ebx]

; copiar título (64 bytes)
mov esi, [ebp+8]
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

; copiar ISBN (20 bytes)
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
.done:
    pop ebp
    ret
.full:
    pop ebp
    ret


; --- função buscar ---
buscar:
    push ebp
    mov ebp, esp

    mov esi, [ebp+8]        
    mov ecx, [book_count]   
    xor eax, eax            

.loop_books:
    cmp eax, ecx
    jge .not_found          

    ; calcular posição base do livro i
    mov ebx, eax
    imul ebx, (64+64+20+4+4)
    lea edi, [books + ebx]  

    ; comparar título
    push ecx                
    mov ecx, 64             
.compare_title:
    mov dl, [esi]
    mov dh, [edi]
    cmp dl, dh
    jne .next_book          
    cmp dl, 0
    je .found               
    inc esi
    inc edi
    loop .compare_title

.found:
    pop ecx
    ; eax já contém o índice
    jmp .done

.next_book:
    pop ecx
    inc eax                 
    jmp .loop_books

.not_found:
    mov eax, -1             

.done:
    pop ebp
    ret





