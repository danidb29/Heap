//
// Created by danid on 12/10/2021.
//

#ifndef PROYECTO1PR_HEAPMAXIMOS_H
#define PROYECTO1PR_HEAPMAXIMOS_H

#include "Heap.cpp"

template<class tipo>
class HeapMaximos : public Heap<tipo>{
public:
    HeapMaximos();
    bool compara(tipo &obj1, tipo &obj2);
    void insertar(tipo nuevo);
    void borrar();
};


#endif //PROYECTO1PR_HEAPMAXIMOS_H
