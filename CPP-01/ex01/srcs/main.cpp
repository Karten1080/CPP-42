/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:58:01 by asmati            #+#    #+#             */
/*   Updated: 2026/03/29 23:43:21 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int n = 9;

	std::cout << "--- Horde ---" << std::endl << std::endl;
	Zombie* horde = zombieHorde(n, "Bob");
	std::cout << std::endl << "--- Talk ---" << std::endl << std::endl;
	for(int i = 0; i < n; i++){
		horde[i].announce();
	}
	std::cout << std::endl << "--- END ---" << std::endl << std::endl;
	delete[] horde;
	return 0;
	
}