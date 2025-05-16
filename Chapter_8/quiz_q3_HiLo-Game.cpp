#include <iostream>
#include "Random.h" // Header files don't use angel brackets

bool playAgain();
bool playHiLo(int guessLimit, int min, int max)
{
    const int randNum{Random::get(min, max)};
    int num{1};
    std::cout << "Let's play a game. I'm thinking of a number between " 
              << min << " and " << max 
              << ". You have " << guessLimit << " guesses to guess what it is!\n";
    /* Terminate when num == guessLimit */
    while (num <= guessLimit)
    {
        int answer{};
        std::cout << "Guess #" << num << ": ";
        std::cin >> answer;

        if (answer > randNum)
        {
            std::cout << "Too High!\n";
            num++;
        }
        else if (answer < randNum)
        {
            std::cout << "Too Low!\n";
            num++;
        }
        else if (answer == randNum)
        {
            std::cout << "Great Job!\n";
            return true;
        }
    }
    // Once it exits the while loop: return after saying the correct answer
    std::cout << "Sorry the answer is: " << randNum << '\n';
    return true;
}

bool playAgain()
{
    while (true)
    {
        std::cout << "Would you like to play again? (y/n) ";
        char response{};
        std::cin >> response;
        switch (response)
        {
            case 'y':
                return true;
            case 'n':
                return false;
        }
    }
}

int main()
{
    constexpr int numGuesses{7};
    constexpr int min{1};
    constexpr int max{100};

    // playHiLo(numGuesses, min, max);

    // Got to use a do-while
    do
    {
        playHiLo(numGuesses, min, max);
    } while (playAgain());
}