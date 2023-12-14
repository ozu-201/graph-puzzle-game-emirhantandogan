//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "Edge.h"

Edge::Edge(int from, int to, int weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
    next = nullptr;
}

void Edge::setNext(Edge *_next) {
    next = _next;
}

Edge *Edge::getNext() const{
    return next;
}

int Edge::getFrom() const{
    return from;
}

int Edge::getTo() const{
    return to;
}

int Edge::getWeight() const{
    return weight;
}

Edge::Edge() {

}