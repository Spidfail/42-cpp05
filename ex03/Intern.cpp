/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:17:13 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 13:33:07 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string	Intern::_formName[3] = {
	"shrubbery form",
	"robotomy form",
	"pardon form",
};

Intern::Intern() {
	_stagedForm[0] = createShrubberyForm;
	_stagedForm[1] = createRobotomyForm;
	_stagedForm[2] = createPrPardonForm;
}

Intern::Intern(Intern const &target) {
	_stagedForm[0] = createShrubberyForm;
	_stagedForm[1] = createRobotomyForm;
	_stagedForm[2] = createPrPardonForm;
	*this = target;
}

Intern::Intern(std::string const &) {
	_stagedForm[0] = createShrubberyForm;
	_stagedForm[1] = createRobotomyForm;
	_stagedForm[2] = createPrPardonForm;
	std::cout << "Intern has no name. Intern is just a good worker." << std::endl;
}

Intern	&Intern::operator=(Intern const &) {
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////
//
//
Form	*createShrubberyForm(std::string const &targetName) {
	std::cout << "Mhhhhhhhhh, he succed to create a form... Interesting." << std::endl;
	return new ShrubberyCreationForm(targetName);
}

Form	*createRobotomyForm(std::string const &targetName) {
	std::cout << "Mhhhhhhhhh, he succed to create a form... Interesting." << std::endl;
	return new RobotomyRequestForm(targetName);
}

Form	*createPrPardonForm(std::string const &targetName) {
	std::cout << "Mhhhhhhhhh, he succed to create a form... Interesting." << std::endl;
	return new PresidentialPardonForm(targetName);
}


Form	*Intern::makeForm(std::string const &formName, std::string const &targetName) {

	if (formName.empty() || targetName.empty())
		throw (Intern::FormNotFoundException());

	for (int formNb = 0; formNb < 3 ; formNb++) {
		if (this->_formName[formNb].compare(formName) == 0)
			return this->_stagedForm[formNb](targetName);
	}
	throw Intern::FormNotFoundException();
}

///////////////////////////////////////////////////////////////////////////////////
//

Intern::~Intern(){ }


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
//

Intern::FormNotFoundException::FormNotFoundException()
	: _rtnStr("Impossible to found the form. WHAT A MISTAKE, HE WILL BE PUNISHED") { }

const char *Intern::FormNotFoundException::what() const throw() {
	return _rtnStr.c_str();
}

Intern::FormNotFoundException::~FormNotFoundException() throw() { }
