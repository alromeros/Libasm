# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alromero <alromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 17:07:17 by alromero          #+#    #+#              #
#    Updated: 2020/02/20 18:27:23 by alromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	global _ft_strcpy
	
	section .text

_ft_strcpy:
		xor rax, rax
error1:
		cmp rdi, 0
		je fallo
error2:
		cmp rsi, 0
		je fallo
copy:
		mov r11b, BYTE[rsi + rax] 
		mov BYTE[rdi + rax], r11b
		cmp BYTE[rsi + rax], 0
		je fin
		inc rax
		jmp copy
fin:
		mov rax, rdi
		ret
fallo:	
		mov rax, rdi
		ret