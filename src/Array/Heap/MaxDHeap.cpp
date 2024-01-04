//
// Created by Olcay Taner YILDIZ on 18.05.2023.
//

#include "MaxDHeap.h"

void MaxDHeap::percolateDown(int no) {
    int child, largestChild;
    int value;
    do{
        largestChild = -1;
        value = array[no].getData();
        for (int i = 1; i <= d && d * no + i < count; i++){
            child = d * no + i;
            if (value < array[child].getData()){
                largestChild = child;
                value = array[child].getData();
            }
        }
        if (largestChild != -1){
            swapNode(no, largestChild);
            no = largestChild;
        } else {
            break;
        }
    } while (true);
}

void MaxDHeap::percolateUp(int no) {
    int parent;
    parent = (no - 1) / d;
    while (parent >= 0 && array[parent].getData() < array[no].getData()){
        swapNode(parent, no);
        no = parent;
        parent = (no - 1) / d;
    }
}

MaxDHeap::MaxDHeap(int N, int d) : DHeap(N, d) {

}

void MaxDHeap::update(int k, int newValue) {
    int oldValue = array[k].getData();
    array[k].setData(newValue);
    if (oldValue > newValue){
        percolateDown(k);
    } else {
        percolateUp(k);
    }
}
