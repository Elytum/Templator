#include "THIS_IS_A_PATH.hpp"
#include <iostream>

THIS_IS_A_CLASS::THIS_IS_A_CLASS( void ) {
	std::cout << "Default constructor called" << std::endl;
}

THIS_IS_A_CLASS::THIS_IS_A_CLASS( THIS_IS_A_CLASS const & cpy ) {
	std::cout << "Copy constructor called" << std::endl;
	(*this) = cpy;
}

THIS_IS_A_CLASS::~THIS_IS_A_CLASS(void) {
	std::cout << "Destructor called" << std::endl;
}

void	THIS_IS_A_CLASS::operator=(THIS_IS_A_CLASS const & arg) {
	//				Please fill me
	(void)arg;
	std::cout << "Assignation operator called" << std::endl;
}

std::ostream &operator<<(std::ostream& flux, const THIS_IS_A_CLASS& fix)  {
	//				Please fill me
	(void)fix;
	flux << "Operator << called" << std::endl;
	return (flux);
}
