# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alromero <alromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 18:49:16 by alromero          #+#    #+#              #
#    Updated: 2020/02/19 21:38:56 by alromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global _ft_strdup
		extern _malloc
		extern _ft_strlen
		extern  _ft_strcpy

		section .text
		
_ft_strdup:
		xor rax, rax
		cmp rdi, 0
		je  fallo
strlen:
		push rdi
		call _ft_strlen
		mov r11, rax
		pop rdi
mem_alloc:
		push rdi
		mov rdi, r11
		inc rdi
		call _malloc
		pop rdi
		mov r11, rax
		xor rax, rax
copy:
		mov rsi, rdi
		push rdi
		mov rdi, r11
		call _ft_strcpy
		pop rdi
fin: 
		mov rax, rax
		ret
fallo:
		mov rax, 0
		ret
