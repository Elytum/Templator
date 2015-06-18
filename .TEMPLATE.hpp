#ifndef THIS_IS_A_PROTECTION
# define THIS_IS_A_PROTECTION

#include <iostream>

class THIS_IS_A_CLASS
{

	public:

		THIS_IS_A_CLASS( void );
		THIS_IS_A_CLASS( THIS_IS_A_CLASS const & cpy );
		~THIS_IS_A_CLASS();

		void	operator=( const THIS_IS_A_CLASS& cpy );

	private:

};

std::ostream &operator<<( std::ostream &flux, const THIS_IS_A_CLASS &fixed );

#endif
