#include <stdio.h>
#include <string.h>
#include "disciplina.h"

// Função para cadastrar uma disciplina
void cadastrarDisciplina(Disciplina disciplinas[], int *qtdDisciplinas) {
    Disciplina disciplina;
    printf("Informe o ID da disciplina: ");
    scanf("%d", &disciplina.id);
    printf("Informe o nome da disciplina: ");
    scanf(" %[^\n]", disciplina.nome);
    printf("Informe o número de alunos matriculados: ");
    scanf("%d", &disciplina.qtdAlunos);
    printf("Informe o ID do professor responsável: ");
    scanf("%d", &disciplina.professorId);

    disciplinas[*qtdDisciplinas] = disciplina;
    (*qtdDisciplinas)++;
}

// Função para listar todas as disciplinas
void listarDisciplinas(Disciplina disciplinas[], int qtdDisciplinas) {
    for (int i = 0; i < qtdDisciplinas; i++) {
        printf("ID: %d, Nome: %s, Alunos matriculados: %d\n", 
                disciplinas[i].id, disciplinas[i].nome, disciplinas[i].qtdAlunos);
    }
}

// Função para listar uma disciplina com seus alunos
void listarDisciplinaComAlunos(Disciplina disciplinas[], int qtdDisciplinas, int idDisciplina) {
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].id == idDisciplina) {
            printf("Disciplina: %s\n", disciplinas[i].nome);
            printf("Alunos matriculados:\n");
            for (int j = 0; j < disciplinas[i].qtdAlunos; j++) {
                printf("Aluno ID: %d\n", disciplinas[i].alunosMatriculados[j]);
            }
        }
    }
}
