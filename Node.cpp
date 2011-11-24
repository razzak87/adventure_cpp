#include "Node.h"


Node::Node(string clue_word){
    clue = clue_word;
}

Node::~Node(){}

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