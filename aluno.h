#ifndef ALUNO_H
#define ALUNO_H

#include "variaveis.h"

void incluirAluno(Aluno alunos[], int* qtd);
void listarAlunos(Aluno alunos[], int qtd);
void atualizarAluno(Aluno alunos[], int qtd);
void excluirAluno(Aluno alunos[], int* qtd);
void listarAlunosPorSexo(Aluno alunos[], int qtdAluno);
void listarAlunosPorNome(Aluno alunos[], int qtdAluno);
void listarAlunosPorNascimento(Aluno alunos[], int qtdAluno);
void listarAlunoAniversariantesMes(Aluno alunos[], int qtdAluno, int mesEscolhido);
void listarAniversariantesMes(Professor professores[], int qtdProf, Aluno alunos[], int qtdAluno);
void buscarPorNomeSubstring(Aluno alunos[], int qtdAluno, Professor professores[], int qtdProf);
void listarAlunosComMenosDeTresDisciplinas(Aluno alunos[], int qtdAlunos, Disciplina disciplinas[], int qtdDisc);

#endif
