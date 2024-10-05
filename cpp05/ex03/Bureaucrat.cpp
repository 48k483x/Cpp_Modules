# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default Name"), grade(75)
{
    std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

Bureaucrat::Bureaucrat(std::string N, int G): name(N), grade(G)
{
    std::cout << "Bureaucrat: Parameterized Constructor Called" << std::endl;
    if (grade <= 0) throw GradeTooHighException();
    else if (grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat: Copy Constructor Called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat: Copy Assignment Operator Called" << std::endl;
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

std::string Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const {return this->grade; }

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 <= 0) throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150) throw GradeTooLowException();
    this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << "Bureaucrat: " << obj.getName()
       << " | Grade: " << obj.getGrade()
       << " | Status: " << (obj.getGrade() <= 50 ? "Senior" : "Junior");
    return os;
}

void Bureaucrat::signForm(AForm& other)
{
      try
    {
        other.beSigned(*this);
        std::cout << this->getName() << " has successfully signed the " << other.getName() << " form" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " failed to sign " << other.getName() << " due to " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " has successfully executed the " << form.getName() << " form" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " failed to execute " << form.getName() << " due to " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: destructor Called" << std::endl;
}
