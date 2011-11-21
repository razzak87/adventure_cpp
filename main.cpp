#include "Parser.h"
#include <cstdlib>


int main() {
    cout << "Application starting " << std::endl;
    Parser p("advent.dat");
    
    for(int i=1; i < 141 ;i++)
        cout << p.locations[i] << endl;
    
    return EXIT_SUCCESS;
}

