NAME				=	minishell

SOURCES				=	builtins/ft_cd.c			\
						builtins/ft_echo.c			\
						builtins/ft_env.c			\
						builtins/ft_exit.c			\
						builtins/ft_export.c		\
						builtins/ft_pwd.c			\
						builtins/ft_unset.c			\
						destroy_msh.c				\
						expand_env.c				\
						free_cmds.c					\
						get_env_var.c				\
						init_envp.c					\
						init_msh.c					\
						minishell.c					\
						parse_cmds/check_syntax.c	\
						parse_cmds/expand_quotes.c	\
						parse_cmds/init_cmds.c		\
						parse_cmds/join_strs.c		\
						parse_cmds/msh_split.c		\
						parse_cmds/parse_cmds.c		\
						parse_cmds/sign_expansion.c	\
						parse_cmds/unsign_str.c		\
						set_env_var_id.c			\
						set_env_var.c				\
						shift_strs.c

LIBFT_DIR			=	libft
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
BUILD_DIR			=	build

CC					=	cc
CFLAGS				=	-I$(INCLUDE_DIR) -MD -Wall -Wextra -Werror -g
LFLAGS				=	-lreadline
RM					=	rm -rf
MKDIR				=	mkdir -p
VALGRIND			=	valgrind --trace-children=yes --track-fds=yes --show-error-list=yes --suppressions=.valgrind.supp --read-var-info=yes --leak-check=full --show-leak-kinds=all --track-origins=yes

LIBFT				=	$(LIBFT_DIR)/libft.a
OBJECTS				=	$(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(OBJECTS:.o=.d)

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(LIBFT)			:	FORCE
	$(MAKE) -C	$(LIBFT_DIR)

$(BUILD_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)				:	$(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

clean				:
	$(MAKE) -C	$(LIBFT_DIR) $@
	$(RM) $(BUILD_DIR)

fclean				:
	$(MAKE) -C	$(LIBFT_DIR) $@
	$(RM) $(BUILD_DIR) $(NAME)

re					:	fclean all

FORCE				:

leaks				:	$(NAME)
	$(VALGRIND) ./$<

.PHONY				:	all clean fclean re FORCE leaks
