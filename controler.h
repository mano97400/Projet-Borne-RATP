#ifndef CONTROLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/*

    Gestion/Définition des modules

*/

typedef enum TPE{
    SUCCESS, FAILURE, WAITING
}TPE;

typedef struct Boutons{
    bool but_val;
    bool but_ann;
    bool but_1;
    bool but_2;
} Boutons;

/*

    Controler's state

*/

typedef struct State{

    int phase;
    int etape;
    int montant_tot;

}State;

/*

    Controler's input

*/

typedef struct Input{

    TPE tpe;
    int kbd_num;
    Boutons boutons;
    bool ctr_sup;
    int esp_in;
    State state;


}Input;

/*

    Controler's output

*/

typedef struct Output{

    int esp_out;
    bool recu;
    bool ctr_rch;
    State state;

}Output;

#endif