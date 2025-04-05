# Nombre del ejecutable
NAME = program

# Compilador
CC = gcc

# Flags de compilación
CFLAGS =  
#CFLAGS = -Wall -Wextra -Werror

# Encuentra todos los archivos .c en el proyecto (excluye la carpeta 'exclude')
SRC = $(shell find . -type f -name "*.c" ! -path "./exclude/*")

# Encuentra los directorios que contienen archivos .h (excluye 'exclude')
INCLUDES = $(shell find . -type d -not -path "./externals/*" -not -path "./exclude")

# Convierte archivos .c en archivos .o
OBJ = $(SRC:.c=.o)

# Flags de enlace para MiniLibX en Linux
LDFLAGS = -Lminilibx -lmlx_Linux -Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

# Regla principal: compilar el programa
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

# Regla para compilar los archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJ)

# Limpiar todo (incluyendo el ejecutable)
fclean: clean
	rm -f $(NAME)

# Recompilar desde cero
re: fclean $(NAME)

# Evitar que make interprete los nombres de las reglas como archivos
.PHONY: clean fclean re
