#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_ALUNO 3
#define TAM_PROFESSOR 3

typedef struct {
    char nome[100];
    int matricula;
    char sexo[20];
    int dia, mes, ano;
    char cpf[15];
} Aluno;

typedef struct {
    char nome[100];
    int matricula;
    char sexo[20];
    int dia, mes, ano;
    char cpf[15];
} Professor;

void toLowerStr(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int validarSexo(char sexo[]) {
    char temp[20];
    int i;
    for (i = 0; sexo[i] != '\0'; i++) {
        temp[i] = sexo[i];
    }
    temp[i] = '\0';
    toLowerStr(temp);

    return (
        strcmp(temp, "m") == 0 ||
        strcmp(temp, "f") == 0 ||
        strcmp(temp, "masculino") == 0 ||
        strcmp(temp, "feminino") == 0
    );
}

int validarData(int d, int m, int a) {
    if (a < 1900 || a > 2025) return 0;
    if (m < 1 || m > 12) return 0;
    int diasPorMes[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))) {
        return (d >= 1 && d <= 29);
    }
    return (d >= 1 && d <= diasPorMes[m - 1]);
}

int validarCPF(char cpf[]) {
    int count = 0, i;
    for (i = 0; cpf[i] != '\0'; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            count++;
        }
    }
    return (count == 11);
}

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
    if (!validarCPF(novo.cpf)) return;

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

void incluirProfessor(Professor profs[], int* qtd) {
    if (*qtd >= TAM_PROFESSOR) {
        printf("Limite de professores atingido.\n");
        return;
    }

    Professor novo;
    int i;

    printf("\n--- Incluir Professor ---\n");
    printf("Nome: ");
    getchar();
    fgets(novo.nome, 100, stdin);
    for (i = 0; novo.nome[i] != '\0'; i++) {
        if (novo.nome[i] == '\n') novo.nome[i] = '\0';
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
    if (!validarCPF(novo.cpf)) return;

    profs[*qtd] = novo;
    (*qtd)++;
    printf("Professor cadastrado com sucesso!\n");
}

void listarProfessores(Professor profs[], int qtd) {
    int i;
    printf("\n--- Lista de Professores ---\n");
    for (i = 0; i < qtd; i++) {
        printf("\nNome: %s\n", profs[i].nome);
        printf("Matrícula: %d\n", profs[i].matricula);
        printf("Sexo: %s\n", profs[i].sexo);
        printf("Nascimento: %02d/%02d/%d\n", profs[i].dia, profs[i].mes, profs[i].ano);
        printf("CPF: %s\n", profs[i].cpf);
    }
}

void atualizarProfessor(Professor profs[], int qtd) {
    int mat, i;
    printf("Digite matrícula para atualizar: ");
    scanf("%d", &mat);
    for (i = 0; i < qtd; i++) {
        if (profs[i].matricula == mat) {
            printf("Novo nome: ");
            getchar();
            fgets(profs[i].nome, 100, stdin);
            for (int j = 0; profs[i].nome[j] != '\0'; j++) {
                if (profs[i].nome[j] == '\n') profs[i].nome[j] = '\0';
            }
            printf("Novo sexo: ");
            scanf("%s", profs[i].sexo);
            printf("Nova data nascimento (dd mm aaaa): ");
            scanf("%d %d %d", &profs[i].dia, &profs[i].mes, &profs[i].ano);
            printf("Novo CPF: ");
            scanf("%s", profs[i].cpf);
            printf("Professor atualizado.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}

void excluirProfessor(Professor profs[], int* qtd) {
    int mat, i, j;
    printf("Digite matrícula para excluir: ");
    scanf("%d", &mat);
    for (i = 0; i < *qtd; i++) {
        if (profs[i].matricula == mat) {
            for (j = i; j < *qtd - 1; j++) {
                profs[j] = profs[j + 1];
            }
            (*qtd)--;
            printf("Professor excluído.\n");
            return;
        }
    }
    printf("Matrícula não encontrada.\n");
}

int main() {
    Aluno alunos[TAM_ALUNO];
    Professor professores[TAM_PROFESSOR];
    int qtdAluno = 0, qtdProf = 0;
    int opcao, sub;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1 - Módulo Aluno\n");
        printf("2 - Módulo Professor\n");
        printf("0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Menu Aluno ---\n");
                printf("1 - Incluir\n2 - Listar\n3 - Atualizar\n4 - Excluir\nEscolha: ");
                scanf("%d", &sub);
                switch (sub) {
                    case 1: incluirAluno(alunos, &qtdAluno); break;
                    case 2: listarAlunos(alunos, qtdAluno); break;
                    case 3: atualizarAluno(alunos, qtdAluno); break;
                    case 4: excluirAluno(alunos, &qtdAluno); break;
                    default: printf("Opção inválida.\n");
                }
                break;

            case 2:
                printf("\n--- Menu Professor ---\n");
                printf("1 - Incluir\n2 - Listar\n3 - Atualizar\n4 - Excluir\nEscolha: ");
                scanf("%d", &sub);
                switch (sub) {
                    case 1: incluirProfessor(professores, &qtdProf); break;
                    case 2: listarProfessores(professores, qtdProf); break;
                    case 3: atualizarProfessor(professores, qtdProf); break;
                    case 4: excluirProfessor(professores, &qtdProf); break;
                    default: printf("Opção inválida.\n");
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
