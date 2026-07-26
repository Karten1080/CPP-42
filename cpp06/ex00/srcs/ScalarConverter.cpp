#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter()
{ std::cout << "Default Constructor Called" << std::endl; };

ScalarConverter::ScalarConverter(std::string object) : _object(object)
{ std::cout << "Constructor Called" << std::endl; }

ScalarConverter::~ScalarConverter()
{ std::cout << "Destructor Constructor Called" << std::endl; };

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if(this != &src)
        this->_object = src._object;
    return *this;
}

bool  ScalarConverter::isChar(const std::string& object)
{
    if(object.size() != 1)
        return 0;
    if(std::isprint(object[0]))
        return 1;
    return 0;
    //check if work with '' : 'a';
}

bool  ScalarConverter::isInt(const std::string& object)
{
    if(object.empty())
        return false;
    size_t i = 0;
    if(object[0] == '-' || object[0] == '+')
    {
        i++;
        if(object.length() == 1)
            return false;
    }
    while(object[i++])
    {
        if(std::isdigit(static_cast<unsigned char>(object)))
            continue;
        else
            return false;
    }
    return true;
}

bool ScalarConverter::isDouble(const std::string& object)
{
    int i = 0;
    bool dot = false;
    bool digit = false;
    if(object.empty())
        return false;
    if(object[0] == '-' || object[0] == '+' || object[0] == '.')
    {
        if(object[0] == '.')
            return false;
        if(object.length() == 1)
            return false;
        if(!std::isdigit(object[1]))
            return false;
            i++;    
    }
    while(object[i])
    {
        if(object[i] == '.')
        {
            if (dot == true)
                return false;
            else
                dot = true;            
        }
        else if(object[i]  == '+' || object[i] == '-')
            return false;
        else if(std::isdigit(static_cast<unsigned char>(object[i])))
            digit = true;
        else
            return false;
        i++;            
    }
    return digit;
}

void ScalarConverter::parse(const std::string object)
{
    if(isChar(object))
        handleChar();
    else if(isInt(object))
        handleInt();
    else if(isDouble(object))
        int;
    else if(isFloat(object))
        int;
    else if(isPseudo(object))
        int;
}


void ScalarConverter::handleChar()
{


}


void ScalarConverter::convert(const std::string object)
{
        parse(object);


}