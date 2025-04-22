#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "utils.h"  
#include "professor.h"
#include "variaveis.h"

void incluirAluno(Aluno alunos[], int* qtd) {
    if (*qtd >= TAM_ALUNO) {
        printf("Limite de alunos atingido.\n");
        return;
    }

    Aluno novo;
    int i;

    printf("\n--- Incluir Aluno ---\n");
    printf("Nome: ");
    getchar();
    fgets(novo.nome, 100, stdin);
    for (i = 0; novo.nome[i] != '\0'; i++) {
        if (novo.nome[i] == '\n') {
            novo.nome[i] = '\0';
            break;
        }
    }

    printf("Matrícula: ");
    scanf("%d", &novo.matricula);
    printf("Sexo (M/F/Masculino/Feminino): ");
    scanf("%s", novo.sexo);
    if (!validarSexo(novo.sexo)) return;
    printf("Data nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &novo.dia, &novo.mes, &novo.ano);
    if (!validarData(novo.dia, novo.mes, novo.ano)) return;
    printf("CPF: ");
    scanf("%s", novo.cpf);
    if (!validarCPF(novo.cpf)) {
        printf("CPF inválido.\n");
        return;
    }
    
    for (i = 0; i < *qtd; i++) {
        if (strcmp(alunos[i].cpf, novo.cpf) == 0) {
            printf("CPF já cadastrado para outro aluno.\n");
            return;
        }
    }

    alunos[*qtd] = novo;
    (*qtd)++;
    printf("Aluno cadastrado com sucesso!\n");
}

void listarAlunos(Aluno alunos[], int qtd) {
    int i;
    printf("\n--- Lista de Alunos ---\n");
    for (i = 0; i < qtd; i++) {
        printf("\nNome: %s\n", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Sexo: %s\n", alunos[i].sexo);
        printf("Nascimento: %02d/%02d/%d\n", alunos[i].dia, alunos[i].mes, alunos[i].ano);
        printf("CPF: %s\n", alunos[i].cpf);
    }
}

void atualizarAluno(Aluno alunos[], int qtd) {
    int mat, i;
    printf("Digite matrícula para atualizar: ");
    scanf("%d", &mat);
    for (i = 0; i < qtd; i++) {
        if (alunos[i].matricula == mat) {
            printf("Novo nome: ");
            getchar();
            fgets(alunos[i].nome, 100, stdin);
            for (int j = 0; alunos[i].nome[j] != '\0'; j++) {
                if (alunos[i].nome[j] == '\n') alunos[i].nome[j] = '\0';
            }
            printf("Novo sexo: ");
            scanf("%s", alunos[i].sexo);
            printf("Nova data nascimento (dd mm aaaa): ");
            scanf("%d %d %d", &alunos[i].dia, &alunos[i].mes, &alunos[i].ano);
            printf("Novo CPF: ");
            scanf("%s", alunos[i].cpf);
            printf("Aluno atualizado.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}

void excluirAluno(Aluno alunos[], int* qtd) {
    int mat, i, j;
    printf("Digite matrícula para excluir: ");
    scanf("%d", &mat);
    for (i = 0; i < *qtd; i++) {
        if (alunos[i].matricula == mat) {
            for (j = i; j < *qtd - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            (*qtd)--;
            printf("Aluno excluído.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}
void listarAlunosPorSexo(Aluno alunos[], int qtdAluno) {
    char sexoEscolhido[20];
    printf("Digite o sexo (M/F/Masculino/Feminino): ");
    scanf(" %s", sexoEscolhido);

    if (!validarSexo(sexoEscolhido)) {
        printf("Sexo inválido.\n");
        return;
    }

    toLowerStr(sexoEscolhido);

    printf("Alunos do sexo %s:\n", sexoEscolhido);
    for (int i = 0; i < qtdAluno; i++) {
        char sexoAluno[20];
        strcpy(sexoAluno, alunos[i].sexo);
        toLowerStr(sexoAluno);
        if (strcmp(sexoAluno, sexoEscolhido) == 0) {
            printf(" %s\n", alunos[i].nome);
        }
    }
}
void listarAlunosPorNome(Aluno alunos[], int qtdAluno) {
    Aluno copia[TAM_ALUNO];
    memcpy(copia, alunos, sizeof(Aluno) * qtdAluno);

    for (int i = 0; i < qtdAluno - 1; i++) {
        for (int j = 0; j < qtdAluno - i - 1; j++) {
            if (strcmp(copia[j].nome, copia[j + 1].nome) > 0) {
                Aluno temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("Alunos em ordem alfabética:\n");
    for (int i = 0; i < qtdAluno; i++) {
        printf(" %s\n", copia[i].nome);
    }
}

void listarAlunosPorNascimento(Aluno alunos[], int qtdAluno) {
    Aluno copia[TAM_ALUNO];
    memcpy(copia, alunos, sizeof(Aluno) * qtdAluno);

    for (int i = 0; i < qtdAluno - 1; i++) {
        for (int j = 0; j < qtdAluno - i - 1; j++) {
            int dataAtual = copia[j].ano * 10000 + copia[j].mes * 100 + copia[j].dia;
            int dataSeguinte = copia[j + 1].ano * 10000 + copia[j + 1].mes * 100 + copia[j + 1].dia;

            if (dataAtual > dataSeguinte) {
                Aluno temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("\nAlunos ordenados por data de nascimento:\n");
    for (int i = 0; i < qtdAluno; i++) {
        printf(" %s - %02d/%02d/%d\n", copia[i].nome, copia[i].dia, copia[i].mes, copia[i].ano);
    }
}
void listarAlunoAniversariantesMes(Aluno alunos[], int qtdAluno, int mesEscolhido){
    
    int i;
    
    printf("Aniversariantes do mês %d:\n", mesEscolhido);
    int encontrou = 0;

    for(i = 0; i < qtdAluno; i++){
                            
        if(alunos[i].mes == mesEscolhido){
            printf("Nome: %s\n", alunos[i].nome);
            encontrou = 1;
        }                    
    }                        
                        
                        
    if(!encontrou){
        printf("Não há aniversariantes nesse mes\n");
    }                   
    
}
void listarAniversariantesMes(Professor professores[], int qtdProf, Aluno alunos[], int qtdAluno) {
    int mesEscolhido;
    printf("Digite o mês escolhido (1-12): ");
    scanf("%d", &mesEscolhido);

    if (mesEscolhido < 1 || mesEscolhido > 12) {
        printf("Mês inválido. Insira um valor entre 1 e 12.\n");
        return;
    }

    printf("\n--- Aniversariantes do mês %d ---\n", mesEscolhido);
    listarProfAniversariantesMes(professores, qtdProf, mesEscolhido);
    listarAlunoAniversariantesMes(alunos, qtdAluno, mesEscolhido);
}
void buscarPorNomeSubstring(Aluno alunos[], int qtdAluno, Professor professores[], int qtdProf) {
    char termo[100];
    printf("Digite pelo menos 3 caracteres do nome para buscar: ");
    getchar(); 
    fgets(termo, 100, stdin);
    termo[strcspn(termo, "\n")] = '\0'; 

    if (strlen(termo) < 3) {
        printf("⚠️  Você deve digitar no mínimo 3 caracteres.\n");
        return;
    }

    toLowerStr(termo);

    int encontrou = 0;

    printf("\n--- Resultados para Alunos ---\n");
    for (int i = 0; i < qtdAluno; i++) {
        char nomeTemp[100];
        strcpy(nomeTemp, alunos[i].nome);
        toLowerStr(nomeTemp);
        if (strstr(nomeTemp, termo)) {
            printf(" %s (Matrícula: %d)\n", alunos[i].nome, alunos[i].matricula);
            encontrou = 1;
        }
    }

    printf("\n--- Resultados para Professores ---\n");
    for (int i = 0; i < qtdProf; i++) {
        char nomeTemp[100];
        strcpy(nomeTemp, professores[i].nome);
        toLowerStr(nomeTemp);
        if (strstr(nomeTemp, termo)) {
            printf(" %s (Matrícula: %d)\n", professores[i].nome, professores[i].matricula);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum nome correspondente foi encontrado.\n");
    }
}
void listarAlunosComMenosDeTresDisciplinas(Aluno alunos[], int qtdAlunos, Disciplina disciplinas[], int qtdDisc) {
    printf("\n--- Alunos matriculados em menos de 3 disciplinas ---\n");
    int encontrou = 0;

    for (int i = 0; i < qtdAlunos; i++) {
        int count = 0;

        for (int j = 0; j < qtdDisc; j++) {
            for (int k = 0; k < disciplinas[j].qtdAlunos; k++) {
                if (disciplinas[j].alunosMatriculados[k] == alunos[i].matricula) {
                    count++;
                    break;
                }
            }
        }

        if (count < 3) {
            printf(" %s (Matrícula: %d) - %d disciplina(s)\n", alunos[i].nome, alunos[i].matricula, count);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Todos os alunos estão matriculados em 3 ou mais disciplinas.\n");
    }
}
