#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap( std::string n );
        ScavTrap(const ScavTrap& other );
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        
        void guardGate();
        void displayInfo();
        void attack(const std::string& target); 
}; 

#endif