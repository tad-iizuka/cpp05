/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 17:56:04 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <climits>

void	checkForm( std::string name );
void	signIn( std::string name );

int main( void )
{
	checkForm("default");
	signIn("default");
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

void	signIn( std::string name )
{
	Bureaucrat b("kelly", 2);
	try {
		Form a( name );
		a.beSigned(&b);
		a.beSigned(&b);
	}
	catch (Form::GradeTooHighException& e)
	{
		Log::a(F, L, C_R, "GradeTooHighException [" + name + "]");
	}
	catch (Form::GradeTooLowException& e)
	{
		Log::a(F, L, C_R, "GradeTooLowException [" + name + "]");
	}
}
