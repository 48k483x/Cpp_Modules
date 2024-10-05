# include "AForm.hpp"
# include <fstream>

class PresidentialPardonForm: public AForm
{
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

  void execute(Bureaucrat const & executor) const;
};