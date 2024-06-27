NAME				=	minishell

SOURCES				=	builtins/ft_cd.c			\
						builtins/ft_echo.c			\
						builtins/ft_env.c			\
						builtins/ft_export.c		\
						builtins/ft_pwd.c		\
						free_cmds.c					\
						free_msh.c					\
						get_env_var.c				\
						init_msh.c					\
						minishell.c					\
						parse_cmds/check_syntax.c	\
						parse_cmds/expand_env.c		\
						parse_cmds/expand_quotes.c	\
						parse_cmds/init_cmds.c		\
						parse_cmds/join_strs.c		\
						parse_cmds/msh_split.c		\
						parse_cmds/parse_cmds.c		\
						parse_cmds/shift_strs.c		\
						parse_cmds/sign_quotes.c	\
						parse_cmds/unsign_str.c		\
						set_env_var.c				\
						set_env_var_id.c

LIBFT_DIR			=	libft
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
BUILD_DIR			=	build

CC					=	cc
CFLAGS				=	-I$(INCLUDE_DIR) -MD -Wall -Wextra -Werror -g
LFLAGS				=	-lreadline
RM					=	rm -rf
MKDIR				=	mkdir -p

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

.PHONY				:	all clean fclean re FORCE
