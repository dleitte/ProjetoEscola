#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "utils.h"  

void incluirAluno(Aluno alunos[], int* qtd) {
    if (*qtd >= TAM_ALUNO) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    Aluno novo;
    int i;

    printf("\n--- Incluir Aluno ---\n");
    printf("Nome: ");
    getchar();
    fgets(novo.nome, 100, stdin);
    for (i = 0; novo.nome[i] != '\0'; i++) {
        if (novo.nome[i] == '\n') {
            novo.nome[i] = '\0';
            break;
        }
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
        if (strcmp(alunos[i].cpf, novo.cpf) == 0) {
            printf("CPF já cadastrado para outro aluno.\n");
            return;
        }
    }

    alunos[*qtd] = novo;
    (*qtd)++;
    printf("Aluno cadastrado com sucesso!\n");
}

void listarAlunos(Aluno alunos[], int qtd) {
    int i;
    printf("\n--- Lista de Alunos ---\n");
    for (i = 0; i < qtd; i++) {
        printf("\nNome: %s\n", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Sexo: %s\n", alunos[i].sexo);
        printf("Nascimento: %02d/%02d/%d\n", alunos[i].dia, alunos[i].mes, alunos[i].ano);
        printf("CPF: %s\n", alunos[i].cpf);
    }
}

void atualizarAluno(Aluno alunos[], int qtd) {
    int mat, i;
    printf("Digite matrícula para atualizar: ");
    scanf("%d", &mat);
    for (i = 0; i < qtd; i++) {
        if (alunos[i].matricula == mat) {
            printf("Novo nome: ");
            getchar();
            fgets(alunos[i].nome, 100, stdin);
            for (int j = 0; alunos[i].nome[j] != '\0'; j++) {
                if (alunos[i].nome[j] == '\n') alunos[i].nome[j] = '\0';
            }
            printf("Novo sexo: ");
            scanf("%s", alunos[i].sexo);
            printf("Nova data nascimento (dd mm aaaa): ");
            scanf("%d %d %d", &alunos[i].dia, &alunos[i].mes, &alunos[i].ano);
            printf("Novo CPF: ");
            scanf("%s", alunos[i].cpf);
            printf("Aluno atualizado.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}

void excluirAluno(Aluno alunos[], int* qtd) {
    int mat, i, j;
    printf("Digite matrícula para excluir: ");
    scanf("%d", &mat);
    for (i = 0; i < *qtd; i++) {
        if (alunos[i].matricula == mat) {
            for (j = i; j < *qtd - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            (*qtd)--;
            printf("Aluno excluído.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}
