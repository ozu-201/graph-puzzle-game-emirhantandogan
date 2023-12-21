//
// Created by et028745 on 12/21/2023.
//

#ifndef GRAPH_PUZZLE_GAME_EMIRHANTANDOGAN_GRAPH_H
#define GRAPH_PUZZLE_GAME_EMIRHANTANDOGAN_GRAPH_H


#include <string>
#include <vector>

class Graph{
private:
    int** edges;
    int vertexCount;
public:
    Graph(int vertexCount);
    ~Graph();
    std::vector<std::string> words;
    int getWordIndex(const std::string &word);
    void addEdge(const std::string &from, const std::string &to);
    bool isAdjacent(int from, int to);
    void BFS(const std::string &start, const std::string &end);
    void printPath(const std::vector<int> prev, int endNode);

};


#endif //GRAPH_PUZZLE_GAME_EMIRHANTANDOGAN_GRAPH_H
