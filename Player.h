/* 
 * File:   Player.h
 * Author: rajib , razzak
 *
 * Created on November 21, 2011, 1:57 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H
#include <iostream>

using namespace std;

class Player {
public:
    int max_items;
    string name;
    int score;
    int current_location;
    int current_item;
    int moves;
    
public:
    Player();
    ~Player();
//    void set_current_location(int location);
//    int  get_current_location();
//    
//    int  get_score();
//    void set_score(int score );
//    
//    void set_item(int item);
//    int get_item();
//    
//    string get_info();

};

#endif	/* PLAYER_H */

