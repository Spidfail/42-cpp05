/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:17:11 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 13:33:42 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {

	private:
		Form	*(*_stagedForm[3])(std::string const &targetName);
		static const std::string		_formName[3];

	public:
		Intern();
		~Intern();
		Intern(Intern const &);
		Intern(std::string const &);
		Intern	&operator=(Intern const &);

		Form	*makeForm(std::string const &formName, std::string const &bureaucratName);

		class FormNotFoundException : public std::exception {
			public:
				FormNotFoundException();
				virtual const char *what() const throw();
				virtual ~FormNotFoundException() throw();

			private:
				std::string		_rtnStr;
		};
};

Form	*createShrubberyForm(std::string const &targetName);
Form	*createRobotomyForm(std::string const &targetName);
Form	*createPrPardonForm(std::string const &targetName);

#endif
