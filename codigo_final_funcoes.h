#ifndef UNTITLED_FUNCOES_H
#define UNTITLED_FUNCOES_H

#include <stdio.h>
#include <string.h>

#define MAX_EQUIP 60
#define MAX_AMB 20
#define MAX_USER 3

struct cadastro_usuario {
    char nome[50];
    char usuario[20];
    char senha[10];
}dados[MAX_USER];

//struct cadastro_usuario dados[MAX_USER] = {
//       {"Alana", "alana123", "2255"},
//       {"Chicao", "chico123", "2266"},
//        {"Daniel", "daniel", "1234"}
//};

char usuario[20];
char senha[10];


struct TEquipamentos {
    int id;
    char nome[20];
    float uso,tempo;
} equipamentos[MAX_EQUIP];

struct TAmbientes {
    int id;
    char nome[20];
    struct TEquipamentos equipamentosambientes[MAX_EQUIP];

} ambientes[MAX_AMB];

float somaConsumo(int aux);
void adicionarAmbiente();
int slotEquipVazio(int aux);
void excluirEquipamento(int pos);
void adicionarEquipamento(int aux);
void removerAmbiente();
void printaAmbiente(int aux);
void editarAmbiente();
void menuAmbientes();
void printaEquip();
void printaEquipamentos(int aux);
void criarEquip();
void removeEquipamento(int aux);
void excluirEquip();
void editarEquip();
void menuEquipamentos();
void menuzin();
int fazerlogin();
int verificadados(char *us, char *pas);
void taxad();

#endif //UNTITLED_FUNCOES_H
