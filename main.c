#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 100
#define TAM_Filme 2
#define TAM_Cliente 2

void Menu();

void Cadastro_Filme();
void Altera_Filme();
void Excluir_Filme();
void Consultar_Filme();

void Gerenciamento_Locacoes();
void Locar();
void Filmes_Locados();

struct tp_ficha{
    char filme[50];
    float duracao;
    char categoria[50];
    char status;
    char midia[50];
    int ativo;
    int Lativo;
    char Lnome[50];
}ficha[2];

int i;
int cont=0;


int main(void)
{    
    setlocale(LC_ALL, "portuguese");

    Menu();

}

void Menu(){
    
    int op=0;
    while( (op!='s') && (op!='S') ){
    system("clear");
    printf("\n====================================================\n");
    printf("                      Locadora\n");
    printf("====================================================\n");
    
    printf("Digite o que deseja fazer:\n");
    printf("1-Cadastrar Filmes\n");
    printf("2-Alterar Filme:\n");
    printf("3-Excluir Filme:\n");
    printf("4-Consultar Filmes\n");
    printf("5-Alugar Filmes\n");
    scanf("%d", &op);
    getchar();
    
        switch(op){
            case 1:
                Cadastro_Filme();
                break;
            case 2:
                Altera_Filme();
                break;
            case 3:
                Excluir_Filme();
                break;
            case 4:
                Consultar_Filme();
                break;
            case 5:
                Gerenciamento_Locacoes();
                break;
            default:
                printf("Opção Invalida!!!!Digite Novamente");
        }
    }
}

void Cadastro_Filme(){
        

    
   setlocale(LC_ALL, "portuguese");
   

    printf("\n===============================================================\n");
    printf("                         Cadastro de Filmes\n");
    printf("===============================================================\n");

        printf("\nDigite o nome do filme: ");
        scanf("%s", ficha[cont].filme);
        getchar();

        printf("\nDuração: ");
        scanf("%f", &ficha[cont].duracao);
        getchar();

        printf("\nCategoria: ");
        scanf("%s", ficha[cont].categoria);
        getchar();
        
        printf("\nDigite o tipo de midia<Fita/DVD>:  ");
        scanf("%s", ficha[cont].midia);

            ficha[cont].ativo = 1;
        system("clear");

        printf("\nRegistro gravado com sucesso!\n");
          cont++;
        getchar();

        Menu();

}

void Altera_Filme(){

    char alterarfilme[TAM];

    printf("\n===============================================================\n");
    printf("                         Alteracao de FILMES\n");
    printf("===============================================================\n");


    printf("Digite o nome do Filme que deseja alterar:\n");
    scanf("%s", &alterarfilme['\0']);
    getchar();

        for(i=0; i<cont; i++){
            if(strcmp(alterarfilme, ficha[i].filme)==0){

                printf("\nFIlme: %s\n", ficha[i].filme);

                printf("\nDigite o novo, Filme:\n ");
                scanf("%s", &ficha[i].filme);
                getchar();


                printf("Digite a duração do filme: ");
                scanf("%f", &ficha[i].duracao);
                getchar();

                printf("\n");

                printf("Digite a categoria do FIlme: ");
                scanf("%s", &ficha[i].categoria);
                getchar();
                
                printf("Digite o tipo de midia<Fita/DVD>:  ");
                scanf("%s", ficha[i].midia);
                getchar();
                
                printf("\n");
                
                printf("Precione enter para continuar: ");
                ficha[i].ativo = 1;
            
        }else{
            printf("O nome não foi encontrado!!!");
        }
    }
    Menu();
} 

void Excluir_Filme(){
    char exc[50];
    char op;

          printf("\n=========================================================\n");
          printf("                  Exclusão de Filmes\n");
          printf("=========================================================\n");


          printf("Digite o nome do Filme que voce deseja excluir: ");
          scanf("%s", &exc['\0']);
          getchar();

          for(i=0; i<cont; i++){
              if(strcmp(exc, ficha[i].filme)==0){

                  printf("\nFilme cadastrado. Deseja excluir o Filme? S/N: ");
                  scanf("%c", &op);
                  getchar();

                  if(op == 's' || op == 'S'){

                      ficha[i].ativo = 0;
                      ficha[i].filme[0] = '\0';
                      ficha[i].duracao = 0;
                      ficha[i].categoria[0] = '\0';
                      ficha[i].midia[0] = '\0';
                      printf("Filme excluido com sucesso!");

                    } else if(op == 'n' || op == 'N'){

                        printf("Filme não foi excluido ");
                        system("exit");
                    }
                } else{

                    printf("\nO Filme não foi encontrado !! \n");
                }
            }
            Menu();
}

void Consultar_Filme(){

    
            system("clear");
          printf("\n=========================================================\n");
          printf("                  Filmes Cadastrados\n");
          printf("=========================================================\n");

          
                for(int i = 0; i < cont; i++) {
                    printf("\n%d-O nome do filme é: %s\n", i+1, ficha[i].filme);
                    printf("\n%d-A duração é: %.2f\n", i+1, ficha[i].duracao);
                    printf("\n%d-A categoria é: %s\n", i+1, ficha[i].categoria);
                    printf("\n%d-Digite o tipo de midia<Fita/DVD>: %s", i+1, ficha[i].midia);
                    
                }
                getchar();
                getchar();
                Menu();
                

            

}

void Gerenciamento_Locacoes(){

    int op=0;

        printf("\n===========================================================\n");
        printf("                     Gerenciamento de Locações\n");
        printf("===========================================================\n");

        printf("  Digite o número referente a opção desejada:\n");
        printf("  1- Locar Filme:\n");
        printf("  2- Listar Filmes Locados:\n");
        printf("Opção: ");
        scanf("%d", &op);
        getchar();

    switch(op)
      {
            case 1:
                Locar(); 
                break;
            case 2:
                Filmes_Locados();
                break;
            default:
                printf("Opção invalida!!!! Digite Novamente:\n ");
      }
}

void Locar(){

    system("clear");

    char buscafilme[50];

        printf("\n=========================================================\n");
        printf("                  Filmes Cadastrados\n");
        printf("=========================================================\n");

          for(int i=0; i<cont; i++){

                printf("\n%d-O nome do filme é: %s", i+1, ficha[i].filme);
                printf("\n%d-A duração é: %.2f", i+1, ficha[i].duracao);
                printf("\n%d-A categoria é: %s", i+1, ficha[i].categoria);
                printf("\n%d-Digite o tipo de midia<Fita/DVD>: ", i+1, ficha[i].midia);

          }
          
        printf("\n===========================================================\n");
        printf("                    LOCAR FILME \n\n");
        printf("===========================================================\n");


        printf("\nDigite o nome do filme para registrar a locação: ");
        scanf("%s",&buscafilme);
        getchar();



        for(i=0; i<cont; i++){
            

            if (strcmp(buscafilme, ficha[i].filme)==0){



                    if(ficha[i].Lativo==0){

                    printf("Digite o seu nome: ");
                    scanf("%s", ficha[i].Lnome);
                    getchar();

                    printf("Filme locado com sucesso por: %s\n ", ficha[i].Lnome);
                    getchar();

                    ficha[i].Lativo = 1;

                    } 
                    else{

                    printf("Filme ja se encontra Locado\n");
                    printf("Clique em enter para voltar ao menu principal\n");

                    }   

                }else if((buscafilme, ficha[i].filme)==1){

                    printf("\nFilme não encontrado !!!\n ");

                }
        }


getchar();
    Menu();

}

void Filmes_Locados(){

    system("clear");
    int i;

        printf("\n===========================================================\n");
        printf("                  Filmes Locados \n\n");
        printf("===========================================================\n");

        for(i=0; i<cont; i++){

            if(ficha[i].Lativo == 1){

                printf("\n%d- Filme: %s\n", i+1, ficha[i].filme);
                printf("\n%d- Locado por: %s", i+1, ficha[i].Lnome);

        }
        getchar();
        Menu();
}
}




 



























