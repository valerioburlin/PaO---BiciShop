/* Dichiarazione e definizione template di classe vettore<K> e suoi metodi */

#ifndef VETTORE_H
#define VETTORE_H

#include "errori.h"
#include <iostream>
using std::cout;
/********************************************************/
/* Interfaccia pubblica template di classe vettore<K> */

template<class T>
class vettore {
  friend class iterator;
  friend class const_iterator;

  private:
  	int capacity, size;
  	T* array;

    void resize();          // Raddoppia la dimensione dell'array
  	
  public:
    class const_iterator {         // Classe interna iteratori costanti
      friend class vettore;

      protected:
        T* punt;

      public:
        bool operator==(const const_iterator& ) const;      // Uguaglianza tra puntatori
        bool operator!=(const const_iterator& ) const;      // Disuguaglianza tra puntatori
        const_iterator& operator++();                       // Incremento prefisso
        const_iterator& operator++(int );                   // Incremento postfisso
        const_iterator& operator--();                       // Decremento prefisso
        const_iterator& operator--(int );                   // Decremento postfisso
        const_iterator operator+(int );                     // Incremento di n posizioni 
        const_iterator operator-(int );                     // Decremento di n posizioni 
        const T& operator*() const;                         // Dereferenzizione
        const T* operator->() const;                        // Indicizazzione
    };

    class iterator : public const_iterator {         // Classe derivata da const_iterator per effettuare modifiche su oggetti puntati
      friend class vettore;

      public:
        T& operator*() const;                         // Dereferenziazione
        T* operator->() const;                        // Indicizazzione
    };  

    vettore(T =0, int =0, int =1);        // Costruttore a 0,1 e 2 argomenti

  	vettore(const vettore& );                       // Costruttore di copia(profondo)
  	~vettore();                                     // Distruttore(profondo)
  	vettore& operator=(const vettore& ) const;      // Assegnazione(profonda)

    int getSize() const;             // Ritorna il numero di elementi del contenitore
    int getCapacity() const;         // Ritorna il numero massimo di elementi che può contenere il contenitore senza ridimensionarlo
    bool isEmpty() const;            // Controlla se il contenitore è vuoto

    const_iterator cbegin() const;
    const_iterator cend() const;
   	iterator begin() const;
    iterator end() const;
    T& operator[](const_iterator ) const;
    T& operator[](iterator ) const; 
    T& operator[](int ) const throw(FuoriPosizione);

    void push_back(T& );       // Inserisce l'elemento in fondo al vettore
    void pop_back();          // Elimina l'ultimo elemento del vettore 

    void insert(int , T& ) throw(FuoriPosizione);   // Inserisce l'elemento nell'indice x 
    void erase(int ) throw(FuoriPosizione);        // Elimina l'elemento nell'indice x
};



/**************************************/
/* Definizione metodi di Container<K> */

/****************************/
/* Metodi di const_iterator */

template<class T>
bool vettore<T>::const_iterator::operator==(const const_iterator& it) const { return punt == it.punt; }


template<class T>
bool vettore<T>::const_iterator::operator!=(const const_iterator& it) const { return punt != it.punt; }


template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator++() {
  if(punt)
    punt = punt + 1;
  return *this;
}


template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator++(int ) {
  typename vettore<T>::const_iterator aux = *this;
  if(punt)
    punt = punt + 1;
  return aux;
}


template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator--() {
  if(punt)
    punt = punt - 1;
  return *this;
}


template<class T>
typename vettore<T>::const_iterator& vettore<T>::const_iterator::operator--(int ) {
  typename vettore<T>::const_iterator aux = *this;
  if(punt)
    punt = punt - 1;
  return aux;
}


template<class T>
typename vettore<T>::const_iterator vettore<T>::const_iterator::operator+(int pos) {
  if(punt)
    punt = punt + pos;
  return *this;
}


template<class T>
typename vettore<T>::const_iterator vettore<T>::const_iterator::operator-(int pos) {
  if(punt)
    punt = punt - pos;
  return *this;
}


template<class T>
const T& vettore<T>::const_iterator::operator*() const { return *punt; }


template<class T>
const T* vettore<T>::const_iterator::operator->() const { return punt; }


/**********************/
/* Metodi di iterator */

template<class T>
T& vettore<T>::iterator::operator*() const { return *(const_iterator::punt); }


template<class T>
T* vettore<T>::iterator::operator->() const { return const_iterator::punt; }


/***********************/
/* Metodi di vettore */

template<class T>
vettore<T>::vettore(T x, int y, int z) : capacity(z) , size(y) , array(new T[z]) {
	for(int i=0; i<size; i++)
		array[i] = x;
} 


template<class T>
vettore<T>::vettore(const vettore<T>& cc) : capacity(cc.capacity) , size(cc.size) , array(new T[cc.capacity]) {
	for(int i=0; i<size; i++)
		array[i] = cc.array[i];
}


template<class T>
vettore<T>::~vettore() { delete[] array; }


template<class T>
vettore<T>& vettore<T>::operator=(const vettore<T>& cc) const {
	if(this != &cc)
	{
		delete[] array;
        capacity = cc.capacity;
		size = cc.size;
		array = new T[capacity];
		for(int i=0; i<size; i++)
			array[i] = cc.array[i];
	}
	return *this;
} 


template<class T>
int vettore<T>::getSize() const { return size; }


template<class T>
int vettore<T>::getCapacity() const { return capacity; }


template<class T>
bool vettore<T>::isEmpty() const { return size==0; }


template<class T>
void vettore<T>::resize() {
    T* tmp = array;
    capacity *= 2;
    array = new T[capacity];
    for(int i=0; i<size; i++)
      array[i] = tmp[i];

    delete[] tmp; 
}


template<class T>
typename vettore<T>::const_iterator vettore<T>::cbegin() const {
  typename vettore<T>::const_iterator aux;
  aux.punt = array;
  return aux;
}


template<class T>
typename vettore<T>::const_iterator vettore<T>::cend() const {
  typename vettore<T>::const_iterator aux;
  aux.punt = &array[size];
  return aux;
}


template<class T>
typename vettore<T>::iterator vettore<T>::begin() const {
  typename vettore<T>::iterator aux;
  aux.punt = array;
  return aux;
}


template<class T>
typename vettore<T>::iterator vettore<T>::end() const {
  typename vettore<T>::iterator aux;
  aux.punt = &array[size];
  return aux;
}


template<class T>
T& vettore<T>::operator[](typename vettore<T>::const_iterator it) const { return *(it.punt); }


template<class T>
T& vettore<T>::operator[](typename vettore<T>::iterator it) const { return *(it.punt); }


template<class T>
T& vettore<T>::operator[](int x) const throw(FuoriPosizione) { 
  if(x<0 || x>=size)
    throw FuoriPosizione("Indice non valido per il vettore");

  return array[x]; 
}


template<class T>
void vettore<T>::push_back(T& t) {
  if(size == capacity)
    resize();
  
  array[size] = t;
  size++;
}


template<class T>
void vettore<T>::pop_back() {
  array[size-1] = 0;
  size--;
}


template<class T>
void vettore<T>::insert(int x, T& t) throw(FuoriPosizione) {
  if(x<0 || x>=size)
    throw FuoriPosizione("Indice non valido per il vettore");

  if(size == capacity)
    resize();

 for(int i=size; i!=x; i--)
    array[i] = array[i-1];

  size++;
  array[x] = t;
}


template<class T>
void vettore<T>::erase(int x) throw(FuoriPosizione) {
  if(x<0 || x>=size)
    throw FuoriPosizione("Indice non valido per il vettore");

  size--;
  for(int i=x; i<size; i++)
    array[i] = array[i+1];

  array[size] = 0;
}


#endif
