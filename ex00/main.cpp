/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/08 21:16:44 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <climits>

void	check( std::string name, int grade );
void	checkInc( std::string name, int grade );
void	checkDec( std::string name, int grade );
void	GradeTooHighExceptionError( Bureaucrat::GradeTooHighException& e );
void	GradeTooLowExceptionError( Bureaucrat::GradeTooLowException& e );

int main( void )
{
	check("Kelly", 1);
	check("Kelly", 150);
	check("Kelly", 0);
	check("Kelly", -1);
	check("Kelly", INT_MAX);
	checkInc("Kelly", 2);
	checkInc("Kelly", 1);
	checkDec("Kelly", 149);
	checkDec("Kelly", 150);
	return (EXIT_SUCCESS);
}

void	check( std::string name, int grade )
{
	try {
		Bureaucrat a( name, grade );
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		GradeTooHighExceptionError(e);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		GradeTooLowExceptionError(e);
	}
}

void	checkInc( std::string name, int grade )
{
	try {
		Bureaucrat a( name, grade );
		a.incGrade();
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		GradeTooHighExceptionError(e);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		GradeTooLowExceptionError(e);
	}
}

void	checkDec( std::string name, int grade )
{
	try {
		Bureaucrat a( name, grade );
		a.decGrade();
		std::cout << a << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		GradeTooHighExceptionError(e);
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		GradeTooLowExceptionError(e);
	}
}

void	GradeTooHighExceptionError( Bureaucrat::GradeTooHighException& e )
{
		std::cout
			<< C_R
			<< "exception occurred: name [" << e.what() << "] grade ["
			<< e.grade() << "]"
			<< C_CLR
			<< std::endl;
}

void	GradeTooLowExceptionError( Bureaucrat::GradeTooLowException& e )
{
		std::cout
			<< C_R
			<< "exception occurred: name [" << e.what() << "] grade ["
			<< e.grade() << "]"
			<< C_CLR
			<< std::endl;
}
