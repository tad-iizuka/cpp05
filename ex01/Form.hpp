/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:26:56 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 17:48:45 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form
{

	public:

		const std::string getName( void ) const;
		bool							getStatus( void );
		int								getSign( void ) const;
		int								getExec( void ) const;
		void							beSigned(Bureaucrat* param);
	
		Form( const std::string name );
		~Form ( void );

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const std::string& name);
				~GradeTooHighException ( void ) throw();
				const char* what() const throw();
			private:
				std::string _name;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(const std::string& name);
				~GradeTooLowException ( void ) throw();
				const char* what() const throw();
			private:
				std::string _name;
		};
		
	private:

		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
	
		Form( void );
		const std::string _name;
		bool							_status;
		const int 				_sign;
		const int					_exec;

};

std::ostream& operator<<( std::ostream& os, const Form& rhs );

#endif
