/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:39:12 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 17:33:48 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form(), _target("Invalid Form"), _signatoryName("Invalid Form"), _type("Robotomy") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &old)
	: Form(old.getName(), old.getGradeToSign(), old.getGradeToExecute()), _target(old._target), _signatoryName("[BLANK]"), _type("Robotomy") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form(target, 72, 42), _target(target), _signatoryName("[BLANK]"), _type("Robotomy") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &) {
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{

	if (this->getIsSigned() == false) {
		std::cout << "   * -WARNING WARNING WARNING- * you cannot execute the form " << this->getName();
		std::cout << " because he hasn't been signed." << std::endl;
		return ;
	}

	std::stringstream	tempErrorStream;
	tempErrorStream << "Bureaucrat " << executor.getName();
	tempErrorStream << " cannot EXECUTE the form <" << this->getName();
	tempErrorStream << "> of type <Robotomy> with target <" << this->getTarget() << "> ";
	tempErrorStream << "because his grade is too low (under " << this->getGradeToExecute() << ").";

	if (executor.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException(*this, executor, tempErrorStream.str()));

	std::cout << " EXECUTION PROCEDURE : execution of the form [" << this->getName() << "]" << std::endl;

	std::cout << "   *VRRRRRRRRRRRRRRRRRRRRRRR VRRRRRRRRRRRRRRRRRRRR*  " << std::endl;

	std::srand((int)std::time(NULL));
	if (std::rand() % 2)
		std::cout << "  *<" << this->_target << "> has been ROBOTOMIZED*" << std::endl;
	else
		std::cout << "   * -WARNING WARNING WARNING- subject <" << this->_target << "> died." << std::endl;

	std::cout << " EXECUTION PROCEDURE : the form [" << this->getName() << "] has been executed. Thank you for your trust." << std::endl;

}
////////////////////////////////////////////////////////////////////////////////
//

void	RobotomyRequestForm::beSigned(Bureaucrat const &signatory) {

	if (this->getIsSigned() == true)
		return ;

	std::stringstream	tempErrorStream;
	tempErrorStream << "Bureaucrat " << signatory.getName();
	tempErrorStream << " cannot SIGN the form <" << this->getName();
	tempErrorStream << "> of type <Robotomy> with target <" << this->getTarget() << "> ";
	tempErrorStream << "because his grade is too low (under " << this->getGradeToSign() << ").";

	if (signatory.getGrade() < this->getGradeToSign()) {
		setSigned();
		this->_signatoryName = signatory.getName();
		std::cout << " PROCEDURE is ready to be EXECUTED." << std::endl;
	}
	else
		throw (GradeTooLowException(*this, signatory, tempErrorStream.str()));
}

////////////////////////////////////////////////////////////////////////////////
//

std::string const		&RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}


std::string const		&RobotomyRequestForm::getSignatoryName(void) const {
	return this->_signatoryName;
}

////////////////////////////////////////////////////////////////////////////////
//

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &formToPublish) {

	os << " REQUESTED FORM : name [" << formToPublish.getName() << "]" << std::endl;
	os << "                  name of the signatory [" << formToPublish.getSignatoryName() << "]" << std::endl;
	os << "                  Form signed status [" << formToPublish.getIsSigned() << "]" << std::endl;
	os << "                  Grade minimum to sign [" << formToPublish.getGradeToSign() << "]" << std::endl;
	os << "                  Grade minimum to execute [" << formToPublish.getGradeToExecute() << "]" << std::endl;
	return os;
}

////////////////////////////////////////////////////////////////////////////////
//

RobotomyRequestForm::~RobotomyRequestForm() { }

