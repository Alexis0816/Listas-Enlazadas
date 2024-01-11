#include <iostream>
#include <initializer_list>

template <typename T>
struct Node
{
    T data{};
    Node *next{};
    Node();
    Node(T newData);
    ~Node();
};

template <typename T>
class ForwardList
{
    int sz{};
    Node<T> *head{};

public:
    ForwardList();
    ForwardList(std::initializer_list<T> init);
    ~ForwardList();
    T front();
    T back();
    void push_back(T newData);
    void push_front(T newData);
    T pop_front();
    T pop_back();
    T operator[](int index);
    bool empty();
    int size();
    void clear();
    void sort();
    void reverse();

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, ForwardList<U> list);
};