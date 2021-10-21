//
// Created by danid on 10/10/2021.
//

#ifndef PROYECTO1PR_HEAP_H
#define PROYECTO1PR_HEAP_H
#include "Nodo.cpp"
#include "ListaDoble.cpp"
template <class tipo>
class Heap {
public:
    Heap();

    Nodo<tipo> *getInicio();

    void setInicio(Nodo<tipo> *inicio);

    virtual bool compara(tipo &obj1, tipo &obj2) = 0;

    Nodo<tipo> *getFinal();

    void setFinal(Nodo<tipo> *final);

    virtual void heapify(Nodo<tipo> *actual) = 0;

    virtual void insertar(tipo nuevo) = 0;

    virtual void swap(Nodo<tipo> *nodo, Nodo<tipo> *nodo2) = 0;

    virtual Heap<tipo> crearHeap(ListaDoble<tipo> *listaDoble) = 0;

    Nodo<tipo>* posicion(Nodo<tipo> *actual, int &pos);

    Nodo<tipo>* hijo(bool op, Nodo<tipo> *actual); //true hijo Izq False hijo Der

    Nodo<tipo>* padre(Nodo<tipo> *actual);
private:
    Nodo<tipo> *inicio;
    Nodo<tipo> *final;

};


#endif //PROYECTO1PR_HEAP_H
