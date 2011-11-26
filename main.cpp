#include <iostream>
#include "Parser.h"
#include "Player.h"
#include "Element.h"
#include "Node.h"
#include <cstdlib>
#include <cctype>

using namespace std;


int main() {
    cout << "Application starting " << endl;

    Parser game("advent.dat");

    Player player("Rajib Ahmed", 0 , 1);

    map<string, int>::iterator it;

    string words[3];



    for(;;){//game loop
        cout << game.locations[player.get_current_location()]->get_clue() << endl;
        player.set_location(game.locations[player.get_current_location()]);

        int numer_of_items = player.get_location()->items.size();

        if(numer_of_items > 0){
            for (int i = 0; i < numer_of_items; i++) {
                //not every item has messages on 0 index
                //this will throw segment fault
                cout << " ===> " << player.get_location()->items[i]->messages[0] << player.get_location()->items[i]->id << endl;
            }
        }

        getline(cin,player.verb);
        player.format_answer();


        game.start_idx=0;
        for(int i=0; i<3 ;i++){
            words[i] = game.tokenizer(player.verb," ");
        }

        !words[0].empty() ? player.verb = words[0] : "";
        !words[1].empty() ? player.noun = words[1] : "";

        if(!player.verb.empty() && !player.noun.empty()){
            //player wants to take Elements

        }else if(!player.verb.empty()){
            //player want to only move
            it = game.vocabulary.find(player.verb);
            if(it!=game.vocabulary.end()){
               player.moves = game.vocabulary.find(player.verb)->second;
               player.go_to_next_location();
            }else{
                cout << "dont understand that" << endl;
            }
        }
        //loop :) continues
    }

    return EXIT_SUCCESS;
}

