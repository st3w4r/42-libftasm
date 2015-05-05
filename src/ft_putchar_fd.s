; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar_fd.s                                    :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/04 17:34:13 by ybarbier          #+#    #+#              ;
;    Updated: 2015/05/04 17:34:14 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define MACH_SYSCALL(nb) 0x2000000 | nb
%define WRITE 4

global _ft_putchar_fd

section .text
_ft_putchar_fd:
	push rbp
	mov rbp, rsp

putchar_fd:
	push rdi
	mov rdi, rsi
	lea rsi, [rel rsp]
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi

done:
	mov rsp, rbp
	pop rbp
	ret
