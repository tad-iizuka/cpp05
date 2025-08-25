/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:48:25 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/25 17:30:29 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*	genShrubberyCreationForm(const std::string& target) {
	Log::a(F, L, C_G, "Intern creates " + target);
	return new ShrubberyCreationForm(target);
}

AForm*	genRobotomyRequestForm(const std::string& target) {
	Log::a(F, L, C_G, "Intern creates " + target);
	return new RobotomyRequestForm(target);
}

AForm*	genPresidentialPardonForm(const std::string& target) {
	Log::a(F, L, C_G, "Intern creates " + target);
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& form, const std::string& target) {

	Forms table[] = {
		{ "shrubbery creation",	&genShrubberyCreationForm },
		{ "robotomy request",	&genRobotomyRequestForm },
		{ "presidential pardon",		&genPresidentialPardonForm },
		{ NULL, 							NULL }
	};

	for (int i = 0; table[i].name != NULL; i++)
	{
		if (std::strcmp(table[i].name, form.c_str()) == 0)
		{
			return (*table[i].f)(target);
		}
	}
	Log::a(F, L, C_R, "[" + form + "] form not registered.");
	return NULL;
}

Intern::Intern( void ) {}
Intern::~Intern ( void ) {}
