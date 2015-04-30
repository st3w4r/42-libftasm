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

section .data
buffer:
	db 0x2a

section .text
_ft_cat:
	push rbp
	mov rbp, rsp

	push rdi	; Save fd

malloc_buf:
	mov rdi, [rel buffer] ; Ajout de la taille pour malloc le buffer
	call _malloc
	mov rsi, rax ; Mettre le ptr alloue (buf) dans rsi

	pop rdi ; fd dans rdi
	mov rdx,  [rel buffer] ; size dans rdx

cat:
	mov rax, MACH_SYSCALL(READ)
	syscall

	push rax

	mov rax, MACH_SYSCALL(WRITE)
	syscall

	pop rax
	cmp rax, 0x0
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
