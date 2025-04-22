#ifndef ALUNO_H
#define ALUNO_H

#define TAM_ALUNO 3

typedef struct {
    char nome[100];
    int matricula;
    char sexo[20];
    int dia, mes, ano;
    char cpf[15];
} Aluno;

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

#endif
