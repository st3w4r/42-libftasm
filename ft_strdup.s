; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/19 20:32:08 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/19 20:32:09 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define MACH_SYSCALL(nb) 0x2000000 | nb
%define malloc


global _ft_strdup
extern _ft_strlen
extern _ft_memcpy
extern _malloc

section .text
_ft_strdup:
	push rbp
	mov rbp, rsp

	mov rax, rdi
	test rdi, rdi
	jz done

len:
	push rdi
	call _ft_strlen	; Met la longeur de la chaine dans rax
	pop rdi

memory_alloc:

	inc rax			; Ajoute 1 pour le 0 final
	mov r10, rdi

	; Save la len de la chaine, save la chaine
	mov rdi, rax	; Met en parametre rax (len de la chaine) pour malloc

	push r10 ; Save la chaine
	push rdi ; Save la len

	; Aligment pour appel
	sub rsp, 16
	call _malloc	; Appeller Malloc, rax pointe sur une chaine alloue
	add rsp, 16

duplicate:

	pop rcx  		; Len
	pop rsi 		; Chaine

	mov rdi, rax	; Met le pointeur de la chaine alloue dans rdi

	cld
	rep movsb
	; Le zero final est copie avec le plus 1 de rcx
	; Le pointeur de retour est deja contenu dans rax
done:
	mov rsp, rbp
	pop rbp
	ret
