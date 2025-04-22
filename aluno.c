#include <stdio.h>
#include <string.h>
#include "aluno.h"

void incluirAluno(Aluno alunos[], int* qtdAlunos) {
    if (*qtdAlunos < TAM_ALUNO) {
        Aluno novoAluno;
        printf("\nNome do Aluno: ");
        scanf(" %[^\n]s", novoAluno.nome);
        printf("Sexo (M/F): ");
        scanf(" %c", &novoAluno.sexo);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf(" %s", novoAluno.dataNascimento);
        
        alunos[*qtdAlunos] = novoAluno;
        (*qtdAlunos)++;
        printf("Aluno incluído com sucesso!\n");
    } else {
        printf("Limite de alunos atingido!\n");
    }
}

void listarAlunos(Aluno alunos[], int qtdAlunos) {
    if (qtdAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
    } else {
        for (int i = 0; i < qtdAlunos; i++) {
            printf("\nAluno %d:\n", i + 1);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Data de Nascimento: %s\n", alunos[i].dataNascimento);
        }
    }
}

void atualizarAluno(Aluno alunos[], int qtdAlunos) {
    int i;
    char nome[50];
    printf("\nDigite o nome do aluno para atualizar: ");
    scanf(" %[^\n]s", nome);
    
    for (i = 0; i < qtdAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            printf("Novo nome: ");
            scanf(" %[^\n]s", alunos[i].nome);
            printf("Novo sexo (M/F): ");
            scanf(" %c", &alunos[i].sexo);
            printf("Nova data de nascimento (dd/mm/aaaa): ");
            scanf(" %s", alunos[i].dataNascimento);
            printf("Aluno atualizado com sucesso!\n");
            return;
        }
    }
    printf("Aluno não encontrado!\n");
}

void excluirAluno(Aluno alunos[], int* qtdAlunos) {
    int i;
    char nome[50];
    printf("\nDigite o nome do aluno para excluir: ");
    scanf(" %[^\n]s", nome);
    
    for (i = 0; i < *qtdAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            for (int j = i; j < *qtdAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            (*qtdAlunos)--;
            printf("Aluno excluído com sucesso!\n");
            return;
        }
    }
    printf("Aluno não encontrado!\n");
}
