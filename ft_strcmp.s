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

	mov rcx, -1
	cld
	repe scasb


	mov rax, [rdi]

	mov rdi, r8
	mov rsi, r9

done:
	ret

; Test rdi et rsi si null retourner -1
; Tester byte par byte chaque chaine
; Si charachere egal incrementer un compteur
; Utiliser rep
; Quand different sortir de la boucle
; Retourner s1[i] - s2[i]
