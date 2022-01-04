#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

int current_temp()
{
    std::string myTemp;

    std::ifstream MyReadFile("readme.txt");

    while (getline(MyReadFile, myTemp))
    {
        return std::stoi(myTemp);
    }

    MyReadFile.close();
}

void play_game()
{
    std::cout << "Guess a temperature in Celsius:" << std::endl;
    while (true)
    {
        int guess;
        std::cin >> guess;
        if (guess == current_temp())
        {
            std::cout << "You got it right!" << std::endl;
            std::cout << "The temperature is " << current_temp() << " degrees Celsius" << std::endl;
            break;
        }
        else if (guess < current_temp())
        {
            std::cout << "Too low!" << std::endl;
        }
        else if (guess > current_temp())
        {
            std::cout << "Too high!" << std::endl;
        }
    }
}
#pragma GCC diagnostic pop

int main()
{
    int choice;
    do
    {
        std::cout << "1. Play Game" << std::endl;
        std::cout << "2. Quit" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Lets Play" << std::endl;
            play_game();
            break;
        case 2:
            std::cout << "Have a good one!" << std::endl;
            break;
        }
    } while (choice != 2);
}