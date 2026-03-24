/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:00:18 by asmati            #+#    #+#             */
/*   Updated: 2026/03/24 13:45:47 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
#include "ClapTrap.hpp"



class ScavTrap : public ClapTrap {
private:
    int* specialGun;
public:
    ScavTrap(const std::string& name);
    ~ScavTrap();

    void attack(const std::string& target);

    void guardGate();
};
#endif