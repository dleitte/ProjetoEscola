#include <stdio.h>
#define TAM_ALUNO 3

int main()
{
    int listaAluno[TAM_ALUNO];
    int opcao, opcaoAluno;
    int sair = 0, sairAluno = 0;
    int qtdAluno = 0, matricula;
    
    while(!sair){
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Diciplina\n");
    scanf("%d", &opcao);
    
    switch(opcao){
        case 0:
          sair = 1;
          break;
          
        case 1:
          printf("Módulo Aluno");
          
          while(!sairAluno){
            printf("0 - Sair\n");
            printf("1 - Cadastrar Aluno\n");
            printf("2 - Listar Aluno\n");
            printf("3 - Atualizar Aluno\n");
            printf("4 - Excluir Aluno\n");
            scanf("%d", &opcaoAluno);
            
            switch(opcaoAluno){
                case 0:  
                  sairAluno = 1;
                  break;
                  
                case 1:
                  printf("Cadastrar Aluno\n");
                  printf("Digite a matricula\n");
                  scanf("%d", &matricula);
                  if(matricula<0){
                      printf("Matricula Invalida\n");
                  }else{
                      if(qtdAluno == TAM_ALUNO){
                        printf("Lista de Alunos Cheia\n");
                      }else{
                          listaAluno[qtdAluno] = matricula;
                          printf("Aluno Cadastrado com sucesso!!");
                          qtdAluno++;
                      }
                  }
                  
                  break;
                  
                case 2:
                  printf("Cadastrar Aluno");
                  break;
                  
                case 3:
                  printf("Cadastrar Aluno");
                  break;
                  
                case 4:
                  printf("Cadastrar Aluno");
                  break;
                  
                default:
                  printf("Opção Invalida");
            }
          }
          break;
          
        case 2:
          printf("Módulo Professor");
          break;
          
        case 3:
          printf("Módulo Diciplina");
          break;
          
        default:
          printf("Opção Invalida");
    }
}



    return 0;
}
