/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:36:59 by asmati            #+#    #+#             */
/*   Updated: 2026/01/13 12:26:23 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac,char **av)
{
	if(ac >= 2)
	{	
		for(int i = 1;i < ac; i++){
			for(int j = 0 ; av[i][j]; j++){
					std::cout << (char)std::toupper(av[i][j]);
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (1);	
}