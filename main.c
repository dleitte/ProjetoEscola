#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

int main() {
    Aluno alunos[TAM_ALUNO];
    Professor professores[TAM_PROFESSOR];
    Disciplina disciplinas[TAM_DISCIPLINA];
    
    int qtdAlunos = 0, qtdProfessores = 0, qtdDisciplinas = 0;
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Incluir Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Atualizar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Incluir Professor\n");
        printf("6. Listar Professores\n");
        printf("7. Atualizar Professor\n");
        printf("8. Excluir Professor\n");
        printf("9. Incluir Disciplina\n");
        printf("10. Listar Disciplinas\n");
        printf("11. Inserir Aluno em Disciplina\n");
        printf("12. Remover Aluno de Disciplina\n");
        printf("13. Listar Disciplinas com Alunos\n");
        printf("14. Listar Alunos por Sexo\n");
        printf("15. Listar Alunos por Nome\n");
        printf("16. Listar Alunos por Nascimento\n");
        printf("17. Listar Professores por Sexo\n");
        printf("18. Listar Professores por Nome\n");
        printf("19. Listar Professores por Nascimento\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                incluirAluno(alunos, &qtdAlunos);
                break;
            case 2:
                listarAlunos(alunos, qtdAlunos);
                break;
            case 3:
                atualizarAluno(alunos, qtdAlunos);
                break;
            case 4:
                excluirAluno(alunos, &qtdAlunos);
                break;
            case 5:
                incluirProfessor(professores, &qtdProfessores);
                break;
            case 6:
                listarProfessores(professores, qtdProfessores);
                break;
            case 7:
                atualizarProfessor(professores, qtdProfessores);
                break;
            case 8:
                excluirProfessor(professores, &qtdProfessores);
                break;
            case 9:
                incluirDisciplina(disciplinas, &qtdDisciplinas, professores, qtdProfessores);
                break;
            case 10:
                listarDisciplinas(disciplinas, qtdDisciplinas, professores, qtdProfessores);
                break;
            case 11:
                inserirAlunoEmDisciplina(disciplinas, qtdDisciplinas, alunos, qtdAlunos);
                break;
            case 12:
                removerAlunoDeDisciplina(disciplinas, qtdDisciplinas);
                break;
            case 13:
                listarDisciplinaComAlunos(disciplinas, qtdDisciplinas, alunos, qtdAlunos, professores, qtdProfessores);
                break;
            case 14:
                listarAlunosPorSexo(alunos, qtdAlunos);
                break;
            case 15:
                listarAlunosPorNome(alunos, qtdAlunos);
                break;
            case 16:
                listarAlunosPorNascimento(alunos, qtdAlunos);
                break;
            case 17:
                listarProfessoresPorSexo(professores, qtdProfessores);
                break;
            case 18:
                listarProfessoresPorNome(professores, qtdProfessores);
                break;
            case 19:
                listarProfessoresPorNascimento(professores, qtdProfessores);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

