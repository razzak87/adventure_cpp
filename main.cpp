#include <iostream>
#include "Parser.h"
#include "Player.h"
#include "Node.h"
#include <cstdlib>

using namespace std;


int main() {
    cout << "Application starting " << endl;
    Parser game("advent.dat");

    Player player("Rajib Ahmed", 0 , 1);
    
    for(;;){//game loop
        cout << game.locations[player.get_current_location()]->get_clue() << endl;
        getline(cin, player.answer);
        
        player.set_location(game.locations[player.get_current_location()]);
//        cout << p.locations[player.get_current_location()]->directions[1] << endl;
//        cout << p.locations[player.get_current_location()]->active_verbs[1][0] << endl;
//        cout << p.locations[player.get_current_location()]->active_verbs[1][1] << endl;
//        cout << p.locations[player.get_current_location()]->active_verbs[1][2] << endl;
        
        

        if(!player.answer.empty());
          player.go_to_next_location();
        break;
    }
    

    
    return EXIT_SUCCESS;
}

