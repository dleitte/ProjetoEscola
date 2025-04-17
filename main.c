#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_ALUNO 3
#define TAM_PROFESSOR 3
#define TAM_DISCIPLINA 5
#define MAX_ALUNOS_POR_DISCIPLINA 40

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

typedef struct {
    char nome[100];
    char codigo[20];
    int semestre;
    int matriculaProfessor;
    int alunosMatriculados[MAX_ALUNOS_POR_DISCIPLINA];
    int qtdAlunos;
} Disciplina;

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

    int i;
    for (i = 0; i < qtdDisc; i++) {
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

void listarProfessoresPorNascimento(Professor professores[], int qtdProf){
    
     Professor copia[TAM_PROFESSOR];
     memcpy(copia, professores, sizeof(Professor) * qtdProf);
     int i, j, dataAtual, dataSeguinte;
    
    
    for(i = 0; i < qtdProf - 1; i++){
                                
        for(j = 0; j < qtdProf - i - 1; j++){
                                    
            dataAtual = copia[j].ano * 10000 + copia[j].mes * 100 + copia[j].dia;
            dataSeguinte = copia[j + 1].ano * 10000 + copia[j + 1].mes * 100 + copia[j + 1].dia;
                                    
            if(dataAtual > dataSeguinte){
                                        
                Professor temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }                            
        }                            
                                
    } 
    for(i = 0; i < qtdProf; i++){
                                
        printf("Professor: %s\n", copia[i].nome);
        printf("Data de Nascimento: %02d/%02d/%04d\n", copia[i].dia, copia[i].mes, copia[i].ano);
    }                            
                            
                            
}
void listarProfessoresPorSexo(Professor professores[], int qtdProf) {
    char sexoEscolhido[20];
    printf("Digite o sexo (M/F/Masculino/Feminino): ");
    scanf(" %s", sexoEscolhido);

    if (!validarSexo(sexoEscolhido)) {
        printf("Sexo inválido.\n");
        return;
    }

    toLowerStr(sexoEscolhido);

    printf("Professores do sexo %s:\n", sexoEscolhido);
    for (int i = 0; i < qtdProf; i++) {
        char sexoProf[20];
        strcpy(sexoProf, professores[i].sexo);
        toLowerStr(sexoProf);
        if (strcmp(sexoProf, sexoEscolhido) == 0) {
            printf(" %s\n", professores[i].nome);
        }
    }
}

void listarProfessoresPorNome(Professor professores[], int qtdProf) {
    
    Professor copia[TAM_PROFESSOR];
    memcpy(copia, professores, sizeof(Professor) * qtdProf);

    for (int i = 0; i < qtdProf - 1; i++) {
        for (int j = 0; j < qtdProf - i - 1; j++) {
            if (strcmp(copia[j].nome, copia[j + 1].nome) > 0) {
                Professor temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("Professores em ordem alfabética:\n");
    for (int i = 0; i < qtdProf; i++) {
        printf(" %s\n", copia[i].nome);
    }
}

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
                    "9 - Listar professores ordenado por nome\n");
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
                        case 11: // aniversariante do mes
                        case 12: // string de busca, listar nomes
                        case 13: // lista de alunos em pelo menos 3 disciplinas
                        case 14: // lista de disciplina q extrapolham 40 vagas
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
    
