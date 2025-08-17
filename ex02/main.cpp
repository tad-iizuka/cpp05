/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/17 15:56:10 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <climits>

void	checkForm( std::string name );
void	signInShrubberyCreationForm( std::string name, std::string form, int grade );
void	signInRobotomyRequestForm( std::string name, std::string form, int grade );
void	signInPresidentialPardonForm( std::string name, std::string form, int grade );

int main( void )
{
	checkForm("default");
	signInShrubberyCreationForm("Marie", "ShrubberyCreationForm", 140);
	signInShrubberyCreationForm("Marie", "ShrubberyCreationForm", 150);
	signInShrubberyCreationForm("Marie", "ShrubberyCreationForm", 120);
	signInRobotomyRequestForm("Marie", "RobotomyRequestForm", 80);
	signInRobotomyRequestForm("Marie", "RobotomyRequestForm", 50);
	signInRobotomyRequestForm("Marie", "RobotomyRequestForm", 1);
	signInPresidentialPardonForm("Marie", "PresidentialPardonForm", 30);
	signInPresidentialPardonForm("Marie", "PresidentialPardonForm", 10);
	signInPresidentialPardonForm("Marie", "PresidentialPardonForm", 1);
	return (EXIT_SUCCESS);
}

void	checkForm( std::string name )
{
	try {
		ShrubberyCreationForm a( name );
		std::cout << a << std::endl;
		RobotomyRequestForm b( name );
		std::cout << b << std::endl;
		PresidentialPardonForm c( name );
		std::cout << c << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

void	signInShrubberyCreationForm( std::string name, std::string form, int grade )
{
	try {
		Bureaucrat bu(name, grade);
		ShrubberyCreationForm a( form );
		a.beSigned(bu);
		a.execute(bu);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

void	signInRobotomyRequestForm( std::string name, std::string form, int grade )
{
	try {
		Bureaucrat bu(name, grade);
		RobotomyRequestForm b( form );
		b.beSigned(bu);
		b.execute(bu);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

void	signInPresidentialPardonForm( std::string name, std::string form, int grade )
{
	try {
		Bureaucrat bu(name, grade);
		PresidentialPardonForm c( form );
		c.beSigned(bu);
		c.execute(bu);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}
