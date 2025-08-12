/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:11:26 by tiizuka           #+#    #+#             */
/*   Updated: 2025/08/12 21:24:30 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm
{

	public:

		const std::string getName( void ) const;
		bool							getStatus( void );
		int								getSign( void ) const;
		int								getExec( void ) const;
		void							beSigned(Bureaucrat* param);
	
		AForm( const std::string name );
		virtual ~AForm ( void );

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
		
	protected:

		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
		static const int DEFAULT_SIGN_GRADE = 1;
		static const int DEFAULT_EXEC_GRADE = 1;

		AForm( void );
		const std::string _name;
		bool							_status;
		const int 				_sign;
		const int					_exec;

};

std::ostream& operator<<( std::ostream& os, const AForm& rhs );

#endif
