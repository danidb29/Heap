//
// Created by danid on 12/10/2021.
//

#ifndef PROYECTO1PR_HEAPMINIMOS_H
#define PROYECTO1PR_HEAPMINIMOS_H

#include "Heap.cpp"
template <class tipo>
class HeapMinimos : public Heap<tipo>{
public:
    HeapMinimos();

public:
    virtual bool compara(tipo &obj1, tipo &obj2);
};


#endif //PROYECTO1PR_HEAPMINIMOS_H
