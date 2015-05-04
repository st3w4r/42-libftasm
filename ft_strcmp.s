; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/01 18:43:39 by ybarbier          #+#    #+#              ;
;    Updated: 2015/05/01 18:43:40 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

; Test rdi et rsi si null retourner -1
; Tester byte par byte chaque chaine
; Si charachere egal incrementer un compteur
; Quand different sortir de la boucle
; Retourner s1[i] - s2[i]

global _ft_strcmp

section .text
_ft_strcmp:
	mov rax, -1
	test rdi, rdi
	jz done
	test rsi,rsi
	jz done

strcmp:
	mov r8, rdi
	mov r9, rsi

	xor rcx, rcx
	xor rax, rax
	xor rbx, rbx

next:
	mov al, byte[rdi + rcx]
	mov bl, byte[rsi + rcx]
	cmp al, 0x0
	je end
	cmp bl, 0x0
	je end
	add rcx, 1
	cmp al, bl
	je next
end:
	sub rax, rbx
	mov rdi, r8
	mov rsi, r9

done:
	ret
