//
// Created by et028745 on 12/14/2023.
//

#include <string>
#include "EdgeString.h"

EdgeString::EdgeString(std::string from, std::string to, int weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
    next = nullptr;
}

void EdgeString::setNext(EdgeString *_next) {
    next = _next;
}

EdgeString *EdgeString::getNext() const{
    return next;
}

std::string EdgeString::getFrom() const{
    return from;
}

std::string EdgeString::getTo() const{
    return to;
}

int EdgeString::getWeight() const{
    return weight;
}

EdgeString::EdgeString() {

}
