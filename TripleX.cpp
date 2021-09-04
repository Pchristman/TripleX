#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) 
{
    // Prints the introductory messages to the terminal
    std::cout << "\nYou are an adventurer delving into a level " << Difficulty << " dungeon.\n";
    std::cout << "Solve the three digit padlock on the door to continue...\n\n";
}

bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code;
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum =  CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;


    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou nailed it! Onto the next level!\n";
        return true;
    }
    else
    {
        std::cout << "\nYou didn't get it Try it again...\n";
        return false;
    }
}


int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed.
    {
       
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "***Congratulations, you finished the dungeon!***\n";
    std::cout << "***The real treasure was the journey, don't you agree?***\n";
    
    return 0;
}

