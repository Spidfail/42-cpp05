# 42-cpp05
Sixth day of the 42 school's C++ learning pool.

## How to use it

There is a Makefile for compiling (`make`) cleaning the project (`make clean`, `make fclean`) and rebuild it (`make re`).

## Tasks

All these exercises are mostly training with previous concepts but with `exceptions` (try-catch) as new feature.

First, we have to code a Bureaucrat class with limited grade and career developement. It throws exceptions if the manipulation of the class (creation, upgrade/downgrade) overpassed fixed limits.

Then, the bureaucrat can sign form if he is of sufficiently high rank. The creation of the form have some protections too.

Next, new type of forms based on the `Form` class with real effects can be created. Thus a bureaucrat can create a presidential pardon request, a robotomy request or the creation of a Shrubbery.   
Again, some bureaucrats who are of sufficiently high ranks can create or execute theses forms with a throw of exceptions if he doesn't meet the requirements.

At last, an Intern class has been added to create the forms instead of the bureaucrats. 



