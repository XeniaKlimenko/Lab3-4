#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
  int length;
  T* x;
  int ind;
public:
  TStack(int size = 0);
  TStack(TStack<T>& _v);
  ~TStack();

  int getStackLength() const;
  int getIndex() const;
  int IsEmpty(void) const;
  int IsFull(void) const;
  void Push(T d);
  T Get();

  int min_elem();
  int max_elem();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TStack<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TStack<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const TStack<T1> &A) {
  for (int i = 0; i < A.ind; i++) {
    ostr << A.x[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TStack<T1> &A) {
  int count;
  istr >> count;
  for (int i = 0; i < count; i++) {
    T1 d;
    istr >> d;
    A.Push(d);
  }
  return istr;
}


template<class T>
inline TStack<T>::TStack(int size)
{
  if (size > 0)
  {
    this->length = size;
    x = new T[length];
    for (int i = 0; i < length; i++)
      x[i] = 0;
    this->ind = 0;
  }
  else throw "wrong index";
}
template <class T>
TStack<T>::TStack(TStack<T>& _v)
{
  length = _v.length;
  ind = _v.ind;
  x = new T [length];
  for (int i = 0; i < length;i = i + 1)
    x[i] = _v.x[i];
}
template <class T>
TStack<T>::~TStack()
{
  length = 0;
  if (x != 0)
    delete [] x;
  x = 0;
}


template <typename T>
inline int TStack<T>::getStackLength() const
{
  return length;
}

template <typename T>
inline int TStack<T>::getIndex() const
{
  return ind;
}

template<class T>
inline int TStack<T>::IsEmpty(void) const
{
  return x = nullptr;

  for (int i = 0; i < length; i++)
  {
    if (x[i] == 0)
      continue;
    else
      throw  logic_error("ERROR");
  }
}

template<class T>
inline int TStack<T>::IsFull(void) const
{
  for (int i = 0; i < length; i++)
  {
    if (x[i] != 0)
      continue;
    else
      throw  logic_error("ERROR");
  }
}

template<class T>
inline void TStack<T>::Push(T d)
{
  if (ind >= length)
    throw "wrong index";
  x[ind] = d;
  ind++; 
}

template<class T>
inline T TStack<T>::Get()
{
  if (ind == 0)
    throw "zero index";
  T d = x[ind - 1];
  ind--;
  return d;
}

template <class T>
int TStack<T>::Length()
{
  return length;
}

template<typename T>
inline int TStack<T>::max_elem()
{
  int res = x[0];
  for (int i = 1; i < length; i++)
  {
    if (x[i] > res)
    {
      res = x[i];
    }
  }
  return res;
}


template<typename T>
inline int TStack<T>::min_elem()
{
  int res = x[0];
  for (int i = 1; i < length; i++)
  {
    if (x[i] < res)
    {
      res = x[i];
    }
  }
  return res;
}

#endif