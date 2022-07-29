/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:42:30 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 17:34:07 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(), _target("Invalid Form"), _signatoryName("Invalid Form"), _type("PARDON") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &old)
	: Form(old.getName(), old.getGradeToSign(), old.getGradeToExecute()), _target(old._target), _signatoryName("[BLANK]"), _type("PARDON") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form(target, 25, 5), _target(target), _signatoryName("[BLANK]"), _type("PARDON") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &) {
	return *this;
}

////////////////////////////////////////////////////////////////////////////////
//

void	PresidentialPardonForm::beSigned(Bureaucrat const &signatory) {

	if (this->getIsSigned() == true)
		return ;

	std::stringstream	tempErrorStream;
	tempErrorStream << "Bureaucrat " << signatory.getName();
	tempErrorStream << " cannot SIGN the form <" << this->getName();
	tempErrorStream << "> of type <PARDON> with target <" << this->getTarget() << "> ";
	tempErrorStream << "because his grade is too low (under " << this->getGradeToSign() << ").";

	if (signatory.getGrade() < this->getGradeToSign()) {
		setSigned();
		this->_signatoryName = signatory.getName();
		std::cout << " Great Zafod Beeblebrox is ready to PARDON." << std::endl << std::endl;
	}
	else
		throw (GradeTooLowException(*this, signatory, tempErrorStream.str()));
}


void	PresidentialPardonForm::execute(Bureaucrat const &executor) const{

	if (this->getIsSigned() == false) {
		std::cout << "   * -WARNING WARNING WARNING- * you cannot execute the form " << this->getName();
		std::cout << " because he hasn't been signed." << std::endl;
		return ;
	}

	std::stringstream	tempErrorStream;
	tempErrorStream << "Bureaucrat " << executor.getName();
	tempErrorStream << " cannot EXECUTE the form <" << this->getName();
	tempErrorStream << "> of type <PARDON> with target <" << this->getTarget() << "> ";
	tempErrorStream << "because his grade is too low (under " << this->getGradeToExecute() << ").";

	if (executor.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException(*this, executor, tempErrorStream.str()));

	std::cout << " EXECUTION PROCEDURE : execution of the form [" << this->getName() << "]" << std::endl;

	std::cout << "    ____  ____  ___________ ________  _______   _______________    __ " << std::endl;
	std::cout << "   / __ \\/ __ \\/ ____/ ___//  _/ __ \\/ ____/ | / /_  __/  _/   |  / / " << std::endl;
	std::cout << "  / /_/ / /_/ / __/  \\__ \\ / // / / / __/ /  |/ / / /  / // /| | / /  " << std::endl;
	std::cout << " / ____/ _, _/ /___ ___/ // // /_/ / /___/ /|  / / / _/ // ___ |/ /___" << std::endl;
	std::cout << "/_/ __/_/ |_/_____//____/___/_____/_____/_/ |_/ /_/ /___/_/  |_/_____/" << std::endl;
	std::cout << "   / __ \\/   |  / __ \\/ __ \\/ __ \\/ | / /                             " << std::endl;
	std::cout << "  / /_/ / /| | / /_/ / / / / / / /  |/ /                              " << std::endl;
	std::cout << " / ____/ ___ |/ _, _/ /_/ / /_/ / /|  /                               " << std::endl;
	std::cout << "/_/   /_/  |_/_/ |_/_____/\\____/_/ |_/                                " << std::endl;
	std::cout << "                                                                      " << std::endl;
	std::cout << "██████╗ ██╗   ██╗                                                                " << std::endl;
	std::cout << "██╔══██╗╚██╗ ██╔╝                                                                " << std::endl;
	std::cout << "██████╔╝ ╚████╔╝                                                                 " << std::endl;
	std::cout << "██╔══██╗  ╚██╔╝                                                                  " << std::endl;
	std::cout << "██████╔╝   ██║                                                                   " << std::endl;
	std::cout << "╚═════╝    ╚═╝                                                                   " << std::endl;
	std::cout << "                                                                                 " << std::endl;
	std::cout << "███████╗ █████╗ ███████╗ ██████╗ ██████╗                                         " << std::endl;
	std::cout << "╚══███╔╝██╔══██╗██╔════╝██╔═══██╗██╔══██╗                                        " << std::endl;
	std::cout << "  ███╔╝ ███████║█████╗  ██║   ██║██║  ██║                                        " << std::endl;
	std::cout << " ███╔╝  ██╔══██║██╔══╝  ██║   ██║██║  ██║                                        " << std::endl;
	std::cout << "███████╗██║  ██║██║     ╚██████╔╝██████╔╝                                        " << std::endl;
	std::cout << "╚══════╝╚═╝  ╚═╝╚═╝      ╚═════╝ ╚═════╝                                         " << std::endl;
	std::cout << "                                                                                 " << std::endl;
	std::cout << "██████╗ ███████╗███████╗██████╗ ██╗     ███████╗██████╗ ██████╗  ██████╗ ██╗  ██╗" << std::endl;
	std::cout << "██╔══██╗██╔════╝██╔════╝██╔══██╗██║     ██╔════╝██╔══██╗██╔══██╗██╔═══██╗╚██╗██╔╝" << std::endl;
	std::cout << "██████╔╝█████╗  █████╗  ██████╔╝██║     █████╗  ██████╔╝██████╔╝██║   ██║ ╚███╔╝ " << std::endl;
	std::cout << "██╔══██╗██╔══╝  ██╔══╝  ██╔══██╗██║     ██╔══╝  ██╔══██╗██╔══██╗██║   ██║ ██╔██╗ " << std::endl;
	std::cout << "██████╔╝███████╗███████╗██████╔╝███████╗███████╗██████╔╝██║  ██║╚██████╔╝██╔╝ ██╗" << std::endl;
	std::cout << "╚═════╝ ╚══════╝╚══════╝╚═════╝ ╚══════╝╚══════╝╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝" << std::endl;
	std::cout << "                   To " << this->_target << std::endl << std::endl;

	std::cout << " EXECUTION PROCEDURE : the form [" << this->getName() << "] has been executed. Thank you for your trust." << std::endl;
}


std::string const		&PresidentialPardonForm::getTarget(void) const {
	return this->_target;
}


std::string const		&PresidentialPardonForm::getSignatoryName(void) const {
	return this->_signatoryName;
}

////////////////////////////////////////////////////////////////////////////////
//

std::ostream	&operator<<(std::ostream &os, PresidentialPardonForm const &formToPublish) {

	os << " REQUESTED FORM : name [" << formToPublish.getName() << "]" << std::endl;
	os << "                  name of the signatory [" << formToPublish.getSignatoryName() << "]" << std::endl;
	os << "                  Form signed status [" << formToPublish.getIsSigned() << "]" << std::endl;
	os << "                  Grade minimum to sign [" << formToPublish.getGradeToSign() << "]" << std::endl;
	os << "                  Grade minimum to execute [" << formToPublish.getGradeToExecute() << "]" << std::endl;
	return os;
}

////////////////////////////////////////////////////////////////////////////////
//

PresidentialPardonForm::~PresidentialPardonForm() { }

