; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/13 23:39:14 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/13 23:39:15 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isalpha

section .text
_ft_isalpha:
	cmp rdi, 0x41	; Comparaison avec A
	jl not_alpha	; Saut si inferrieur à A

	cmp rdi, 0x7a	; Comparaison avec z
	jg not_alpha	; Saut a Faux si superieur à Z

	cmp rdi, 0x5a	; Comparaison avec Z
	jle is_alpha	; Saut a vrai si inferieur ou egal a Z

	cmp rdi, 0x61	; Comparaison avec a
	jge is_alpha	; Saut a vrai si superieur ou egal a a

	jmp not_alpha

is_alpha:
	mov rax, 1
	jmp return

not_alpha:
	mov rax, 0
	jmp return

return:
	ret
