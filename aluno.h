#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int id;
    char nome[100];
    int idade;
    char sexo;
    char dataNascimento[11];
    int disciplinas[10];  // Disciplinas que o aluno está matriculado
    int qtdDisciplinas;
} Aluno;

void cadastrarAluno(Aluno alunos[], int *qtdAlunos);
void listarAlunos(Aluno alunos[], int qtdAlunos);
void buscarAlunoPorNome(Aluno alunos[], int qtdAlunos, const char* nome);
void listarAlunosPorSexo(Aluno alunos[], int qtdAlunos, char sexo);
void listarAlunosOrdenadosPorNome(Aluno alunos[], int qtdAlunos);
void listarAlunosOrdenadosPorData(Aluno alunos[], int qtdAlunos);

#endif
