/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 02:24:06 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/15 02:43:45 by tiizuka          ###   ########.fr       */
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
		AForm* f = intern.makeForm(tasks[i], "target");
		delete f;
	}
	return (EXIT_SUCCESS);
}
