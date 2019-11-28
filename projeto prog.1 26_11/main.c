#include <stdio.h>
#include <string.h>

#define MAX_EQUIP 60
#define MAX_AMB 20

float taxa = 0.3;
struct TEquipamentos {
    char nome[20];
    float cons_uso, cons_stand; /* Potência em uso e stand-by */
} equipamentos[MAX_EQUIP];

struct TAmbientes {
    int id;
    char nome[20];
    struct TEquipamentos equipamentosambientes[MAX_EQUIP];
    float consumo;
    float uso[MAX_EQUIP], stand[MAX_EQUIP]; /* Horas em uso e horas em stand-by*/
} ambientes[MAX_AMB];

void cal_kwh_ambientes() {
    for (int i = 0; i < MAX_AMB; i++) /* Aqui é feito o cálculo do consumo total diário em Kwh de cada ambiente  */ {
        for (int j = 0; j < MAX_AMB; j++) {
            ambientes[i].consumo = (ambientes[i].equipamentosambientes[j].cons_uso * ambientes[i].uso[j]) +
                                   (ambientes[i].equipamentosambientes[j].cons_stand * ambientes[i].stand[j]);

        }
    }
}

float somaTotalConsumo() {
    float soma = 0;
    for (int i = 0; i < MAX_AMB; i++) {
        soma = soma + ambientes[i].consumo;
    }
    return soma;
}


void consumo() {
    printf("Diário\n");
    printf("KWh: %.3f", somaTotalConsumo());
    printf("R$: %.2f", somaTotalConsumo() * taxa);
    printf("Semanal\n");
    printf("KWh: %.3f", somaTotalConsumo() * 7);
    printf("R$: %.2f", somaTotalConsumo() * taxa * 7);
    printf("Mensal\n");
    printf("KWh: %.3f", somaTotalConsumo() * 30);
    printf("R$: %.2f", somaTotalConsumo() * taxa * 30);
}

void acessaAmbiente(int aux) {
    for (int i = 0; i < MAX_EQUIP; i++) {
        ambientes[aux].equipamentosambientes[i].nome;
    }
}

void adicionarAmbiente() {  //loop infinito
    char nome[20];
    int x;
    for (int i = 0; i < MAX_AMB; i++) {
        if (ambientes[i].id == 0) {
            ambientes[i].id = i + 1;
            printf("Insira o nome do ambiente: ");
            scanf(" %[^\n]s", nome);
            strcpy(ambientes[i].nome, nome);
            printf("Insira quantas horas a sala fica ativa:");
            scanf("%f", &ambientes[i].uso);
            printf("Insira quantas horas a sala fica inativa:");
            scanf("%f", &ambientes[i].stand);
            printf("Deseja adicionar mais ambientes?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            printf("->");
            scanf("%d",&x);
            if (x == 2)
                i = MAX_AMB;
        }
    }
}

void menuAmbientes() {
    int x = 1;
    while (x) {
        int escolha;
        printf("1 - Adicionar\n");
        printf("2 - Editar\n");
        printf("3 - Excluir\n");
        printf("4 - Voltar\n");
        printf("Escolha uma das opções acima: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                adicionarAmbiente();
                break;
            case 2:
                //editarAmbiente();
                break;
            case 3:
                //1  removerAmbiente();
                break;
            case 4:
                x=0;
                break;
            default:
                printf("Escolha não existe");
                break;
        }
    }
}


int main() {
    cal_kwh_ambientes();
    int menu, periodo, opc_cons;
    while (taxa == 0) {
        printf("Informe o valor da tarifa do Kwh de sua cidade");
        scanf("%f", &taxa);
    }

    int x = 1;
    while (x) {
        printf("1 - Consumo Total\n");
        printf("2 - Ambientes\n");
        printf("3 - Equipamentos\n");
        printf("4 - Sair");
        printf("\nEscolha a opção desejada\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                consumo();
                break;
            case 2:
                menuAmbientes();
                break;
            case 3:
                printf("Adicionar equipamentos\n");
                break;
            case 4:
                printf("Saindo");
                x = 0;
                break;
            default:
                printf("Opção Inválida\n");
                break;
        }

        //printf("Semanal %.2fR$", (ambientes[0].consumo) * 7);

    }
}
