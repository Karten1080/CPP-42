/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:58:01 by asmati            #+#    #+#             */
/*   Updated: 2026/02/02 20:31:18 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int n = 9;
	Zombie* horde = zombieHorde(n, "Bob");
	for(int i = 0; i < n; i++){
		horde[i].announce();
	}
	delete[] horde;
	return 0;
	
}