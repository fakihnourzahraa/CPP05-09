# CPP Module 05

_This project has been created as part of the 42 curriculum by nfakih._

## Description

CPP Module 05 focuses on **exception handling in C++**. The goal of this module is to understand how to properly handle errors and exceptional situations using C++'s try-catch mechanism and to create custom exception classes.

**Key concepts:**
- Exception handling (try, catch, throw)
- Custom exception classes as nested classes
- Abstract base classes and polymorphism

## Instructions

### Compilation

Each exercise contains a Makefile with the following rules:
```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

**Compilation flags:** `-Wall -Wextra -Werror -std=c++98`

### Execution

Each exercise produces an executable that can be run to test the implementation:
```bash
./bureaucrat  # Or the name specified in the exercise
```

The program will run test cases demonstrating exception handling, form signing, and execution.

### Project Structure

#### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
Create a `Bureaucrat` class with:
- **Attributes:**
  - `name` (const string)
  - `grade` (int: 1-150, where 1 is highest)
- **Methods:**
  - Getters for name and grade
  - `incrementGrade()` and `decrementGrade()`
- **Exceptions:**
  - `GradeTooHighException` (grade < 1)
  - `GradeTooLowException` (grade > 150)
- **Overload:** insertion operator (`<<`) to print bureaucrat info

#### Exercise 01: Form up, maggots!
Create a `Form` class with:
- **Attributes:**
  - `name` (const string)
  - `signed` (bool)
  - `gradeToSign` (const int: 1-150)
  - `gradeToExecute` (const int: 1-150)
- **Methods:**
  - Getters for all attributes
  - `beSigned(Bureaucrat&)` - sign the form if grade is sufficient
- **Exceptions:**
  - `GradeTooHighException`
  - `GradeTooLowException`
- Update `Bureaucrat` with `signForm(Form&)` method

#### Exercise 02: No, you need form 28B, not 28C...
Create abstract `AForm` class and concrete form classes:
- **ShrubberyCreationForm:** Creates ASCII trees in a file
  - Sign grade: 145
  - Exec grade: 137
  - Target: filename
- **RobotomyRequestForm:** Makes drilling noises and robotomizes target (50% success)
  - Sign grade: 72
  - Exec grade: 45
  - Target: individual to robotomize
- **PresidentialPardonForm:** Announces pardon by Zaphod Beeblebrox
  - Sign grade: 25
  - Exec grade: 5
  - Target: individual to pardon

All forms must:
- Inherit from `AForm`
- Implement `execute(Bureaucrat const &)` method
- Check execution requirements (signed, grade sufficient)
- Throw exceptions if requirements not met

Update `Bureaucrat` with `executeForm(AForm const &)` method

#### Exercise 03: At least this beats coffee-making
Create an `Intern` class with:
- `makeForm(string formName, string target)` method
- Creates one of the three form types based on name
- Returns pointer to created form
- Handles unknown form names gracefully

### Implementation Details

**Exception Handling Example:**
```cpp
try
{
    Bureaucrat bob("Bob", 0);
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

**Orthodox Canonical Form:**
All classes must implement:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

**Abstract Classes:**
Use pure virtual functions:

```cpp
class AForm
{
    public:
        virtual void execute(Bureaucrat const & executor) const = 0;
};
```

## Resources

**Classic References:**
- https://riceset.com/C++/The-Orthodox-Canonical-Class-Form - Orthodox Canonical Class Form explanation
- https://www.ibm.com/docs/en/i/7.4.0?topic=only-abstract-classes-c - IBM documentation on abstract classes
- https://www.geeksforgeeks.org/cpp/virtual-function-cpp/ - Virtual functions in C++
- https://cplusplus.com/doc/tutorial/exceptions/ - C++ exception handling tutorial

**AI Usage:**
No AI tools were used in the development of this project. All code was written manually following the 42 curriculum requirements and subject guidelines.