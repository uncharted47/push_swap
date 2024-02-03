NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = SRC
GNL_DIR = GNL
BONUS = bonus
INCLUDES_DIR = includes
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC_FILES:.c=.o)
GNL_FILES = $(wildcard $(GNL_DIR)/*.c)
SRCBNS_FILES = $(wildcard $(BONUS)/*.c) $(GNL_FILES)
OBJBNS = $(SRCBNS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJBNS)
	$(CC) $(CFLAGS) $(OBJBNS)  -o $(NAME_BONUS)


clean:
	rm -f $(OBJ) $(OBJBNS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
