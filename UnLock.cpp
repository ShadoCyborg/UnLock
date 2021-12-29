#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcom Messages to the terminal
    std::cout << "\n\nYou are a thief breaking into a level "<< Difficulty;
    std::cout << " secure Locker...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    //Generating Random Numbbers using time
    const int CodeA = (rand() % Difficulty) + Difficulty;
    const int CodeB = (rand() % Difficulty) + Difficulty;
    const int CodeC = (rand() % Difficulty) + Difficulty;

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
        std::cout << "Well Done! You got a piece of gold! Keep going!\n";
        return true;
    }
    else
    {   
        std::cout << "You entered the wrong code! Be Careful! Try Again!\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // Create a new random seed based on the time of the day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }   
    }
    std::cout << "\n Great work! You got all the Valuables! Now get out of there!";
    return 0;
}