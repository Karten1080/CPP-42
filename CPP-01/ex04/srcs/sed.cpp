/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:08:28 by asmati            #+#    #+#             */
/*   Updated: 2026/02/10 12:46:46 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/sed.hpp"

Sed::Sed(const std::string& filename,const std::string& s1,const std::string& s2) : _filename (filename), _s1(s1), _s2(s2) {}


void Sed::process()
{
	std::string line;
	std::ifstream ifs(_filename.c_str());
	if(!ifs)
	{
		std::cerr << "Error: Cannot open file." << std::endl;
		return;
	}
	std::ofstream ofs((_filename + ".replace").c_str());
	while(getline(ifs,line))
	{
		std::size_t pos = 0;
		std::size_t last_pos = 0;
		while((pos = line.find(_s1,last_pos)) != std::string::npos)
		{
			ofs << line.substr(last_pos,pos - last_pos);
			ofs << _s2;
			last_pos = (pos + _s1.length());
		}
		ofs << line.substr(last_pos);
		if (!ifs.eof())
            ofs << '\n';
		}
}

Sed::~Sed()
{
	
}