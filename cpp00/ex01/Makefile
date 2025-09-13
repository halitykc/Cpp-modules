
NAME = phonebook

CCPP= c++
CPPFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = Functions.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CCPP) $(CPPFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re