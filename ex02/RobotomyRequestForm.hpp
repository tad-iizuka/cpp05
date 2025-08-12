/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:31:13 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/13 07:24:57 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:

	void	execute(Bureaucrat const & executor);

		RobotomyRequestForm( const std::string target);
		~RobotomyRequestForm( void );

	private:

		static const int DEFAULT_SIGN_GRADE = 72;
		static const int DEFAULT_EXEC_GRADE = 45;

		RobotomyRequestForm( void );
		const int 				_sign;
		const int					_exec;	
};

#endif
