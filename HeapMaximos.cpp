//
// Created by danid on 12/10/2021.
//

#include "HeapMaximos.h"

template<class tipo>
HeapMaximos<tipo>::HeapMaximos() : Heap<tipo>() {}

template<class tipo>
bool HeapMaximos<tipo>::compara(tipo &obj1, tipo &obj2) {
    return obj1 > obj2;
}

template<class tipo>
void HeapMaximos<tipo>::insertar(tipo nuevo) {
    Nodo<tipo>* nuevoN = new Nodo<tipo>(nuevo);
    if(this->getInicio() == nullptr){
        this->setInicio(nuevoN);
        this->setFinal(nuevoN);
        return;
    }else{
        nuevoN->setAnt(this->getFinal());
        this->getFinal()->setNext(nuevoN);
        this->setFinal(nuevoN);
        Nodo<tipo> *padre = this->padre(this->getFinal());
        Nodo<tipo> * tmp = this->getFinal();
        Nodo<tipo> *auxAnt;
        Nodo<tipo> *auxNext;
        while(tmp->getDato() > padre->getDato()){
            swap(tmp, padre);
            padre = this->padre(tmp);
        }
        return;
    }
}
template <class tipo>
void HeapMaximos<tipo>::borrar() {
    Nodo<tipo> *tmp = this->getFinal();
    this->setFinal(tmp->getAnt());
    tmp->getAnt()->setNext(nullptr);
    this->getInicio()->getNext()->setAnt(tmp);
    tmp->setNext(this->getInicio()->getNext());
    tmp->setAnt(nullptr);
    delete this->getInicio();
    this->setInicio(nullptr);
    this->setInicio(tmp);

    Nodo<tipo> *der = this->hijo(false, this->getInicio());
    Nodo<tipo> *izq = this->hijo(true, this->getInicio());
    Nodo<tipo> *mayorHijo = nullptr;
    Nodo<tipo> *auxAnt = nullptr;
    Nodo<tipo> *auxNext = nullptr;
    if(izq->getDato() > der->getDato()){
        mayorHijo = izq;
    }else{
        mayorHijo = der;
    }
    Nodo<tipo> *aux = this->getInicio();
    while(aux->getDato() < mayorHijo->getDato()){
        swap(mayorHijo, aux);
        der = this->hijo(false, aux);
        izq = this->hijo(true, aux);
        if(!der && !izq){
            break;
        }
        if(!der || !izq){
            mayorHijo = izq;
        }else{
            if(izq->getDato() > der->getDato()){
                mayorHijo = izq;
            }else{
                mayorHijo = der;
            }
        }
    }
}



