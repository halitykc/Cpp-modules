
NAME = Zombie

CXX= c++
CXXFLAG = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS =  Zombie.cpp main.cpp  newZombie.cpp  randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re