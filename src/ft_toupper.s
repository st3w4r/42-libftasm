; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/15 17:19:35 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/15 17:19:45 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_toupper

section .text
_ft_toupper:
	mov rax, rdi
	cmp rdi, 0x61
	jl return
	cmp rdi, 0x7a
	jg return

upper:
	sub rax, 0x20
	jmp return

return:
	ret
