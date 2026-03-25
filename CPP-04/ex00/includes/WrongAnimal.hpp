/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/17 14:06:19 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>


class WrongAnimal {
protected:
 	std::string type;


public:
	WrongAnimal();
    ~WrongAnimal(); 
    void makeSound() const; 
    std::string getType() const;
};



#endif