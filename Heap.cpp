//
// Created by danid on 10/10/2021.
//

#include "Heap.h"

template<class tipo>
Heap<tipo>::Heap() {
    inicio = nullptr;
    final = nullptr;
}

template<class tipo>
Nodo<tipo> *Heap<tipo>::getInicio(){
    return inicio;
}

template<class tipo>
void Heap<tipo>::setInicio(Nodo<tipo> *inicio) {
    Heap::inicio = inicio;
}


template<class tipo>
Nodo<tipo> *Heap<tipo>::getFinal(){
    return final;
}

template<class tipo>
void Heap<tipo>::setFinal(Nodo<tipo> *final) {
    Heap::final = final;
}

template <class tipo>
Nodo<tipo>* Heap<tipo>::posicion(Nodo<tipo> *actual, int &pos) {
    Nodo<tipo> *tmp = inicio;
    pos = 0;
    while(tmp != nullptr){
        if(tmp == actual){
            return tmp;
        }
        tmp = tmp->getNext();
        pos++;
    }
}

template <class tipo>
Nodo<tipo>* Heap<tipo>::padre(Nodo<tipo> *actual) {
    int pos = 0;
    Nodo<tipo> *tmp = inicio;
    posicion(actual, pos);
    int papa = (pos-1)/2;
    pos = 0;
    while(pos < papa){
        tmp = tmp->getNext();
        pos++;
    }
    return tmp;
}

template <class tipo>
Nodo<tipo>* Heap<tipo>::hijo(bool op, Nodo<tipo> *actual) {
    Nodo<tipo> *tmp;
    int pos = 0;
    tmp = posicion(actual,pos);
    int hijo = 0;
    if (op){
        hijo = pos*2+1;
        while(pos < hijo){
            tmp = tmp->getNext();
            pos++;
        }
        return tmp;
    }
    hijo = 2*pos+2;
    while(pos < hijo){
        tmp = tmp->getNext();
        pos++;
    }
    return tmp;
}
