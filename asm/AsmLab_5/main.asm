%include "io.inc"

section .bss
    str_buf_1: resb 64
    str_buf_2: resb 64
    
section .data
    ; m - message
    ; s - string
    ; e - equal
    ; n - not
    mse: db "Strings are equal", 0
    msne: db "Strings aren't equal. Difference at symbol ", 0
    msle: db "Strings' length are equal", 0
    mslne: db "Strings' length are not equal", 0
    message: db "Input string:", 0
    str1: db "aaa", 0
    str2: db "baa", 0
    %define buffer_size 64
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    ;write your code here
    xor eax, eax
    ; task 1
    call COMPARE_STRINGS
    ; task 2
    call COMPARE_STRINGS_LENGTH
    ret

INPUT_STRINGS:
    ; input 2 strings
    GET_STRING str_buf_1, 64
    GET_STRING str_buf_2, 64
    ; load addresses of strings into sting related registers 
    mov esi, str_buf_1
    mov edi, str_buf_2
    ret

COMPARE_STRINGS:
    call INPUT_STRINGS
    ; reset df flag
    cld
    ; load string size into ecx
    mov ecx, buffer_size
    ; repeat while ecx != 0 and ZF == 0
    repe cmpsb
    ; jcxz - dosen't work
    cmp ecx, 0
    jz str_eq
    PRINT_STRING msne
    mov ebx, buffer_size
    sub ebx, ecx
    PRINT_DEC 4, ebx
    jmp cmp_str_exit
    str_eq:
        PRINT_STRING mse
        NEWLINE
    cmp_str_exit:
    ret
    
COMPARE_STRINGS_LENGTH:
    call INPUT_STRINGS
    
    mov al, 0
    
    mov ecx, buffer_size
    repne scasb ; repeat while ecx != 0 and ZF != 0
    mov ebx, ecx
    
    mov ecx, buffer_size
    mov edi, esi
    repne scasb
    
    cmp ebx, ecx
    jz equal_length
    jmp not_equal_length
    equal_length:
        PRINT_STRING msle
        jmp cmp_strlen_exit
    not_equal_length:
        PRINT_STRING mslne
    
    cmp_strlen_exit:
    ret