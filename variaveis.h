#ifndef VARIAVEIS_H
#define VARIAVEIS_H

#define TAM_ALUNO 3
#define TAM_DISCIPLINA 3
#define MAX_ALUNOS_POR_DISCIPLINA 50
#define TAM_PROFESSOR 3

typedef struct {
    char nome[100];
    int matricula;
    char sexo[20];
    int dia, mes, ano;
    char cpf[15];
} Aluno;

typedef struct {
    char nome[100];
    char codigo[20];
    int semestre;
    int matriculaProfessor;
    int alunosMatriculados[MAX_ALUNOS_POR_DISCIPLINA];
    int qtdAlunos;
} Disciplina;

typedef struct {
    char nome[100];
    int matricula;
    char sexo[20];
    int dia, mes, ano;
    char cpf[15];
} Professor;

#endif
