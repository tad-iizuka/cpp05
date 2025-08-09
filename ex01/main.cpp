/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/10 06:44:36 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <climits>

void	checkForm( std::string name, int grade );
void	signIn( std::string name, int grade );
// void	checkInc( std::string name, int grade );
// void	checkDec( std::string name, int grade );
void	GradeTooHighExceptionError( Form::GradeTooHighException& e );
void	GradeTooLowExceptionError( Form::GradeTooLowException& e );

int main( void )
{
	checkForm("default", 1);
	checkForm("default", 150);
	checkForm("default", 0);
	checkForm("default", -1);
	checkForm("default", INT_MAX);
	signIn("default", 1);
	// checkInc("Kelly", 2);
	// checkInc("Kelly", 1);
	// checkDec("Kelly", 149);
	// checkDec("Kelly", 150);
	return (EXIT_SUCCESS);
}

void	checkForm( std::string name, int grade )
{
	try {
		Form a( name, grade, grade );
		std::cout << a << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		GradeTooHighExceptionError(e);
	}
	catch (Form::GradeTooLowException& e)
	{
		GradeTooLowExceptionError(e);
	}
}

void	signIn( std::string name, int grade )
{
	Bureaucrat b("kelly", 2);
	try {
		Form a( name, grade, grade );
		a.beSigned(&b);
		a.beSigned(&b);
		// std::cout << a << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		GradeTooHighExceptionError(e);
	}
	catch (Form::GradeTooLowException& e)
	{
		GradeTooLowExceptionError(e);
	}
}

// void	checkInc( std::string name, int grade )
// {
// 	try {
// 		Form a( name, grade );
// 		a.incGrade();
// 		std::cout << a << std::endl;
// 	}
// 	catch (Form::GradeTooHighException& e)
// 	{
// 		GradeTooHighExceptionError(e);
// 	}
// 	catch (Form::GradeTooLowException& e)
// 	{
// 		GradeTooLowExceptionError(e);
// 	}
// }

// void	checkDec( std::string name, int grade )
// {
// 	try {
// 		Form a( name, grade );
// 		a.decGrade();
// 		std::cout << a << std::endl;
// 	}
// 	catch (Form::GradeTooHighException& e)
// 	{
// 		GradeTooHighExceptionError(e);
// 	}
// 	catch (Form::GradeTooLowException& e)
// 	{
// 		GradeTooLowExceptionError(e);
// 	}
// }

void	GradeTooHighExceptionError( Form::GradeTooHighException& e )
{
		std::cout
			<< C_R
			<< "Exception occurred: Level Too High." << std::endl
			<< C_W
			<< "Form name [" << e.what() << "]"
			<< " sign level [" << e.sign() << "]"
			<< " exec level [" << e.exec() << "]"
			<< C_CLR
			<< std::endl;
}

void	GradeTooLowExceptionError( Form::GradeTooLowException& e )
{
		std::cout
			<< C_R
			<< "Exception occurred: Level Too Low." << std::endl
			<< C_W
			<< "Form name [" << e.what() << "]"
			<< " sign level [" << e.sign() << "]"
			<< " exec level [" << e.exec() << "]"
			<< C_CLR
			<< std::endl;
}
