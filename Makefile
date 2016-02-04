# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbert <ealbert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 16:04:31 by ealbert           #+#    #+#              #
#    Updated: 2016/02/04 19:15:14 by ealbert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPIL = gcc -o morse -I includes/

SRCS = srcs/main_read.c srcs/error_conv.c srcs/42_funcs.c

all :
	@$(COMPIL) $(SRCS)

clean :
	@rm morse

re : clean all
