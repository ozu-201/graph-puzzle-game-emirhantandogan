//
// Created by et028745 on 12/14/2023.
//

#include <iostream>
#include <fstream>
#include "main.h"

void ReadFile(const std::string &filename, int lengthOfWord);

int main(){
    std::cout << "Hello World" << std::endl;
    ReadFile("C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-emirhantandogan\\dictionary.txt",3);

    return 0;
}

void ReadFile(const std::string &filename, int lengthOfWord)
{
    std::ifstream file(filename);
    std::string word;

    if(!file){return;}

    while(file>>word)
    {
        if(word.length()==lengthOfWord)
        {
            std::cout << word << std::endl;
        }
    }
}




