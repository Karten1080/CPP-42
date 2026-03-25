/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/21 22:32:26 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& name) : _Name(name) , Hit_points(10), Energy_points(10), Attack_damage(0){};

void ClapTrap::attack(const std::string& target){
	if(Energy_points < 1){
		std::cout << "you do not have enough energy points for attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _Name << " Attack " << target << ", causing" << Attack_damage << " points of damage!" << std::endl;
	Energy_points--;
	takeDamage(10);
}	

void ClapTrap::takeDamage(unsigned int amount){
	Hit_points -= amount;
	std::cout << "ClapTrap " << _Name <<  " take " << amount << "of domage! " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){<
	if(Energy_points < 1){
		std::cout << "you do not have enough energy points for heal>" << std::endl;
		return ;
	}
	Energy_points--;
	std::cout << "ClapTrap " << _Name << " heals " << amount << " hit points!" << std::endl;
}