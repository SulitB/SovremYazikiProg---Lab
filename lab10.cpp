#include "lab10list.h"
#include "lab10.h"
#include <iostream>

using namespace std;

// Функция вывода
void printList(const char* title, LinkedList<Bus>* list) {
    cout << title << endl;

    Node<Bus>* c = list->start;

    while (c != nullptr) {
        cout << "Bus number = " << c->data.number << ", driver = " << c->data.driver << ", route = " << c->data.route
            << endl;
        c = c->next;
    }
    cout << endl;
}

int main() {
    // Создайте два связанных списка, один для парка, другой для маршрута
    auto* park = new LinkedList<Bus>;
    auto* route = new LinkedList<Bus>;
    // Создайте экземпляры автобусов
    Bus bus1 = *new Bus(1, (char*)"driver1", 11);
    Bus bus2 = *new Bus(2, (char*)"driver2", 22);
    Bus bus3 = *new Bus(3, (char*)"driver3", 33);
    // Добавить автобусы в список парков
    park->first(1, bus1);
    park->add(2, bus2);
    park->add(3, bus3);
    // Вывод исходных списков
    printList("PARK", park);
    printList("ROUTE", route);
    // Удалить автобус 2 из парка и добавить его в маршрут
    Node<Bus>* removed2 = park->remove(2);
    route->add(2, removed2->data);
    printList("PARK (bus 2 removed)", park);
    printList("ROUTE (bus 2 added)", route);

    // Удалить автобус 2 с маршрута и добавить его обратно в парк
    Node<Bus>* fromRoute = route->remove(2);
    park->add(2, fromRoute->data);
    printList("PARK (bus 2 added back)", park);
    printList("ROUTE (bus 2 removed)", route);

    return 0;
}