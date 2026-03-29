/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/28 20:30:33 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== CRÉATION ===" << std::endl;
    ClapTrap robotB("C3PO");
    ClapTrap* polyPtr = new ScavTrap("R2D2");

    std::cout << "\n=== FIGHT ===" << std::endl;
    polyPtr->attack("C3PO");
    robotB.attack("PolyPtr");

    std::cout << "\n=== HEAL ===" << std::endl;
    robotB.beRepaired(10);
    polyPtr->beRepaired(15);
    
    std::cout << "\n=== TEST STAMINA ===" << std::endl;
    for (int i = 0; i < 10; i++) {
        polyPtr->attack("un mur");
        robotB.attack("C3PO");
    }   

    std::cout << "\n=== DESTRUCTIONS ===" << std::endl;\
    delete polyPtr;
    return 0; 
}

