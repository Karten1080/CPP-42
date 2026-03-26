/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/24 14:48:51 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
    Hit_points =  100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap: " << _Name << " is born from the ashes of a ClapTrap!" << std::endl; 
};

FragTrap::~FragTrap(){
	std::cout << "FragTrap: Destructor called" << std::endl;
};

void FragTrap::attack(const std::string& target){
	if(Energy_points <= 0 || Hit_points <= 0){
		std::cout << "FragTrap: " << "you do not have enough energy points for attack" << std::endl;
		return ;
	}
	std::cout << "FragTrap: " << _Name << " Attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_points--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _Name << ": Hey guys! High five? Anyone? Please don't leave me hanging! ✋" << std::endl;
}
