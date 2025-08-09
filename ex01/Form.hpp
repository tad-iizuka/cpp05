/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:26:56 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/09 09:04:45 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form : public Bureaucrat
{

	public:

		Form( void );
		Form( const std::string& name, int grade );
		~Form ( void );

	private:
		const std::string _name;
		bool							_signed;
		const int					_gradeSign;
		const int					_gradeExecute;

};

#endif
