
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "ScalarConverter.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout <<"Invalid Input"<<std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}