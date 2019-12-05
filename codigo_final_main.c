/*
///////////////////////////////////////////////////////
* IFSC - Campus São José                             *
* Projeto Programação I  - Consumo Energético        *
* Desenvolvedores - Alana Beatriz Rostirolla Mandim  *
*                  - Daniel Pereira de Brito Filho   *
///////////////////////////////////////////////////////
*/

#include "funcoes.h"

int main() {

    int controle;

    controle =  fazerlogin();
    if(controle == 1) {
        taxad();
    }

}
