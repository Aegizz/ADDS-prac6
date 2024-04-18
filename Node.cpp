#include "Node.h"

Node::Node(){
    data = 0;
    link = nullptr;
}
Node::Node(int num){
    data = num;
    link = nullptr;
}
Node::Node(int num, Node* newLink){
    data = num;
    link = newLink;
    
}
int Node::getData(){
    return data;
}
void Node::setLink(Node* newLink){
    link = newLink;
}
Node* Node::getLink(){
    return link;
}