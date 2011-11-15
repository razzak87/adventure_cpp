/* 
 * File:   Parser.h
 * Author: rajib
 *
 * Created on November 15, 2011, 7:20 AM
 */

#ifndef PARSER_H
#define	PARSER_H
#include <iostream>
#include <fstream>

using namespace std;

class Parser {

    string filename;

public:
    Parser(char* datafile);
    ~Parser();
    string getDataFileName();

private:

};

#endif	/* PARSER_H */

