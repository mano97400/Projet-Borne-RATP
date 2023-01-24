#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>


/*

    Gestion/Définition des modules

*/

typedef enum TPE{
    WAITING,AUTOR, SUCCESS, FAILURE
}TPE;

typedef struct Boutons{
    bool valide;
    bool stop;
    bool bouton_1;
    bool bouton_2;
} Boutons;

/*

    Controler's state

*/

typedef struct State{
    int phase;
    int step;
    int substep;
} State;

/*

    Controler's input

*/

typedef struct Input{

    TPE tpe;
    int key_board;
    Boutons boutons;
    bool ctr;
    int amount;
    State state;


}Input;

/*

    Controler's output

*/

typedef struct Output{

    int money_back;
    bool receip;
    bool ctr_transaction;
    State state;

}Output;


/*

    Controler's implementation

*/
Output controler(Input input){
    Output output;
    return output;
}

/*

    Initialization: à n'utiliser qu'une seul fois par lancement d'application pour ne pas surcharger la mémoire

*/

Boutons init_boutons(){
    Boutons boutons;
    boutons.valide=false;
    boutons.stop=false;
    boutons.bouton_1=false;
    boutons.bouton_2=false;
    return boutons;
}

State init_state(){
    State state;
    state.phase = 1;
    state.step = 1;
    state.substep = 0;
}

Input init_input(){
    Input input;
    input.amount = 0;
    input.boutons = init_boutons();
    input.ctr = false;
    input.key_board = -1;
    input.tpe = WAITING;
    input.state = init_state();
    return input;
}



void main(){

    Input input = init_input();
    Output output;

    output = controler(input);


}