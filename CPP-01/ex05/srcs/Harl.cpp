/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:11:05 by asmati            #+#    #+#             */
/*   Updated: 2026/02/18 10:46:26 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl()
{
	this->fonctions[0] = &Harl::debug;
	this->fonctions[1] = &Harl::info;
	this->fonctions[2] = &Harl::warning;
	this->fonctions[3] = &Harl::error;

};

Harl::~Harl(){};

void Harl::debug(void)	{	std::cout << " [DEBUG] : Si tu lis ça, c'est que mon code est plus intelligent que je ne le pensais " << std::endl;}

void Harl::info(void)	{	std::cout << " [INFO] : Tout se déroule comme prévu. Étrangement calme... " << std::endl; }

void Harl::error(void)	{	std::cout << " [ERROR] : Quelque chose s'est mal passé, mais j'ai été trop paresseux pour coder un message précis. " << std::endl; }

void Harl::warning(void){	std::cout << " [WARNING] : La logique tient avec du scotch, mais ça passe pour l'instant. " << std::endl; }

void Harl::complain(std::string level)
{
	Harl harl;
	int i = 0;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while(i < 4 && levels[i] != level)
		i++;
	if(i < 4)
		(this->*fonctions[i])();
	else
		std::cout << " Error Level not found" << std::endl;	
}

