/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:07:10 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/02 15:45:55 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main() {

	std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

	try {

		std::cout << "TEST : Try to hired a goodWorker and random with good grades" << std::endl << std::endl;

		Bureaucrat	random;
		Bureaucrat	goodWorker("Sergio LOPEZ", 10);
		std::cout << goodWorker << std::endl;
		std::cout << random << std::endl;
		std::cout << std::endl;


		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Try to hired a goodWorker2 of grade 0 && badWorker3 of grade 155" << std::endl << std::endl;

		try {
			Bureaucrat	goodWorker2("Sergio RAMIREZ", 0);

			std::cout << goodWorker2 << std::endl;
			std::cout << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Bureaucrat	badWorker3("Sergio HERNANDEZ", 155);

			std::cout << badWorker3 << std::endl;
			std::cout << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Try an upgrade and a downgrade : too mutch" << std::endl << std::endl;
		try {
			random.upGrade(200);
			goodWorker.downGrade(200);
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << goodWorker << std::endl;
		std::cout << random << std::endl;
		std::cout << std::endl;

		try {
			goodWorker.downGrade(200);
			random.upGrade(200);
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << goodWorker << std::endl;
		std::cout << random << std::endl;
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Try an upgrade and a downgrade : regular" << std::endl << std::endl;
		try {
			random.upGrade(100);
			goodWorker.downGrade(5);
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << goodWorker << std::endl;
		std::cout << random << std::endl;
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "//////////////////////////////FILES/////////////////////////////////////////" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Try to create a Shrubbery Form : it cannot fail" << std::endl << std::endl;

		Form	*shrubberyForm = new ShrubberyCreationForm("MACRON'S ROOFTOP");
		Form	*shrubberyFormUnsigned = new ShrubberyCreationForm("MARINE LEPEN'S ROOFTOP");
		Form	*robotomyForm = new RobotomyRequestForm("STEP MOTHER");
		Form	*pardonForm = new PresidentialPardonForm("HAN SOLO");
		std::cout << *shrubberyForm << std::endl;


		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Bureaucrats try to SIGN form : too low" << std::endl << std::endl;

		Bureaucrat	tooLowBureaucrat("Juan PEDRO", 150);

		try {
			shrubberyForm->beSigned(tooLowBureaucrat);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}

		try {
			robotomyForm->beSigned(tooLowBureaucrat);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *robotomyForm << std::endl;
		std::cout << std::endl;

		try {
			pardonForm->beSigned(tooLowBureaucrat);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *pardonForm << std::endl;
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Bureaucrats try to SIGN form" << std::endl << std::endl;

		std::cout << random << std::endl;
		std::cout << *shrubberyForm << std::endl;
		std::cout << *robotomyForm << std::endl;
		std::cout << *pardonForm << std::endl;

		try {
			shrubberyForm->beSigned(random);
			std::cout << std::endl;
			robotomyForm->beSigned(random);
			std::cout << std::endl;
			pardonForm->beSigned(goodWorker);
			std::cout << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *shrubberyForm << std::endl;
		std::cout << *robotomyForm << std::endl;
		std::cout << *pardonForm << std::endl;
		//
		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Form try to EXECUTE form : not signed !!!" << std::endl << std::endl;

		try {
			shrubberyFormUnsigned->execute(random);
			std::cout << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *shrubberyForm << std::endl;
		std::cout << std::endl;


		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Form try to EXECUTE form : bad grade" << std::endl << std::endl;

		try {
			robotomyForm->execute(random);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *shrubberyForm << std::endl;
		std::cout << std::endl;

		try {
			pardonForm->execute(random);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *robotomyForm << std::endl;
		std::cout << *pardonForm << std::endl;
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Form try to EXECUTE form : good grade" << std::endl << std::endl;

		std::cout << "TEST : Try an upgrade" << std::endl;
		try {
			goodWorker.upGrade(10);
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << goodWorker << std::endl;
		std::cout << std::endl;

		try {
			shrubberyForm->execute(random);
			std::cout << std::endl;
			robotomyForm->execute(goodWorker);
			std::cout << std::endl;
			pardonForm->execute(goodWorker);
			std::cout << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *shrubberyForm << std::endl;
		std::cout << *robotomyForm << std::endl;
		std::cout << *pardonForm << std::endl;
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Bureaucrats try to EXECUTE form : good grade" << std::endl << std::endl;

		try {
			goodWorker.executeForm(*shrubberyForm);
			std::cout << std::endl;
			goodWorker.executeForm(*robotomyForm);
			std::cout << std::endl;
			goodWorker.executeForm(*pardonForm);
			std::cout << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << *shrubberyForm << std::endl;
		std::cout << *robotomyForm << std::endl;
		std::cout << *pardonForm << std::endl;
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		delete shrubberyForm;
		delete shrubberyFormUnsigned;
		delete robotomyForm;
		delete pardonForm;

	}
	catch(Bureaucrat::GradeTooLowException &e) {
		e.what();
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		e.what();
	}
	catch (Form::GradeTooHighException &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : INTERN try to CREATE forms" << std::endl << std::endl;

	try {
		Intern	stupidInter;
		Form	*temp = stupidInter.makeForm("Shrubbery creation", "Jura");
		delete temp;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "OKAY, let's call a better Intern." << std::endl;

	try {
		Intern	interestingIntern;
		Form	*temp = interestingIntern.makeForm("robotomy form", "Worst Ennemy");
		delete temp;
	}
	catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
