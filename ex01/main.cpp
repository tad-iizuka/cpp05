/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 17:53:37 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <climits>

void	checkForm( std::string name, int sign, int exec );
void	signIn( std::string name, std::string form, int grade );

int main( void )
{
	checkForm("default", 1, 1);
	signIn("Marie", "form0", 1);
	signIn("Marie", "form1", 0);
	signIn("Marie", "form2", 151);
	return (EXIT_SUCCESS);
}

void	checkForm( std::string name, int sign, int exec )
{
	try {
		Form a( name, sign, exec);
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
		Form a( form, 1, 1 );
		a.beSigned(*b);
		a.beSigned(*b);
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
