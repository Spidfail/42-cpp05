/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:34:43 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 15:44:32 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include "Bureaucrat.hpp"

class Form {

	public:
		Form();
		~Form();
		Form(Form const &);
		Form	&operator=(Form const &);


		Form(std::string const &);
		Form(std::string const &, unsigned int const &);
		Form(std::string const &customFormName, unsigned int const &gradeToSign,
				unsigned int const &gradeToExecute);
		std::string getName(void) const;
		int 		getGradeToSign(void) const;
		int 		getGradeToExecute(void) const;
		bool		getIsSigned(void) const;
		void		beSigned(Bureaucrat const &workerAssigned);

		class GradeTooLowException : public std::exception {
			public:
				virtual ~GradeTooLowException() throw();
				GradeTooLowException(Form const &targetForm, Bureaucrat const &worker);
				GradeTooLowException(Form const &targetCreation);
				const char *what() const throw();
			private:
				GradeTooLowException();
				std::string		_rtnStr;
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual ~GradeTooHighException() throw();
				GradeTooHighException(Form const &targetForm, Bureaucrat const &worker);
				GradeTooHighException(Form const &targetCreation);
				const char *what() const throw();
			private:
				GradeTooHighException();
				std::string		_rtnStr;
		};

	private:
		std::string const	_name;
		long const			_gradeToSign;
		bool				_isSigned;
		long const			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &os, Form const &);

#endif
