#include <iostream>
#include <stdexcept>

int main(void)
{
    int x, y;

    while(std::cin >> x >> y)
    {
        try
        {
            if(y == 0)
                throw std::runtime_error("The second number could't be zero.");
            std::cout << x / y << std::endl;
        }
        catch(std::runtime_error err)
        {
            std::cout << err.what() << std::endl;
            std::cout << "Try again? y or n: ";
            char c;
            std::cin >> c;
            if(!std::cin || c == 'n')
                break;
        }

    }

    return 0;
}
