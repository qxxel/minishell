NAME				=	libft.a

SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
BUILD_DIR			=	.build

SOURCES				=	free_nptr.c					\
						ft_abs.c					\
						ft_atoi.c					\
						ft_bzero.c					\
						ft_calloc.c					\
						ft_isalnum.c				\
						ft_isalpha.c				\
						ft_isascii.c				\
						ft_isblank.c				\
						ft_iscntrl.c				\
						ft_isdigit.c				\
						ft_isgraph.c				\
						ft_islower.c				\
						ft_isprint.c				\
						ft_ispunct.c				\
						ft_isspace.c				\
						ft_isupper.c				\
						ft_isxdigit.c				\
						ft_itoa.c					\
						ft_lstadd_back.c			\
						ft_lstadd_front.c			\
						ft_lstclear.c				\
						ft_lstdelone.c				\
						ft_lstiter.c				\
						ft_lstlast.c				\
						ft_lstmap.c					\
						ft_lstnew.c					\
						ft_lstshift.c				\
						ft_lstsize.c				\
						ft_memchr.c					\
						ft_memcmp.c					\
						ft_memcpy.c					\
						ft_memmove.c				\
						ft_memset.c					\
						ft_printf/conv_c.c			\
						ft_printf/conv_d.c			\
						ft_printf/conv_percent.c	\
						ft_printf/conv_s.c			\
						ft_printf/conv_u.c			\
						ft_printf/ft_dprintf.c		\
						ft_printf/ft_printf.c		\
						ft_printf/ft_vdprintf.c		\
						ft_printf/ft_vprintf.c		\
						ft_putchar_fd.c				\
						ft_putendl_fd.c				\
						ft_putnbr_fd.c				\
						ft_putstr_fd.c				\
						ft_split.c					\
						ft_strchr.c					\
						ft_strcmp.c					\
						ft_strdup.c					\
						ft_striteri.c				\
						ft_strjoin.c				\
						ft_strlcat.c				\
						ft_strlcpy.c				\
						ft_strlen.c					\
						ft_strmapi.c				\
						ft_strncmp.c				\
						ft_strnstr.c				\
						ft_strrchr.c				\
						ft_strtrim.c				\
						ft_substr.c					\
						ft_tolower.c				\
						ft_toupper.c				\
						get_next_line.c

CC					=	cc
CFLAGS				=	-I$(INCLUDE_DIR) -MD -Wall -Wextra -Werror
AR					=	ar
ARFLAGS				=	-c -r -s
RM					=	rm -rf
MKDIR				=	mkdir -p

OBJECTS				=	$(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.d))

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(BUILD_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)				:	$(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

clean				:
	$(RM) $(BUILD_DIR)

fclean				:
	$(RM) $(BUILD_DIR) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
