//
// Created by et028745 on 12/14/2023.
//

#include <iostream>
#include <fstream>
#include "main.h"
#include "Graph.h"

bool isOneLetterDifference(const std::string word1, const std::string word2)
{
    int count=0;
    if(word1.size()!=word2.size())
    {
        return false;
    }
    for(int i = 0; i<word1.size(); i++)
    {
        if(word1[i]!=word2[i])
        {
            count++;
        }
    }

    if(count==1)
    {
        return true;
    }
    return false;
}

void ReadFile(const std::string &filename, int lengthOfWord, Graph g)
{
    std::ifstream file(filename);
    std::string word;

    if(!file){return;}

    while(file>>word)
    {
        if(word.length()==lengthOfWord)
        {
            g.words.push_back(word);
            //std::cout << word << std::endl;
        }
    }

    for(int i = 0; i<g.words.size(); i++)
    {
        for(int j = i+1; j<g.words.size(); j++)
        {
            if(isOneLetterDifference(g.words[i], g.words[j]))
            {
                g.addEdge(g.words[i], g.words[j]);
            }
        }
    }
    g.BFS("diz","def");
}


int main(){
    std::cout << "Hello World" << std::endl;

    Graph g(40000);

    ReadFile("C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-emirhantandogan\\dictionary.txt",3,g);

    std::string word1 = "diz";
    std::string word2 = "def";
    //std::cout<<g.getWordIndex(word1)<<std::endl;

    return 0;
}






