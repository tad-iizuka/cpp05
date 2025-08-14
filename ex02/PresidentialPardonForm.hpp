/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:30:13 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/14 18:22:49 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		void	execute(const Bureaucrat& executor) const;

		PresidentialPardonForm( const std::string target);
		~PresidentialPardonForm( void );

	private:

		static const int DEFAULT_SIGN_GRADE = 145;
		static const int DEFAULT_EXEC_GRADE = 137;

		const std::string _target;
};

#endif
