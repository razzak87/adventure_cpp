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
#define LOCATIONS 141
#define VERBS 50
#define LONG_DESC_SECTION       1
#define SHORT_DESC_SECTION      2
#define TRAVEL_TABLE            3
#define VOCABULARY              4
#define ELEMENT_DESC            5
#define ELEMENT_LOCATION        6
#define ABBR_MSG                7
#define ACTIONS                 8
#define LIQUID_ASSET            9
#define CLASS_MSG               10
#define HINTS                   11
#define MAGIC_WORDS             12


#include <iostream>
#include <map>


using namespace std;



class Parser {
public:
    string fileData; 
    string locations[LOCATIONS] ; 
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

