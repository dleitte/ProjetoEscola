#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "aluno.h"
#include "professor.h"

#define TAM_DISCIPLINA 3
#define MAX_ALUNOS_POR_DISCIPLINA 50

typedef struct {
    char nome[100];
    char codigo[20];
    int semestre;
    int matriculaProfessor;
    int alunosMatriculados[MAX_ALUNOS_POR_DISCIPLINA];
    int qtdAlunos;
} Disciplina;

void incluirDisciplina(Disciplina disciplinas[], int* qtdDisc, Professor professores[], int qtdProf);
void listarDisciplinas(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf);
void inserirAlunoEmDisciplina(Disciplina disciplinas[], int qtdDisc, Aluno alunos[], int qtdAlunos);
void removerAlunoDeDisciplina(Disciplina disciplinas[], int qtdDisc);
void listarDisciplinaComAlunos(Disciplina disciplinas[], int qtdDisc, Aluno alunos[], int qtdAlunos, Professor professores[], int qtdProf);

#endif
