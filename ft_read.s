# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alromero <alromero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 15:20:25 by alromero          #+#    #+#              #
#    Updated: 2020/02/15 15:22:40 by alromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

		global _ft_read

section .text

_ft_read:
		mov rax, 0x200004
		syscall
		ret