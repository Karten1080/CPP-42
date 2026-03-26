/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/24 14:51:36 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP
# include <iostream>


class ClapTrap {
protected:
	std::string 	_Name;
	int 			Hit_points;
	int 			Energy_points;
	int 			Attack_damage;

public:
	
	ClapTrap(const std::string& name);
    virtual ~ClapTrap();

	virtual void	 attack(const std::string& target);
	virtual void	 takeDamage(unsigned int amount);
	virtual void	 beRepaired(unsigned int amount);
	
};

#endif