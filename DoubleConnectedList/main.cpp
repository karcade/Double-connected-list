#include <iostream>
#include "List.h"

int main()
{
    list::Head* head = list::createList();

        list::Item* itemT = list::searchElement(head, "Vasiliy");
        if (itemT != nullptr) std::cout << itemT->userObject.name << " " << itemT->userObject.lastName << " was found.";
        else std::cout << "Vasiliy wasn't found.";

        list::Item* item = new list::Item();
        item->userObject.name = "Ivan";
        item->userObject.lastName = "Bivanov";

        list::Item* item2 = new list::Item();
        item2->userObject.name = "Vasiliy";
        item2->userObject.lastName = "Astrov";

        list::Item* item3 = new list::Item();
        item3->userObject.name = "Petya";
        item3->userObject.lastName = "Ersh";

        list::Item* item4 = new list::Item();
        item4->userObject.name = "Helen";
        item4->userObject.lastName = "Costrovskih";

        list::addElement(head, item);
        list::addElement(head, item2);
        list::addElement(head, item3);
        list::addElement(head, item4);

        list::printList(head);

        list::Item* itemX = list::searchElement(head, "Vasiliy");
        if (itemX != nullptr) std::cout << itemX ->userObject.name<<" " << itemX->userObject.lastName << " was found.";
        else std::cout << "Vasiliy wasn't found.";

        list::Item* itemY = list::searchElement(head, "Kristofer");
        if (itemY != nullptr) std::cout << itemY->userObject.name << " " << itemY->userObject.lastName << " was found.";
        else std::cout << "Kristofer wasn't found.";

        list::deleteElement(head, item3);
        list::printList(head);

        list::deleteList(head);

    return 0;
}
