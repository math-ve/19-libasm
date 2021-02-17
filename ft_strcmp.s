            global ft_strcmp

ft_strcmp:                     ; rdi = str1 ; rsi = str2 ; rcx = i
		    mov	rcx, 0

ft_strcmp_loop:
            mov	dl, [rdi + rcx] ; str1[i]
            mov	dh, [rsi + rcx] ; str2[i]
            inc	ecx             ; i++
            cmp	dl, 0           ; str1[i] = \0 ?
            jz	ft_strcmp_equal ; if yes
            cmp	dl, dh          ; str1[i] = str2[i] ?
            je	ft_strcmp_loop  ; if yes
            jb	ft_strcmp_less  ; if str1[i] < str2[i]
            ja	ft_strcmp_more  ; if str1[i] > str2[i]

ft_strcmp_more:
            mov	rax, 1          ; ret 1
            ret

ft_strcmp_less:
            mov	rax, -1         ; ret -1
            ret

ft_strcmp_equal:
            cmp	dh, 0           ; str2[i] = \0 ?
            jnz	ft_strcmp_less  ; if no
            mov	rax, 0          ; ret 0
            ret

