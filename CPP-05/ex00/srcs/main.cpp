/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:43:56 by asmati            #+#    #+#             */
/*   Updated: 2026/03/30 21:48:01 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try{
         Bureaucrat chef("Arthur",1);
        chef.incrementGrade();
        std::cout << chef << std::endl;

        std::cout << "Ceci ne s'affichera pas" << std::endl;        
        
    }
    catch (std::exception & e){
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    std::cout << "  FIN de test c propre" <<  std::endl;
    return 0;
}