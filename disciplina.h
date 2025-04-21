#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct {
    int id;
    char nome[100];
    int alunosMatriculados[40]; // IDs dos alunos matriculados
    int qtdAlunos;
    int professorId;  // ID do professor responsável
} Disciplina;

void cadastrarDisciplina(Disciplina disciplinas[], int *qtdDisciplinas);
void listarDisciplinas(Disciplina disciplinas[], int qtdDisciplinas);
void listarDisciplinaComAlunos(Disciplina disciplinas[], int qtdDisciplinas, int idDisciplina);

#endif
