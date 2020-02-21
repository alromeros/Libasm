# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alromero <alromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 12:54:37 by alromero          #+#    #+#              #
#    Updated: 2020/02/20 18:24:29 by alromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global _ft_strlen

section .text
	
_ft_strlen:
		mov rax, 0
		cmp rdi, 0
		je finish
comp:	
		cmp BYTE[rdi + rax], 0 
		je  finish
inc:
		inc	rax
		jmp comp
finish: 
		ret
