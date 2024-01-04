//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include <string>
#include <codecvt>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "../DisjointSet.h"
#include "../Queue.h"
#include "../Heap/Heap.h"
#include "../Heap/MinHeap.h"

namespace array{

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount){
        edges = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++){
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::addEdge(int from, int to, int weight) {
        edges[from][to] = weight;
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                    }
                }
            }
        }
    }

    void Graph::BFS(std::wstring word1, std::wstring word2)
    {
        int index1 = -1;
        int index2 = -1;
        bool control1 = true;
        bool control2 = true;
        for(int i = 0; i<words.size(); i++)
        {
            if(words[i] == word1 && control1)
            {
                control1 = false;
                index1 = i;
            }
            if(words[i] == word2 && control2)
            {
                control2 = false;
                index2 = i;
            }
        }
        shortestPathBFS(numbers[index1], numbers[index2]);
    }

    void Graph::shortestPathBFS(int startNode, int endNode)
    {
        std::vector<int> predecessor(vertexCount, -1);
        std::vector<bool> visited(vertexCount, false);
        visited[startNode] = true;
        Queue queue = Queue(vertexCount);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()) {
            int fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0 && !visited[toNode]) {
                    visited[toNode] = true;
                    predecessor[toNode] = fromNode;
                    queue.enqueue(Element(toNode));
                    if(toNode == endNode)
                    {
                        printBFS(predecessor, endNode);
                        return;
                    }
                }
            }
        }
        std::cout<<"There is no path."<<std::endl;
    }

    void Graph::printBFS(std::vector<int> predecessor, int current)
    {
        if(current == -1)
        {
            return;
        }
        printBFS(predecessor, predecessor[current]);
        std::wcout<<words[current]<<std::endl;
    }

    bool Graph::isOneLetterDifference(const std::wstring word1, const std::wstring word2)
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

    void Graph::readFile(const std::string &filename, int lengthOfWord)
    {
        std::wifstream file(filename);
        file.imbue(std::locale(std::locale::classic(), new std::codecvt_utf8<wchar_t>));
        std::wstring word;

        if(!file){return;}

        while(file>>word)
        {
            int size = words.size();
            if(word.length()==lengthOfWord)
            {
                words.push_back(word);
                numbers.push_back(size);
            }
        }

        for(int i = 0; i<words.size(); i++)
        {
            for(int j = i+1; j<words.size(); j++)
            {
                if(isOneLetterDifference(words[i], words[j]))
                {
                    addEdge(words[i], words[j]);
                }
            }
        }
    }

    void Graph::addEdge(std::wstring word1, std::wstring word2)
    {
        int index1 = -1;
        int index2 = -1;
        bool control1 = true;
        bool control2 = true;
        for(int i = 0; i<words.size(); i++)
        {
            if(words[i] == word1 && control1)
            {
                index1 = i;
                control1 = false;
            }
            if(words[i] == word2 && control2)
            {
                index2 = i;
                control2 = false;
            }
        }
        if(index1==-1)
        {
            int size = words.size();
            words.push_back(word1);
            numbers.push_back(size);
        }
        if(index2==-1)
        {
            int size = words.size();
            words.push_back(word2);
            numbers.push_back(size);
        }
        control1 = true;
        control2 = true;
        for(int i = 0; i<words.size(); i++)
        {
            if(words[i] == word1 && control1)
            {
                index1 = i;
                control1 = false;
            }
            if(words[i] == word2 && control2)
            {
                index2 = i;
                control2 = false;
            }
        }
        addEdge(numbers[index1],numbers[index2]);
        addEdge(numbers[index2],numbers[index1]);
    }


    void Graph::dijkstra(std::wstring word1, std::wstring word2)
    {
        int index1 = -1;
        int index2 = -1;
        bool control1 = true;
        bool control2 = true;
        for(int i = 0; i<words.size(); i++)
        {
            if(words[i] == word1 && control1)
            {
                control1 = false;
                index1 = i;
            }
            if(words[i] == word2 && control2)
            {
                control2 = false;
                index2 = i;
            }
        }
        dijkstraShortestPath(numbers[index1], numbers[index2]);
    }

    void Graph::dijkstraShortestPath(int startNode, int endNode) {
        std::vector<int> dist(vertexCount, INT_MAX);
        std::vector<bool> sptSet(vertexCount, false);
        std::vector<int> previous(vertexCount, -1);
        dist[startNode] = 0;
        for (int count = 0; count < vertexCount - 1; count++) {
            int u = -1;
            for (int v = 0; v < vertexCount; v++) {
                if (!sptSet[v] && (u == -1 || dist[v] < dist[u]))
                    u = v;
            }
            sptSet[u] = true;
            for (int v = 0; v < vertexCount; v++) {
                if (!sptSet[v] && edges[u][v] && dist[u] != INT_MAX && dist[u] + edges[u][v] < dist[v]) {
                    dist[v] = dist[u] + edges[u][v];
                    previous[v] = u;
                }
            }
        }
        std::vector<int> path;
        for (int at = endNode; at != -1; at = previous[at]) {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());
        if (path.size() == 1 && path[0] == startNode) {
            std::cout << "There is no path. "<< std::endl;
        } else {
            for (int i = 0; i < path.size(); i++) {
                std::wcout << words[path[i]]<<std::endl;
            }
        }
    }

    void Graph::printWords()
    {
        for(int i = 0; i<words.size(); i++)
        {
            std::wcout<<numbers[i]<<" "<<words[i]<<std::endl;
        }
    }
}
