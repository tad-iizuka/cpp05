/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/15 16:40:33 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <climits>

int main( void )
{
	const char* tasks[] = {
		"shrubbery create",
		"robotomy request",
		"pardon request",
		"unknown request",
		NULL
	};

	Intern intern;

	for (int i = 0; tasks[i] != NULL; i++)
	{
		Bureaucrat* b = new Bureaucrat("newbie", 1);
		AForm* f = intern.makeForm(tasks[i], "target");
		if (f)
		{
			b->signForm(*f);
			b->executeForm(*f);
			delete f;
		}
		delete b;
	}
	return (EXIT_SUCCESS);
}
