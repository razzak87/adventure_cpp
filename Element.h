/* 
 * File:   Element.h
 * Author: rajib
 *
 * Created on November 25, 2011, 12:52 AM
 */

#ifndef ELEMENT_H
#define	ELEMENT_H
#include <iostream>
using namespace std;

class Element {
public:
    string description;
    string messages[6];
    bool  moveable;
    Element(string desc);
    ~Element();
private:

};

#endif	/* ELEMENT_H */

