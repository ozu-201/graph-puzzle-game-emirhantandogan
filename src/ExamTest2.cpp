//
// Created by Olcay Taner YILDIZ on 18.12.2023.
//
#include <iostream>
#include "Array/Graph/Graph.h"
#include "Array/Heap/MaxHeap.h"
#include "Array/DisjointSet.h"
#include "Array/Heap/MaxDHeap.h"

using namespace array;

int main(){
    setlocale(LC_ALL, "Turkish");

    //Test case with reading the dictionary
    std::cout<<"---TEST CASES WITH READING DICTIONARY---"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"Please be patient it runs very slow due to implementation made using arrays. Also, graph has 20000 vertices, please don't change it."<<std::endl;
    std::cout<<"In case it doesn't run, you can increase the vertex count."<<std::endl;
    std::cout<<" "<<std::endl;

    std::string fileDestination = "C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-emirhantandogan\\src\\dictionary.txt"; // write here the FULL DESTINATION of the dictionary.

    Graph g = Graph(20000); //Creating graph with 20000 vertices.
    std::wstring word1 = L"minik"; //Enter the first word here (from)
    std::wstring word2 = L"balet"; //Enter the second word here (to)
    int wordLength = 5; //Enter the words length.
    g.readFile(fileDestination,wordLength);

    std::cout<<"---Shortest Path with BFS---"<<std::endl;
    g.BFS(word1, word2);
    std::cout<<"---Shortest Path with Dijkstra---"<<std::endl;
    g.dijkstra(word1, word2);

}