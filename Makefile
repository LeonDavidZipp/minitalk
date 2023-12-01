# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 09:34:03 by lzipp             #+#    #+#              #
#    Updated: 2023/12/01 10:03:58 by lzipp            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENTNAME	:= client

SERVERNAME	:= server

CFLAGS	:= -Wextra -Wall -Werror

HEADERS	:= -I ./include

LIB := ./lib/libftprintf.a

CLIENTSRC	:=  client.c
SERVERSRC	:=  server.c
CLIENTOBJS	:= ${CLIENTSRC:.c=.o}
SERVEROBJS	:= ${SERVERSRC:.c=.o}

BONUSCLIENTSRC	:=  client_bonus.c
BONUSSERVERSRC	:=  server_bonus.c
BONUSCLIENTOBJS	:= ${BONUSCLIENTSRC:.c=.o}
BONUSSERVEROBJS	:= ${BONUSSERVERSRC:.c=.o}

CC		:= cc

all: $(CLIENTNAME) $(SERVERNAME)

bonus: b1 b2

cm: bonus clean

lib:
	make -C ./lib

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(CLIENTNAME): $(CLIENTOBJS) lib
	@$(CC) $(CLIENTOBJS) $(LIB) $(HEADERS) -o $(CLIENTNAME)
$(SERVERNAME): $(SERVEROBJS) lib
	@$(CC) $(SERVEROBJS) $(LIB) $(HEADERS) -o $(SERVERNAME)
	
b1: $(BONUSCLIENTOBJS) lib
	@$(CC) $(BONUSCLIENTOBJS) $(LIB) $(HEADERS) -o $(CLIENTNAME)
b2: $(BONUSSERVEROBJS) lib
	@$(CC) $(BONUSSERVEROBJS) $(LIB) $(HEADERS) -o $(SERVERNAME)

clean:
	make -C ./lib clean
	rm -rf $(CLIENTOBJS) $(SERVEROBJS)
	rm -rf $(BONUSCLIENTOBJS) $(BONUSSERVEROBJS)

fclean: clean
	make -C ./lib fclean
	rm -rf $(CLIENTNAME) $(SERVERNAME)

re: clean all

.PHONY: all, clean, fclean, re, lib