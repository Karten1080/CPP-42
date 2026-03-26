/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:46:16 by asmati            #+#    #+#             */
/*   Updated: 2026/03/24 12:28:03 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


ClapTrap::ClapTrap(const std::string& name) : _Name(name) , Hit_points(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
};


void ClapTrap::attack(const std::string& target){
	if(Energy_points <= 0 || Hit_points <= 0){
		std::cout << "ClapTrap: " << "you do not have enough energy points for attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap: " << _Name << " Attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
	Energy_points--;
}	
void ClapTrap::takeDamage(unsigned int amount){
    Hit_points -= amount;
    std::cout << "ClapTrap: " << _Name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
		if(Energy_points <= 0 || Hit_points <= 0){
			std::cout << "ClapTrap can’t do anything if it has no energy points left." << std::endl;
			return ;
		}
		Energy_points--;
		Hit_points += amount;
		std::cout << "ClapTrap: " << _Name << " heals " << amount << " hit points!" << std::endl;
		return;
}