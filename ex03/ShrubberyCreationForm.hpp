/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:53:29 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/28 20:45:13 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

	public:
		////////// Canonical
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &);

		////////// Main constructor
		ShrubberyCreationForm(std::string const &target);

		////////// Overload
		void		beSigned(Bureaucrat const &signatory);
		void		execute (Bureaucrat const &executor) const;

		////////// Own
		std::string const		&getTarget(void) const;
		std::string const		&getSignatoryName(void) const;
	
	private:
		std::string const	_target;
		std::string			_signatoryName;
		std::string const	_type;

};

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &);

#endif
