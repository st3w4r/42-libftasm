; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/15 17:37:09 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/15 17:37:10 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_tolower

section .text
_ft_tolower:
	mov rax, rdi
	cmp rdi, 0x41
	jl return
	cmp rdi, 0x5a
	jg return

lower:
	add rax, 0x20
	jg return

return:
	ret
