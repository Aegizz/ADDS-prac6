#ifndef NODE_H
#define NODE_H

class Node{
    private:
        int data;
        Node* link;
    public:
        Node();
        Node(int num);
        Node(int num, Node* link);
        int getData();
        void setLink(Node* newLink);
        Node* getLink();
};
#endif
