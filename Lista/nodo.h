#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo
{
private:
    T dato;
    Nodo<T> *siguiente;

public:
    T getDato()
    {
        return dato;
    }

    void setDato(T d)
    {
        dato = d;
    }

    Nodo<T> *getSiguiente()
    {
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguientePtr)
    {
        this->siguiente = siguientePtr;
    }
};

#endif // NODO_H