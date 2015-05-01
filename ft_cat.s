; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/30 18:12:23 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/30 18:12:26 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;


;   user_ssize_t read(int fildes, void *buf, size_t nbyte);
;	user_ssize_t write(int fd, user_addr_t cbuf, user_size_t nbyte);
%define MACH_SYSCALL(nb) 0x2000000 | nb
%define STDOUT 1
%define READ 3
%define WRITE 4

global _ft_cat
extern _malloc

section .bss
buffer:
	.buf resb 0x2a0

section .data
len:
	db 0x2a0

section .text
_ft_cat:
	push rbp
	mov rbp, rsp

	;push rdi	; Save fd

init_data:
	;mov rdi, [rel buffer] ; Ajout de la taille pour malloc le buffer

	;call _malloc
	;mov rsi, rax ; Mettre le ptr alloue (buf) dans rsi

	;pop rdi ; fd dans rdi
	; RDI contient le fd

	mov rdx, [rel len] ; size dans rdx (3 eme parametre)
	lea rsi, [rel buffer.buf]	; Mettre le ptr sur le buffer dans le 2 eme param

cat:
	push rdi ; Envoi de fd
	push rsi ; Envoi de ptr
	push rdx ; Envoi de size

	mov rax, MACH_SYSCALL(READ)
	syscall

	;pop rdi
	mov rdi, STDOUT
	pop rdx ; Mettre la size
	pop rsi ; Mettre ptr sur str

	push rdx ; Envoi size
	push rsi ; Ensoi ptr sur str
	push rax ; Envoi nb charactere read

	mov rax, MACH_SYSCALL(WRITE)
	syscall

	pop rax
	pop rsi
	pop rdx
	pop rdi

	cmp rax, 0
	jg cat

done:
	mov rsp, rbp
	pop rbp
	ret
; fd dans rdi
; buf dans rsi
; size dans rdx
;
; Appeler Read, tant que rax superieur à zero boucler sur Read
