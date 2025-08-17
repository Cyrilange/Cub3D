NAME            = cub3D

CC              = gcc -g
CFLAGS          = -Wall -Wextra -Werror
MLX42_LIB       = ./Include/MLX42/build/libmlx42.a
MLX42_INCLUDE   = ./Include/MLX42/include
LIBFT           = ./Include/libft
FT_PRINTF       = ./Include/ft_printf
GNL             = ./Include/get_next_line
INCLUDES        = -I$(MLX42_INCLUDE) -IInclude -I$(LIBFT) -I$(FT_PRINTF) -I$(GNL)
LIBS            = -L./Include/MLX42/build -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf -g

SRC_DIR         = ./Src
OBJ_DIR         = ./obj

SRC_FILES       = main.c
OBJS            = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

PINK            = \033[1;35m
RESET           = \033[0m

all: $(NAME)

# Build MLX42
$(MLX42_LIB):
	cmake -B Include/MLX42/build -S ./Include/MLX42
	cmake --build Include/MLX42/build -j4

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(MLX42_LIB)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(GNL)/libgnl.a $(MLX42_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@clear
	@echo "\n\n\n"
	@echo "$(PINK)"
	@echo "                 ,----..                                    ,---,.          /   /     '.              ,---,     "
	@echo "                /   /   \\\\                  ,--,           ,'  .'  \\\\        / ../        ;           .'  .' \\\\   "
	@echo "               |   :     :               ,'_ /|         ,---.' .' |        \\\\ ''\\\\  .'-    '        ,---.'     \\\\  "
	@echo "               .   |  ;. /          .--. |  | :         |   |  |: |         \\\\___\\\\/   \\\\   :        |   |  .\\\\\\\\  | "
	@echo "               .   ; /--\`         ,'_ /| :  . |         :   :  :  /              \\\\   :   |        :   : |  '  | "
	@echo "               ;   | ;            |  ' | |  . .         :   |    ;               /  /   /         |   ' '  ;  : "
	@echo "               |   : |            |  | ' |  | |         |   :     \\\\              \\\\  \\\\   \\\\         '   | ;  .  | "
	@echo "               .   | '___         :  | | :  ' ;         |   |   . |          ___ /   :   |        |   | :  |  ' "
	@echo "               '   ; : .'|        |  ; ' |  | '         '   :  '; |         /   /\\\\   /   :        '   : | /  ;  "
	@echo "               '   | '/  :        :  | : ;  ; |         |   |  | ;         / ,,/  ',-    .        |   | '\` ,/   "
	@echo "               |   :    /         '  :  \`--'   \\\\        |   :   /          \\\\ ''\\\\        ;         ;   :  .'     "
	@echo "                \\\\   \\\\ .'          :  ,      .-./        |   | ,'            \\\\   \\\\     .'          |   ,.'       "
	@echo "                 \`---\`             \`--\`----'            \`----'               \`--\`-,,-'            '---'         "
	@echo "\n"
	@echo "$(RESET)"
	@echo "\033[1;34m                                     <usage> <./cub3D> <includes/maps/map.yourchoice> \033[0m"
	@echo "\n\n\n"









# Build Libft
$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

# Build ft_printf
$(FT_PRINTF)/libftprintf.a:
	@$(MAKE) -C $(FT_PRINTF)

# Build GNL
$(GNL)/libgnl.a:
	@$(MAKE) -C $(GNL)

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	@$(MAKE) -C $(GNL) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(PINK)$(NAME) BYE$(RESET)"

fclean: clean
	@rm -f $(NAME) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a $(GNL)/libgnl.a
	@echo "$(PINK)$(NAME) BYE$(RESET)"

re: fclean all

.PHONY: all clean fclean re
