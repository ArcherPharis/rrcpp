#include "Hangman.h"
#include <fstream>
#include <random>
#include <iostream>

void hangmanGame()
{
    vector<string> words = getWords();
    vector<string> arts = getArt();
    srand(time(nullptr));
    int pickIndex = rand() % words.size();

    string answer = words[pickIndex];
    string currentGuess = "";
    for (int i = 0; i < answer.size(); ++i)
    {
        currentGuess.push_back('-');
    }
    int guessesLeft = arts.size() - 1;

    while (currentGuess != answer && guessesLeft > 0)
    {
        cout << arts [guessesLeft] << endl;
        cout << "guesses left: \n " << guessesLeft << endl;
        cout << "your guess\n " << currentGuess << endl;
        bool correctGuess = false;
        char playerGuess = getPlayerInput("Please take a guess.");
        for (int i = 0; i < answer.size(); ++i)
        {
            if (playerGuess == answer[i] && currentGuess[i] != playerGuess)
            {
                currentGuess[i] = playerGuess;
                correctGuess = true;
            }
        }

        if (correctGuess)
        {
            cout << "you found a correct one! " << endl;
        }
        else
        {
            cout <<  "not a correct guess" << endl;
            --guessesLeft;
        }
    }

    if (guessesLeft > 0)
    {
        cout << "You win! The word is: " << answer << endl;
    }
    else
    {
        cout << "You lose! The word is: " << answer << endl;
    }





}

vector<string> getWords()
{
    vector<string> words;
    fstream fs{"../words.txt"};
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            string nextWord;
            getline(fs, nextWord);
            words.push_back(nextWord);
        }
    }

    return words;
}

vector<string> getArt()
{
    vector<string> arts;
    fstream fs("../hangmanArt.txt");
    if (fs.is_open())
    {
        while (!fs.eof())
        {
            string nextArt = "";
            string nextLine;
            getline(fs, nextLine);
            while (nextLine.size() != 0 && !fs.eof())
            {

                nextArt.append(nextLine + '\n');
                getline(fs, nextLine);
            }

            arts.push_back(nextArt);
        }
    }
    return arts;
}

char getPlayerInput(const string& msg)
{
    cout << msg << endl;
    char input;
    cin >> input;
    return input;
}
