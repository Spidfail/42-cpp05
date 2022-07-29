/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:16:33 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 15:45:51 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat {


	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &);
		Bureaucrat	&operator=(Bureaucrat const &);

		class GradeTooHighException : public std::exception {
			public :
				const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				const char	*what() const throw();
		};

		Bureaucrat(std::string const &);
		Bureaucrat(std::string const &, unsigned int const &);
		std::string getName(void) const;
		int 		getGrade(void) const;
		void		upGrade(int const &);
		void		downGrade(int const &);

		void		signForm(Form &targetForm);

		static const int		gradeMin;
		static const int		gradeMax;

	private:
		std::string const	_name;
		long				_grade;

};
std::ostream	&operator<<(std::ostream &os, Bureaucrat const &);

#endif

