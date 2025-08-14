/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:32:05 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 17:28:30 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class ShrubberyCreationForm : public AForm
{
	public:

		void	execute(const Bureaucrat& executor) const;

		ShrubberyCreationForm( const std::string target);
		~ShrubberyCreationForm( void );

	private:

		static const int DEFAULT_SIGN_GRADE = 145;
		static const int DEFAULT_EXEC_GRADE = 137;

		ShrubberyCreationForm( void );
		// const int 				_sign;
		// const int					_exec;	
};

#endif
