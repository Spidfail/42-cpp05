/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:34:48 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 15:46:35 by guhernan         ###   ########.fr       */
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

std::string Form::getName(void) const{
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

////////////////////////////////////////////////////////////////////////////////
//

void		Form::beSigned(Bureaucrat const &workerAssigned) {

	if (workerAssigned.getGrade() < this->getGradeToSign()) {
		this->_isSigned = true;
		std::cout << "Congratulation ! Bureaucrat " << workerAssigned.getName();
		std::cout << " of grade " << workerAssigned.getGrade();
		std::cout << " succeded in signing the form ! (Please remember that is not a valide argument to promote a Bureaucrat)" << std::endl;
	}
	else
		throw (GradeTooLowException(*this, workerAssigned));
}

////////////////////////////////////////////////////////////////////////////////
//

std::ostream	&operator<<(std::ostream &os, Form const &target) {
	os << " REQUESTED FORM : name [" << target.getName() << "]" << std::endl;
	os << "                  Form signed status [" << target.getIsSigned() << "]" << std::endl;
	os << "                  Grade minimum to sign [" << target.getGradeToSign() << "]" << std::endl;
	os << "                  Grade minimum to execute [" << target.getGradeToSign() << "]" << std::endl;
	return os;
}

////////////////////////////////////////////////////////////////////////////////
//
Form::~Form(){ }


////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////NESTED CLASSES/////////////////////////////////////////////////


Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(Form const &targetForm, Bureaucrat const &worker) {
	std::stringstream	tempstream;
	tempstream << "Bureaucrat " << worker.getName();
	tempstream << " cannot sign the form <" << targetForm.getName();
	tempstream<< "> because his grade is too low (under " << targetForm.getGradeToSign() << ").";
	_rtnStr = tempstream.str();
}

Form::GradeTooLowException::GradeTooLowException(Form const &targetCreation) {
	std::stringstream	tempstream;
	tempstream << " Manager cannot create the form <";
	tempstream << targetCreation.getName();
	tempstream<< "> because requested grades are invalid (below 150 on 1 - 150). SIGN : " << targetCreation.getGradeToSign();
	tempstream << " | EXECUTE : " << targetCreation.getGradeToExecute();
	_rtnStr = tempstream.str();
}


const char *Form::GradeTooLowException::what() const throw() {
	return _rtnStr.c_str();
}

///////////////////////////////////////////////////////////////////////////////////
//

Form::GradeTooHighException::GradeTooHighException() {};

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(Form const &targetForm, Bureaucrat const &worker) {
	std::stringstream	tempstream;
	tempstream << "Bureaucrat " << worker.getName();
	tempstream << " cannot sign the form <" << targetForm.getName();
	tempstream<< "> because his grade is too high (above " << targetForm.getGradeToSign() << ").";
	_rtnStr = tempstream.str();
}

Form::GradeTooHighException::GradeTooHighException(Form const &targetCreation) {
	std::stringstream	tempstream;
	tempstream << " Manager cannot create the form <";
	tempstream << targetCreation.getName();
	tempstream<< "> because requested grades are invalid (above 1 on 1 - 150). SIGN : " << targetCreation.getGradeToSign();
	tempstream << " | EXECUTE : " << targetCreation.getGradeToExecute();
	_rtnStr = tempstream.str();
}

const char *Form::GradeTooHighException::what() const throw() {
	return _rtnStr.c_str();
}

////////////////////////////////////////////////////////////////////////////////
