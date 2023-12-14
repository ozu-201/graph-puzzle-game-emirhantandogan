//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_EDGE_H
#define DATASTRUCTURES_CPP_EDGE_H


class EdgeString {
private:
    std::string from;
    std::string to;
    int weight;
    EdgeString* next;
public:
    EdgeString();
    EdgeString(std::string from, std::string to, int weight);
    void setNext(EdgeString* _next);
    EdgeString* getNext() const;
    std::string getFrom() const;
    std::string getTo() const;
    int getWeight() const;
};


#endif //DATASTRUCTURES_CPP_EDGE_H