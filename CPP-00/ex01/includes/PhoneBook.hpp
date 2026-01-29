/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:58:59 by asmati            #+#    #+#             */
/*   Updated: 2026/01/29 13:46:14 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook {

private:
	Contact _contact[8]; 
	int	_index;
	std::string truncate(std::string str);

public:
	PhoneBook(); //Constrcuteur
	~PhoneBook(); //Destructeur

	void addContact();
	void searchContact();

};

#endif