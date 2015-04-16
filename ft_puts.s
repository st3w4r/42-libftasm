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
extern _ft_strlen

section .data
nl:
	db 0x0a

section .text
_ft_puts:
	test rdi, rdi
	jz done
	mov r10, rdi
	mov rdi, STDOUT
	lea rsi, [rel r10]

	push rdi
	mov rdi, r10
	call _ft_strlen
	pop rdi

	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall

new_line:
	mov rdi, STDOUT
	lea rsi, [rel nl]
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall

done:
	ret
