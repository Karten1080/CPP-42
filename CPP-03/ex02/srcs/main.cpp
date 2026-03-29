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
#include "FragTrap.hpp"

int main() {
    std::cout << "=== CRÉATION ===" << std::endl;
    ClapTrap Clap("C3PO");
    ClapTrap* Scav = new ScavTrap("R2D2");
    ClapTrap* Frag = new FragTrap("R2D2");
    
    std::cout << "\n=== FIGHT ===" << std::endl;
    Clap.attack("Scav");
    Scav->attack("Frag");
    Frag->attack("Clap");
    std::cout << "\n=== HEAL ===" << std::endl;
    Clap.beRepaired(10);
    Scav->beRepaired(15);
    Frag->beRepaired(20);
    
    std::cout << "\n=== Dommage ===" << std::endl;
    Clap.takeDamage(10);
    Scav->takeDamage(15);
    Frag->takeDamage(20);
    
    std::cout << "\n=== TEST STAMINA ===" << std::endl;
    for (int i = 0; i < 10; i++) {
        Clap.attack("Scav");
        Scav->attack("Frag");
        Frag->attack("Clap");
    }   
    std::cout << "\n=== FONCTIONS SPECIAL ===" << std::endl;
    ((ScavTrap*)Scav)->guardGate();
    ((FragTrap*)Frag)->highFivesGuys();
    
    std::cout << "\n=== DESTRUCTIONS ===" << std::endl;\
    delete Scav;
    delete Frag;
    return 0; 
}

