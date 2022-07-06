#include "List.h"

namespace list
{
    Head* createList()
    {
        Head* head = new Head();
        head->first = nullptr;

        return head;
    }

    void addElement(Head* head, Item* itemPtr)
    {
        Item* ptr = head->first;

        if (ptr == nullptr)
        {
            head->first = itemPtr;
            itemPtr->next = nullptr;
            itemPtr->prev = nullptr;

            return;
        }

        if (ptr->userObject.lastName > itemPtr->userObject.lastName)
        {
            ptr->prev = itemPtr;
            itemPtr->next = ptr;
            itemPtr->prev = nullptr;
            head->first = itemPtr;

            return;
        }

        ptr = ptr->next;

        Item* prevPtr = head->first;

        while (ptr!= nullptr)
        {
            if (ptr->userObject.lastName == itemPtr->userObject.lastName)
            {
                ptr->next = itemPtr;
                itemPtr->prev = ptr;
                itemPtr->next = ptr->next;
                if (ptr->next != nullptr)
                    ptr->next->prev = itemPtr;

                return;
            }

            if (ptr->userObject.lastName > itemPtr->userObject.lastName)
            {
                prevPtr->next = itemPtr;
                itemPtr->next = ptr;
                itemPtr->prev = prevPtr;
                ptr->prev = itemPtr;

                return;
            }

            prevPtr = ptr;
            ptr = ptr->next;
        }

        prevPtr->next = itemPtr;
        itemPtr->prev = prevPtr;
        itemPtr->next = nullptr;
    }

    void deleteList(Head* head)
    {
        Item* itemPtr = head->first;
        Item* current;

        while (itemPtr != nullptr)
        {
            current = itemPtr;
            itemPtr = itemPtr->next;
            delete current;
        }

        delete head;

        std::cout << "List was deleted.";
    }

    void printList(Head* head)
    {
        Item* current = head->first;

        std::cout << "\n";
        while (current != nullptr)
        {
            std::cout << "Name: " << current->userObject.name << ". Last Name: " << current->userObject.lastName << std::endl;
            current = current->next;
        }
    }

    Item* searchElement(Head* head, const std::string search)
    {
        Item* ptr = head->first;

        while (ptr != nullptr)
        {
            if (ptr->userObject.name == search || ptr->userObject.lastName == search) return ptr;

            ptr = ptr->next;
        }

        return nullptr;
    }

    void deleteElement(Head* head, Item* itemPtr)
    {
        if (itemPtr == nullptr)
        {
            std::cout << "\nThe Item is empty." << std::endl;

            return;
        }

        std::cout << "\nItem " << itemPtr->userObject.name << " " << itemPtr->userObject.lastName << " was deleted." << std::endl;

        if (itemPtr == head->first)
        {
            head->first = itemPtr->next;
            itemPtr->next->prev = nullptr;
            delete itemPtr;

            return;
        }

        Item* ptr = head->first->next;
        Item* prevPtr = head->first;

        while (ptr != nullptr)
        {
            if (ptr == itemPtr)
            {
                prevPtr->next = ptr->next;
                if (ptr->next != nullptr) ptr->next->prev = prevPtr;
                delete itemPtr;

                return;
            }

            prevPtr = ptr;
            ptr = ptr->next;
        }

    }
}
