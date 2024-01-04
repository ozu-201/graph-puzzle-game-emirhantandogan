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

    //IMPORTANT!!! This is Yiğit's test case other test case with dictionary in the ExamTest2.cpp
    // Test Case: Adding Edges with One-Letter Difference (3 letter words)
    Graph graph3(10);
    graph3.addEdge(L"cat", L"cot");
    graph3.addEdge(L"cot", L"cog");
    graph3.addEdge(L"cog", L"dog");
    std::cout << "Test Case: Adding Edges with One-Letter Difference (3 letter words)\n";
    std::cout << "Shortest Path from 'cat' to 'dog' (BFS):\n";
    graph3.BFS(L"cat", L"dog");
    std::cout << "Shortest Path from 'cat' to 'dog' (Dijkstra):\n";
    graph3.dijkstra(L"cat", L"dog");
    std::cout << "------------------------------------------\n";


    // Test Case: Adding Edges with One-Letter Difference (4 letter words)
    Graph graph4(10);
    graph4.addEdge(L"dark", L"bark");
    graph4.addEdge(L"bark", L"barn");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (4 letter words)\n";
    std::cout << "Shortest Path from 'dark' to 'barn' (BFS):\n";
    graph4.BFS(L"dark", L"barn");
    std::cout << "Shortest Path from 'dark' to 'barn' (Dijkstra):\n";
    graph4.dijkstra(L"dark", L"barn");
    std::cout << "------------------------------------------\n";

    // Test Case: Adding Edges with One-Letter Difference (5 letter words)
    Graph graph5(10);
    graph5.addEdge(L"stone", L"store");
    graph5.addEdge(L"store", L"score");

    std::cout << "Test Case: Adding Edges with One-Letter Difference (5 letter words)\n";
    std::cout << "Shortest Path from 'stone' to 'score' (BFS):\n";
    graph5.BFS(L"stone", L"score");
    std::cout << "Shortest Path from 'stone' to 'score' (Dijkstra):\n";
    graph5.dijkstra(L"stone", L"score");
    std::cout << "------------------------------------------\n";

}