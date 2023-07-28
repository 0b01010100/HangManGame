#include "hangman_funcs.h"
#include<ctime>
#include <cstdlib>

std::vector<std::pair<int, std::string>> Words =
{ {0, "Friend"}, {1,"Computer"}, {2, "Keyboard"}, 
{3, "HelloWorld"} , {4, "JoeyYong"}, {5, "Wish"}, {6, "CppGeek"}};
int main()
{
	back:
	srand(time(0));
	int randomNumber = (rand() % Words.size());
	int CorrectTries = 0;
	std::vector<char> IncorretTries;
	std::string WordToGuess = Words[randomNumber].second;
	std::string Answer = "";
	Greet();
	GetWordSize(WordToGuess, Answer);
	std::string input;
	while (IncorretTries.size() < 9 && WordToGuess.size() != CorrectTries)
	{
		DisplayMan(IncorretTries.size());
		DisplayStatus(Answer, IncorretTries);
		std::cout << "Enter one Letter: ";
		std::cin >> input;
		char input_ = input[0];
		CheckStringAnswer(input_, Answer, WordToGuess, IncorretTries, CorrectTries);
	}
	EndGame(WordToGuess, Answer);

	Reset_:
	std::cout << "\n\nYou want to save another friend from being hung (y || n)";
	std::string Answer_ = "";
	std::cin >> Answer_;
	if (Answer_ == "y")
	{
		std::cout << "\n\nOk\n\n";
		goto back;
	}
	else if (Answer_ == "n")
	{
		return 0;
	}
	else
	{
		std::cout << "\n\n\n\ Invailed Input\n\n";
		goto Reset_;
	}
	return 0;
}
