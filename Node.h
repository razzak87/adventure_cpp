/*
 * File:   Location.h
 * Author: Rajib, Razzak
 *
 * Created on November 20, 2011, 8:42 AM
 */



#ifndef NODE_H
#define	NODE_H


#include <iostream>
#include <vector>
#include "Element.h"
using namespace std;


class Node{

public:
    string clue;
    string short_clue;
    int directions[10];
    int active_verbs[10][10];
    int count;
    int needed_item;
    vector<Element*> items;
    int id;

    Node(string clue);
    ~Node();


    void set_clue(string clue);
    void set_short_clue(string short_clue);

    string get_clue();

    void append(string);
};

#endif	/* LOCATION_H */
