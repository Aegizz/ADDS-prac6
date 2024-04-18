#include "LinkedList.h"
#include <limits>
#include <iostream>
LinkedList::LinkedList(){
    head = nullptr;
}
LinkedList::LinkedList(int * array, int len){
    head = nullptr;
    for (int i = 0; i < len; i++){
        insertPosition(i+1, array[i]);
    }
}
LinkedList::~LinkedList(){
    Node * temp = head;
    Node * next;
    while (temp != nullptr){
        next = temp->getLink();
        delete temp;
        temp = next;
    }
}

void LinkedList::insertPosition(int pos, int num){
    Node * newNode = new Node(num);
    if (pos == 1 && head == nullptr){
        head = newNode;
    } else if (pos == 1 && head != nullptr){
        newNode->setLink(head);
        head = newNode;
    } else {
        Node * current = head;
        for (int i = 1; i < pos - 1 && current->getLink() != nullptr; i++){
            current = current->getLink();
        }
        newNode->setLink(current->getLink());
        current->setLink(newNode);
    }
}
bool LinkedList::deletePosition(int pos){
    if (pos <= 0 || head == nullptr){
        return false;
    }
    Node * current = head;
    if (pos == 1){
        head = head->getLink();
        delete current;
    } else {
        Node * previous = nullptr;
        for (int i = 1; i < pos && current != nullptr; i++){
            previous = current;
            current = current->getLink();
        }
        if (current == nullptr){
            return false;
        }
        previous->setLink(current->getLink());
        delete current;
    }
    return true;
}
int LinkedList::get(int pos){
    if (pos <= 0 || head == nullptr){
        return std::numeric_limits<int>::max();
    }
    Node * current = head;
    for (int i = 1; i < pos && current != nullptr; i++){
        current = current->getLink();
    }
    if (current == nullptr){
        return std::numeric_limits<int>::max();
    }
    return current->getData();
}
int LinkedList::search(int target){
    int pos = 1;
    Node * temp = head;
    while (temp != nullptr){
        if (temp->getData() == target){
            return pos;
        }
        temp = temp->getLink();
        pos++;
    }
    return -1;
}
void LinkedList::printList(){
    Node * curr = head;
    if (head != NULL){
        std::cout << "[";
        while (curr->getLink() != nullptr){
            std::cout << curr->getData() << " ";
            curr = curr->getLink();
        }
        std::cout << curr->getData() << "]" << std::endl;
    }

}


