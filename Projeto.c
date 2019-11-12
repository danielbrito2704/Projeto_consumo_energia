#include <stdio.h>
#define MAX_EQUIP 20



struct TEquipamentos {
    int id;
    char nome[20];
    float potencia,corrente,tensao,tempo,consumo;
}equipamentos[MAX_EQUIP];

struct TSala {
    int id;
    char nome[20];
    struct TEquipamentos equipamentosSala[MAX_EQUIP];
    float consumo;
}salas[20];

int main() {

    equipamentos[0].id=1;
   // equipamentos[0].nome[20]="cafeteira";
    equipamentos[0].consumo=152;


    printf("nome %f",equipamentos[0].consumo);
    return 0;


}
