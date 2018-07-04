INC          = /usr/include

INCLIB       = $(INC)/../lib

CC          := gcc

RM          := rm -rf

CFLAGS      += -I$(INC) -I../minilibx -Wall -Wextra -Werror -g

SRCS        := $(wildcard ./*.c)

OBJS        := $(SRCS:.c=.o)

NAME		    := vm_graphics

all:        $(NAME)

$(NAME):    $(OBJS)
	          $(CC) -o $(NAME) $(OBJS) -L../minilibx -l mlx  -L$(INCLIB) -lXext -lX11 -lm -lbsd

clean:
						$(RM) $(OBJS)

re:         clean all
