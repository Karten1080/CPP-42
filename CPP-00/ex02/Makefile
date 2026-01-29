# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmati <asmati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 10:57:45 by asmati            #+#    #+#              #
#    Updated: 2026/01/29 23:46:05 by asmati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AccountBook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ./srcs/Account.cpp ./srcs/tests.cpp 
INCLUDES = -I ./includes
OBJS = $(SRCS:.cpp=.o)

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