#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string n);
		~Zombie();
		void announce( void );
		void setName( const std::string& n );
};

Zombie* zombieHorde( int N, std::string name );

#endif