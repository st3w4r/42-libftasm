; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/04 20:14:27 by ybarbier          #+#    #+#              ;
;    Updated: 2015/05/04 20:14:27 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcpy

section .text
_ft_strcpy:
	mov rax, rdi
	test rdi, rdi
	jz done
	test rsi, rsi
	jz done

	mov r8, rdi
	mov r9, rsi
	xor rcx, rcx

next:
	cmp byte[rsi + rcx], 0x0
	mov al, byte[rsi + rcx]
	mov byte[rdi + rcx], al
	je end
	add rcx, 0x1
	jmp next

end:
	mov rdi, r8
	mov rsi, r9
	mov rax, rdi

done:
	ret
