#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;
template <typename E>
class Queue
{
  public:
    Queue();
    ~Queue();

    void insert(const E& e);

    const E& remove();
    const E& peek();
    DoubleLinkedNode<E>* peekNode() const;
    bool isEmpty() const;
    int getSize();
    void printQueue();

  private:
    //DoubleLinkedNode<E> *front;
    //DoubleLinkedNode<E> *back;

    DoubleLinkedList<E> linkedList;
};
template<typename E> Queue<E>::Queue()
{

}
template<typename E> Queue<E>::~Queue()
{

}
template<typename E> void Queue<E>::insert(const E& e)
{
  linkedList.insertBack(e);
}
template<typename E> const E& Queue<E>::remove()
{
  return linkedList.removeFront();
}
template<typename E> const E& Queue<E>::peek()
{
  return linkedList.getFront();
}
template<typename E> DoubleLinkedNode<E>* Queue<E>::peekNode() const
{
  return linkedList.getFrontNode();
}
template<typename E> bool Queue<E>::isEmpty() const
{
  return linkedList.isEmpty();
}
template<typename E> int Queue<E>::getSize()
{
  return linkedList.getSize();
}


















template<typename E> void Queue<E>::printQueue()
{
  linkedList.printList();
}
