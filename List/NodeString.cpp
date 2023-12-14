//
// Created by Olcay Taner YILDIZ on 6.03.2023.
//

#include "NodeString.h"

NodeString::NodeString(std::string data) {
    this->data = data;
    this->next = nullptr;
}

void NodeString::setNext(NodeString *_next) {
    this->next = _next;
}

NodeString *NodeString::getNext() {
    return next;
}

std::string NodeString::getData() {
    return data;
}

/*
string NodeString::to_string() {
    return ::to_string(data);
}*/