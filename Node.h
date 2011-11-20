/* 
 * File:   Location.h
 * Author: Rajib, Razzak
 *
 * Created on November 20, 2011, 8:42 AM
 */

#include <iostream>
using namespace std;

#ifndef NODE_H
#define	NODE_H

class Node{
public:
    
    Node* east;
    Node* west;
    Node* south;
    Node* north;
    string clue;
    string short_clue;
    
public:
    Node();
    ~Node();
    void set_north(Node* north);
    void set_south(Node* south);
    void set_east(Node* east);
    void set_west(Node* west);
    
    Node* get_north();
    Node* get_south();
    Node* get_east();
    Node* get_west();
    
    void set_clue(string clue);
    void set_short_clue(string short_clue);
    void set_short_clue(string short_clue);
    
    
};

#endif	/* LOCATION_H */

