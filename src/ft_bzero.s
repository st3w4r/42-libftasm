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
	mov r10, rsi ; Recupere le parametre n
	xor rcx, rcx ; Met a zero le compteur

next:
	cmp rcx, r10
	jge done
	mov byte[rdi + rcx], 0
	inc rcx
	jmp next

done:
	ret
