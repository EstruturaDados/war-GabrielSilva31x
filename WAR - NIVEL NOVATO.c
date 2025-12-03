// --------------------------------------------------------------
// ------ DESAFIO DO TABULEIRO - "WAR" FASE 1 NIVEL NOVATO ------
// --------------------------------------------------------------
// OBJETIVO: CRIAR UM PROGRAMA PARA CADASTRAR TROPAS USANDO:
// - UMA STRUCT COM AS VARIAVEIS QUE IRAM ARMAZENAR OS DADOS CADASTRADOS...
// - USAR SWITCH COM LOOP DO...WHILE PARA PROPORCIONAR UM MENU INTERATIVO PARA OS USUARIO...
// - USAR LOOP E ESTRUTURAS IF...ELSE PARA EXIBIR OS DADOS CADASTRADOS...

// AS BIBLIOTECAS DAS FUNÇÕES USADAS NO CODIGO...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// DEFININDO AS CONSTANTES...
#define STRING 100
#define TOTAL 50

// CRIANDO MINHA STRUCT ONDE FICA OS DADOS CADASTRADOS...
    typedef struct {
     char nome[STRING];
     char cor[STRING];
     int tropa;
    } Territorio;

// CRIANDO A FUNÇÃO DE LIMPAR O BUFFER -> BOA PRATICA...
    void Limpar(){
        int a;
    while((a = getchar()) != '\n' && a != EOF);
    }

// INICIO DO MEU BLOCO DE CODIGO...
   int main() {

// DECLARANDO E ALOCANDO A MÉMORIA PARA MINHA STRUCT...

  Territorio *Territorios = malloc(TOTAL * sizeof(Territorio));

// DECLARANDO AS VARIAVEIS...
   int totalareas = 0;
   int opcao;

// INICIO DO MEU LOOP (DO...WHILE)...
 do {
// EXIBINDO O MENU PRINCIPAL DE OPÇÕES...
    printf("==================================================\n");
        printf("\t--- DESAFIO DO TABULEIRO - WAR ---\n");
    printf("==================================================\n");
        printf("1) - CADASTRAR TROPAS\n");
        printf("2) - VERIFICAR TERRITORIOS\n");
        printf("0) - SAIR\n");
    printf("==================================================\n");
        printf("Escolha sua Opção Desejada: ");
           scanf("%d", &opcao);
               Limpar();
                    system("clear");

// INICIALIZANDO MINHA SWITCH
    switch (opcao)
    {
        case 1: // CADASTRO DOS TERRITORIOS!
      
          printf("\n\n --- CADASTRO DE TERRITORIOS --- \n\n");

        // VERIFICAÇÃO PARA VER SE REALMENTE TEM ESPAÇO PARA MAIS CADASTROS...
        if(totalareas < TOTAL ){
          printf("Digite o Nome: ");
          fgets(Territorios[totalareas].nome, STRING, stdin);
        
          printf("Digite a Cor da Tropa(ex: Red, Yellow, Blue): ");
          fgets(Territorios[totalareas].cor, STRING, stdin);

          Territorios[totalareas].nome[strcspn(Territorios[totalareas].nome,"\n")] = '\0'; 
          Territorios[totalareas].cor[strcspn(Territorios[totalareas].cor,"\n")] = '\0';

          printf("Digite a Quantidade de Tropas: ");
            scanf("%d", &Territorios[totalareas].tropa);
              Limpar();
                totalareas++;

            printf("\nCadastro Realizado com \"Sucesso\"...\n");
        } else { // CASO A CONST NÃO POSSUI ESPAÇO AI A MENSAGEM...
            printf("Buffer já Atingiu a Capacidade Maxima!\n");
        }
          printf("\nPrecione Enter pra Continuar...\n");
            getchar();
               system("clear");
          break;
        
        case 2:
        // EXIBINDO OS CADASTROS REALIZADOS...
    printf("\n\n============================================\n");
            printf("\t --- \"Territorios - WAR\" ---\n");
    printf("============================================\n\n");
        // VERIFICANO O STATUS DA VARIAVEL...
        if (totalareas == 0 ){
            printf("Nenhum territorio Declarado...\n");
        } else { 
            for (int g = 0; g < totalareas; g++){ // LOOP PARA EXIBIR OS DADOS DA VARIAVEL...
               if ( Territorios[g].tropa <= 0 ){
                    continue;
        } // EXIBINDO OS DADOS CADASTRADOS...
            printf("--------------------------------------------\n");
            printf("\"Territorio - %d\"\n", g + 1);
            printf("--------------------------------------------\n");
            printf("Exercito Dominante: %s\n", Territorios[g].nome);
            printf("Cor do Exercito: %s\n", Territorios[g].cor);
            printf("Quantidade de Tropas: %d\n", Territorios[g].tropa);
        }  
            printf("--------------------------------------------\n");
            printf("\n");
        } 
        printf("\nPrecione Enter para Sair\n"); // RETORNA PARA O MENU PRINCIPAL AO CLICAR ENTER...
          getchar();
            system("clear");
        break;

        case 0: // OPÇÃO PARA SAIR E RETORNA PARA O MENU PRINCIPAL...
          printf("\n Saindo do Sistema...\n");
        break;
   
        default: // OPÇÃO PARA QUANDO A ENTRADA FOR INVALIDA...
          printf("Opção Invalida, Tente Novamente!");
            printf("\nPrecione Enter para Sair\n\n");
              getchar(); // RETORNA PARA O MENU PRINCIPAL...
  }
} while (opcao != 0); // LOOP COM A CONDIÇÃO PARA RODAR O PROGRAMA...

return 0; // RETORNA NADA
