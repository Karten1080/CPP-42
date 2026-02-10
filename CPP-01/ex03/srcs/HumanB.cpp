/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:57:25 by asmati            #+#    #+#             */
/*   Updated: 2026/02/03 14:01:58 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(const std::string& Name) : _Name(Name), _Weapon(NULL){}

HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon& weapon)
{
	_Weapon = &weapon;
}

void HumanB::attack()
{
	if(_Weapon)
		std::cout << _Name << " attacks with their " << _Weapon->getType() << std::endl;
	else
		std::cout << _Name << " has no weapon" << std::endl;
}