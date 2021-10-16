//
// Created by danid on 10/10/2021.
//

#include "Nodo.h"

template<class tipo>
Nodo<tipo>::Nodo(tipo dato):dato(dato), next(nullptr), ant(nullptr) {}

template<class tipo>
tipo Nodo<tipo>::getDato(){
    return dato;
}

template<class tipo>
void Nodo<tipo>::setDato(tipo dato) {
    Nodo::dato = dato;
}

template<class tipo>
Nodo<tipo>* Nodo<tipo>::getNext() {
    return next;
}

template<class tipo>
void Nodo<tipo>::setNext(Nodo *next) {
    Nodo::next = next;
}

template<class tipo>
Nodo<tipo> *Nodo<tipo>::getAnt(){
    return ant;
}

template<class tipo>
void Nodo<tipo>::setAnt(Nodo *ant) {
    Nodo::ant = ant;
}
