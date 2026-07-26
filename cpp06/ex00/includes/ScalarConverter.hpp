/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 11:07:35 by asmati            #+#    #+#             */
/*   Updated: 2026/06/19 13:14:34 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
 #define ScalarConverter_HPP
#include <string>
#include <iostream>
#include <unistd.h>

class ScalarConverter
{
private:
    std::string _object;
    
    ScalarConverter();
    ScalarConverter(std::string object);
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &src);
    

public:
    
    static void convert(const std::string object);
    static void parse(const std::string object);
    
    static void handleChar();
    static void handleInt();

    static bool isChar(const  std::string& object);
    static bool isInt(const std::string& object);
    static bool isFloat(const std::string& object);
    static bool isDouble(const std::string& object);
    static bool isPseudo(const std::string& object);


};
#endif 