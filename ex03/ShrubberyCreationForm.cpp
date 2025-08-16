/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:32:00 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/17 03:39:55 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::string command = "find ../ | sed -e 's/[^-][^\\/]*\\//|   /g' -e 's/|\\([^ ]\\)/|--- \\1/'";
	command.append(" > ");
	command.append(_target + "_shrubbery");
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
	Log::a(F, L, C_Y, ("[" + _target + "_shrubbery]"), "has been created.");
	Log::a(F, L, C_G, executor.getName(), "executed", _target);
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target) :
	AForm("ShrubberyCreationForm", DEFAULT_SIGN_GRADE, DEFAULT_EXEC_GRADE), _target(target) {
	Log::a(F, L, C_B, "[" + _name + "] constructed.");
}

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) {
	Log::a(F, L, C_B, "[" + _name + "] destructed.");
}
