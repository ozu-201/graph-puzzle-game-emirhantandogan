//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include <vector>
#include "../../General/AbstractGraph.h"
#include "../../List/Graph/Edge.h"

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void printBFS(std::vector<int> predecessor, int current);
        void shortestPathBFS(int startNode, int endNode);
        void dijkstraShortestPath(int startNode, int endNode);
    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
    public:
        std::vector<std::wstring> words;
        std::vector<int> numbers;
        explicit Graph(int vertexCount);
        ~Graph();



        bool isOneLetterDifference(const std::wstring word1, const std::wstring word2);

        void readFile(const std::string &filename, int lengthOfWord);

        void addEdge(std::wstring word1, std::wstring word2);

        void BFS(std::wstring word1, std::wstring word2);

        void dijkstra(std::wstring word1, std::wstring word2);

        void printWords();
    };

}


#endif //DATASTRUCTURES_CPP_GRAPH_H
