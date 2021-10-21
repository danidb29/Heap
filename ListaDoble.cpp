//
// Created by danid on 21/10/2021.
//

#include "ListaDoble.h"
template<class tipo>
ListaDoble<tipo>::ListaDoble(){
    inicio = nullptr;
}
template<class tipo>
Nodo<tipo>* ListaDoble<tipo>::getInicio() {
    return inicio;
}
template<class tipo>
void ListaDoble<tipo>::setInicio(Nodo<tipo>* inicio) {
    this->inicio = inicio;
}
template<class tipo>
bool ListaDoble<tipo>::IsEmpty() {
    if (inicio == nullptr) {
        return true;
    }
    return false;
}
template<class tipo>
void ListaDoble<tipo>::Insertar(tipo valor) {
    Nodo<tipo>* nuevo = new Nodo<tipo>;
    nuevo->setValor(valor);

    if (IsEmpty()) {
        inicio = nuevo;
        return;
    }
    Nodo<tipo> *tmp = inicio;
    while (tmp->getNext() != nullptr){
        tmp = tmp->getNext();
    }
    nuevo->setNext(nullptr);
    nuevo->setBefore(tmp);
    tmp->setNext(nuevo);
    return;
}
template<class tipo>
ListaDoble<tipo>::~ListaDoble() {
    Nodo<tipo>* tmp;

    while (tmp != nullptr) {
        tmp = inicio;
        inicio = inicio->getNext();
        delete tmp;
    }
}