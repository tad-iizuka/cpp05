/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:32:00 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 06:35:26 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	std::string command = "find ../ | sed -e 's/[^-][^\\/]*\\//|   /g' -e 's/|\\([^ ]\\)/|--- \\1/'";
	command.append(" > ");
	command.append(_name + "_shrubbery");
	int ret = system(command.c_str());
	if (ret == -1) {
		Log::a(F, L, C_R, getName(), "couldn't execute system command.");
		return;
	}
	else {
		if (WIFEXITED(ret)) {
				int exit_status = WEXITSTATUS(ret);
				if (exit_status != 0) {
					Log::a(F, L, C_R, getName(), "couldn't complete command.");
					return;
				}
		} else {
				Log::a(F, L, C_R, getName(), "couldn't complete command.");
				return;
		}
	}
	Log::a(F, L, C_Y, ("[" + _name + "_shrubbery]"), "has been created.");
	Log::a(F, L, C_G, executor.getName(), "executed", getName());
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target) :
	AForm(target, DEFAULT_SIGN_GRADE, DEFAULT_EXEC_GRADE) {

	if (_sign < MAX_GRADE)
		throw GradeTooHighException("[" + target + "]" + " sign grade " + Log::itoa(_sign));
	else if (_sign > MIN_GRADE)
		throw GradeTooLowException("[" + target + "]" + " sign grade " + Log::itoa(_sign));
	if (_exec < MAX_GRADE)
		throw GradeTooHighException("[" + target + "]" + " exec grade " + Log::itoa(_exec));
	else if (_exec > MIN_GRADE)
		throw GradeTooLowException("[" + target + "]" + " exec grade " + Log::itoa(_exec));
	_status = false;
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) {
	Log::a(F, L, C_R, "[" + _name + "] destructed.");
}
