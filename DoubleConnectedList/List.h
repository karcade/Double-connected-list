#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

namespace list
{
    struct Item;

       struct Head
       {
           Item* first = nullptr;
       };

       struct User
       {
           std::string name;
           std::string lastName;
       };

       struct Item
       {
           Item* next = nullptr;
           Item* prev = nullptr;
           User userObject;
       };

       Head* createList();

       void addElement(Head* head, Item* itemPtr);

       Item* searchElement(Head* head, std::string search);

       void deleteList(Head* head);

       void printList(Head* head);

       void deleteElement(Head* head, Item* itemPtr);
};

#endif // LIST_H
