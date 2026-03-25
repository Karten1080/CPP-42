# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmati <asmati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 11:00:24 by asmati            #+#    #+#              #
#    Updated: 2026/03/25 15:31:06 by asmati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = Polymorphisme

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = ./srcs/main.cpp \
              ./srcs/Cat.cpp \
			  ./srcs/Dog.cpp \
			  ./srcs/Animal.cpp \
			   ./srcs/WrongAnimal.cpp \
			   ./srcs/WrongCat.cpp

INCLUDES    = -I ./includes

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re