/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:39:57 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 15:55:32 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"

const  int	Bureaucrat::gradeMax = 1;
const  int	Bureaucrat::gradeMin = 150;

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150) {
	std::cout << " NEW MEMBER : " << _name << " as bureaucrat of grade : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &oldBureau) : _name(oldBureau._name), _grade(oldBureau._grade) {
	std::cout << " NEW MEMBER : " << _name << " as bureaucrat of grade : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name) : _name(name), _grade(150) {
	std::cout << " NEW MEMBER : " << _name << " as bureaucrat of grade : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int const &grade) : _name(name) {
	if (grade <= 150 && grade >= 1)
		this->_grade = grade;
	else if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	std::cout << " NEW MEMBER : " << _name << " as bureaucrat of grade : " << _grade << std::endl;
}

//////////////////////////////////////////////////////////////////////////////
//
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &target) {
	this->_grade = target._grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &target) {
	os <<" REQUESTED FILE : " << target.getName() << ", bureaucrat unit of grade " << target.getGrade() << ".";
	return os;
}

/////////////////////////////////////////////////////////////////////////////
//

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "---------The grade enterred is too high. Max level is 1";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "---------The grade enterred is too low. Min level is 150";
}

/////////////////////////////////////////////////////////////////////////////
//
std::string Bureaucrat::getName(void) const {
	return _name;
}

int 		Bureaucrat::getGrade(void) const {
	return _grade;
}

void		Bureaucrat::upGrade(int const &nbLevelSkip) {

	std::cout << "Trying to upgrade " << this->_name << " of " << nbLevelSkip << std::endl;
	if (_grade - nbLevelSkip < gradeMax)
		throw GradeTooHighException();
	else
		_grade -= nbLevelSkip;
}

void		Bureaucrat::downGrade(int const &nbLevelFall) {

	std::cout << "Trying to downgrade " << this->_name << " of " << nbLevelFall << std::endl;
	if (nbLevelFall + _grade > gradeMin)
		throw GradeTooLowException();
	else
		_grade += nbLevelFall;
}

void		Bureaucrat::executeForm(Form const &form) const {
	form.execute(*this);
}

void		Bureaucrat::signForm(Form &targetForm) {
	targetForm.beSigned(*this);
}

/////////////////////////////////////////////////////////////////////////////
//
Bureaucrat::~Bureaucrat() {
}
