/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:53:38 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/01 17:33:14 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(), _target("Invalid Form"), _signatoryName("Invalid Form"), _type("Shrubbery") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &old)
	: Form(old.getName(), old.getGradeToSign(), old.getGradeToExecute()), _target(old._target), _signatoryName("[BLANK]"), _type("Shrubbery") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form(target + "_shrubbery", 145, 137), _target(target), _signatoryName("[BLANK]"), _type("Shrubbery") {
	std::cout << " TARGET : " << this->_target << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &) {
	return *this;
}

////////////////////////////////////////////////////////////////////////////////
//

void	ShrubberyCreationForm::beSigned(Bureaucrat const &signatory) {

	if (this->getIsSigned() == true)
		return ;

	std::stringstream	tempErrorStream;
	tempErrorStream << "Bureaucrat " << signatory.getName();
	tempErrorStream << " cannot SIGN the form <" << this->getName();
	tempErrorStream << "> of type <Shrubbery> with target <" << this->getTarget() << "> ";
	tempErrorStream << "because his grade is too low (under " << this->getGradeToSign() << ").";

	if (signatory.getGrade() < this->getGradeToSign()) {
		setSigned();
		this->_signatoryName = signatory.getName();
		std::cout << " The tree is now ready to be settled." << std::endl;
	}
	else
		throw (GradeTooLowException(*this, signatory, tempErrorStream.str()));
}


void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{

	if (this->getIsSigned() == false) {
		std::cout << "   * -WARNING WARNING WARNING- * you cannot execute the form " << this->getName();
		std::cout << " because he hasn't been signed." << std::endl;
		return ;
	}

	std::stringstream	tempErrorStream;
	tempErrorStream << "Bureaucrat " << executor.getName();
	tempErrorStream << " cannot EXECUTE the form <" << this->getName();
	tempErrorStream << "> of type <Shrubbery> with target <" << this->getTarget() << "> ";
	tempErrorStream << "because his grade is too low (under " << this->getGradeToExecute() << ").";

	if (executor.getGrade() > this->getGradeToExecute())
		throw (GradeTooLowException(*this, executor, tempErrorStream.str()));

	std::cout << " EXECUTION PROCEDURE : execution of the form [" << this->getName() << "]" << std::endl;

	// How to pass a string as filename in c++ 98 retro compatible style :
	// Cast the c_str() output to an array with the needed type of fstream constructor
	const char	*fileName = static_cast<const char*>(this->getName().c_str());

	// Pass the 'const char *' array to output file stream as filename
	std::ofstream	newFile(fileName);

	if (newFile.fail()){
		std::cout << "ERROR : FAILED TO EXECUTE FORM. CONTACT ADMINISTRATOR" << std::endl;
		return ;
	}

	newFile << "  ___  _                _     _                    " << std::endl;
	newFile << " / __|| |_   _ _  _  _ | |__ | |__  ___  _ _  _  _ " << std::endl;
	newFile << " \\__ \\| ' \\ | '_|| || || '_ \\| '_ \\/ -_)| '_|| || |" << std::endl;
	newFile << " |___/|_||_||_|   \\_,_||_.__/|_.__/\\___||_|   \\_, |" << std::endl;
	newFile << "                                              |__/ " << std::endl << std::endl;
	
	newFile << " REQUESTED FORM : name [" << this->getName() << "]" << std::endl;
	newFile << "                  target [" << this->getTarget() << "]" << std::endl;
	newFile << "                  name of the signatory [" << this->getSignatoryName() << "]" << std::endl;
	newFile << "                  Form signed status [" << this->getIsSigned() << "]" << std::endl;
	newFile << "                  Grade minimum to execute [" << this->getGradeToSign() << "]" << std::endl;
	newFile << "                  Grade minimum to sign [" << this->getGradeToSign() << "]" << std::endl << std::endl;
	
	newFile << "                      ___  " << std::endl;
	newFile << "                _,-'''   ''''`--.  " << std::endl;
	newFile << "             ,-'          __,,-- \\  " << std::endl;
	newFile << "           ,'    __,--''''dF      )  " << std::endl;
	newFile << "          /   .-'Hb_,--''dF      /  " << std::endl;
	newFile << "        ,'       _Hb ___dF'-._,-'  " << std::endl;
	newFile << "      ,'      _,-''''   ''--..__  " << std::endl;
	newFile << "     (     ,-'                  `.  " << std::endl;
	newFile << "      `._,'     _   _             ;  " << std::endl;
	newFile << "       ,'     ,' `-'Hb-.___..._,-'  " << std::endl;
	newFile << "       \\    ,''Hb.-'HH`-.dHF'  " << std::endl;
	newFile << "        `--'   'Hb  HH  dF'  " << std::endl;
	newFile << "                'Hb HH dF  " << std::endl;
	newFile << "                 'HbHHdF  " << std::endl;
	newFile << "                  |HHHF  " << std::endl;
	newFile << "                  |HHH|  " << std::endl;
	newFile << "                  |HHH|  " << std::endl;
	newFile << "                  |HHH|  " << std::endl;
	newFile << "                  |HHH|  " << std::endl;
	newFile << "                  dHHHb  " << std::endl;
	newFile << "                .dFd|bHb.               o  " << std::endl;
	newFile << "      o       .dHFdH|HbTHb.          o /  " << std::endl;
	newFile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y  " << std::endl;
	newFile << "##########################################  " << std::endl << std::endl;
	newFile << "------------------------------------------------ " << std::endl;

	newFile.close();

	std::cout << " EXECUTION PROCEDURE : the form [" << this->getName() << "] has been executed. Thank you for your trust." << std::endl;
}


std::string const		&ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}


std::string const		&ShrubberyCreationForm::getSignatoryName(void) const {
	return this->_signatoryName;
}

////////////////////////////////////////////////////////////////////////////////
//

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &formToPublish) {

	os << " REQUESTED FORM : name [" << formToPublish.getName() << "]" << std::endl;
	os << "                  name of the signatory [" << formToPublish.getSignatoryName() << "]" << std::endl;
	os << "                  Form signed status [" << formToPublish.getIsSigned() << "]" << std::endl;
	os << "                  Grade minimum to sign [" << formToPublish.getGradeToSign() << "]" << std::endl;
	os << "                  Grade minimum to execute [" << formToPublish.getGradeToSign() << "]" << std::endl;
	return os;
}

////////////////////////////////////////////////////////////////////////////////
//

ShrubberyCreationForm::~ShrubberyCreationForm() { }

