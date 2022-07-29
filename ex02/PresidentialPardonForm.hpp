/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:42:34 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/29 13:44:41 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include "Form.hpp"

class PresidentialPardonForm : public Form {

	public:
		////////// Canonical
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &);

		////////// Main constructor
		PresidentialPardonForm(std::string const &target);

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

std::ostream	&operator<<(std::ostream &os, PresidentialPardonForm const &);

#endif
