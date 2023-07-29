#include "hangman_funcs.h"
void Greet()
{
	std::cout << "+ = = = = = = = = = = = = = = = = = = = = = = = = = = = + \n\n";
	std::cout << "Hello, You have to save your friend form being hanged\n";
	std::cout << "To save him you have to Guess the word Correctly under 9 tries\n";
	std::cout << "Good Luck\n";
	std::cout << "\n+ = = = = = = = = = = = = = = = = = = = = = = = = = = = + \n\n";
}
void GetWordSize(std::string& MysteryWord, std::string& WordAnswer)
{
    for(int i = 0; i< MysteryWord.size(); i++)
	{
		WordAnswer += "_";
	}
}
void DisplayMan(int misses)
{
    switch (misses)
    {
    case 0:
        std::cout << "   \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    case 1:
        std::cout << "  +---+ \n";
        std::cout << "     | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    case 2:
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    case 3:
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    case 4:
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << "  |   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    case 5:
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    case 6:
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|\\  | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    case 7:
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|\\  | \n";
        std::cout << " /    | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    default:
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|\\  | \n";
        std::cout << " / \\  | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
        break;
    }
}
void DisplayStatus(std::string& Answer, std::vector<char>& Incorrect) {
	//Displays Incorrect Letters
	std::cout << "Incorrect Letters: " << std::endl;
	if(Incorrect.size() != 0)
	{
		for (std::vector<char>::iterator ptr = Incorrect.begin(); ptr< Incorrect.end(); ptr++)
		{
			std::cout << *ptr <<"  ";
		}
	}
	else 
	{
		std::cout << 0;
	}

	//Displays Correct Letters
	std::cout << "\n\nCorrect Letter: " << std::endl;
	for (std::string::iterator it = Answer.begin(); it<Answer.end(); it++)
	{
		std::cout << *it<< "  ";
	}
	std::cout << "\n";
}
void CheckStringAnswer(char& input, std::string& Answer, std::string& CodeWord, std::vector<char>& Incorrect, int& CorrectTries)
{
        bool WasCorrect = 0;
		for(int i = 0; i< CodeWord.length(); i++)
		{
			if(input == CodeWord[i])
			{
				Answer[i] = CodeWord[i];      
                WasCorrect = true;
			}
	    }
        if(WasCorrect == true)
        {
            std::cout << "\t\tCorrect" << std::endl << std::endl;
            CorrectTries++;
        }
        else
        {
            Incorrect.push_back(input);
            std::cout << "\t\tSorry, but that was Incorrect"<<std::endl<<std::endl;
        }
}
bool operator==(std::string& inputArg0, std::string& inputArg1)
{
    bool d = true; 
    for (int i = 0; i < inputArg1.size(); i++) {
        
        if(inputArg0[i] != inputArg1[i])
        {
            d = false;
            break;
        }
    }
    return d;
}
void EndGame(std::string& Codeword, std::string& Answer)
{
    if(Answer == Codeword)
    {
        std::cout << "Yay!!!! YOu saved your firend\n\nThe Code word was "<<Codeword<<"\n\n\n";
    }
    else
    {
        std::cout << "Sorry you friend died from being hung\n\nThe Code word was "<<Codeword<<"\n\n\n";
    }
}
