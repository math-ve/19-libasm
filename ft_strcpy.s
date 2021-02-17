            global ft_strcpy

ft_strcpy:                             ; rdi = dest ; rsi = src ; rdx = temp ; rcx = i
            xor     rcx, rcx            ; i = 0
            xor     rdx, rdx            ; temp = ""
            cmp     rsi, 0              ; src = \0 ?
            je      return_done         ; if yes
            jmp     make_copy

next_char:
            inc     rcx                 ; i++

make_copy:
            mov     dl, BYTE [rsi + rcx]; temp = src[i]
            mov     BYTE [rdi + rcx], dl; dest[i] = temp
            cmp     dl, 0               ; src[i] = '\0' ?
            jnz     next_char           ; if no

return_done:
            mov     rax, rdi            ; return dest
            ret