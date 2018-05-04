#pragma once

#ifndef INCLUDED_LISTA_H
#define INCLUDED_LISTA_H

#include <stdexcept>

template<class T>
class Lista
{
   T * contents;

   int size;
   int capacity;

public:
   virtual ~Lista();
   Lista(int _capacity);

   void push_back(const T& data);
   void push_front(const T& data);

   T pop(int index);
   T pop_back();
   T pop_front();

   void clear();
   void remove(const T& data);
   
   bool empty() const;
   bool full() const;
   bool contains(const T& data) const;

   int find(const T& data) const;

   int getSize() const { return size; }
   int getCapacity() const { return capacity; }

   T& operator[](int index) const { return contents[index]; }
};

template <class T>
Lista<T>::~Lista()
{
   delete[] contents;
}

template <class T>
Lista<T>::Lista(int _capacity)
{
   size = 0;
   capacity = _capacity;
   contents = new T[capacity];
}

/* Throws std::overflow_error */
template <class T>
void Lista<T>::push_back(const T& data)
{
   if (full())
      throw std::overflow_error("Empty list.");
   contents[size++] = data;
}

/* Throws std::overflow_error */
template <class T>
void Lista<T>::push_front(const T& data)
{
   if (full())
      throw std::overflow_error("Full list");
   if (size > 0) {
      for (int i = size; i > 0; i--)
         contents[i] = contents[i - 1];
   }
   contents[0] = data;
   size++;
}

template <class T>
T Lista<T>::pop(int index)
{
   if (empty())
      throw std::underflow_error("Lista vazia");
   if (index > size - 1)
      throw std::range_error("Indice nao valido");
   auto data = contents[index];
   for (int i = index; i < size; i++)
      contents[i - 1] = contents[i];
   size--;
   return data;
}

template <class T>
T Lista<T>::pop_back()
{
   if (empty())
      throw std::underflow_error("Lista vazia");
   auto data = contents[--size];
   contents[size] = 0;
   return data;
}

template <class T>
T Lista<T>::pop_front()
{
   if (empty())
      throw std::underflow_error("Lista vazia");
   auto data = contents[0];
   for (int i = 1; i < capacity; i++)
      contents[i - 1] = contents[i];
   size--;
   return data;
}

template <class T>
void Lista<T>::clear()
{
   while (size)
      delete pop_back();
}

template <class T>
void Lista<T>::remove(const T& data)
{
   const int index = find(data);
   if (index > -1) {
      contents[index] = 0;
      for (int i = index; i < capacity; i++)
         contents[i - 1] = 1;
      size--;
   }
}

template <class T>
bool Lista<T>::empty() const
{
   return size == 0;
}

template<class T>
bool Lista<T>::full() const {
   return size == capacity;
}


template <class T>
bool Lista<T>::contains(const T& data) const
{
   for (int i = 0; i < size; i++) {
      if (contents[i] == data)
         return true;
   }
   return false;
}

template <class T>
int Lista<T>::find(const T& data) const
{
   for (int i = 0; i < size; i++) {
      if (contents[i] == data)
         return i;
   }
   return -1;
}


#endif