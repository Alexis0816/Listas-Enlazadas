#include "forwardlist.h"

template <typename T>
Node<T>::Node() : data(T{}), next(nullptr) {}

template <typename T>
Node<T>::Node(T newData) : data(newData), next(nullptr) {}

template <typename T>
Node<T>::~Node() {}

template <typename T>
ForwardList<T>::ForwardList() : sz(0), head(nullptr) {}

template <typename T>
ForwardList<T>::ForwardList(std::initializer_list<T> init) : sz(0), head(nullptr)
{
    for (const auto &value : init)
    {
        push_back(value);
    }
}

template <typename T>
ForwardList<T>::~ForwardList() { clear(); }

template <typename T>
T ForwardList<T>::front()
{
    return empty() ? T{} : head->data;
}

template <typename T>
T ForwardList<T>::back()
{
    if (empty())
    {
        return T{};
    }
    auto it = head;
    while (it->next)
    {
        it = it->next;
    }
    return it->data;
}

template <typename T>
void ForwardList<T>::push_front(T newData)
{
    auto newHead = new Node(newData);
    newHead->next = head;
    head = newHead;
    ++sz;
}

template <typename T>
void ForwardList<T>::push_back(T newData)
{
    if (empty())
    {
        auto newNode = new Node(newData);
        head = newNode;
    }
    else
    {
        auto it = head;
        while (it->next)
        {
            it = it->next;
        }
        auto newNode = new Node(newData);
        it->next = newNode;
    }
    ++sz;
}

template <typename T>
T ForwardList<T>::pop_front()
{
    if (empty())
    {
        return T{};
    }
    auto newHead = head->next;
    T res = head->data;
    delete head;
    --sz;
    head = newHead;
    return res;
}

template <typename T>
T ForwardList<T>::pop_back()
{
    if (empty())
    {
        return T{};
    }

    if (!head->next)
    {
        T res = head->data;
        delete head;
        head = nullptr;
        --sz;
        return res;
    }

    auto it = head;
    while (it->next->next)
    {
        it = it->next;
    }
    T res = it->next->data;
    delete it->next;
    it->next = nullptr;
    --sz;

    return res;
}

// Access element by index
template <typename T>
T ForwardList<T>::operator[](int index)
{
    if (index < 0 || index >= sz)
    {
        return T{};
    }

    auto it = head;
    for (int i = 0; i < index; i++)
    {
        it = it->next;
    }
    return it->data;
}

template <typename T>
bool ForwardList<T>::empty()
{
    return !head;
}

template <typename T>
int ForwardList<T>::size()
{
    return sz;
}

template <typename T>
void ForwardList<T>::clear()
{
    if (!empty())
    {
        auto it = head;
        while (it->next)
        {
            auto nextNode = it->next;
            delete it;
            it = nextNode;
        }
        delete it;
        sz = 0;
    }
}

template <typename T>
void ForwardList<T>::sort()
{
}

template <typename T>
void ForwardList<T>::reverse()
{
    if (empty() || !head->next)
    {
        return;
    }
    Node<T> *it = head, *prev = nullptr, *next = nullptr;
    while (it)
    {
        next = it->next;
        it->next = prev;
        prev = it;
        it = next;
    }
    head = prev;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, ForwardList<T> list)
{
    auto it = list.head;
    while (it)
    {
        os << it->data;
        if (it->next)
        {
            os << ", ";
        }
        it = it->next;
    }

    return os;
}
