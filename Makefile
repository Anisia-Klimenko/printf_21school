NAME	=	libftprintf.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

OBJDIR	=	obj
SRCDIR	=	src
LIBDIR	=	libft
INCDIR	=	$(LIBDIR)

HEADER	=	ft_printf.h


SRC		=	$(LIBDIR)/ft_putchar_fd.c	\
			$(LIBDIR)/ft_putnbr_fd.c	\
			$(LIBDIR)/ft_putstr_fd.c	\
			$(LIBDIR)/ft_itoa.c			\
			$(LIBDIR)/ft_toupper.c		\
			$(LIBDIR)/ft_strchr.c		\
			$(SRCDIR)/ft_putptr_fd.c	\
			$(SRCDIR)/ft_parse_str.c	\
			$(SRCDIR)/ft_putunb_fd.c	\
			$(SRCDIR)/ft_putxnb_fd.c	\
			ft_printf.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
LIB		=	$(LIBDIR)/libft.a

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@printf "Compilation OK! \n"
			@ar rcs $@ $^

$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER)
				@printf "Sources : \n"
				@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/%.o: 	%.c $(HEADER)
				@printf "Sources : \n"
				@$(CC) $(CFLAGS) -c $< -o $@
$(OBJDIR)/$(LIBDIR)/%.o: 	$(LIBDIR)/%.c $(HEADER)
							@printf "Libft : \n"
							@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	@mkdir $@ $@/$(LIBDIR) $@/$(SRCDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... \n"
	@rm -rf $(OBJDIR)

fclean: clean
	@printf "fclean... \n"
	@rm -rf $(NAME)

re: fclean all
