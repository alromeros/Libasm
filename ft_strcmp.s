# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alromero <alromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 16:07:49 by alromero          #+#    #+#              #
#    Updated: 2020/02/19 20:04:46 by alromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global _ft_strcmp
		
		section .text

	_ft_strcmp:
			xor rax, rax
	error: 
			cmp rdi, 0
			je equal
			cmp rsi, 0
			je equal
	error1:
			cmp BYTE[rdi + rax], 0
			je comp
	error2:
			cmp BYTE[rsi + rax], 0
			je comp
	compare:
			mov r14b, BYTE[rdi + rax]
			cmp BYTE[rsi + rax], r14b
			jne comp
			inc rax
			jmp error1
	comp: 
			mov r14b, BYTE[rdi + rax]
			cmp r14b, BYTE[rsi + rax]
			js less
			jne pos	
	equal:
			mov rax, 0
			ret
	less:
			mov rax, -1
			ret
	pos: 	
			mov rax, 1
			ret