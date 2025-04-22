#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "variaveis.h"

void incluirDisciplina(Disciplina disciplinas[], int* qtdDisc, Professor professores[], int qtdProf);
void listarDisciplinas(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf);
void inserirAlunoEmDisciplina(Disciplina disciplinas[], int qtdDisc, Aluno alunos[], int qtdAlunos);
void removerAlunoDeDisciplina(Disciplina disciplinas[], int qtdDisc);
void listarDisciplinaComAlunos(Disciplina disciplinas[], int qtdDisc, Aluno alunos[], int qtdAlunos, Professor professores[], int qtdProf);
void listarDisciplinasComMaisDe40Alunos(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf);

#endif
