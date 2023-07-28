#pragma once
#include <iostream>
#include <vector>
#include <iterator>
void Greet();

void GetWordSize(std::string& MysteryWord, std::string& WordAnswer);

void DisplayMan(int misses);

void DisplayStatus(std::string& Answer, std::vector<char>& Incorrect);

void CheckStringAnswer(char& input, std::string& Answer, std::string& CodeWord, 
std::vector<char>& Incorrect, int& CorrectTries);

void EndGame(std::string& Codeword, std::string& Answer);
