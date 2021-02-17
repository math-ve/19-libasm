			global	ft_strlen

ft_strlen:								; rdi = str ; rax = i
			xor		rax, rax			; rax = 0
			jmp		test
nextchar:
			inc		rax
test:
			cmp		BYTE [rdi + rax], 0	; (while str[i] != 0)
			jne		nextchar
done:
			ret							; return rax