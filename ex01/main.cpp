/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 20:29:54 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <climits>

void	checkForm( std::string name );
void	signIn( std::string name, std::string form, int grade );

int main( void )
{
	checkForm("default");
	signIn("Marie", "form-ex01", 1);
	signIn("Marie", "form-ex01", 0);
	signIn("Marie", "form-ex01", 151);
	return (EXIT_SUCCESS);
}

void	checkForm( std::string name )
{
	try {
		Form a( name );
		std::cout << a << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what());
	}
	catch (Form::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what());
	}
}

void	signIn( std::string name, std::string form, int grade )
{
	Bureaucrat *b;
	try {
		b = new Bureaucrat(name, grade);
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
		Form a( form );
		a.beSigned(b);
		a.beSigned(b);
	}
	catch (Form::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException", e.what());
	}
	catch (Form::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException", e.what());
	}
}
