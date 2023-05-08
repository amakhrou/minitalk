# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakhrou <amakhrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 14:55:40 by amakhrou          #+#    #+#              #
#    Updated: 2023/05/05 17:24:55 by amakhrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLNAME = client
SVNAME = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLSRC = client.c utilis.c
SVSRC = server.c utilis.c

all : $(CLNAME) $(SVNAME)
$(CLNAME) :
	$(CC) $(CFLAGS) $(CLSRC) -o $(CLNAME)
$(SVNAME) :
	$(CC) $(CFLAGS) $(SVSRC) -o $(SVNAME)

clean :
	@rm -rf $(CLNAME)
	@rm -rf $(SVNAME)
fclean : clean

re : fclean all