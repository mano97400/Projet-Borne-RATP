#include "controler.h"




/*

    Controler's implementation

*/

Output controler_phase1(Input input) {
    Output output = init_output();
    output.state = input.state;
    switch (input.state.etape) {
        case 1 : 
            if (input.ctr_sup) {
                output.state.phase = 2;
                output.state.etape = 1;
                output.state.montant_tot = input.state.montant_tot;
            }
            break;
    }
    return output;
}

Output controler_phase2(Input input) {
    Output output = init_output();
    switch (input.state.etape) {
        case 1 : 
            if (input.boutons.but_ann) {
                output.state.phase = 4;
                output.state.etape = 1;
            }
            else if (input.boutons.but_1) {
                output.state.etape = 2;
            }
            else if (input.boutons.but_2) {
                output.state.etape = 3;
            }
            break;
        case 2 :
            if (input.boutons.but_ann) {
                output.state.etape = 1;
            }
            else if (input.kbd_num > 0 && input.boutons.but_val) {
                output.state.phase = 3;
                output.state.etape = 1;
                output.state.montant_tot = input.kbd_num;
            }
            break;
        case 3 : 
            if (input.boutons.but_ann) {
                output.state.etape = 1;
            }
            else if (input.boutons.but_1) {
                output.state.phase = 3;
                output.state.etape = 1;
                output.state.montant_tot = MONTANT_SUB_1;
            }
            else if (input.boutons.but_2) {
                output.state.phase = 3;
                output.state.etape = 1;
                output.state.montant_tot = MONTANT_SUB_2;
            }
            break;
    }
    return output;
}

Output controler(Input input){
    Output output;
    switch (input.state.phase) {
        case 1 : 
            output = controler_phase1(input); 
            break;
        case 2 : 
            output = controler_phase2(input); 
            break;
    }
    return output;
}

/*

    Initialization: à n'utiliser qu'une seul fois par lancement d'application pour ne pas surcharger la mémoire

*/

Boutons init_boutons(){
    Boutons boutons;
    boutons.but_val=false;
    boutons.but_ann=false;
    boutons.but_1=false;
    boutons.but_2=false;
    return boutons;
}

State init_state(){
    State state;
    state.phase = 1;
    state.etape = 1;
    state.montant_tot = 0;
    return state;
}

Input init_input(){
    Input input;
    input.tpe = WAITING;
    input.kbd_num = 0;
    input.boutons = init_boutons();
    input.ctr_sup = false;
    input.esp_in = 0;
    input.state = init_state();
    return input;
}

Output init_output(){
    Output output;
    output.esp_out = 0;
    output.recu = false;
    output.ctr_rch = false;
    return output;
}



void main(){

    Input input = init_input();
    Output output;

    output = controler(input);


}