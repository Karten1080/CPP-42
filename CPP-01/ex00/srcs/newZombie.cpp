/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:17:57 by asmati            #+#    #+#             */
/*   Updated: 2026/02/02 17:35:37 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Setter = DOnne une valeur
//Getter = Demande la valeur

#include "Zombie.hpp"

//constructeur 

Zombie* newZombie(std::string name){
	Zombie* zombie = new Zombie(name);
	return zombie;
}