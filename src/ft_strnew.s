; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strnew.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/12 19:27:02 by ybarbier          #+#    #+#              ;
;    Updated: 2015/05/12 19:27:03 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strnew
extern _ft_memalloc

section .text
_ft_strnew:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10

	mov [rbp - 8], rdi
	inc rdi
	call _ft_memalloc
	mov rdi, [rbp - 8]
	test rax, rax
	jz ret_null
	jmp done

ret_null:
	xor rax, rax

done:
	mov rsp, rbp
	pop rbp
	ret
