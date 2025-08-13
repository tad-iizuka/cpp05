/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:30:13 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 03:13:51 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class PresidentialPardonForm : public AForm
{
	public:

	void	execute(Bureaucrat const & executor);

		PresidentialPardonForm( const std::string target);
		~PresidentialPardonForm( void );

	private:

		static const int DEFAULT_SIGN_GRADE = 145;
		static const int DEFAULT_EXEC_GRADE = 137;

		PresidentialPardonForm( void );
		const int 				_sign;
		const int					_exec;	
};

#endif
