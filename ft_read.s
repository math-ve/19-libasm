                                    extern __errno_location
                                    global ft_read

ft_read:
    mov rax, 0                      ; syscall read
    syscall                         ; syscall
    cmp rax, 0                      ; rax = 0 ?
    jl error                        ; if(rax < 0) => error
    ret                             ; return
error:
    neg rax                         ; get absolute value of syscall return
    mov rdi, rax                    ; rdi = rax (saving rax value for later)
    call __errno_location wrt ..plt ; call __errno_location
    mov [rax], rdi                  ; *rax = rdi
    mov rax, -1                     ; ret = -1
    ret                             ; return