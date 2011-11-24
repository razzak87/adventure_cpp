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
#define ELEMENT_LOCATION        6
#define ABBR_MSG                5
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
    size_t start_idx;
    size_t end_idx;
    unsigned int incrementor;

public:
    Parser(string file);
    ~Parser();
    void parse_locations(string &line, int first_number=0);
    void parse_vocabulary(string &line);
    void parse_travel_table(string &line, int first_number=0);
    void parse_element_desc(string &line);
    void parse_element_location(string &line);
    void parse_actions(string &line);
    void parse_player_classification(string &line);
    void parse_abbr_msg(string &line);
    

    bool is_object(string key);
    bool is_special(string key);
    bool is_motion(string key);
    bool is_action(string key);
    string tokenizer(string &line);
    int prop_vlaue(int m);
 private:
     //sting
     
     int getFirstNumberOf(string &line);
};

#endif	/* PARSER_H */
