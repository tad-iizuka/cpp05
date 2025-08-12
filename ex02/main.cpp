/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:09:03 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 14:11:46 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cstdlib>
#include <climits>

void	checkForm( std::string name, int grade );
void	signIn( std::string name, int grade );

int main( void )
{
	checkForm("default", 1);
	checkForm("default", 150);
	checkForm("default", 0);
	checkForm("default", -1);
	checkForm("default", INT_MAX);
	signIn("default", 1);
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
		Log::a(F, L, C_R, "GradeTooHighException [" + name + "]",
			"[" + Log::itoa(grade) + "]",
			"[" + Log::itoa(grade) + "]");
	}
	catch (Form::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException [" + name + "]",
			"[" + Log::itoa(grade) + "]",
			"[" + Log::itoa(grade) + "]");
	}
}

void	signIn( std::string name, int grade )
{
	Bureaucrat b("kelly", 2);
	try {
		Form a( name, grade, grade );
		a.beSigned(&b);
		a.beSigned(&b);
	}
	catch (Form::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException [" + name + "]",
			"[" + Log::itoa(grade) + "]",
			"[" + Log::itoa(grade) + "]");
	}
	catch (Form::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException [" + name + "]",
			"[" + Log::itoa(grade) + "]",
			"[" + Log::itoa(grade) + "]");
	}
}
