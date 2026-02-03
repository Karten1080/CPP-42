/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:57:48 by asmati            #+#    #+#             */
/*   Updated: 2026/02/02 19:08:29 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _Name(name){}

Zombie::~Zombie(){
	std::cout << _Name << " has been destroyed" << std::endl;	
}

void Zombie::announce(){
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
