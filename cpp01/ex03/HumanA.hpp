#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& gun;
    public:
        HumanA(std::string n, Weapon& w);
        void attack();
};

#endif