#include "Harl.hpp"

Harl::Harl()
{
    funcArray[0] = &Harl::debug;
    funcArray[1] = &Harl::info;
    funcArray[2] = &Harl::warning;
    funcArray[3] = &Harl::error;
}

void Harl::complain( std::string level )
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t i = -1;

    while (++i < 4)
    {
        if (level == levels[i])
        {
            (this->*funcArray[i])();
            return ;
        }
    }
    std::cout << "Not a Valid Level......" << std::endl;
}