/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/10 02:30:50 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <cstdlib>
#include <climits>

void	check( std::string name, int grade );
// void	checkInc( std::string name, int grade );
// void	checkDec( std::string name, int grade );
void	GradeTooHighExceptionError( Form::GradeTooHighException& e );
void	GradeTooLowExceptionError( Form::GradeTooLowException& e );

int main( void )
{
	check("Kelly", 1);
	check("Kelly", 150);
	check("Kelly", 0);
	check("Kelly", -1);
	check("Kelly", INT_MAX);
	// checkInc("Kelly", 2);
	// checkInc("Kelly", 1);
	// checkDec("Kelly", 149);
	// checkDec("Kelly", 150);
	return (EXIT_SUCCESS);
}

void	check( std::string name, int grade )
{
	try {
		// Form a( name, grade );
		Bureaucrat a( name, grade );
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
			<< "Exception occurred: name [" << e.what() << "] grade ["
			<< e.grade() << "] is too high."
			<< C_CLR
			<< std::endl;
}

void	GradeTooLowExceptionError( Form::GradeTooLowException& e )
{
		std::cout
			<< C_R
			<< "Exception occurred: name [" << e.what() << "] grade ["
			<< e.grade() << "] is too low."
			<< C_CLR
			<< std::endl;
}
