// -----------------------------------------------------
// --- DESAFIO DO TABULEIRO "WAR" - FASE AVENTUREIRO ---
// -----------------------------------------------------
// OBJETIVO -> MODULARIZAR O CODIGO PARA UMA MENHOR EFICIENCIA..
// - USANDO FUNÇÕES E STRUCT
// - USANDO PONTEIROS PARA APONTAR PARA ESSAS FUNÇÕES OU STRUCT 
// - ALOCAÇÃO DINAMICA 

// AS BIBLIOTECAS DAS FUNÇÕES USADAS NO CODIGO...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// AS CONSTANTES...
#define STRING 50
#define TOTAL 50

// DEFININDO A STRUCT COM VARIAVEIS PARA CADA TERRITORIO...
    typedef struct {
     char nome[STRING];
     char cor[STRING];
     int tropa;
     int ataque;
     int defesa;
    } Territorio;

// FUNÇÃO COM A FUNÇÃO RAND() PARA GERAR NUMEROS ALEATORIOS PARA A BATALHA...
 
    void Ataques(Territorio *Atacante,Territorio *Defensor){
        Atacante-> ataque = rand() % 5 + 1;
        Defensor-> defesa = rand() % 5 + 1;
    }

// FUNÇÃO PARA LIMPAR AS ENTRADAS -> BOA PRATICA... 
    void Limpar(){
        int a;
    while((a = getchar()) != '\n' && a != EOF);
    }

// INICIALIZAÇÃO DO MEU MAIN...
   int main() {

// ALOCANDO A MEMORIA E DECLARANDO AS VARIAVEIS...
   Territorio *Territorios = (Territorio *) malloc(TOTAL * sizeof(Territorio));
  
   int totalareas = 0;
   int opcao;

// EXIBIÇAO DE MENU PRINCIPAL...
 do {

printf("==================================================\n");
printf("\t--- DESAFIO DO TABULEIRO - WAR ---\n");
printf("==================================================\n");
printf("1) - CADASTRAR TROPAS\n");
printf("2) - VERIFICAR TERRITORIOS\n");
printf("3) - BATALHAR ENTRE TROPAS\n");
printf("0) - SAIR\n");
printf("==================================================\n");
printf("Escolha sua Opção Desejada: ");

scanf("%d", &opcao);
  Limpar();
    system("clear");

// DECLARANDO A SWITCH()
    switch(opcao){

      case 1:
      // CADASTRO DOS TERRITORIOS!
        printf("\n\n --- CADASTRO DE TERRITORIOS --- \n\n");

        // VERIFICANDO SE MINHA CONSTANTE AINDA POSSUI ESPAÇO PARA ARMAZENAR MAIS UM TERRITORIO, SE NÃO PROSSEGUIR...
        if (totalareas < TOTAL ){
          printf("Digite o Nome: ");
          fgets(Territorios[totalareas].nome, STRING, stdin);

          printf("Digite a Cor da Tropa(ex: Red, Yellow, Blue): ");
          fgets(Territorios[totalareas].cor, STRING, stdin);

          Territorios[totalareas].nome[strcspn(Territorios[totalareas].nome,"\n")] = '\0';
          Territorios[totalareas].cor[strcspn(Territorios[totalareas].cor,"\n")] = '\0';

          printf("Digite a Quantidade de Tropas: ");
            scanf("%d", &Territorios[totalareas].tropa);
              Limpar();  // CHAMANDO FUNÇÃO PARA LIMPAR O BUFFER DO SCANF...
                totalareas++;  // INCREMENTANDO OS VALORES DE ENTRADA PARA A VARIAVEL...

            printf("\nCadastro Realizado com \"Sucesso\"...\n");
        } else {
            printf("Buffer já Atingiu a Capacidade Maxima!\n");
        }
          printf("\nPrecione Enter pra Continuar...\n");          
            getchar();
               system("clear");
        break;
        
        case 2:
     // EXIBIR A BIBLIOTECA DE TERRITORIOS CADASTRADOS...
    printf("\n\n============================================\n");
            printf("\t --- \"Territorios - WAR\" ---\n");
    printf("============================================\n\n");

    // VERIFICANDO SE POSSUI CADASTROS, SE SIM ENTÃO PROSSEGUIR EXIBINDO...
          if (totalareas == 0 ){
            printf("Nenhum territorio Declarado...\n");
          } else {
            for (int g = 0; g < totalareas; g++){
               if ( Territorios[g].tropa <= 0 ){
                    continue;
          } // EXIBINDO TUDOS OS TERRITORIOS AQUI...
            printf("--------------------------------------------\n");
            printf("\"Territorio - %d\"\n", g + 1);
            printf("--------------------------------------------\n");
            printf("Exercito Dominante: %s\n", Territorios[g].nome);
            printf("Cor do Exercito: %s\n", Territorios[g].cor);
            printf("Quantidade de Tropas: %d\n", Territorios[g].tropa);
          }  
            printf("--------------------------------------------\n");
            printf("\n");
          } // RETORNA PARA O MENU PRINCIPAL...
        printf("\nPrecione Enter para Sair\n");
          getchar();
            system("clear");
        break;

        case 3: // OPÇÃO DE BATALHAR...

  // DECLARANDO AS VARIAVEIS UTILIZADAS DENTRO DA FUNÇÃO...
      int a, c;
        int b;

  // MENU INICIAL USANDO LOOP (DO...WHILE)...
    do {

  // // VERIFICANDO SE A QUANTIDADE DE TERRITORIOS DA OK PARA PODE DISPUTAR...
  if ( totalareas < 2){
    printf("\nMenos que 2 Tropas Cadastrada para Batalhar!\n");
      printf("Cadastre suas Tropas para Batalhar com Adversarios!\n");
  break;
}  system("clear");

    printf("\n\n---------------------------------------------------------\n");
      printf("\t       *** \"MAPA MUNDO\" *** \n");
        printf("---------------------------------------------------------\n");

  int j = 0; // VARIAVEL DECLARADA PARA CONDIÇÃO...
 
    for (int i = 0; i < totalareas; i++) { 
        if (Territorios[i].tropa > 0) {  // ESSE BLOCO DE CODÍGO ATUALIZA O MAPA MUNDO...
            Territorios[j] = Territorios[i]; // CÓPIA A ALTERNATIVA VALIDA...
              j++;
        } // SE TROPA <= 0, NÃO CÓPIA, EFETIVAMENTE...
    } // ATUALIZA O TOTAL DE TERRITORIOS...
    totalareas = j; 

  // LOOP PARA EXIBIR OS TERRITORIOS CADASTRADOS...
  for (int i = 0; i < totalareas; i++) {
    if ( Territorios[i].tropa <= 0 ){
      continue;
  }
    printf("%d).(%s) com Exercito (%s) - Tropas: %d\n",
            i + 1,
            Territorios[i].nome,
            Territorios[i].cor,
            Territorios[i].tropa);
   
  }
    printf("-----------------------------------------------------------\n");

  // EXIBIR O MENU DE AÇÕES...
    printf("\n  --- MENU DE AÇÕES ---  \n");
      printf("1.BATALHAR \n");
        printf("0.SAIR \n");
          printf("Digite Sua Opção Aqui: ");
            scanf("%d", &b);

  // INICIALIZANDO A SWITCH DO MENU DE AÇÕES...
  switch (b){

  // OPÇÃO PARA SAIR PARA O MENU PRINCIPAL...
  case 1:
      // SE NÃO FOR VERDADEIRA ELA VAI PROSSEGUIR COM A BATALHA...
      printf("\nEscolha a Tropa que irá Atacar: ");
        scanf("%d", &a);
      printf("Escolha a Tropa que irá Defender: ");
        scanf("%d", &c);
          system("clear");

// VERIFICANDO A ENTRADAS...
    if( a < 1 || a > totalareas || c < 1 || c > totalareas ){
      printf("Opção Invalida!\n");
      break;
    } 
    system("clear");

// DECLARANDO OS PONTEIROS PARA AS ENTRADAS...
    Territorio *Atacante = &Territorios[a - 1];
      Territorio *Defensor = &Territorios[c - 1];

// CHAMANDO A FUNÇAO QUE SORTEA OS VALORES PARA BATALHA ENTRE TROPAS...
      Ataques(Atacante, Defensor);

// EXIBI OS RESULTADOS DA BATALHA ENTRE OS TERRITORIOS...
      printf("------------------------------------------------------\n");
              printf("\t *** \"Resultado da Batalha\" *** \n");
      printf("------------------------------------------------------\n");
              printf("Atacante (%s): %d |x| Defensor (%s): %d\n",
                      Territorios[a-1].nome, 
                        Atacante->ataque,

                      Territorios[c-1].nome,  
                        Defensor->defesa);

// ATUALIZA A TROPAS DO USUARIO APÓS AS BATALHAS...
  if ( Atacante->ataque > Defensor->defesa ){
      Atacante->tropa++;
      Defensor->tropa--;
    
  } else  if (Defensor->defesa > Atacante->ataque ){
      Atacante->tropa--;
      Defensor->tropa++;
  
   } else {
      Atacante->tropa-=2;
      Defensor->tropa+=2;
  }

  
// RETORNA PARA O MAPA MUNDO...
printf("\nPrecione Enter pra Batalhar Novamente...\n");
  getchar();
    Limpar();
      system("clear");
  break;


        case 0: // OPÇÃO PARA SAIR...
          system("clear");
        break;

        default: // CASO O USUARIO DIGITE UM VALOR INVALIDO...
          printf("Opção Invalida, Tente Novamente! \n");
        system("clear");
        break;
     }
    
  } while(b == 1); // LOOP COM UMA CODIÇÃO ONDE ELE SÓ EXECUTA SE A OPÇÃO FOR 1...
  break;

  // OPÇÃO PARA RETORNA PARA O MENU PRINCIPAL...
  printf("\nPrecione Enter pra Retornar ao Menu Principal...\n");
      getchar();
        system("clear");
  

        case 0: // OPÇÃO PARA SAIR...
          printf("\n Saindo do Sistema...\n");
        break;
   
        default: // CASO O USUARIO DIGITE UM VALOR INVALIDO...
          printf("Opção Invalida, Tente Novamente!");
            printf("\nPrecione Enter para Sair\n\n");
              getchar(); // CAPTURA O ENTER...
               break;
} 
} while( opcao != 0 ); // LOOP PARA RODAR O BLOCO DE CODIGO...


// LIBERANDO A MÉMORIA ALOCADA PARA A STRUCT...
free(Territorios);
Territorios = NULL;

if (Territorios == NULL){
    printf("Memoria Liberada com sucesso...\n"); // VAI EXIBIR O RESULTADO QUANDO A MEMORIA FOR LIBERADA...

  }
   return 0;
 }
