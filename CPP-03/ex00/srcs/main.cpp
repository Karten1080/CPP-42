/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:24 by asmati            #+#    #+#             */
/*   Updated: 2026/03/23 13:33:32 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {
    std::cout << "=== CRÉATION DES ROBOTS ===" << std::endl;
    ClapTrap robotA("R2D2");
    ClapTrap robotB("C3PO");

    std::cout << "\n=== DÉBUT DU COMBAT ===" << std::endl;
    
    // robotA attaque robotB
    robotA.attack("C3PO"); // Affiche le message et consomme 1 point d'énergie à robotA
    
    // Comme attack() ne fait pas les dégâts directement, on le fait manuellement sur la cible :
    // Attention, de base l'Attack_damage est à 0 !
    robotB.takeDamage(0); 

    std::cout << "\n=== SOINS ===" << std::endl;
    // robotB se soigne
    robotB.beRepaired(5); // Affiche le message, consomme 1 point d'énergie et rend 5 HP

    std::cout << "\n=== TEST D'ÉNERGIE ===" << std::endl;
    // On fait attaquer robotA en boucle pour vider son énergie (il en a 10 de base, -1 de la première attaque = 9)
    for (int i = 0; i < 10; i++) {
        robotA.attack("un mur");
    }

    std::cout << "\n=== FIN DU PROGRAMME ET DESTRUCTIONS ===" << std::endl;
    return 0; // Ici, tes destructeurs vont être appelés automatiquement !
}