; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/14 21:45:22 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/14 21:45:23 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isdigit

section .text
_ft_isdigit:
	cmp rdi, 0x30
	jl not_digit

	cmp rdi, 0x39
	jg not_digit

is_digit:
	mov rax, 1
	jmp return

not_digit:
	mov rax, 0
	jmp return

return:
	ret
