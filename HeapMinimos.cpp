//
// Created by danid on 12/10/2021.
//

#include "HeapMinimos.h"

template<class tipo>
HeapMinimos<tipo>::HeapMinimos() : Heap<tipo>() {}

template<class tipo>
bool HeapMinimos<tipo>::compara(tipo &obj1, tipo &obj2) {
    return obj1 < obj2;
}
