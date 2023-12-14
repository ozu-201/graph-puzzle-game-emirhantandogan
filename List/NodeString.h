//
// Created by Olcay Taner YILDIZ on 6.03.2023.
//

#ifndef DATASTRUCTURES_CPP_NODE_H
#define DATASTRUCTURES_CPP_NODE_H
#include <string>

using namespace  std;

class NodeString {
private:
    std::string data;
    NodeString* next;
public:
    explicit NodeString(std::string data);
    void setNext(NodeString* _next);
    NodeString* getNext();
    std::string getData();
    string to_string();
};


#endif //DATASTRUCTURES_CPP_NODE_H