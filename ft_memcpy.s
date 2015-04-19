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

;void *ft_memcpy(void *dst, const void *src, size_t n)

global _ft_memcpy

section .text
_ft_memcpy:
	test rdi, rdi
	jz done
	test rsi, rsi
	jz done
	cmp edx, 0
	jle done
memcpy:
	cld
	movsx rcx, edx
	mov r10, rdi
	mov r11, rsi

next:
	mov al, byte[rsi]
	stosb
	add rsi, 1
	loop next
	mov rdi, r10
done:
	mov rax, rdi
	ret
