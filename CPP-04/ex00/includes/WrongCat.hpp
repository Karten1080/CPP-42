/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/17 14:06:19 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
private:


public:

	WrongCat();
	~WrongCat();

	void makeSound() const;
};


#endif