; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memalloc.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/12 18:04:16 by ybarbier          #+#    #+#              ;
;    Updated: 2015/05/12 18:04:19 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memalloc
extern _ft_bzero
extern _malloc

section .text
_ft_memalloc:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10

	test rdi, rdi
	jz ret_null

	mov [rbp - 0x8], rdi
	call _malloc
	test rax, rax
	jz ret_null

	mov rdi, rax
	mov rsi, [rbp - 0x8]
	mov [rbp - 0x10], rax
	call _ft_bzero
	mov rax, [rbp - 0x10]
	jmp done

ret_null:
	xor rax, rax

done:
	mov rsp, rbp
	pop rbp
	ret
