//
// Created by danid on 10/10/2021.
//

#ifndef PROYECTO1PR_NODO_H
#define PROYECTO1PR_NODO_H

template <class tipo>
class Nodo {
public:
    Nodo(tipo dato);

    tipo getDato();

    void setDato(tipo dato);

    Nodo<tipo> *getNext();

    void setNext(Nodo *next);

    Nodo<tipo> *getAnt();

    void setAnt(Nodo *ant);


private:
    tipo dato;
    Nodo * next;
    Nodo * ant;

};


#endif //PROYECTO1PR_NODO_H
