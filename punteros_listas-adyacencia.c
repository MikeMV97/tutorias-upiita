
typedef struct Nodo_ {
    int dato;
    Nodo_* sig;
} Nodo;

typedef Nodo* Nodo_ptr;

int dato = 24;
dato++; // dato==25
int* dato_ptr = &dato;

int arreglo[5] = {1,2,3,4,5};
arreglo++; // ==arreglo+=(una posicion de memoria);
(*arreglo) // == 2
arreglo[0];

dato_ptr++;

int** dato_ptr_ptr = &dato_ptr;
int valor_dato = (*dato_ptr); // 24
int* otro_ptr = dato_ptr; // 0Xasdfasd

// Buscar el elemento con dato == x
Nodo_ptr lista_ady;
Nodo_ptr buscar_x(Nodo_ptr raiz, int x){
    Nodo_ptr nodo_observado = raiz;

    while( nodo_observado!=NULL 
            && nodo_observado->dato != x){
        // nodo_observado = nodo_observado->sig;
        nodo_observado = (*nodo_observado).sig;
    }
    if (nodo_observado != NULL){
        // Se encontro valor
        return nodo_observado;
    }
    return NULL;
}


// Pila:
Nodo_ptr push(Nodo_ptr raiz, Nodo_ptr nuevo_elemento){
    Nodo_ptr aux = raiz;
    raiz = nuevo_elemento;
    raiz->sig = aux;
    return raiz;
}
Nodo_ptr pop(Nodo_ptr raiz){
    Nodo_ptr aux = copia(raiz);
    // Eliminar ultimo elemento de lista
    raiz = raiz->sig;
    raiz->ant = NULL;

    return aux;
}
// Cola
Nodo_ptr push(Nodo_ptr raiz, Nodo_ptr nuevo_elemento){
    Nodo_ptr aux = raiz;
    raiz = nuevo_elemento;
    raiz->sig = aux;
    return raiz;
}
Nodo_ptr pop(Nodo_ptr raiz){
    Nodo_ptr aux = raiz;
    while(aux->sig != NULL){
        aux = aux->sig;
    }
    return aux;
}

// Dolemente ligadas
Nodo_ptr actual;

Nodo_ptr otro_nodo = actual->ant->sig->sig;


Nodo_ptr eliminar(Nodo_ptr raiz, Nodo_ptr nd_elim){
    Nodo_ptr nd_ant = nd_elim->ant;
    Nodo_ptr nd_sig = nd_elim->sig;
    nd_ant->sig = nd_elim->sig;
    nd_sig->ant = nd_elim->ant;
    free(nd_elim);
    return raiz;
}

