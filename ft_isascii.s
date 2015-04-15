; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/15 16:45:30 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/15 16:45:41 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isascii

section .text
_ft_isascii:
	cmp rdi, 0x0
	jl not_ascii
	cmp rdi, 0x7f
	jg not_ascii

is_ascii:
	mov rax, 1
	jmp return

not_ascii:
	mov rax, 0
	jmp return

return:
	ret
