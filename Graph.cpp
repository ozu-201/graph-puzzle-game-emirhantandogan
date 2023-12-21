//
// Created by et028745 on 12/21/2023.
//

#include <iostream>
#include "Graph.h"
#include "List/Queue.h"

Graph::Graph(int vertexCount) : vertexCount(vertexCount) {
    edges = new int *[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        edges[i] = new int[vertexCount];
    }
}

Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}

int Graph::getWordIndex(const std::string &word) {
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word) {
            //std::cout<<i<<std::endl;
            return i;
        }
    }
    return -1;
}

void Graph::addEdge(const std::string &from, const std::string &to) {
    int fromIndex = getWordIndex(from);
    int toIndex = getWordIndex(to);
    if (fromIndex != -1 && toIndex != -1) {
        //std::cout << "calisti" << std::endl;
        edges[fromIndex][toIndex] = 1;
        edges[toIndex][fromIndex] = 1;
    }
}

bool Graph::isAdjacent(int from, int to) {
    return edges[from][to] != 0;
}

void Graph::BFS(const std::string &start, const std::string &end) {
    int startNode = getWordIndex(start);
    int endNode = getWordIndex(end);
    if(startNode==-1)
    {
        std::cout<<"There is no "<<start<<"in the dictionary."<<std::endl;
    }
    if(endNode==-1)
    {
        std::cout<<"There is no "<<end<<"in the dictionary."<<std::endl;
        return;
    }

    std::vector<int> prev(words.size(), -1);
    std::vector<bool> visited(words.size(), false);
    list::Queue queue;
    queue.enqueue(new Node(startNode));
    visited[startNode] = true;
    bool thereIsPath = false;

    while (!queue.isEmpty()) {
        Node *node = queue.dequeue();
        int fromNode = node->getData();
        if (fromNode == endNode) {
            printPath(prev, endNode);
            thereIsPath = true;
            return;
        }
        for (int toNode = 0; toNode < words.size(); toNode++) {
            if (isAdjacent(fromNode, toNode) && !visited[toNode]) {
                visited[toNode] = true;
                prev[toNode] = fromNode;
                queue.enqueue(new Node(toNode));
            }
        }
    }

    if (!thereIsPath) {
        std::cout << "There is no path" << std::endl;
    }

}

void Graph::printPath(const std::vector<int> prev, int endNode) {
    std::vector<int> path;
    for (int at = endNode; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    int pathSize = path.size();
    for (int i = 0; i < pathSize / 2; ++i) {
        int temp = path[i];
        path[i] = path[pathSize - 1 - i];
        path[pathSize - 1 - i] = temp;
    }
    for (int node: path) {
        std::cout << words[node] << std::endl;
    }
}

