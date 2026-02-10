/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:57:01 by asmati            #+#    #+#             */
/*   Updated: 2026/02/03 13:27:44 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string& name,Weapon& weapon) : _Name(name),_Weapon(weapon){}

HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << _Name << " attacks with their " << _Weapon.getType()<< std::endl; 
}
	

