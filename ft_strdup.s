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

	test rdi, rdi
	jz done
len:
	push rdi
	call _ft_strlen	; Met la longeur de la chaine dans rax
	pop rdi

memory_alloc:

	inc rax			; Ajoute 1 pour le 0 final
;	push rax

	mov r10, rdi


	; Save la len de la chaine, save la chaine
	mov rdi, rax	; Met en parametre rax (len de la chaine) pour malloc

	push rdi ; Save la len
	push r10 ; Save la chaine

	; Aligment pour appel
;	push rbp
;	mov rbp, rsp
	;sub rsp, 16

	call _malloc	; Appeller Malloc, rax pointe sur une chaine alloue

	;add rsp, 8

duplicate:

	pop rsi ; Chaine
	pop rcx ; Len

	mov rdi, rax	; Met le pointeur de la chaine alloue dans rdi

	cld
	rep movsb


done:
	mov rax, rdi
	pop rbp



;----
	;movsx rdi, eax
;	push rbp
;	mov rbp, rsp
;	sub rsp, 16
	;call _malloc; Appelle de malloc

;	leave
	;mov al, 0x63
	;stosb


;	mov rdi, rax ; Met le pointeur mallocé dans rdi
;	pop rsi

;	pop rax
;	dec rax

;	mov rcx, rax
;	cld
;	rep movsb

;	mov rdi, 0



;done:
;	mov rax, r10
;	ret


; trouver la taille malloc
