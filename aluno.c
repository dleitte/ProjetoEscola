#include <stdio.h>
#include <string.h>
#include "aluno.h"

// Função para cadastrar um aluno
void cadastrarAluno(Aluno alunos[], int *qtdAlunos) {
    Aluno aluno;
    printf("Informe o ID do aluno: ");
    scanf("%d", &aluno.id);
    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]", aluno.nome);
    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno.idade);
    printf("Informe o sexo do aluno (M/F): ");
    scanf(" %c", &aluno.sexo);
    printf("Informe a data de nascimento do aluno (dd/mm/aaaa): ");
    scanf("%s", aluno.dataNascimento);

    aluno.qtdDisciplinas = 0;  // Inicializa a quantidade de disciplinas como 0

    alunos[*qtdAlunos] = aluno;
    (*qtdAlunos)++;
}

// Função para listar todos os alunos
void listarAlunos(Aluno alunos[], int qtdAlunos) {
    for (int i = 0; i < qtdAlunos; i++) {
        printf("ID: %d, Nome: %s, Idade: %d, Sexo: %c, Data de Nascimento: %s\n", 
                alunos[i].id, alunos[i].nome, alunos[i].idade, alunos[i].sexo, alunos[i].dataNascimento);
    }
}

// Função para buscar aluno pelo nome
void buscarAlunoPorNome(Aluno alunos[], int qtdAlunos, const char* nome) {
    for (int i = 0; i < qtdAlunos; i++) {
        if (strstr(alunos[i].nome, nome) != NULL) { // Verifica se o nome contém a substring
            printf("Aluno encontrado: %s\n", alunos[i].nome);
        }
    }
}

// Função para listar alunos por sexo
void listarAlunosPorSexo(Aluno alunos[], int qtdAlunos, char sexo) {
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].sexo == sexo) {
            printf("Aluno: %s, Sexo: %c\n", alunos[i].nome, alunos[i].sexo);
        }
    }
}

// Função para listar alunos ordenados por nome
void listarAlunosOrdenadosPorNome(Aluno alunos[], int qtdAlunos) {
    for (int i = 0; i < qtdAlunos - 1; i++) {
        for (int j = i + 1; j < qtdAlunos; j++) {
            if (strcmp(alunos[i].nome, alunos[j].nome) > 0) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
    listarAlunos(alunos, qtdAlunos);
}

// Função para listar alunos ordenados por data de nascimento
void listarAlunosOrdenadosPorData(Aluno alunos[], int qtdAlunos) {
    for (int i = 0; i < qtdAlunos - 1; i++) {
        for (int j = i + 1; j < qtdAlunos; j++) {
            if (strcmp(alunos[i].dataNascimento, alunos[j].dataNascimento) > 0) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }
    listarAlunos(alunos, qtdAlunos);
}
