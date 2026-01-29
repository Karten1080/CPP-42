/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:17:57 by asmati            #+#    #+#             */
/*   Updated: 2026/01/29 13:46:15 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Setter = DOnne une valeur
//Getter = Demande la valeur

#include "Contact.hpp"

//constructeur 
Contact::Contact() {

};

//destructeur
Contact::~Contact(){

	
};

//Setters
void 	Contact::setFirstName(std::string str) {
    this->_firstName = str;
}

void  Contact::setLastName(std::string str){
	this->_lastName = str;
}

void  Contact::setNickName(std::string str){
	this->_nickname = str;
}

void  Contact::setPhoneNumber(std::string str){
	this->_phoneNumber = str;
}

void  Contact::setDarkestsecret(std::string str){
	this->_darkestsecret = str;
}

//GETTERS

std::string Contact::getFirstName() const {
    return (this->_firstName);
}

std::string Contact::getLastName() const {
    return (this->_lastName);
}

std::string Contact::getNickName() const {
    return (this->_nickname);
}

std::string Contact::getPhoneNumber() const {
    return (this->_phoneNumber);
}

std::string Contact::getDarkestsecret() const {
    return (this->_darkestsecret);
}

