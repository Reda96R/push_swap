NAME = push_swap
FILES = main.c ft_checkers.c ft_cleaner.c ft_errors_busters.c ft_helpers.c ft_lists.c ft_parsing.c ft_actions_0.c ft_actions_1.c ft_sorting.c ft_sorting1.c ft_finders.c ft_placer.c ft_calculators.c ft_appliers.c
OBJS = $(FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address


all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(NAME):::" $(NONE)
	@gcc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)":::Compiled:::"$(NONE)

$(OBJS): $(FILES)
	@echo $(CURSIVE)$(GRAY) ":::Making object files:::" $(NONE)
	@gcc $(CFLAGS) -c $(FILES)
	@echo $(GREEN)":::Done:::"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) ":::Deleting object files:::" $(NONE)
	@rm -f $(OBJS)
	@echo $(RED)":::Deleted:::"$(NONE)


fclean: clean
	@echo $(CURSIVE)$(GRAY) ":::Deleting $(NAME):::" $(NONE)
	@rm -f $(NAME)
	@echo $(RED)":::All deleted:::"$(NONE)

re: fclean all

.PHONY:all clean fclean re 

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED = '\033[1;31m'
YELLOW = '\033[1;33m'
CURSIVE='\033[3m'
