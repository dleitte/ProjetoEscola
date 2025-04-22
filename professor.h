#ifndef PROFESSOR_H
#define PROFESSOR_H

#define TAM_PROFESSOR 3

typedef struct {
    char nome[100];
    int matricula;
    char sexo[20];
    int dia, mes, ano;
    char cpf[15];
} Professor;

void incluirProfessor(Professor profs[], int* qtd);
void listarProfessores(Professor profs[], int qtd);
void atualizarProfessor(Professor profs[], int qtd);
void excluirProfessor(Professor profs[], int* qtd);

#endif

