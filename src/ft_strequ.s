; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strequ.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/04 19:54:26 by ybarbier          #+#    #+#              ;
;    Updated: 2015/05/04 19:54:27 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strequ
extern _ft_strcmp

section .text
_ft_strequ:
	mov rax, 0x0
	test rdi, rdi
	jz done
	test rsi,rsi
	jz done

strequ:
	push rdi
	push rsi

	call _ft_strcmp

	pop rsi
	pop rdi

	cmp rax, 0x0
	je find
	mov rax, 0x0
	jmp done

find:
	mov rax, 0x1

done:
	ret
