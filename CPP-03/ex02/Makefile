# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmati <asmati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 11:00:24 by asmati            #+#    #+#              #
#    Updated: 2026/03/24 14:50:21 by asmati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = ScavTrap

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -g -std=c++98

SRCS        = ./srcs/main.cpp \
              ./srcs/ClapTrap.cpp \
			  ./srcs/ScavTrap.cpp \
			  ./srcs/FragTrap.cpp

INCLUDES    = -I./includes

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