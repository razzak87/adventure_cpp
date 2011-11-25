#include <iostream>
#include "Parser.h"
#include "Player.h"
#include "Node.h"
#include <cstdlib>
#include <cctype>

using namespace std;


int main() {
    cout << "Application starting " << endl;
    Parser game("advent.dat");

    Player player("Rajib Ahmed", 0 , 3);
    
    map<string, int>::iterator it;
    
    //cout << game.elements[2]->description <<endl;
    cout << game.elements[2]->messages[0] <<endl;
    cout << game.elements[2]->messages[1] <<endl;
    //cout << game.elements[2]->messages[2] <<endl;
    
//    for(;;){//game loop
//        cout << game.locations[player.get_current_location()]->get_clue() << endl;
//        getline(cin, player.answer);
//        player.format_answer();
//
//        player.set_location(game.locations[player.get_current_location()]);
//        
//
//        if(!player.answer.empty()){
//            it = game.vocabulary.find(player.answer);
//            if(it!=game.vocabulary.end()){
//               player.moves = game.vocabulary.find(player.answer)->second;
//               player.go_to_next_location();
//            }else{
//                cout << "dont understand that" << endl;
//            }
//        } 
//        //break;
//    }
    

    
    
    
    return EXIT_SUCCESS;
}

