; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/19 14:53:08 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/19 14:53:09 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memcpy

section .text
_ft_memcpy:
	mov rax, rdi
	test rdi, rdi
	jz done
	test rsi, rsi
	jz done
memcpy:
	movsx rcx, edx
	cld
	rep movsb
done:
	ret
