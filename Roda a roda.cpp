#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

//palavras

int main() {
  system("cls");
  setlocale(LC_ALL, "Portuguese");

  char palavra[3][17], letra, chute, lacuna[17], dica[17], palavras[3][17];
  int a,i,j, v,fim, cont, qtd, random, quant, valor,vitoria, jogador,pula, p1 = 0, p2 = 0, p3 = 0,compara;
  float premios, premioJoga[3], premio;
  //puxar palavra do txt
  fflush(stdout);
  FILE * palavraS;
  palavraS = fopen("Palavras.txt", "r");

  int caractere, quant_linhas;
  while ((caractere = fgetc(palavraS)) != EOF) {

    if (caractere == '\n') {
      quant_linhas++;
    }
  }
  srand(time(NULL));
  random = rand() % quant_linhas;

  fclose(palavraS);

  char line[256];
  // reabre o aqruivo
  palavraS = fopen("Palavras.txt", "r");

  i = 0;

  while (fgets(line, sizeof(line), palavraS)) {
    if (i == random) {

      char * vetor = strtok(line, ";");
      strcpy(dica, vetor);

      int cont = 0;
      qtd = 0;

      while (vetor != NULL) {
        if (cont == 1) {
          qtd = atoi(vetor);
        }
	
	
        //Determinar a posição da palavra 
        if (cont > 1) {
          if (cont == 2) {
            strcpy(palavras[0], vetor);

          }
          if (cont == 3) {
            strcpy(palavras[1], vetor);

          }
          if (cont == 4) {
            strcpy(palavras[2], vetor);

          }
        }

        cont++;
        //printf("%s", vetor,cont++); 
        vetor = strtok(NULL, ";");
      }
      break;

    } else {
      i++;
    }
  }  
  fclose(palavraS);

  //fazer a lacuna 
  int tamanho;

  int size = strlen(palavras[0]);
  char charada[size] = "";

  
  for (i = 0; i < strlen(palavras[0]); i++) {
    charada[i] = '_';
  }


  size = strlen(palavras[1]); 
  
  char charada2[size]= "";
  p2 = size > 2 ? 1 : 0;

  
  for (i = 0; i < strlen(palavras[1]); i++) {
    charada2[i] = '_';
  	}


  	size = strlen(palavras[2]);
	p3 = size > 2 ? 1 : 0;
  char charada3[size] = "";
  for (i = 0; i < strlen(palavras[2]); i++) {
    charada3[i] = '_';
	  }
	
  premios = 0;
 
  fflush(stdout);

    cont=0;
 jogador=1;
  do {
	vitoria= strlen(palavras[0])+strlen(palavras[1])+strlen(palavras[2]);
    //Premios//
    
	FILE * premioS;
    premioS = fopen("Premios.txt", "r");

    quant = 0;
    while ((valor = fgetc(premioS)) != EOF) {

      if (valor == '\n') {
        quant++;
      }
    }
    srand(time(NULL));
    random = rand() % quant;

    fclose(premioS);

    premioS = fopen("Premios.txt", "r");

    j = 0;
    while (fgets(line, sizeof(line), premioS)) {
      if (j == random) {

        char * vetor = strtok(line, "");
        premio = atof(vetor);
        break;
      } else {
        j++;
      }
    }
	

	if (premio >1){
    //tela do jogo   
    printf("A  PALAVRA ESTÁ ASSOCIADA COM:%s.\n", dica);
	printf("VEZ DO JOGADOR NUMERO  %d\n", jogador);    
    printf("%20s\n",  charada);
   
    if(p2  == 1){
		printf("%20s\n", charada2);
	}    
   	if(p3 == 1){
	   printf("%20s\n", charada3);
	}
   		
    printf("\n");

    printf("%-20s", "jogador1");
    printf("%-20s", "jogador2");
    printf("%-20s", "jogador3\n");
    printf("%-10s", "=================================================================  \n");
 
    printf("R$%-18.2f", premioJoga[0]);
     printf("R$%-18.2f", premioJoga[1]);
    printf("R$%-18.2f \n", premioJoga[2]);
  
	
	printf("\n");
    printf("\n");
    printf("Valendo R$%-10.2f ", premio);
  	    //ler o chute//	
    printf("\nDigite uma letra ");
    
	scanf("%s", & letra);
   letra=toupper(letra);
	}

	if (premio == 0){
		
		printf("%20s"," PASSOU A VEZ ");
			jogador++;
			jogador++;
			Sleep(3000);
			if(jogador>3 ){
				jogador=1;
			
			
			}
	}
	if(premio ==-1){		
		printf("%20s"," PERDEU TUDO ");
		
			premioJoga[jogador-1]=0;
			if(premioJoga[jogador-1]==0){
			jogador++;
			jogador++;
			Sleep(3000);
			}
			if(jogador>3 ){
				jogador=1;
					
			}
	}	
	// comparar letras com a palavra  
     j=0;
	 v=0;
    	for (int a = 0; a < strlen(palavras[0]); a++) {
        if (palavras[0][a] == letra) {
          charada[a] = letra;
          	j++;
    		cont++;
			v++;
			}
    	}
		for (int a = 0; a < strlen(palavras[1]); a++){ 
	    if (palavras[1][a] == letra) {
          charada2[a] = letra;
          	j++;
			cont++;
			v++;
			}
        }
		for (int a = 0; a < strlen(palavras[2]); a++) {
        if (palavras[2][a] == letra) {
          charada3[a] = letra;
         	j++;
    		cont++;
			v++;
			}	
		}
   		//somando os premios 
       	if (j>=1){
      	premioJoga[jogador-1]=premioJoga[jogador-1]+(premio*j); 
	 
	  }
		if (j==0){
			jogador++;
			if (jogador >=4 ){
				jogador=1;
			}
		}
		system("cls");
				vitoria=vitoria-v;
			
	

 	

  } while (vitoria > 3);
	//fazer telas de fim de jogo	
	for (fim =0;fim<4;fim++)	
	Sleep(2000);
	
	
	
	printf("fim de jogo");
	
	
}
