/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:07:10 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/02 15:28:35 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		catch(std::exception &e) {
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
	}

	catch(std::exception &e) {
		e.what();
	}

	return 0;
}
