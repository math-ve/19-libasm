            extern __errno_location
            global ft_write

ft_write:                               ;
    mov rax, 0x1                        ; syscall write
    syscall                             ; call write
    cmp rax, 0                          ; rax = 0 ?
    jl error                            ; if(rax < 0) => error
    ret                                 ; return
error:
    neg rax                             ; get absolute value of syscall return
    mov rdi, rax                        ; rdi = rax (saving the value for later)
    call __errno_location wrt ..plt     ; call __errno_location
    mov [rax], rdi                      ; *rax = rdi
    mov rax, -1                         ; rax = -1
    ret                                 ; return