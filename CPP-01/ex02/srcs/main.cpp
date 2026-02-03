/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:58:01 by asmati            #+#    #+#             */
/*   Updated: 2026/02/02 21:24:11 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;
	
	std::cout << "Address of brain:     " << &brain << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in stringREF: " << &stringREF << std::endl;

	std::cout << "Value of brain:       " << brain << std::endl;
	std::cout << "Value via stringPTR:  " << *stringPTR << std::endl;
	std::cout << "Value via stringREF:  " << stringREF << std::endl;
	return 0;
}
