NAME 	:= 2048
LIB	:= ./lib/


LIBFTNAME	:= 
LIBFT		:= 

OBJDIR		:= ./obj

SRCDIR	:= ./srcs/
SRC	:= init.c menu.c print_borad.c numbers.c two_powers.c play.c board.c check.c util.c ft_atoi.c ft_itoa.c
ENTRY	:= main.c
ENTRYBONUS	:= main_bonus.c
DELENTRY	:= $(OBJDIR)/main_bonus.o
ifdef WITH_BONUS
ENTRY	:= $(ENTRYBONUS)
DELENTRY	:= $(OBJDIR)/main.o
SRC	+= best_score.c 
endif
SRC	+= $(ENTRY)

SRCS	:= $(addprefix $(SRCDIR), $(SRC))
OBJS	:= $(SRCS:.c=.o)
OBJECTS	:= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS	:= $(OBJECTS:.o=.d)
INCS	:= ./include 

LIBDIRS	:= $(LIBFTDIR)
IFLAGS	:= $(addprefix -I,$(INCS))
LFLAGS	:= $(addprefix -L,$(LIBDIRS))
LIBS	:= $(LIBFT)

CC	:= cc
ifdef WITH_BONUS
CFLAGS	:= -Wall -Wextra -Werror -D WITH_BONUS=1
else
CFLAGS	:= -Wall -Wextra -Werror
endif
LDFLAGS := $(IFLAGS) $(LFLAGS) -lncurses

all:
	@make $(NAME)	

$(NAME)	:	$(OBJECTS) $(LIBS) 
		$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
		$(RM) $(DELENTRY)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) / $(*D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -MMD -MP -MF $(OBJDIR)/$*.d  -o $@
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean	:
			$(RM) $(OBJECTS)
			$(RM) $(DEPS)
			$(RM) $(OBJDIR)/$(ENTRYBONUS:.c=.o)
			$(RM) $(OBJDIR)/$(ENTRYBONUS:.c=.d)
			$(RM) $(SRC)/best_score.c

fclean	:	clean
			$(RM) $(NAME)
			$(RM) $(LIBS)

re	:		fclean all

bonus	:	
			@make WITH_BONUS=1

ifeq ($(findstring clean,$(MAKECMDGOALS)),)
-include $(DEPS)
endif

.PHONY: all clean fclean re bonus
