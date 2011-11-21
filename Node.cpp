#include "Node.h"


Node::Node(string clue){
    this->clue = clue;
}

Node::~Node(){}

void Node::set_north(Node* north){

};
void Node::set_south(Node* south){

}
void Node::set_east(Node* east){

}
void Node::set_west(Node* west){

}

Node* Node::get_north(){
    return this->north;

}
Node* Node::get_south(){
    return this->south;
}
Node* Node::get_east(){
    return this->east;
}

Node* Node::get_west(){
    return this->west;
}

void Node::set_clue(string clue){
    this->clue = clue;
}

void set_short_clue(string short_clue){
}

void Node::append(string txt){
    this->clue = this->clue + txt;
} 

string Node::get_clue(){
    return this->clue;
}