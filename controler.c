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

    Controler's input

*/

typedef struct Input{

    TPE tpe;
    int key_board;
    Boutons boutons;
    bool ctr;
    int amount;


}Input;

/*

    Controler's output

*/

typedef struct Output{

    int money_back;
    bool receip;
    bool ctr_transaction;

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

Input init_input(){
    Input input;
    input.amount = 0;
    input.boutons = init_boutons();
    input.ctr = false;
    input.key_board = -1;
    input.tpe = WAITING;
    return input;
    
}



void main(){

    Input input = init_input();
    Output output;

    output = controler(input);


}