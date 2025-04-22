#ifndef ALUNO_H
#define ALUNO_H

#define TAM_ALUNO 3

typedef struct {
    char nome[50];
    char sexo;
    char dataNascimento[11]; // dd/mm/aaaa
} Aluno;

void incluirAluno(Aluno alunos[], int* qtdAlunos);
void listarAlunos(Aluno alunos[], int qtdAlunos);
void atualizarAluno(Aluno alunos[], int qtdAlunos);
void excluirAluno(Aluno alunos[], int* qtdAlunos);

#endif
