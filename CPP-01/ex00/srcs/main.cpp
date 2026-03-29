/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:58:01 by asmati            #+#    #+#             */
/*   Updated: 2026/03/28 20:30:33 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
	randomChump("Sal");
	
	Zombie* newZB = newZombie("line");
	newZB->announce();
	delete newZB;
	return 0;
}