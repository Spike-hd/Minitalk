# Fichiers sources
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

# Fichiers objets
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
B_SERVER_OBJS = $(SERVER_BONUS_SRCS:.c=.o)
B_CLIENT_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Bibliothèques et headers
LIB = libftprintf.a
INC = minitalk.h ft_printf.h

# Noms des exécutables
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Règle par défaut : compiler les deux exécutables
all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

# Création de l'exécutable serveur / client
$(SERVER): $(SERVER_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) -L. -lftprintf
$(CLIENT): $(CLIENT_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) -L. -lftprintf

# Création de l'exécutable serveur / client bonus
$(SERVER_BONUS): $(B_SERVER_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(B_SERVER_OBJS) -L. -lftprintf
$(CLIENT_BONUS): $(B_CLIENT_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(B_CLIENT_OBJS) -L. -lftprintf


# Compilation des fichiers .c en .o, avec dépendance à minitalk.h
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

# Nettoyage des fichiers objets
clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(B_SERVER_OBJS) $(B_CLIENT_OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

# Recompilation complète
re: fclean all

# Marque que les règles ne sont pas des fichiers
.PHONY: all clean fclean re
