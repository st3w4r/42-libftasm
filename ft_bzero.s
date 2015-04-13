; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/13 19:38:52 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/13 19:38:53 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_bzero

section .text
_ft_bzero:
	push rdi
	push rsi
	mov rax, [rdi]
	mov rax, 0
	dec rsi
	jnz _ft_bzero
