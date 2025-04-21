#include <stdio.h>
#include <string.h>
#include "professor.h"

// Função para cadastrar um professor
void cadastrarProfessor(Professor professores[], int *qtdProfessores) {
    Professor professor;
    printf("Informe o ID do professor: ");
    scanf("%d", &professor.id);
    printf("Informe o nome do professor: ");
    scanf(" %[^\n]", professor.nome);
    printf("Informe o sexo do professor (M/F): ");
    scanf(" %c", &professor.sexo);
    printf("Informe a data de nascimento do professor (dd/mm/aaaa): ");
    scanf("%s", professor.dataNascimento);

    professor.qtdDisciplinas = 0;  // Inicializa a quantidade de disciplinas como 0

    professores[*qtdProfessores] = professor;
    (*qtdProfessores)++;
}

// Função para listar todos os professores
void listarProfessores(Professor professores[], int qtdProfessores) {
    for (int i = 0; i < qtdProfessores; i++) {
        printf("ID: %d, Nome: %s, Sexo: %c, Data de Nascimento: %s\n", 
                professores[i].id, professores[i].nome, professores[i].sexo, professores[i].dataNascimento);
    }
}

// Função para listar professores por sexo
void listarProfessoresPorSexo(Professor professores[], int qtdProfessores, char sexo) {
    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].sexo == sexo) {
            printf("Professor: %s, Sexo: %c\n", professores[i].nome, professores[i].sexo);
        }
    }
}

// Função para listar professores ordenados por nome
void listarProfessoresOrdenadosPorNome(Professor professores[], int qtdProfessores) {
    for (int i = 0; i < qtdProfessores - 1; i++) {
        for (int j = i + 1; j < qtdProfessores; j++) {
            if (strcmp(professores[i].nome, professores[j].nome) > 0) {
                Professor temp = professores[i];
                professores[i] = professores[j];
                professores[j] = temp;
            }
        }
    }
    listarProfessores(professores, qtdProfessores);
}

