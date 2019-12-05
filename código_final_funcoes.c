#include "funcoes.h"

struct cadastro_usuario dados[MAX_USER] = {
        {"Alana", "alana123", "2255"},
        {"Chicao", "chico123", "2266"},
        {"Daniel", "daniel", "1234"}
};

float taxa;

void taxad() {
    while (taxa == 0) {
        printf("Informe o valor da tarifa do Kwh de sua cidade:");
        scanf("%f", &taxa);
    }
    menuzin();
}

int verificadados(char *us, char *pas) { /* retorno da funçao se o usuário for incorreto é 1*/

    for (int i = 0; i < MAX_USER; i++) {
        if (strcmp(us, dados[i].usuario) == 0 && strcmp(pas, dados[i].senha) == 0) {
            return 0;
        }
    }
    return 1;
}

int fazerlogin() { //Função onde o usuário realiza o login.
    //nome, usuario, senha, salario
    int i, j, opcao;

    do {
        printf("Bem vindo\n");

        printf("\n1. Fazer login");
        printf("\n0. Sair");
        scanf("%d", &opcao);


        if (opcao == 1) {
            printf("Bem vindo\n");

            printf("\nDigite seu usuário: ");
            scanf(" %s", usuario);
            getchar();

            printf("\nDigite a sua senha (4 digitos): ");
            scanf("%s", senha);
            getchar();

            i = verificadados(usuario, senha);

            if (i != 0) {
                printf("\nUsuário ou senha Incorreto! \nTente fazer login novamente...\n");
            }
        }
    } while (i != 0);

    if (i == 0) {
        taxad();
    }
}


float somaConsumo(int aux) {
    float soma = 0;
    for (int i = 0; i < MAX_AMB; i++) {
        soma = soma + (ambientes[aux].equipamentosambientes[i].uso * ambientes[aux].equipamentosambientes[i].tempo);
    }
    return soma;
}

void adicionarAmbiente() {
    char nome[20];
    int x;
    for (int i = 0; i < MAX_AMB; i++) {
        if (ambientes[i].id == 0) {
            ambientes[i].id = i + 1;
            printf("Insira o nome do ambiente:\n ");
            scanf(" %[^\n]s", nome);
            strcpy(ambientes[i].nome, nome);
            printf("Deseja adicionar mais ambientes?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            printf("-> ");
            scanf("%d", &x);
            if (x == 2)
                i = MAX_AMB;
        }
    }
}

int slotEquipVazio(int aux) {
    int i = 0;
    while (ambientes[aux].equipamentosambientes[i].id != 0) {
        i++;
    }
    return i;
}

void excluirEquipamento(int pos) {
    int idEquip;
    int i = 0;
    int x = 1;
    do {
        for (int i = 0; i < MAX_EQUIP; i++) {
            if (equipamentos[i].id == 0) {
                continue;
            } else {
                printf("%d - %s   Pot. Uso %f \n", equipamentos[i].id, equipamentos[i].nome, equipamentos[i].uso);
            }
        }
        printf("0 - Voltar:\n ");
        printf("Informe o id que deseja excluir:\n ");
        scanf("%d", &idEquip);
        for (int i = 0; ambientes[pos].equipamentosambientes[i].id == idEquip; i++) {
        }
        ambientes[pos].equipamentosambientes[i].id = 0;
        if (idEquip == 0) {
            break;
        }


    } while (idEquip != 0);
}


void adicionarEquipamento(int aux) {

    int x = 1;
    int escolha, count = 0;
    while (x) {
        for (int i = 0; i < MAX_EQUIP; i++) {
            if (equipamentos[i].id == 0) {
                continue;
            } else {
                printf("%d - %s   Pot. Uso %f \n", equipamentos[i].id, equipamentos[i].nome, equipamentos[i].uso);
                count++;
            }
        }

        printf("Digite o id do equipamento que deseja adicionar no ambiente  \n");
        printf("0 - Voltar\n");
        scanf("%d", &escolha);
        if (escolha == 0) {
            break;
        } else if (escolha > 0 && escolha <= count) {
            int posEquip = slotEquipVazio(aux);
            ambientes[aux].equipamentosambientes[posEquip] = equipamentos[escolha - 1];
            printf("Tempo de uso em horas: ");
            scanf("%f", &ambientes[aux].equipamentosambientes[posEquip].tempo);
        } else {
            printf("Opção invalida!\n");
        }
    }
}

void removerAmbiente() {
    int escolha;

    while (1) {
        int count = 0;
        for (int i = 0; ambientes[i].id != 0; i++) {
            printf("%d - %s\n", ambientes[i].id, ambientes[i].nome);
            count++;
        }
        printf("0 - Voltar\n");
        printf("Digite o id do ambiente que deseja remover: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        } else if (escolha > 0 && escolha <= count) {
            ambientes[escolha].id = 0;
        } else {
            printf("Opção invalida!\n");
        }
    }
}

void printaAmbiente(int aux) {
    int escolha;
    char altnome[20];
    int pos = aux - 1;
    int x = 1;
    while (x) {
        printf("Nome: %s\n", ambientes[pos].nome);
        printf("Consumo: %.3f\n", somaConsumo(pos));
        printf("1 - Alterar o nome\n");
        printf("2 - Adicionar equipamento\n");
        printf("3 - Excluir equipamento\n");
        printf("4 - Voltar\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Insira o novo nome: ");
                scanf(" %[^\n]s", altnome);
                strcpy(ambientes[pos].nome, altnome);
                break;
            case 2:
                adicionarEquipamento(pos);
                break;
            case 3:
                excluirEquipamento(pos);
                break;
            case 4:
                x = 0;
                break;
            default:
                printf("Opção Inválida\n");
                break;

        }

    }
}

void editarAmbiente() {
    int escolha;

    while (1) {
        int count = 0;
        for (int i = 0; ambientes[i].id != 0; i++) {
            printf("%d - %s\n", ambientes[i].id, ambientes[i].nome);
            count++;
        }
        printf("0 - Voltar\n");
        printf("Digite o id do ambiente que deseja editar: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        } else if (escolha > 0 && escolha <= count) {
            printaAmbiente(escolha);
        } else {
            printf("Opção invalida!");
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
                editarAmbiente();
                break;
            case 3:
                removerAmbiente();
                break;
            case 4:
                x = 0;
                break;
            default:
                printf("Escolha não existe");
                break;
        }
    }
}

void printaEquip() {
    for (int i = 0; i < MAX_EQUIP; i++) {
        if (equipamentos[i].id == 0)
            continue;
        printf("%d - %s Pot. consumo: %.3f \n", equipamentos[i].id, equipamentos[i].nome, equipamentos[i].uso);
    }
}

void printaEquipamentos(int aux) {
    int escolha;
    char altnome[20];
    int pos = aux - 1;
    int x = 1;
    while (x) {
        printf("Nome: %s\n", equipamentos[pos].nome);
        printf("1 - Alterar o nome\n");
        printf("2 - Alterar Potência de Uso\n");
        printf("3 - Voltar\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Insira o novo nome: ");
                scanf(" %[^\n]s", altnome);
                strcpy(equipamentos[pos].nome, altnome);
                break;

            case 2:
                printf("Insira a nova potência de uso");
                scanf("%f", &equipamentos[pos].uso);
                break;

            case 3:
                x = 0;
                break;
            default:
                printf("Opção Inválida");
                break;

        }

    }
}

void criarEquip() {
    char nome[20];
    int x;

    for (int i = 0; i < MAX_EQUIP; i++) {
        if (equipamentos[i].id == 0) {
            equipamentos[i].id = i + 1;
            printf("Insira o nome do equipamento: ");
            scanf(" %[^\n]s", nome);
            strcpy(equipamentos[i].nome, nome);
            printf("Informe a Potência (khw) do Aparelho em uso:");
            scanf("%f", &equipamentos[i].uso);
            printf("Deseja adicionar mais equipamentos?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            printf("-> ");
            scanf("%d", &x);
            if (x == 2)
                i = MAX_EQUIP;
        }
    }
}

void removeEquipamento(int aux) {
    int pos = aux - 1;
    char nome[20];
    strcpy(equipamentos[pos].nome, nome);
    equipamentos[pos].uso = 0;

}

void excluirEquip() {
    int escolha;

    while (1) {
        int count = 0;
        for (int i = 0; equipamentos[i].id != 0; i++) {
            printf("%d - %s\n", equipamentos[i].id, equipamentos[i].nome);
            count++;
        }
        printf("0 - Voltar\n");
        printf("Digite o id do equipamentos que deseja remover: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        } else if (escolha > 0 && escolha <= count) {
            removeEquipamento(escolha);
        } else {
            printf("Opção invalida!");
        }
    }

}

void editarEquip() {
    while (1) {
        int escolha;
        int count = 0;
        for (int i = 0; i < MAX_EQUIP; i++) {
            if (equipamentos[i].id == 0)
                continue;
            printf("%d - %s Pot. consumo: %f \n", equipamentos[i].id, equipamentos[i].nome,
                   equipamentos[i].uso);
            count++;
        }

        printf("0 - Voltar\n");
        printf("Digite o id do equipamento que deseja editar: \n");
        scanf("%d", &escolha);

        if (escolha == 0) {
            break;
        } else if (escolha > 0 && escolha <= count) {
            printaEquipamentos(escolha);
        } else {

            printf("Opção invalida!");

        }

    }
}


void menuEquipamentos() {
    int x = 1;
    while (x) {
        int escolha;
        printaEquip();
        printf("1 - Criar\n");
        printf("2 - Excluir\n");
        printf("3 - Editar\n");
        printf("0 - Voltar\n");
        printf("-> ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                criarEquip();
                break;
            case 2:
                excluirEquip();
                break;
            case 3:
                editarEquip();
                break;
            case 0:
                x = 0;
                break;
            default:
                printf("Opção Invalida!");
                break;
        }
    }
}

void menuzin() {
    int menu;
    int x = 1;
    while (x) {
        printf("1 - Ambientes\n");
        printf("2 - Equipamentos\n");
        printf("3 - Sair");
        printf("\nEscolha a opção desejada\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                menuAmbientes();
                break;
            case 2:
                menuEquipamentos();
                break;
            case 3:
                printf("Saindo");
                x = 0;
                break;
            default:
                printf("Opção Inválida\n");
                break;
        }
    }
}
