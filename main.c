#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "utils.h"

int main() {
    Aluno alunos[TAM_ALUNO];
    Professor professores[TAM_PROFESSOR];
    Disciplina disciplinas[TAM_DISCIPLINA];
    int qtdAluno = 0, qtdProf = 0, qtdDisc = 0;
    int opcao, sub;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1 - Módulo Aluno\n");
        printf("2 - Módulo Professor\n");
        printf("3 - Módulo Disciplinas\n");
        printf("4 - Relatórios\n");
        printf("0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Menu Aluno ---\n");
                printf("1 - Incluir\n2 - Atualizar\n3 - Excluir\nEscolha: ");
                scanf("%d", &sub);
                switch (sub) {
                    case 1: incluirAluno(alunos, &qtdAluno); break;
                    case 2: atualizarAluno(alunos, qtdAluno); break;
                    case 3: excluirAluno(alunos, &qtdAluno); break;
                    default: printf("Opção inválida.\n");
                }
                break;

            case 2:
                printf("\n--- Menu Professor ---\n");
                printf("1 - Incluir\n2 - Atualizar\n3 - Excluir\nEscolha: ");
                scanf("%d", &sub);
                switch (sub) {
                    case 1: incluirProfessor(professores, &qtdProf); break;
                    case 2: atualizarProfessor(professores, qtdProf); break;
                    case 3: excluirProfessor(professores, &qtdProf); break;
                    default: printf("Opção inválida.\n");
                }
                break;
            
            case 3:
                printf("\n--- Menu Disciplina ---\n");
                printf("1 - Incluir Disciplina\n2 - Inserir Aluno\n3 - Remover Aluno\nEscolha: ");
                scanf("%d", &sub);
                    switch (sub) {
                        case 1: incluirDisciplina(disciplinas, &qtdDisc, professores, qtdProf); break;
                        case 2: inserirAlunoEmDisciplina(disciplinas, qtdDisc, alunos, qtdAluno); break;
                        case 3: removerAlunoDeDisciplina(disciplinas, qtdDisc); break;
                        default: printf("Opção inválida.\n");
                }
                break;

            case 4:
                printf("\n==============================\n");
                printf("     MENU DOS RELATÓRIOS     \n");
                printf("==============================\n");

                printf(
                    "1 - Listar Alunos\n"
                    "2 - Listar Professores\n"
                    "3 - Listar Disciplinas(sem dados dos alunos)\n"
                    "4 - Listar uma Disciplina(com dados dos alunos)\n"
                    "5 - Listar Alunos por Sexo\n"
                    "6 - Listar Alunos ordenado por nome\n"
                    "7 - Listar Alunos ordenado por Data de Nascimento\n"
                    "8 - Listar professores por sexo\n"
                    "9 - Listar professores ordenado por nome\n"
                    "10 - Listar Professores por Data de Nascimento\n"
                    "11 - Listar Aniversariantes do Mês\n"
                    "12 - Buscar Aluno/Professor pelo Nome (mín. 3 letras)\n"
                    "13 - Listar Alunos com menos de 3 Disciplinas\n"
                    "14 - Listar Disciplinas com mais de 40 Alunos e Professor Responsável\n"
                    "Escolha: ");
                scanf("%d", &sub);



                    
                    switch(sub){
                        
                        case 1: listarAlunos(alunos, qtdAluno); break;
                        case 2: listarProfessores(professores, qtdProf); break;
                        case 3: listarDisciplinas(disciplinas, qtdDisc, professores, qtdProf); break;
                        case 4: listarDisciplinaComAlunos(disciplinas, qtdDisc, alunos, qtdAluno, professores, qtdProf); break;
                        case 5: listarAlunosPorSexo(alunos, qtdAluno); break;                                     
                        case 6: listarAlunosPorNome(alunos, qtdAluno); break;
                        case 7: listarAlunosPorNascimento(alunos, qtdAluno); break;
                        case 8: listarProfessoresPorSexo(professores, qtdProf); break;
                        case 9: listarProfessoresPorNome(professores, qtdProf); break;
                        case 10: listarProfessoresPorNascimento(professores, qtdProf); break;
                        case 11: listarAniversariantesMes(professores, qtdProf, alunos, qtdAluno); break;
                        case 12: buscarPorNomeSubstring(alunos, qtdAluno, professores, qtdProf); break;
                        case 13: listarAlunosComMenosDeTresDisciplinas(alunos, qtdAluno, disciplinas, qtdDisc); break;
                        case 14: listarDisciplinasComMaisDe40Alunos(disciplinas, qtdDisc, professores, qtdProf); break;
                    }
                    break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        
}
    } while (opcao != 0);

    return 0;
} 
