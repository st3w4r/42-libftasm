; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/16 16:00:23 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/16 16:00:24 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen

section .text
_ft_strlen:
	xor rcx, rcx
	test rdi, rdi
	jz done

next:
	mov rcx, -1
	mov al, 0x0
	cld
	repne scasb
	not rcx
	dec rcx

done:
	mov rax, rcx
	ret
