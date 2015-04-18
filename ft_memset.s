; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ybarbier <ybarbier@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/18 15:50:18 by ybarbier          #+#    #+#              ;
;    Updated: 2015/04/18 15:50:19 by ybarbier         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memset

section .text
_ft_memset:
	test rdi, rdi	; Test si le parametre est nul
	jz done
	mov rcx, rdx	; Met la len dans le compteur
memset:
	mov r10, rdi	; Save le pointeur sur le debut de la chaine
	mov al, sil
	rep stosb		; Prend le contenue de al et le met dans rdi et inc rdi
	mov rdi, r10
done:
	mov rax, rdi
	ret
