#include <stdio.h>
#include <string.h>
#include "disciplina.h"
#include "aluno.h"
#include "professor.h"

void incluirDisciplina(Disciplina disciplinas[], int* qtdDisc, Professor professores[], int qtdProf) {
    if (*qtdDisc >= TAM_DISCIPLINA) {
        printf("Limite de disciplinas atingido.\n");
        return;
    }

    Disciplina nova;
    printf("\n--- Incluir Disciplina ---\n");
    printf("Nome da Disciplina: ");
    getchar();
    fgets(nova.nome, 100, stdin);
    nova.nome[strcspn(nova.nome, "\n")] = '\0';

    printf("Código: ");
    scanf("%s", nova.codigo);
    printf("Semestre: ");
    scanf("%d", &nova.semestre);

    printf("Matrícula do Professor Responsável: ");
    scanf("%d", &nova.matriculaProfessor);

    int professorExiste = 0;
    for (int i = 0; i < qtdProf; i++) {
        if (professores[i].matricula == nova.matriculaProfessor) {
            professorExiste = 1;
            break;
        }
    }

    if (!professorExiste) {
        printf("Professor com matrícula %d não encontrado.\n", nova.matriculaProfessor);
        return;
    }

    nova.qtdAlunos = 0;
    disciplinas[*qtdDisc] = nova;
    (*qtdDisc)++;
    printf("Disciplina cadastrada com sucesso!\n");
}

void listarDisciplinas(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf) {
    printf("\n--- Lista de Disciplinas ---\n");
    for (int i = 0; i < qtdDisc; i++) {
        printf("Nome: %s\n", disciplinas[i].nome);
        printf("Código: %s\n", disciplinas[i].codigo);
        printf("Semestre: %d\n", disciplinas[i].semestre);

        int encontrou = 0;
        for (int j = 0; j < qtdProf; j++) {
            if (professores[j].matricula == disciplinas[i].matriculaProfessor) {
                printf("Professor: %s\n", professores[j].nome);
                encontrou = 1;
                break;
            }
        }

        if (!encontrou) {
            printf("Professor: [NÃO ENCONTRADO]\n");
        }

        printf("Total de Alunos: %d\n\n", disciplinas[i].qtdAlunos);
    }
}

void inserirAlunoEmDisciplina(Disciplina disciplinas[], int qtdDisc, Aluno alunos[], int qtdAlunos) {
    char codigo[20];
    int matriculaAluno;

    printf("Código da disciplina: ");
    scanf("%s", codigo);

    for (int i = 0; i < qtdDisc; i++) {
        if (strcmp(disciplinas[i].codigo, codigo) == 0) {
            if (disciplinas[i].qtdAlunos >= MAX_ALUNOS_POR_DISCIPLINA) {
                printf("Limite de alunos atingido nesta disciplina.\n");
                return;
            }

            printf("Matrícula do aluno a inserir: ");
            scanf("%d", &matriculaAluno);

            int alunoExiste = 0;
            for (int j = 0; j < qtdAlunos; j++) {
                if (alunos[j].matricula == matriculaAluno) {
                    alunoExiste = 1;
                    break;
                }
            }

            if (!alunoExiste) {
                printf("Aluno com matrícula %d não encontrado.\n", matriculaAluno);
                return;
            }

            for (int j = 0; j < disciplinas[i].qtdAlunos; j++) {
                if (disciplinas[i].alunosMatriculados[j] == matriculaAluno) {
                    printf("Aluno já está matriculado nesta disciplina.\n");
                    return;
                }
            }

            disciplinas[i].alunosMatriculados[disciplinas[i].qtdAlunos++] = matriculaAluno;
            printf("Aluno inserido na disciplina com sucesso.\n");
            return;
        }
    }

    printf("Disciplina não encontrada.\n");
}

void removerAlunoDeDisciplina(Disciplina disciplinas[], int qtdDisc) {
    char codigo[20];
    int matriculaAluno;
    printf("Código da disciplina: ");
    scanf("%s", codigo);

    for (int i = 0; i < qtdDisc; i++) {
        if (strcmp(disciplinas[i].codigo, codigo) == 0) {
            printf("Matrícula do aluno a remover: ");
            scanf("%d", &matriculaAluno);

            for (int j = 0; j < disciplinas[i].qtdAlunos; j++) {
                if (disciplinas[i].alunosMatriculados[j] == matriculaAluno) {
                    for (int k = j; k < disciplinas[i].qtdAlunos - 1; k++) {
                        disciplinas[i].alunosMatriculados[k] = disciplinas[i].alunosMatriculados[k + 1];
                    }
                    disciplinas[i].qtdAlunos--;
                    printf("Aluno removido da disciplina.\n");
                    return;
                }
            }

            printf("Aluno não está matriculado nesta disciplina.\n");
            return;
        }
    }

    printf("Disciplina não encontrada.\n");
}

void listarDisciplinaComAlunos(Disciplina disciplinas[], int qtdDisc, Aluno alunos[], int qtdAlunos, Professor professores[], int qtdProf) {
    printf("\n--- Lista Detalhada de Disciplinas ---\n");

    for (int i = 0; i < qtdDisc; i++) {
        printf("Nome: %s\n", disciplinas[i].nome);
        printf("Código: %s\n", disciplinas[i].codigo);
        printf("Semestre: %d\n", disciplinas[i].semestre);

        int encontrouProf = 0;
        for (int j = 0; j < qtdProf; j++) {
            if (professores[j].matricula == disciplinas[i].matriculaProfessor) {
                printf("Professor: %s\n", professores[j].nome);
                encontrouProf = 1;
                break;
            }
        }
        if (!encontrouProf) {
            printf("Professor: [NÃO ENCONTRADO]\n");
        }

        printf("Alunos matriculados (%d):\n", disciplinas[i].qtdAlunos);
        for (int k = 0; k < disciplinas[i].qtdAlunos; k++) {
            int matAluno = disciplinas[i].alunosMatriculados[k];
            int encontrouAluno = 0;

            for (int a = 0; a < qtdAlunos; a++) {
                if (alunos[a].matricula == matAluno) {
                    printf("  - %s (Matrícula: %d)\n", alunos[a].nome, alunos[a].matricula);
                    encontrouAluno = 1;
                    break;
                }
            }

            if (!encontrouAluno) {
                printf("  - [Aluno com matrícula %d não encontrado]\n", matAluno);
            }
        }
        printf("\n");
    }
}
