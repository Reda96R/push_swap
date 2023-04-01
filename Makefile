NAME = push_swap
BONUS = checker
FILES_M = main.c 
FILES = ft_checkpoint.c ft_cleaner.c ft_errors_busters.c ft_helpers.c ft_lists.c ft_parsing.c ft_actions_0.c ft_actions_1.c ft_sorting0.c ft_sorting1.c ft_finders.c ft_placers.c ft_calculators.c ft_calculators1.c ft_appliers.c
BONUS_FILES = checker.c get_next_line.c get_next_line_utils.c
OBJS_M = $(FILES_M:.c=.o)
OBJS = $(FILES:.c=.o)
B_OBJS = $(BONUS_FILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(OBJS_M)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(NAME):::" $(NONE)
	@cc $(CFLAGS) $(OBJS) $(OBJS_M) -o $(NAME)
	@echo $(GREEN)":::Compiled:::"$(NONE)

$(BONUS): $(B_OBJS) $(OBJS)
	@echo $(CURSIVE)$(GRAY) ":::Compiling $(BONUS):::" $(NONE)
	@cc $(CFLAGS) $(B_OBJS) $(OBJS) -o $(BONUS)
	@echo $(GREEN)":::Compiled:::"$(NONE)

$(OBJS): $(FILES)
	@echo $(CURSIVE)$(GRAY) ":::Making object files:::" $(NONE)
	@cc $(CFLAGS) -c $(FILES)
	@echo $(GREEN)":::Done:::"$(NONE)

$(OBJS_M): $(FILES_M)
	@cc $(CFLAGS) -c $(FILES_M)

$(B_OBJS): $(BONUS_FILES)
	@echo $(CURSIVE)$(GRAY) ":::Making object files:::" $(NONE)
	@cc $(CFLAGS) -c $(BONUS_FILES)
	@echo $(GREEN)":::Done:::"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) ":::Deleting object files:::" $(NONE)
	@rm -f $(OBJS) $(B_OBJS) $(OBJS_M)
	@echo $(RED)":::Deleted:::"$(NONE)


fclean: clean
	@echo $(CURSIVE)$(GRAY) ":::Deleting executables:::" $(NONE)
	@rm -f $(NAME) $(BONUS)
	@echo $(RED)":::All deleted:::"$(NONE)

re: fclean all

.PHONY:all clean fclean re bonus

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
RED = '\033[1;31m'
YELLOW = '\033[1;33m'
CURSIVE='\033[3m'
