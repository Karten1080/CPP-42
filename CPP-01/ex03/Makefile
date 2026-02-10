# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmati <asmati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 10:57:40 by asmati            #+#    #+#              #
#    Updated: 2026/02/03 13:34:29 by asmati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Weapon

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  srcs/main.cpp \
		srcs/HumanA.cpp\
		srcs/HumanB.cpp\
		srcs/Weapon.cpp
INCLUDES = -I ./includes
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
