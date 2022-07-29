/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:39:19 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/29 11:33:18 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include "Form.hpp"
#include <random>

class RobotomyRequestForm : public Form {

	public:
		////////// Canonical
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &);

		////////// Main constructor
		RobotomyRequestForm(std::string const &target);

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

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &);

#endif
