/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:07:10 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/02 15:26:45 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main() {

	std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

	try {

		std::cout << "TEST : Try to hired a goodWorker and random with good grades" << std::endl;

		Bureaucrat	random;
		Bureaucrat	goodWorker("Sergio LOPEZ", 10);
		std::cout << goodWorker << std::endl;
		std::cout << random << std::endl;
		std::cout << std::endl;


		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Try to hired a goodWorker2 of grade 0 && badWorker3 of grade 155" << std::endl;

		try {
		Bureaucrat	goodWorker2("Sergio RAMIREZ", 0);

		std::cout << goodWorker2 << std::endl;
		std::cout << std::endl;
		}
		catch(std::exception &e) {
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

		std::cout << "TEST : Try an upgrade and a downgrade : too mutch" << std::endl;
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

		std::cout << "TEST : Try an upgrade and a downgrade : regular" << std::endl;
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

		std::cout << "TEST : Try to create form : too low and too high" << std::endl;

		try {
			Form	badCustomForm("Big Contract BAD", 151, 10);
			std::cout << badCustomForm << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}

		try {
			Form	badCustomForm2("Big Contract BAAD", 0, 10);
			std::cout << badCustomForm2 << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}

		try {
			Form	badCustomForm3("Big Contract BAD", 50, 151);
			std::cout << badCustomForm3 << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}

		try {
			Form	badCustomForm4("Big Contract BAAD", 50, 0);
			std::cout << badCustomForm4 << std::endl;
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Bureaucrats try to sign form : too low" << std::endl;

		try {
			random.downGrade(50);
		}
		catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << random << std::endl;

		Form	standardForm("Regular Contract");
		Form	customForm("Big Contract", 50, 10);
		std::cout << standardForm << std::endl;
		std::cout << customForm << std::endl;

		try {
			standardForm.beSigned(random);
			customForm.beSigned(random);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << standardForm << std::endl;
		std::cout << customForm << std::endl;
		std::cout << std::endl;

		try {
			random.signForm(customForm);
			random.signForm(standardForm);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << standardForm << std::endl;
		std::cout << customForm << std::endl;
		std::cout << std::endl;

		std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;

		std::cout << "TEST : Bureaucrats try to sign form : good grade" << std::endl;

		std::cout << goodWorker << std::endl;
		std::cout << standardForm << std::endl;
		std::cout << customForm << std::endl;

		try {
			standardForm.beSigned(goodWorker);
			goodWorker.signForm(customForm);
		}
		catch (Form::GradeTooHighException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		catch (Form::GradeTooLowException &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		std::cout << standardForm << std::endl;
		std::cout << customForm << std::endl;
		std::cout << std::endl;

	}

	catch(std::exception &e) {
		e.what();
	}

	return 0;
}
