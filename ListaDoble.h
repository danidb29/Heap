
// Created by danid on 21/10/2021.
//

#include "Nodo.cpp"
#ifndef PROYECTO1PR_LISTADOBLE_H
#define PROYECTO1PR_LISTADOBLE_H

template <class tipo>
class ListaDoble {
private:
    Nodo<tipo>* inicio;
public:

    ListaDoble();
    Nodo<tipo>* getInicio();
    void setInicio(Nodo<tipo>* inicio);
    void Insertar(tipo valor);
    bool IsEmpty();
    ~ListaDoble();


};


#endif //PROYECTO1PR_LISTADOBLE_H
