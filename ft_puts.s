; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/15 17:50:15 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/15 17:50:17 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define MACH_SYSCALL(nb) 0x2000000 | nb
%define STDOUT 1
%define WRITE 4

global _ft_puts
extern _write

section .text
_ft_puts:
	mov r10, rdi

	mov rdi, STDOUT
	lea rsi, [rel r10]
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	leave
	ret

section .data
msg:
	db "OK", 10, 0
