/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:43:56 by asmati            #+#    #+#             */
/*   Updated: 2026/03/30 21:50:04 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat boss("Le Boss", 1);
        Bureaucrat stagiaire("Stagiaire", 150);
        Form contrat("Contrat Ultra Secret", 10, 10);

        std::cout << contrat << std::endl; // Affiche l'état initial

        stagiaire.signForm(contrat); // Doit échouer et afficher le message d'erreur
        boss.signForm(contrat);      // Doit réussir

        std::cout << contrat << std::endl; // Doit être "signé: true"
    }
    catch (std::exception &e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }
    return 0;
}