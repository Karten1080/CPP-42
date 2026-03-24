/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/24 14:03:44 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"


ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
    Hit_points =  100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap: " << _Name << " is born from the ashes of a ClapTrap!" << std::endl; 
};

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap: Destructor called" << std::endl;
};

void ScavTrap::attack(const std::string& target){
	if(Energy_points <= 0 || Hit_points <= 0){
		std::cout << "ScavTrap: " << "you do not have enough energy points for attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap: " << _Name << " Attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_points--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << _Name << " is now in Gatekeeper mode!" << std::endl;
}
