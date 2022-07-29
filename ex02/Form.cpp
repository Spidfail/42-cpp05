/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:34:48 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 17:32:51 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("random form"), _gradeToSign(99), _isSigned(false), _gradeToExecute(50) {
	std::cout << " NEW FORM : " << _name << " with grade to sign [" << _gradeToSign << "] and grade to execute [" << _gradeToExecute << "]" << std::endl;
}


Form::Form(Form const &target)
	: _name(target._name), _gradeToSign(target._gradeToSign), _isSigned(target._isSigned), _gradeToExecute(target._gradeToExecute) {

	std::cout << " NEW FORM COPY : " << _name << " with grade to sign [" << _gradeToSign << "] and grade to execute [" << _gradeToExecute << "]" << " || STATUS : " << _isSigned << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//

Form::Form(std::string const &standardFormName)
	: _name(standardFormName), _gradeToSign(99), _isSigned(false), _gradeToExecute(50) {

	std::cout << " NEW FORM : " << _name << " with grade to sign [" << _gradeToSign << "] and grade to execute [" << _gradeToExecute << "]" << std::endl;
}


Form::Form(std::string const &customFormName, unsigned int const &gradeToSign, unsigned int const &gradeToExecute)
	: _name(customFormName), _gradeToSign(gradeToSign), _isSigned(false), _gradeToExecute(gradeToExecute) {

	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw(GradeTooHighException(*this));
	}
	else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw(GradeTooLowException(*this));
	}
	std::cout << " NEW FORM : " << _name << " with grade to sign [" << _gradeToSign << "] and grade to execute [" << _gradeToExecute << "]" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//
Form		&Form::operator=(Form const &) {
	std::cout << "ERROR : you cannot modify parameters of a produced form." << std::endl;
	return *this;
}

////////////////////////////////////////////////////////////////////////////////
//

const std::string &Form::getName(void) const{
	return this->_name;
}

int 		Form::getGradeToSign(void) const{
	return this->_gradeToSign;
}

int 		Form::getGradeToExecute(void) const{
	return this->_gradeToExecute;
}

bool		Form::getIsSigned(void) const{
	return this->_isSigned;
}

void		Form::setSigned(void) {
	this->_isSigned = true;
}

void		Form::execute(Bureaucrat const &executor) const {

	if (this->getIsSigned() == false) {
		std::cout << "   * -WARNING WARNING WARNING- * " << executor.getName() << " cannot execute the form " << this->getName();
		std::cout << " because he hasn't been signed." << std::endl;
		return ;
	}

	std::cout << "THERE IS NOTHING TO EXECUTE. PLEASE CONTACT AN ADMINISTRATOR IMMEDIATLY" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//


std::ostream	&operator<<(std::ostream &os, Form const &target) {
	os << " REQUESTED FORM : name [" << target.getName() << "]" << std::endl;
	os << "                  name of the signatory [" << target.getSignatoryName() << "]" << std::endl;
	os << "                  Form signed status [" << target.getIsSigned() << "]" << std::endl;
	os << "                  Grade minimum to sign [" << target.getGradeToSign() << "]" << std::endl;
	os << "                  Grade minimum to execute [" << target.getGradeToExecute() << "]" << std::endl;
	return os;
}

////////////////////////////////////////////////////////////////////////////////
//
Form::~Form(){ }


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////NESTED CLASS/////////////////////////////////////
//

Form::GradeTooLowException::GradeTooLowException() {};

Form::GradeTooLowException::~GradeTooLowException() throw() {};


Form::GradeTooLowException::GradeTooLowException(Form const &, Bureaucrat const &,
		std::string const &errorStr) : _rtnStr(errorStr) {}


Form::GradeTooLowException::GradeTooLowException(Form const &targetCreation) {
	std::stringstream	tempstream;
	tempstream << " Manager cannot create the form <" << targetCreation.getName();
	tempstream << "> because requested grades are invalid (below 150 on 1 - 150).";
	tempstream << "SIGN : " << targetCreation.getGradeToSign();
	tempstream << " | EXECUTE : " << targetCreation.getGradeToExecute();
	_rtnStr = tempstream.str();
}

const char *Form::GradeTooLowException::what() const throw() {
	return _rtnStr.c_str();
}

////////////////////////////////////////////////////////////////////////////////
//

Form::GradeTooHighException::GradeTooHighException() {};

Form::GradeTooHighException::~GradeTooHighException() throw() {};


Form::GradeTooHighException::GradeTooHighException(Form const &, Bureaucrat const &,
		std::string const &errorStr) : _rtnStr(errorStr) {}


Form::GradeTooHighException::GradeTooHighException(Form const &targetCreation) {
	std::stringstream	tempstream;
	tempstream << " Manager cannot create the form <" << targetCreation.getName();
	tempstream << "> because requested grades are invalid (above 1 on 1 - 150). ";
	tempstream << "SIGN : " << targetCreation.getGradeToSign();
	tempstream << " | EXECUTE : " << targetCreation.getGradeToExecute();
	_rtnStr = tempstream.str();
}

const char *Form::GradeTooHighException::what() const throw() {
	return _rtnStr.c_str();
}

////////////////////////////////////////////////////////////////////////////////
