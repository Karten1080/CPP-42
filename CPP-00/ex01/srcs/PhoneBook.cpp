/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:57:48 by asmati            #+#    #+#             */
/*   Updated: 2026/01/29 13:38:52 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "All.hpp"



std::string PhoneBook::truncate(std::string str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}


PhoneBook::PhoneBook() {
	this->_index = 0;
};
// Aucun champ me peut etre vide a prevoir une secur /
void	PhoneBook::addContact(){
	std::string input;
	int i = this->_index % 8;

	std::cout << "Entrer First Name: ";
	std::getline(std::cin,input);
	this->_contact[i].setFirstName(input);
	
	std::cout << "Entrer Last Name: ";
	std::getline(std::cin,input);
	this->_contact[i].setLastName(input);

	std::cout << "Entrer Nick name: ";
	std::getline(std::cin,input);
	this->_contact[i].setNickName(input);
	
	std::cout << "Entrer Phone number: ";
	std::getline(std::cin,input);
	this->_contact[i].setPhoneNumber(input);

	std::cout << "Entrer darkest secret: ";
	std::getline(std::cin,input);
	this->_contact[i].setDarkestsecret(input);
	
	this->_index++;
}

void	PhoneBook::searchContact(){
	int i = 0;
	int totalcontact = (this->_index < 8) ? this->_index : 8; 
	
	std::cout << "     Index|First Name| Last Name|  Nickname " << std::endl;
	for(i = 0; i < totalcontact; i++){
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(_contact[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(this->_contact[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncate(this->_contact[i].getNickName()) << std::endl;
	}

	std::cout << "Entre votre index : ";
	int index;
	std::cin >> index;
	if(std::cin.fail() || index < 0 || index >= totalcontact){
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		std::cout << "Index Invalid!" << std::endl;
		return;
	}	
	std::cin.ignore(10000,'\n');
	std::cout << "Fisrt Name: " << this->_contact[index].getFirstName() << std::endl;
	std::cout << "Fisrt Name: " << this->_contact[index].getLastName() << std::endl;
	std::cout << "Fisrt Name: " << this->_contact[index].getNickName() << std::endl;
	std::cout << "Fisrt Name: " << this->_contact[index].getPhoneNumber() << std::endl;
	std::cout << "Fisrt Name: " << this->_contact[index].getDarkestsecret() << std::endl;

}