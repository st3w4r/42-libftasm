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
	dec rcx
memset:
	cmp rcx, 0
	jl done
	mov byte[rdi + rcx], sil
	dec rcx
	jmp memset
	;rep movsb

done:
	mov rax, rdi
	ret
