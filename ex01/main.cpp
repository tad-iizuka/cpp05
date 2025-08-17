/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/17 13:06:24 by tiizuka          ###   ########.fr       */
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
	checkForm("default", 0, 1);
	checkForm("default", 1, 0);
	signIn("Marie", "resume", 1);
	signIn("Marie", "resume", 0);
	signIn("Marie", "resume", 151);
	return (EXIT_SUCCESS);
}

void	checkForm( std::string name, int sign, int exec )
{
	try {
		Form a( name, sign, exec);
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

void	signIn( std::string name, std::string form, int grade )
{
	try {
		Bureaucrat b(name, grade);
		Form a( form, 1, 1 );
		std::cout << a << std::endl;
		a.beSigned(b);
		std::cout << a << std::endl;
		a.beSigned(b);
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}
