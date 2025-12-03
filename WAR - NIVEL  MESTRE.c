// -----------------------------------------------------
// --- DESAFIO DO TABULEIRO -"WAR" NIVEL AVENTUREIRO ---
// -----------------------------------------------------
// OBJETIVO -> MODULARIZAÇÃO DO CODIGO PARA UMA MELHOR PERFORMACE:
//
// - MODULARIZAR TODO O CODIGO USANDO FUNÇÕES
// - CRIAR UM VETOR DE MISSÕES
// - USAR A FUNÇÃO RAND() PARA SORTEAR AS MISSÕES PARA OS USÚARIOS
// - ARMAZENAR OS DADOS USANDO AS FUNÇÕES MALLOC() OU CALLOC()
// - CRIAR UM OPÇÃO PARA VERIFICAR AS CONQUISTAS
// - ATUALIZAR OS TERRITORIOS PARA OS USÚARIOS
// - LIBERAÇÃO DA MEMORIA ALOCADA -> "BOA PRATICA"

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

// DECLARANDO AS FUNÇÕES...
  void Limpar();
  void Clear();
  void Ataques(Territorio *Atacante,Territorio *Defensor);
  void ExibirMenuPrincipal(int *opcao);
  void CadastrarTropas( Territorio *Territorios, int *areas);
  void ExibirCadastros( const Territorio *territorios, int *totalareas);
  void LiberarMemoria( Territorio *Territorios,char *Destino);
  void Batalhar( Territorio * Territorios, int *totalareas, char *Destino, char Missoes[][STRING], int *Concluidas, int *Total);
  int VerificarMissao(char *Destino, Territorio *Territorios, int* Total, int* totalareas, int *Concluidas, int f, Territorio *Defensor, Territorio *Atacante);
  
// INICIALIZAÇÃO
  int main() {

// ALOCAÇÃO DE MÉMORIA PARA A STRUCT->(TERRITORIO)
  Territorio *Territorios = (Territorio *) malloc(TOTAL * sizeof(Territorio));

// ALOCANDO A MÉMORIA PARA MINHA VARIAVEL...
  char *Destino = malloc(STRING);
    if (!Destino) { // VERIFICANDO CASO A ALOCAÇÃO DE MÉMORIA PARA A MINHA VARIAVEL DE ERRO...
      printf("Erro ao alocar memória!\n");
        return 1;
  }

// DECLARANDO AS VARIAVEIS DENTRO DO (MAIN)...
  char Missoes[][STRING] = 
        { "Derrote 1 Territorio"
        , "Ganhe 3 Ataques"
        , "Ataque e Perca 1 Tropa"
        , "Defenda 3x"
        , "Elimine Todos os Inimigos" 
        };
  int Concluidas[TOTAL] = {0};
    int Total = 5;
      int totalareas = 0;
        int opcao;


// EXIBIÇAO DE MENU PRINCIPAL...
 do {
  ExibirMenuPrincipal(&opcao);
      Clear();

// DECLARANDO A SWITCH()
    switch(opcao){

      case 1: // CADASTRO DOS TERRITORIOS...
            CadastrarTropas(Territorios, &totalareas);
        Clear();
      break;
        
      case 2: // TERRITORIOS CADASTRADOS...
            ExibirCadastros(Territorios, &totalareas);
        Clear();
      break;

      case 3: // BATALHAR PARA COMPLETAR AS MISSÕES...
            Batalhar(Territorios, &totalareas, Destino, Missoes, Concluidas, &Total);
        Clear();
      break;

      case 0: // OPÇÃO SAIR...
                // LIBERANDO A MEMORIA...
        printf("\n Saindo do Sistema...\n");
      break;
   
      default: // FECHANDO CODIGO...
        printf("Opção Invalida, Tente Novamente!");
          printf("\nPrecione Enter para Sair\n\n");
            getchar(); 
        }

      } while( opcao != 0 ); // LOOP COM A CONDIÇÃO PARA RODAR O PROGRAMA...

      LiberarMemoria(Territorios, Destino); // CHAMANDO A FUNÇÃO PARA LIBERAR AS MÉMORIAS QUE FORAM ALOCADAS...
  
   return 0;
}

// FUNÇÃO DO TIPO INTEIRO ONDE REALIZA O SORTEIO DAS MISSÕES PARA OS PLAYER... 
  int AtribuirMissao(char *Destino, char Missoes[][STRING], int TotalMissoes, int Concluidas[], int* f){
     
  do { // LOOP PARA AS MISSÕES SEMPRE VOLTAR ALEATORIA
      *f = rand() % TotalMissoes;
       } while(Concluidas[*f] == 1); 
      // FUNÇÃO DA PARA COPIA AS MISSÕES PARA O PLAYER...
       strcpy(Destino,Missoes[*f]);
      // RETORNA A MISSÃO QUE FOI EXECUTADA...
       return *f;
   }

// FUNÇÃO PARA LIMPAR AS ENTRADAS -> BOA PRATICA... 
  void Limpar(){
  int a;
    while((a = getchar()) != '\n' && a != EOF);
  }

// FUNÇÃO COM A FUNÇÃO RAND() PARA GERAR NUMEROS ALEATORIOS PARA A BATALHA...
    void Ataques(Territorio *Atacante,Territorio *Defensor){ 
      srand(time(NULL)); // FUNÇÃO QUE VAI FAZER OS NUMEROS RETORNAREM ALEATORIOS...
        Atacante-> ataque = rand() % 5 + 1; // PONTEIROS PARA DEFINIR AS VARIAVEIS DO RAND()...
        Defensor-> defesa = rand() % 5 + 1;
}
// FUNÇÃO DE LIMPAR A TELA DO TERMINAL APÓS ALGUMA AÇÃO -> OBJETIVO - EVITAR MUITA INFORMAÇÃO NA TELA...
  void Clear(){
    system("clear");
  }

// FUNÇÃO DE OPÇÃO DE ENTRADAS PARA RESPECTIVAS AÇÕES...
    void ExibirMenuPrincipal(int *opcao){
      printf("==================================================\n");
printf("\t--- DESAFIO DO TABULEIRO - WAR ---\n");
printf("==================================================\n");
printf("1) - CADASTRAR TROPAS\n");
printf("2) - VERIFICAR TERRITORIOS\n");
printf("3) - BATALHAR ENTRE TROPAS\n");
printf("0) - SAIR\n");
printf("==================================================\n");
printf("Escolha sua Opção Desejada: ");
  scanf("%d", opcao);
    getchar();
}

// FUNÇÃO DE CADASTRO DOS TERRITORIOS...
    void CadastrarTropas( Territorio *Territorios, int *totalareas)
    {
      // CADASTRO DOS TERRITORIOS!
        printf("\n\n --- CADASTRO DE TERRITORIOS --- \n\n");

      // VERIFICANDO SE MINHA CONSTANTE AINDA POSSUI ESPAÇO PARA ARMAZENAR MAIS UM TERRITORIO, SE NÃO PROSSEGUIR...
        if(*totalareas < TOTAL ){
          printf("Digite o Nome: ");
          fgets(Territorios[*totalareas].nome, STRING, stdin);

          printf("Digite a Cor da Tropa(ex: Red, Yellow, Blue): ");
          fgets(Territorios[*totalareas].cor, STRING, stdin);

          Territorios[*totalareas].nome[strcspn(Territorios[*totalareas].nome,"\n")] = '\0';
          Territorios[*totalareas].cor[strcspn(Territorios[*totalareas].cor,"\n")] = '\0';

          printf("Digite a Quantidade de Tropas: ");
            scanf("%d", &Territorios[*totalareas].tropa);
              Limpar(); // CHAMANDO FUNÇÃO PARA LIMPAR O BUFFER DO SCANF...
                (*totalareas)++;  // INCREMENTANDO OS VALORES DE ENTRADA PARA A VARIAVEL...
          
            printf("\nCadastro Realizado com \"Sucesso\"...\n");
        } else {
            printf("Buffer já Atingiu a Capacidade Maxima!\n");
        }
          printf("\nPrecione Enter pra Continuar...\n");
            getchar();
        }

      // EXIBIR A BIBLIOTECA DE TERRITORIOS CADASTRADOS...
        void ExibirCadastros(const Territorio *Territorios, int *totalareas){
          
            printf("\n\n============================================\n");
            printf("\t --- \"Territorios - WAR\" ---\n");
            printf("============================================\n\n");

      // VERIFICANDO SE POSSUI CADASTROS, SE SIM ENTÃO PROSSEGUIR EXIBINDO...
        if (*totalareas == 0 ){
            printf("Nenhum territorio Declarado...\n");
           } else {
            for (int g = 0; g < *totalareas; g++){
              if ( Territorios[g].tropa <= 0 ){
                  continue;
           }
      // EXIBINDO TUDOS OS TERRITORIOS AQUI...
            printf("--------------------------------------------\n");
            printf("\"Territorio - %d\"\n", g + 1);
            printf("--------------------------------------------\n");
            printf("Exercito Dominante: %s\n", Territorios[g].nome);
            printf("Cor do Exercito: %s\n", Territorios[g].cor);
            printf("Quantidade de Tropas: %d\n", Territorios[g].tropa);
            }
          }  
            printf("--------------------------------------------\n");
            printf("\n");
      // RETORNA PARA O MENU PRINCIPAL...
        printf("\nPrecione Enter para Sair\n");
          getchar();
  }
      // FUNÇÃO DE BATALHAR / MISSÕES... 
        void Batalhar( Territorio * Territorios, int *totalareas, char *Destino, char Missoes[][STRING], int *Concluidas, int *Total){
            srand(time(NULL));

      // DECLARANDO AS VARIAVEIS UTILIZADAS DENTRO DA FUNÇÃO...
          int a, c, b;
            int f;
              int MissaoAtiva = 0; 
                char Conquistadores[TOTAL][STRING];
        
      // MENU INICIAL USANDO LOOP (DO...WHILE)...
    do {
        if ( *totalareas < 2){ // VERIFICANDO SE A QUANTIDADE DE TERRITORIOS DA OK PARA PODE DISPUTAR...
          printf("\nMenos que 2 Tropas Cadastrada para Batalhar!\n");
            printf("Cadastre suas Tropas para Batalhar com Adversarios!\n");
        break;
      // SE SIM ELE CONTINUA PARA EXIBIR O MAPA MUNDO...
      } else {
printf("\n\n---------------------------------------------------------\n");
  printf("\t       *** \"MAPA MUNDO\" *** \n");
    printf("---------------------------------------------------------\n");

    int j = 0; // VARIAVEL DECLARADA PARA CONDIÇÃO...
 
    for (int i = 0; i < *totalareas; i++) { 
        if (Territorios[i].tropa > 0) {  // ESSE BLOCO DE CODÍGO ATUALIZA O MAPA MUNDO...
            Territorios[j] = Territorios[i]; // CÓPIA A ALTERNATIVA VALIDA...
              j++;
        } // SE TROPA <= 0, NÃO CÓPIA, EFETIVAMENTE...
    } // ATUALIZA O TOTAL DE TERRITORIOS...
  *totalareas = j; 

      // LOOP PARA EXIBIR OS TERRITORIOS CADASTRADOS...
for (int i = 0; i < *totalareas; i++) {
    printf("%d).(%s) com Exercito (%s) - Tropas: %d\n",
            i + 1,
            Territorios[i].nome,
            Territorios[i].cor,
            Territorios[i].tropa);
 }
  printf("---------------------------------------------------------\n\n");

      // EXIBIR AS MISSÕES PARA O PLAYER...
  printf("\t   --- MISSÕES ---   \n");
  
      // USANDO UMA CONDIÇÃO PARA VERIFICAR MINHAS MISSÕES ANTES DE EXIBIR PARA O PLAYER... 
  if (!MissaoAtiva) {
   f = AtribuirMissao(Destino, Missoes, *Total, Concluidas, &f);
      MissaoAtiva = 1; // QUANDO ELA FOR 1 AI ELA EXIBIR A PROXIMA...
}
      // PRINTA AS MISSÕES CASO FOR TRUE...
  printf(" --- Sua Missão: \"%s\" ---\n", Destino);

      // EXIBIR O MENU DE AÇÕES...
        printf("\n --- MENU DE AÇÕES --- \n");
          printf("1.BATALHAR \n");
            printf("2.VERIFICAR CONQUISTAS \n");
              printf("0.SAIR \n");
            printf("Digite sua opção aqui: ");
              scanf("%d", &b);
                Limpar();
                  Clear();

      // INICIALIZANDO A SWITCH DO MENU DE AÇÕES...
      } switch (b){

      // OPÇÃO DE SAIR DO MENU DE AÇÕES...
    case 0:
      printf("Precione Enter para Sair...");
        getchar();
          Clear();
    return;
  
      // OPÇÃO DE VISUALIZAR AS CONQUISTAS DO MENU DE AÇÕES...
    case 2:
          if ( *Total == 0){ // CODIÇÃO PARA VERIFICAR SE REALMENTE O PLAYER POSSUI ALGUMA CONQUISTA...
            printf("Nenhuma Conquista por Enquanto...");
                return;
          } else {
            printf("---------------------------\n");
              printf("   --- CONQUISTAS --- \n");
            printf("---------------------------\n\n");
    for (int i = 0; i < *Total; i++) { // LOOP PARA EXBIR A MISSÕES DOS PLAYER...
      if (Concluidas[i] == 1) {   
        
        printf(" --- Missão Concluída - %d --- \n", i+1);
          printf("- - - - - - - - - - - - - - - - - -\n");
            printf(" Objetivo:\"%s\"\n", Missoes[i]);
          printf(" Conquistador: (%s)\n", Conquistadores[i]);
        printf("PARABÉNS POR SUA CONQUISTA!\n");
        printf("- - - - - - - - - - - - - - - - - -\n");
    }
  }
}     // RETORNA PARA O MENU DE BATALHA AO CLICAR ENTER...
          printf("\nPrecione Enter pra Retornar ao Menu de Batalha...\n");
            getchar();
              Clear();
    continue; // RETORNA PARA O MENU DE AÇÕES...

      // ENTRADAS PARA ESCOLHER QUEM VAI ATACAR E QUEM VAI DEFENDER NA DISPUTA...
    case 1:
      printf("\nEscolha a Tropa que irá Atacar: ");
        scanf("%d", &a);
      printf("Escolha a Tropa que irá Defender: ");
        scanf("%d", &c);
            Limpar();
    break;

    default:
      printf("Opção inválida!\n");
        printf("Pressione Enter...\n");
          getchar();
    return; // VOLTA PRO MENU
    }


      // VERIFICA O VALOR DA ENTRADA!
    if( a < 1 || a > *totalareas || c < 1 || c > *totalareas ){
        printf("Opção Invalida!\n");
          printf("Pressione Enter...\n");
            getchar();
    return; // VOLTA PRO MENU
}

      // DECLARANDO OS PONTEIROS DA FUNÇÃO -> (ATAQUES) QUE ESTÃO APONTANDO PARA A STRUCT -> (TERRITORIO) PARA AS ENTRADAS...
        Territorio *Atacante = &Territorios[a - 1];
          Territorio *Defensor = &Territorios[c - 1];

      // CHAMANDO A FUNÇÃO(ATAQUES) - PARA GERAR O VALORES ALEATORIOS...
        Ataques(Atacante, Defensor);

      // EXIBIR O RESULTADOS DA BATALHA APÓS O CONFLITO...
         printf("------------------------------------------------------\n");
              printf("\t *** \"Resultado da Batalha\" *** \n");
         printf("------------------------------------------------------\n");
              printf("Atacante (%s): %d | Defensor (%s): %d\n",
                      Territorios[a-1].nome, 
                        Atacante->ataque,

                      Territorios[c-1].nome,  
                        Defensor->defesa);
        
      // FAZENDO A INCREMENTAÇÃO E DECREMETAÇÃO PARA ATUALIZAR OS TERRITORIOS APÓS BATALHAREM...
          if ( Atacante->ataque > Defensor->defesa ){ // CASO O ATACANTE VENÇA...
            printf("\"VITORIA\" do Atacante - (%s)\n",Territorios[a-1].nome);
              Atacante->tropa++;
                Defensor->tropa--;
          } else  if (Defensor->defesa > Atacante->ataque ){     // NO CASO SE O DEFENSOR DEFENDER...
            printf("\"VITORIA\" do Defensor - (%s)\n",Territorios[c-1].nome);
              Atacante->tropa--;
                Defensor->tropa++;
          } else {    // EM CASO DE EMPATE...
            printf("\"EMPATADO\" Defensor - (%s) ganhou 2 Tropas do Atacante! - (%s)\n",Territorios[c-1].nome, Territorios[a-1].nome);
              Atacante->tropa = Atacante->tropa -=2;
                Defensor->tropa = Defensor->tropa +=2;
          } 

      // FUNÇÃO PARA VERIFICAR SE A MISSÕES REALMENTE FORAM COMPLETADAS...
          if (VerificarMissao( Destino, Territorios, Total, totalareas, Concluidas, f, Defensor, Atacante )) {
                printf("\n\n*** MISSÃO CONCLUÍDA! ***\n");
                  Concluidas[f] = 1;
                    (*Total)++;

              strcpy(Conquistadores[f], Atacante->nome);
                MissaoAtiva = 0;
        } continue;

      //LOOP PARA RETORNA PARA O MAPA MUNDO ENQUANTO A CONDIÇÃO FOR TRUE...
        } while(1);

      // RETORNA PARA O MENU PRINCIPAL... 
          printf("\nPrecione Enter pra Retornar ao Menu Principal...\n");
            getchar();
        }    
  
      // FUNÇÃO PARA VERIFICAR AS MISSÕES APÓS AS BATALHA...
        int VerificarMissao(char *Destino, Territorio *Territorios, int* Total, int* totalareas, int *Concluidas, int f, Territorio *Defensor, Territorio *Atacante){
        {
    
      // MISSÃO: "DERROTE 1 TERRITORIO"
        if (strcmp(Destino, "Derrote 1 Territorio") == 0) // COMPARA USANDO A FUNÇÃO(strcmp) E RETORNA UM VALOR INTEIRO...
        {  
      // LOOP PARA É COLETANDO OS RESULTADOS...
        for (int i = 0; i < *totalareas; i++) {
        if (Territorios[i].tropa <= 0 && i != f) {  
              Concluidas[f] = 1;
        return 1;
        }// AQUI QUANDO ALGUM VOCÊ ELIMINAR UM TERRITORIO ELE RETORNA CONQUISTA...
      }
        return 0;
    }

    // MISSÃO: "GANHE 3 ATAQUES"
    if (strcmp(Destino, "Ganhe 3 Ataques") == 0) // COMPARA USANDO A FUNÇÃO(strcmp) E RETORNA UM VALOR INTEIRO...
    {
        static int ataques = 0; // DEIXA O VALOR DA INT ESTATICO PARA NÃO MUDAR MSM QUE EXECUTE A BATALHA...
        
        for (int i = 0; i < *totalareas; i++) {
            if (Atacante->ataque > Defensor->defesa) { // COMPARAÇÃO 
                ataques++; // INCREMENTA TODA VIDA QUE FOR VERDADEIRA CONDIÇÃO...
            }
        }
        if ( ataques >= 3){ // CASO A CONDIÇÃO FOR TRUE, ELE VAI MARCA A MISSÃO COMO CONCLUIDA E RETORNA 1...
              Concluidas[f] = 1;
                return 1;
        }
        return 0;
    }

    // MISSÃO: "ATAQUE E PERCA 1 TROPA"
    if (strcmp(Destino, "Ataque e Perca 1 Tropa") == 0) // COMPARA USANDO A FUNÇÃO(strcmp) E RETORNA UM VALOR INTEIRO...
    {
        static int Destruidos = 0; // DEIXA O VALOR DA INT ESTATICO PARA NÃO MUDAR MSM QUE EXECUTE A BATALHA...
        
        for (int i = 0; i < *totalareas; i++) {
            if (Atacante->ataque < Defensor->defesa) { // COMPARAÇÃO
                Destruidos++; // INCREMENTA TODA VIDA QUE FOR VERDADEIRA CONDIÇÃO...
            }
        }
            if (Destruidos >= 1) {  // CASO A CONDIÇÃO FOR TRUE, ELE VAI MARCA A MISSÃO COMO CONCLUIDA E RETORNA 1...
              Concluidas[f] = 1;
                return 1;
        }

        return 0;
    }

    // MISSÃO: "DEFENDA 3X"
    if (strcmp(Destino, "Defenda 3x") == 0) // COMPARA USANDO A FUNÇÃO(strcmp) E RETORNA UM VALOR INTEIRO...
    {
        static int defesa = 0;
       
        for (int i = 0; i < *totalareas; i++) {
            if (Defensor->defesa > Atacante->ataque) { // QUANDO O PLAYER DEFENDER 3X OS ATAQUES ELE INCREMENTA...
                  defesa++;  // INCREMENTA QUANDO O DEFENSOR DEFENDER 3X...
            }
        }  // 
            if ( defesa >= 3){  // CASO O DEFENSOR DEFENDER 3X, ELE VAI MARCA A MISSÃO COMO CONCLUIDA E RETORNA 1...
              Concluidas[f] = 1;
          return 1;
        }
        return 0;
    }

    // MISSÃO: "ELIKMINE TODOS OS INIMIGOS"
    if (strcmp(Destino, "Elimine Todos os Inimigos") == 0) // COMPARA USANDO A FUNÇÃO(strcmp) E RETORNA UM VALOR INTEIRO...
    {
        int territoriosVivos = 0;

        for (int i = 0; i < *totalareas; i++) {   
        if (Territorios[i].tropa > 0) {  // NESSA CONDIÇÃO É TRUE QUANDO TIVER UM NUMERO DE TROPAS ACIMA DE ZERO...
            territoriosVivos++;  // INCREMENTA QUANDO FOR VERDADEIRA CONDIÇÃO...
        }
      }

    // SE SO RESTA 1 TERRITORIO CONQUISTA CONCLUIDA...
    if (territoriosVivos == 1 && Atacante->tropa > 0) {  
        Concluidas[f] = 1;  // CASO A CONDIÇÃO FOR TRUE, ELE VAI MARCA A MISSÃO COMO CONCLUIDA E RETORNA 1...
      return 1;
      }
    return 0;
  }      
  return 0; // CASO A MISSÃO NÃO EXISTIR...
  }
} 

   
    // FUNÇÃO PARA LIBERAR TODA A MÉMORIA QUE FOI ALOCADA PARA AS VARIAVEIS...
      void LiberarMemoria(Territorio *Territorios,char *Destino){