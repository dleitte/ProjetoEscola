#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct {
    int id;
    char nome[100];
    char sexo;
    char dataNascimento[11];
    int disciplinas[10]; // Disciplinas que o professor leciona
    int qtdDisciplinas;
} Professor;

void cadastrarProfessor(Professor professores[], int *qtdProfessores);
void listarProfessores(Professor professores[], int qtdProfessores);
void listarProfessoresPorSexo(Professor professores[], int qtdProfessores, char sexo);
void listarProfessoresOrdenadosPorNome(Professor professores[], int qtdProfessores);

#endif
