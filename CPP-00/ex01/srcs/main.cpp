/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:58:01 by asmati            #+#    #+#             */
/*   Updated: 2026/01/29 13:54:11 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook Myphonebook;
	std::string command;
	
	while(1)
	{
		std::cout << "Entrez votre command (ADD, SEARCH, EXIT) ";
		std::getline(std::cin,command);
		
		if(command == "ADD")
			Myphonebook.addContact();
		else if(command == "SEARCH")
			Myphonebook.searchContact();
		else if (command == "EXIT")
			break;
			


	}


	
}
