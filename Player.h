/* 
 * File:   Player.h
 * Author: rajib , razzak
 *
 * Created on November 21, 2011, 1:57 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H
#include <iostream>
#include "Node.h"
using namespace std;

class Player {
    
public:
    int max_items;
    string answer;
    int moves;

private:
    string name;
    int score;
    int current_location_idx;
    Node* location;
    int current_item;
    
public:
    Player(string name,int score, int location);
    
    ~Player();
    
    void set_current_location(int location);
    int  get_current_location();
    
    int  get_score();
    void set_score(int score);
    
    Node* get_location();
    void set_location(Node* loc);
    
    void set_item(int item);
    int get_item();
    string get_input();
    
    string format_answer();
    void go_to_next_location();
    
    string get_info();

private:
    
};
        
#endif	/* PLAYER_H */

