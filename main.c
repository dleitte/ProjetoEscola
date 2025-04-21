#include <stdio.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

int main() {
    Aluno alunos[100]; 
    Professor professores[20];
    Disciplina disciplinas[50];
    
    int qtdAlunos = 0, qtdProfessores = 0, qtdDisciplinas = 0;
    int sub;
    
    printf(
        "1 - Cadastrar Aluno\n"
        "2 - Cadastrar Professor\n"
        "3 - Cadastrar Disciplina\n"
        "4 - Listar Alunos\n"
        "5 - Listar Professores\n"
        "6 - Listar Disciplinas\n"
        "Escolha: ");
    scanf("%d", &sub);

    switch (sub) {
        case 1: cadastrarAluno(alunos, &qtdAlunos); break;
        case 2: cadastrarProfessor(professores, &qtdProfessores); break;
        case 3: cadastrarDisciplina(disciplinas, &qtdDisciplinas); break;
        case 4: listarAlunos(alunos, qtdAlunos); break;
        case 5: listarProfessores(professores, qtdProfessores); break;
        case 6: listarDisciplinas(disciplinas, qtdDisciplinas); break;
        default: printf("Opção inválida!\n");
    }

    return 0;
}
