/*
 * File:   Parser.h
 * Author: Rajib, Razzak
 *
 * Created on November 15, 2011, 7:20 AM
 */

#ifndef PARSER_H
#define	PARSER_H

#define SEPARATOR -1
#define END_LINE "_*_"
#define LOCATIONS 142
#define VERBS 50


#define LONG_DESC_SECTION       0
#define SHORT_DESC_SECTION      1
#define TRAVEL_TABLE            2
#define VOCABULARY              3
#define ELEMENT_DESC            4
#define ELEMENT_LOCATION        5
#define ABBR_MSG                6
#define ACTIONS                 7
#define LIQUID_ASSET            8
#define CLASS_MSG               9
#define HINTS                   10
#define MAGIC_WORDS             11


#include <iostream>
#include <map>
#include "Node.h"


using namespace std;



class Parser {
public:
    string fileData;
    Node* locations[LOCATIONS] ;
    map <string, int> vocabulary;

public:
    Parser(string file);
    ~Parser();
    void parse_locations(string line, int first_number=0);
    void parse_vocabulary(string line);
    bool is_object(string key);
    bool is_special(string key);
    bool is_motion(string key);
    bool is_action(string key);

 private:
     int getFirstNumberOf(string line);
};

#endif	/* PARSER_H */
