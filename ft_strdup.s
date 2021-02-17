            global ft_strdup
            extern malloc
            extern ft_strlen
            extern ft_strcpy

ft_strdup:                              ; rdi = src ;
            mov		rax, 0
            mov		rsi, 0
            push	rdi                 ; src on stack
            call	ft_strlen           ; ft_strlen(src)
            mov		rdi, rax            ; rdi = ft_strlen(src)
            inc		rdi                 ; rdi++
            call	malloc wrt ..plt    ; malloc(rdi)
            cmp		rax, 0              ; malloc(rdi) = 0 ?
            pop		rsi                 ; rsi = src
            je		error               ; error malloc ?
            mov		rdi, rax            ; rdi = malloc(rdi)
            call	ft_strcpy           ; ft_strcpy(rdi, rsi)
            ret

error:
            mov		rax, 0
            ret