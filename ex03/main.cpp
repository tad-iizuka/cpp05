/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 06:35:49 by tiizuka          ###   ########.fr       */
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
	signInShrubberyCreationForm("Marie", "ShrubberyCreationForm", 1);
	signInRobotomyRequestForm("Marie", "RobotomyRequestForm", 1);
	signInPresidentialPardonForm("Marie", "PresidentialPardonForm", 1);
	return (EXIT_SUCCESS);
}

void	checkForm( std::string name )
{
	try {
		ShrubberyCreationForm a( name );
		RobotomyRequestForm b( name );
		PresidentialPardonForm c( name );
		std::cout << a << std::endl;
	}
	catch (AForm::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what());
	}
	catch (AForm::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what());
	}
}

void	signInShrubberyCreationForm( std::string name, std::string form, int grade )
{
	Bureaucrat *bu;
	try {
		bu = new Bureaucrat(name, grade);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what(), Log::itoa(grade));
		return;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what(), Log::itoa(grade));
		return;
	}
	try {
		ShrubberyCreationForm a( form );
		a.beSigned(*bu);
		if (a.getStatus())
			a.execute(*bu);
	}
	catch (AForm::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what());
	}
	catch (AForm::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what());
	}
}

void	signInRobotomyRequestForm( std::string name, std::string form, int grade )
{
	Bureaucrat *bu;
	try {
		bu = new Bureaucrat(name, grade);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what(), Log::itoa(grade));
		return;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what(), Log::itoa(grade));
		return;
	}
	try {
		RobotomyRequestForm b( form );
		b.beSigned(*bu);
		b.execute(*bu);
	}
	catch (AForm::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what());
	}
	catch (AForm::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what());
	}
}

void	signInPresidentialPardonForm( std::string name, std::string form, int grade )
{
	Bureaucrat *bu;
	try {
		bu = new Bureaucrat(name, grade);
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what(), Log::itoa(grade));
		return;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what(), Log::itoa(grade));
		return;
	}
	try {
		PresidentialPardonForm c( form );
		c.beSigned(*bu);
		c.execute(*bu);
	}
	catch (AForm::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what());
	}
	catch (AForm::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what());
	}
	// delete bu;
}
