/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:43:53 by asmati            #+#    #+#             */
/*   Updated: 2026/03/30 21:59:12 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default") , _grade(150){};

Bureaucrat::Bureaucrat(std::string name,int grade) : _name(name)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    if(this != &src)
        this->_grade = src._grade;
    return *this;    
}

Bureaucrat::~Bureaucrat(){};

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if(_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if(_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}


void    Bureaucrat::signForm(Form &src)
{
    try
    {
        src.beSigned(*this);
        std::cout<< _name << " signed " << src.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << _name << " couldn't sign " << src.getName() << " because " << e.what() << std::endl;
    }

        
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    
    return o;
}
