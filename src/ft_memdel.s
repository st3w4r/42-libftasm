; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memdel.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/12 14:02:36 by ybarbier          #+#    #+#              ;
;    Updated: 2015/05/12 14:02:38 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memdel
extern _free

section .text

_ft_memdel:
	push rbp
	mov rbp, rsp

	sub rsp, 16

	test rdi, rdi
	jz done

memory_free:
	mov [rbp - 8], rdi
	mov rax, [rbp - 8]
	mov rdi, [rax]
	call _free
	mov rax, [rbp - 8]
	xor rdx, rdx
	mov [rax], rdx

done:
	add rsp, 16
	pop rbp
	ret
