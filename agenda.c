#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char nome[100];
    char data[15];
    char hora[10];
    char desc[200];
    int ativo;
} Atend;

Atend ag[MAX];
int total = 0;

void cadastrar() {
    if (total >= MAX) { printf("Agenda cheia!\n"); return; }
    Atend a; a.ativo = 1;
    printf("Nome: "); getchar(); fgets(a.nome, 100, stdin);
    a.nome[strcspn(a.nome, "\n")] = 0;
    printf("Data: "); fgets(a.data, 15, stdin);
    a.data[strcspn(a.data, "\n")] = 0;
    printf("Hora: "); fgets(a.hora, 10, stdin);
    a.hora[strcspn(a.hora, "\n")] = 0;
    printf("Descricao: "); fgets(a.desc, 200, stdin);
    a.desc[strcspn(a.desc, "\n")] = 0;
    ag[total++] = a;
    printf("Cadastrado!\n");
}

void listar() {
    if (total == 0) { printf("Vazia.\n"); return; }
    printf("\n=== ATENDIMENTOS ===\n");
    for (int i = 0; i < total; i++) {
        if (ag[i].ativo) printf("%d. %s | %s %s\n   %s\n\n", 
            i+1, ag[i].nome, ag[i].data, ag[i].hora, ag[i].desc);
    }
}

void buscar() {
    char b[100]; int achou = 0;
    printf("Buscar nome: "); getchar(); fgets(b, 100, stdin);
    b[strcspn(b, "\n")] = 0;
    for (int i = 0; i < total; i++) {
        if (ag[i].ativo && strstr(ag[i].nome, b)) {
            printf("\nEncontrado:\n%s | %s %s\n%s\n",
                ag[i].nome, ag[i].data, ag[i].hora, ag[i].desc);
            achou = 1;
        }
    }
    if (!achou) printf("Nao encontrado.\n");
}

int main() {
    int op;
    printf("\n1-Cadastrar  2-Listar  3-Buscar  0-Sair\nEscolha: ");
    op = getchar() - '0';
    while(op != 0) {
        while(getchar() != '\n');
        switch(op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: buscar(); break;
            default: printf("Invalido!\n");
        }
        printf("\n1-Cadastrar  2-Listar  3-Buscar  0-Sair\nEscolha: ");
        op = getchar() - '0';
    }
    printf("Saindo...\n");
    return 0;
}