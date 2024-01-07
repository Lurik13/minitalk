# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lribette <lribette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 11:49:18 by lribette          #+#    #+#              #
#    Updated: 2024/01/07 17:51:55 by lribette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_SOURCES = server.c utils.c
CLIENT_SOURCES = client.c utils.c
PRINTF = ft_printf/libftprintf.a

SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJECTS) $(PRINTF)
	$(CC) $(SERVER_OBJECTS) $(PRINTF) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS) $(PRINTF)
	$(CC) $(CLIENT_OBJECTS) $(PRINTF) -o $(CLIENT)

$(PRINTF):
	make -C ./ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	make clean -C ./ft_printf

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re