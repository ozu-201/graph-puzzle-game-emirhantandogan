//
// Created by Olcay Taner YILDIZ on 20.03.2023.
//

#include "Element.h"

namespace array {

    Element::Element(int data) {
        this->data = data;
    }

    int Element::getData() {
        return data;
    }

    Element::Element() {

    }

}