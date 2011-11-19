/*
 * File:   Parser.h
 * Author: Rajib, Razzak
 *
 * Created on November 15, 2011, 7:20 AM
 */

#ifndef PARSER_H
#define	PARSER_H
#include <iostream>
#include <fstream>

#define SEPARATOR -1
#define END_LINE "_*_"
#define LOCATIONS 140
#define VERBS 50

using namespace std;

class Parser {
public:
    string fileData; 
    string locations[LOCATIONS] ; 
public:
    Parser(string file);
    ~Parser();
    void display();
    void parseLocations(string line, int first_number=0);
    void parseVerbs();
    
 private:
     int getFirstNumberOf(string line);
};

#endif	/* PARSER_H */

