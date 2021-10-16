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
            auxNext = tmp->getNext();
            auxAnt = tmp->getAnt();

            //caso de tener que subir hata la raiz
            if(padre->getAnt() == nullptr){
                //caso en el que esten a la par
                if(auxAnt == padre){
                    this->setInicio(tmp);
                    tmp->setAnt(nullptr);
                    padre->setNext(auxNext);
                    auxNext->setAnt(padre);
                    tmp->setNext(padre);
                    padre->setAnt(tmp);
                }else{
                    //caso en el que no esten a la par de la raiz
                    this->setInicio(tmp);
                    tmp->setAnt(nullptr);
                    tmp->setNext(padre->getNext());
                    padre->getNext()->setAnt(tmp);

                    padre->setNext(auxNext);
                    auxNext->setAnt(padre);
                    auxAnt->setNext(padre);
                    padre->setAnt(auxAnt);
                }
                break;
            //si no es la raiz
            }else{
                padre->getAnt()->setNext(tmp);
                tmp->setAnt(padre->getAnt());
            }
            padre->getNext()->setAnt(tmp);
            tmp->setNext(padre->getNext());

            auxAnt->setNext(padre);
            padre->setAnt(auxAnt);
            //si estamos en el final
            if(auxNext == nullptr){
                this->setFinal(padre);
                padre->setNext(nullptr);
            }else{
                auxNext->setAnt(padre);
                padre->setNext(auxNext);
            }
            padre = this->padre(tmp);
        }
        return;
    }
}
template <class tipo>
void HeapMaximos<tipo>::borrar() {
    Nodo<tipo> *tmp = this->getFinal();
    tmp->getAnt()->setNext(nullptr);
    this->getInicio()->getNext()->setAnt(tmp);
    tmp->setNext(this->getInicio()->getNext());
    tmp->setAnt(nullptr);
    delete this->getInicio();
    this->setInicio(nullptr);
    this->setInicio(tmp);

    Nodo<tipo> *der = this->hijo(true, this->getInicio());
    Nodo<tipo> *izq = this->hijo(false, this->getInicio());
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
        auxNext = mayorHijo->getNext();
        auxAnt = mayorHijo->getAnt();

        if(aux->getAnt() == nullptr){
            //caso especial raiz pegado
            if(auxAnt == aux){
                this->setInicio(mayorHijo);
                aux->setNext(auxNext);
                auxNext->setAnt(aux);
                mayorHijo->setNext(aux);
                aux->setAnt(mayorHijo);
                mayorHijo->setAnt(nullptr);
            }else{
                //caso en el que no esten a la par de la raiz
                this->setInicio(mayorHijo);
                mayorHijo->setAnt(nullptr);
                mayorHijo->setNext(aux->getNext());
                aux->getNext()->setAnt(mayorHijo);

                aux->setNext(auxNext);
                auxNext->setAnt(aux);
                auxAnt->setNext(aux);
                aux->setAnt(auxAnt);
            }
        }else{
            //se realiza el cambio si no es la raiz
            aux->getAnt()->setNext(mayorHijo);
            mayorHijo->setAnt(aux->getAnt());
            aux->getNext()->setAnt(mayorHijo);
            mayorHijo->setNext(aux->getNext());

            //se hace el cambio de del anterior al padre
            auxAnt->setNext(aux);
            aux->setAnt(auxAnt);
            //se verifica que no sea nullptr
            if(auxNext == nullptr){
                this->setFinal(aux);
                aux->setNext(nullptr);
            }else{
                auxNext->setAnt(aux);
                aux->setNext(auxNext);
            }
        }
        der = this->hijo(true, aux);
        izq = this->hijo(false, aux);
        if(izq->getDato() > der->getDato()){
            mayorHijo = izq;
        }else{
            mayorHijo = der;
        }
    }
}



