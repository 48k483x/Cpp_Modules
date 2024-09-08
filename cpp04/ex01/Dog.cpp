# include "Dog.hpp"

Dog::Dog(): Animal() {
    std::cout << "Dog default constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog( const Dog &other ): Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = other;
}

Dog &Dog::operator = ( const Dog &other ) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}