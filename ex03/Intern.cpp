/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:48:25 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/15 02:33:26 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*	genShrubberyCreationForm(const std::string& target) {
	Log::a(F, L, C_G, "[" + target + "] generated.");
	return new ShrubberyCreationForm(target);
}

AForm*	genRobotomyRequestForm(const std::string& target) {
	Log::a(F, L, C_G, "[" + target + "] generated.");
	return new RobotomyRequestForm(target);
}

AForm*	genPresidentialPardonForm(const std::string& target) {
	Log::a(F, L, C_G, "[" + target + "] generated.");
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& form, const std::string& target) {

	Forms table[] = {
		{ "shrubbery create",	&genShrubberyCreationForm },
		{ "robotomy request",	&genRobotomyRequestForm },
		{ "pardon request",		&genPresidentialPardonForm },
		{ NULL, 							NULL }
	};

	for (int i = 0; table[i].name != NULL; i++)
	{
		if (std::strcmp(table[i].name, form.c_str()) == 0)
		{
			return (*table[i].f)(target);
		}
	}
	Log::a(F, L, C_R, "[" + form + "] not registered.");
	return NULL;
}

Intern::Intern( void ) {}
Intern::~Intern ( void ) {}
