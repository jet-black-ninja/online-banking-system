
#include <iostream>
#include <cstdlib>
#include "headers/utility.h"
using namespace std;

int main(int argc, char* argv[]){
    while(1){
        Controller::showBanner();
        Controller::showMenu();
    }
    return EXIT_SUCCESS;
}