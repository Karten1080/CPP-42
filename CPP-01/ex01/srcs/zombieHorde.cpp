/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:08:22 by asmati            #+#    #+#             */
/*   Updated: 2026/02/02 19:54:42 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name ){
	
	Zombie* horde = new Zombie[N];
	for(int i = 0;i < N;i++){
		horde[i].setName(name);
	}
	return horde;
}