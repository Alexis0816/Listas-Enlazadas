#include <iostream>
#include "DoublyLinkedList.h"
// using namespace std;

int main()
{
    DoublyLinkedList<int> d1;
    // vemos si está vacío --> 1 = true ; 0 = false
    cout << "Vacio: " << d1.empty() << endl;

    // agregamos valores al inicio
    d1.push_front(2);
    d1.push_front(6);
    d1.push_front(0);

    // imprimimos el arreglo
    d1.display();

    // imprimimos el tamaño
    cout << "Size: " << d1.size() << endl;

    // imprimimos el valor del head y tail
    cout << d1.front() << endl;
    cout << d1.back() << endl;

    // agregamos valores al final
    d1.push_back(10);
    d1.push_back(8);
    d1.push_back(11);

    d1.display();
    cout << "Size: " << d1.size() << endl;

    // imprimimos el valor del head y tail
    cout << d1.front() << endl;
    cout << d1.back() << endl;

    // imprimimos el elemento del head
    cout << d1.pop_front() << endl;

    d1.display();
    cout << "Size: " << d1.size() << endl;

    // imprimimos el elemento del tail
    cout << d1.pop_back() << endl;

    d1.display();
    cout << "Size: " << d1.size() << endl;

    // insertamos luego del primer valor
    d1.insert(21, 2);
    d1.display();

    // removemos el valor en la posición 2
    d1.remove(2);
    d1.display();

    // retornamos el elemento en la posición 3
    cout << d1[3] << endl;

    cout << "Vacio: " << d1.empty() << endl;

    // imprimimos de forma reversa el arreglo
    d1.reverse();

    // eliminamos
    d1.clear();

    // verificamos
    cout << "Vacio: " << d1.empty() << endl; // retorna 1, osea está vacio luego de ejecutar el método clear

    return 0;
}