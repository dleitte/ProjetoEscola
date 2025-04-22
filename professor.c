#include <stdio.h>
#include <string.h>
#include "professor.h"
#include "utils.h"
#include "aluno.h"

void incluirProfessor(Professor profs[], int* qtd) {
    if (*qtd >= TAM_PROFESSOR) {
        printf("Limite de professores atingido.\n");
        return;
    }

    Professor novo;
    int i;

    printf("\n--- Incluir Professor ---\n");
    printf("Nome: ");
    getchar(); 
    fgets(novo.nome, 100, stdin);
    for (i = 0; novo.nome[i] != '\0'; i++) {
        if (novo.nome[i] == '\n') novo.nome[i] = '\0';
    }

    printf("Matrícula: ");
    scanf("%d", &novo.matricula);
    printf("Sexo (M/F/Masculino/Feminino): ");
    scanf("%s", novo.sexo);
    if (!validarSexo(novo.sexo)) return;

    printf("Data nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &novo.dia, &novo.mes, &novo.ano);
    if (!validarData(novo.dia, novo.mes, novo.ano)) return;

    printf("CPF: ");
    scanf("%s", novo.cpf);
    if (!validarCPF(novo.cpf)) {
        printf("CPF inválido.\n");
        return;
    }

    for (i = 0; i < *qtd; i++) {
        if (strcmp(profs[i].cpf, novo.cpf) == 0) {
            printf("CPF já cadastrado para outro professor.\n");
            return;
        }
    }

    profs[*qtd] = novo;
    (*qtd)++;
    printf("Professor cadastrado com sucesso!\n");
}

void listarProfessores(Professor profs[], int qtd) {
    int i;
    printf("\n--- Lista de Professores ---\n");
    for (i = 0; i < qtd; i++) {
        printf("\nNome: %s\n", profs[i].nome);
        printf("Matrícula: %d\n", profs[i].matricula);
        printf("Sexo: %s\n", profs[i].sexo);
        printf("Nascimento: %02d/%02d/%d\n", profs[i].dia, profs[i].mes, profs[i].ano);
        printf("CPF: %s\n", profs[i].cpf);
    }
}

void atualizarProfessor(Professor profs[], int qtd) {
    int mat, i;
    printf("Digite matrícula para atualizar: ");
    scanf("%d", &mat);
    for (i = 0; i < qtd; i++) {
        if (profs[i].matricula == mat) {
            printf("Novo nome: ");
            getchar();
            fgets(profs[i].nome, 100, stdin);
            for (int j = 0; profs[i].nome[j] != '\0'; j++) {
                if (profs[i].nome[j] == '\n') profs[i].nome[j] = '\0';
            }
            printf("Novo sexo: ");
            scanf("%s", profs[i].sexo);
            printf("Nova data nascimento (dd mm aaaa): ");
            scanf("%d %d %d", &profs[i].dia, &profs[i].mes, &profs[i].ano);
            printf("Novo CPF: ");
            scanf("%s", profs[i].cpf);
            printf("Professor atualizado.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}

void excluirProfessor(Professor profs[], int* qtd) {
    int mat, i, j;
    printf("Digite matrícula para excluir: ");
    scanf("%d", &mat);
    for (i = 0; i < *qtd; i++) {
        if (profs[i].matricula == mat) {
            for (j = i; j < *qtd - 1; j++) {
                profs[j] = profs[j + 1];
            }
            (*qtd)--;
            printf("Professor excluído.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}


