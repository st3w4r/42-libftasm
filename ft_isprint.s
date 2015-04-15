; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/15 17:03:24 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/15 17:03:25 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isprint

section .text
_ft_isprint:
	cmp rdi, 0x20
	jl not_print
	cmp rdi, 0x7e
	jg not_print

is_print:
	mov rax, 1
	jmp return

not_print:
	mov rax, 0
	jmp return

return:
	ret
