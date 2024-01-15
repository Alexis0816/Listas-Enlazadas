#include <iostream>
using namespace std;

// La estructura de los nodos
template <typename T>
struct Node
{
  T data;
  Node<T> *next;
  Node<T> *prev;

  // inicializamos
  Node(T value = T()) : data(value), next(nullptr), prev(nullptr){}

  void liberar(){
    delete next;
    delete prev; // liberamos memoria dinámica
  }
};

template <typename T>
class DoublyLinkedList
{
private:
  Node<T> *head;
  Node<T> *tail;
  int nodes;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr), nodes(0){}

  ~DoublyLinkedList(){
    delete head;
    delete tail;
  }

  T front(){
    return head->data;
  }

  T back(){
    return tail->data;
  }

  void push_front(T data){
    auto *nuevo = new Node<T>{data};
    if (head == nullptr and tail == nullptr)
    {
      head = tail = nuevo;
    }
    else
    {
      nuevo->prev = nullptr;
      nuevo->next = head;
      head->prev = nuevo;
      head = nuevo;
      tail->next = nullptr;
    }
    nodes += 1;
  };

  void push_back(T data)
  {
    auto *nuevo = new Node<T>{data}; // creamos un nuevo nodo
    nuevo->next = nullptr;
    nuevo->prev = tail;
    tail->next = nuevo;
    tail = nuevo;
    nodes += 1;
  }

  T pop_front()
  {
    if (head == nullptr)
      exit(0);
    int valor = head->data;
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    nodes--;
    return valor;
  }

  T pop_back()
  {
    if (head == nullptr)
    {
      exit(0);
    }
    else if (head->next == nullptr)
    { // verifica si está vacío
      int valor = head->data;
      delete head;
      delete tail;
      head = nullptr;
      tail = nullptr;
      return valor;
    }
    else
    {
      int valor = tail->data;
      tail = tail->prev;
      delete tail->next;
      tail->next = nullptr;
      nodes--;
      return valor;
    }
  }

  void insert(T data, int pos)
  {
    if (pos <= 1)
    { // inserta al inicio si la posición es negativa
      push_front(data);
    }
    else if (pos > size())
    { // inserta al final si la posición es mayor a la cantidad de nodos
      push_back(data);
    }
    else
    {
      auto *nuevo = new Node<T>{data};
      Node<T> *temp = head;
      int i = 0;
      while (++i < pos - 1)
      {
        temp = temp->next;
      }
      nuevo->next = temp->next;
      temp->next = nuevo;
      nodes++;
    }
  }

  void remove(int pos)
  {
    if (pos == 0 or pos == 1)
    {
      pop_front();
    }
    else if (pos == size())
    {
      pop_back();
    }
    else
    {
      auto *nuevo = new Node<T>;
      Node<T> *temp = head;
      int i = 0;
      while (++i < pos - 1)
      {
        temp = temp->next;
      }
      nuevo->data = temp->next->data;
      nuevo = temp->next;
      temp->next = nuevo->next; // el puntero anterior al nodo a remover apunta al nodo siguiente del nodo a remover
      delete nuevo;
      nodes--;
    }
  }

  T &operator[](int pos)
  {
    Node<T> *iter = head;
    for (int i = 1; i < pos; i++)
    {
      iter = iter->next;
    }
    return iter->data;
  }

  bool empty() { return (head == nullptr and tail == nullptr); }

  int size()
  {
    return nodes;
  }

  void clear()
  {
    if (head == nullptr)
    {
      exit(0);
    }
    else
    {
      Node<T> *temp;
      Node<T> *ptr = head;
      while (ptr->next->next == tail)
      {
        ptr = ptr->next;
      }
      temp = ptr->next;
      ptr->next = nullptr;
      delete temp;
      pop_back();
    }
  }

  void display()
  {
    for (Node<T> *temp = head; temp != nullptr; temp = temp->next)
    {
      cout << temp->data << " ";
    }
    cout << endl;
  }

  void reverse()
  {
    Node<T> *temp = tail;
    while (true)
    {
      if (temp == head)
      {
        cout << temp->data << endl;
        break;
      }
      cout << temp->data << " ";
      temp = temp->prev;
    }
  }
};
