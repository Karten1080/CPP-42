/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:57:48 by asmati            #+#    #+#             */
/*   Updated: 2026/02/02 20:33:26 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	    std::cout << "Zombie created" << std::endl;

}

Zombie::~Zombie(){
	std::cout << _Name << " has been destroyed" << std::endl;	
}

void Zombie::announce(){
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name ){
	_Name = name;
}