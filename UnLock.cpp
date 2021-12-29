#include <iostream>

void PrintIntroduction(int Difficulty)
{
    // Print welcom Messages to the terminal
    std::cout << "\n\nYou are a thief breaking into a level "<< Difficulty;
    std::cout << " secure Locker...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    //Declare 3 number code
    const int CodeA = 4;
    const int CodeB = 8;
    const int CodeC = 6;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "There are 3 numbers in the code.\n";
    std::cout << "The codes add-up to: "<< CodeSum;
    std::cout << "\nThe codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Won.\n";
        return true;
    }
    else
    {   
        std::cout << "You Lose.\n";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    while(true)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    return 0;
}