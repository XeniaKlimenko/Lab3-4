#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

using namespace std;

template <class T>
class TQueue
{
protected:
  int length;
  T* x;
  int ind;
  int end;
  int count;
public:
  TQueue(int size=0);
  TQueue(TQueue<T>& _v);
  ~TQueue();

  void Push(T d);
  T Get();
  int IsEmpty(void) const;
  int IsFull(void) const;

  int min_elem();
  int max_elem();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TQueue<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TQueue<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const TQueue<T1> &A) {
  for (int i = A.ind; i < A.end; i++) {
    ostr << A.x[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TQueue<T1> &A) {
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
inline TQueue<T>::TQueue(int size)
{
  if (size > 0)
  {
    this->length = size;
    x = new T[length];

    for (int i = 0; i < length; i++)
      x[i] = 0;

    this->ind = 0;
    this->end = 0;
    this->count = 0;
  }
  else throw logic_error("ERROR");
}

template <class T>
TQueue<T>::TQueue(TQueue<T>& _v)
{
  length = _v.length;
  ind = _v.ind;
  end = _v.end;
  count = _v.count;
  x = new T[length];

  for (int i = 0; i < length; i = i + 1)
  {
    x[i] = _v.x[i];
  }

}

template <class T>
TQueue<T>::~TQueue()
{
  length = 0;
  if (x != 0)
    delete [] x;
  x = 0;
}


template<class T>
inline void TQueue<T>::Push(T d)
{
  if (IsFull())
    throw "the queue is full";

  x[end] = d;
  end = (end + 1) % length;
  count++;
}

template<class T>
inline T TQueue<T>::Get()
{
  if (IsEmpty())
    throw "the queue is empty";

  T d = x[ind];
  ind = (ind + 1) % length;
  count--;
  return d;
}

template<class T>
inline int TQueue<T>::IsEmpty(void) const
{
  return count==0;
}

template<class T>
inline int TQueue<T>::IsFull(void) const
{
  return count == length;
}

template <class T>
int TQueue<T>::Length()
{
  return length;
}

template<class T>
inline int TQueue<T>::min_elem()
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

template<class T>
inline int TQueue<T>::max_elem()
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


#endif