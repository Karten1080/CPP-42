/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:57:25 by asmati            #+#    #+#             */
/*   Updated: 2026/02/05 14:55:10 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Sed {
private:

	std::string _filename;
	std::string _s1;
	std::string _s2;

public:
	Sed(const std::string& filename,const std::string& s1,const std::string& s2);
	~Sed();

	void process();
};

#endif