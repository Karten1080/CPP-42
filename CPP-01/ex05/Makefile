# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asmati <asmati@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/24 10:57:40 by asmati            #+#    #+#              #
#    Updated: 2026/02/12 11:14:29 by asmati           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = Harl

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

SRCS        = ./srcs/main.cpp \
              ./srcs/Harl.cpp

# L'option -I doit être utilisée pendant la compilation des .o
INCLUDES    = -I ./includes

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

# Commande de link final
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Règle de compilation des fichiers objets
# On ajoute $(INCLUDES) ici pour que le compilo trouve tes .hpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re