#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Definição de limites da matriz.

#define TAMANHO 5

int main(void) {


  int l = 0, c = 0;
  char controle = 'x';
  char robo = 'x';
  char* mapa [TAMANHO] [TAMANHO];
  
  //Preenchimento da matriz com caracteres.
  
  for (l = 0; l < TAMANHO; l++){
    for (c = 0; c < TAMANHO; c++){
      mapa [l] [c] = "#";
    }
  }

  //Definindo o ponto incial, final e obstáculo.
    
    int lInicio = 0;                  //Define a linha da posição inicial
    int cInicio = 0;                  //Define a coluna da posição inicial
    int lPa = lInicio;                //Define a linha da posição atual do 'robô'
    int cPa = cInicio;                //Define a coluna da posição atual do 'robô'
    int lFim = 1;                     //Define a linha posição final
    int cFim = 4;                     //Define a coluna posição final
    int ObsC = 2;                     //Define a coluna do obstáculo
    int ObsL = 1;                     //Define a linha do obstáculo
    mapa [lInicio][cInicio] = "I";    //Posiciona o caractere de início no mapa
    mapa [lFim][cFim] = "F";          //Posiciona o caractere de final do mapa
    mapa [ObsL][ObsC] = "O";          //Posiciona o caractere de obstáculo do mapa

  //Apresentação inicial do mapa
  
  for (l = 0; l < TAMANHO; l++){
    for (c = 0; c < TAMANHO; c++){
      printf("%s | ", mapa[l][c]);
    }
    printf ("\n");
  }

  //Movimentação do robô
  
  do{

    if (mapa [lPa] [cPa] != "F"){

      //Diagonal inferior direita.
      if (lPa < lFim && cPa < cFim ){
        lPa++;
        cPa++;
        if (mapa [lPa][cPa] == "O"){
          if (lFim > 2){
            lPa--;
          }
          else{
            lPa--;
          }
        }
      }
      //Diagonal inferior esquerda.
      else if(lPa < lFim && cPa > cFim){
        lPa++;
        cPa--;
        if (mapa [lPa][cPa] == "O"){
          if (lFim > 2){
            cPa++;
          }
          else{
            lPa--;
          }
        }
      }
      //Diagonal superior esquerda.
      else if(lPa > lFim && cPa > cFim){
        lPa--;
         cPa--;
        if (mapa [lPa][cPa] == "O"){
          cPa++;
        }
      }
      //Diagonal superior direita.
      else if(lPa > lFim && cPa < cFim){
        lPa--;
        cPa++;
        if (mapa [lPa][cPa] == "O"){
          cPa--;
        }
      }
      //Baixo.
      else if(lPa < lFim && cPa == cFim){
        lPa++;
        if (mapa [lPa][cPa] == "O"){
          cPa++;
        }
      }
      //Cima.
      else if(lPa > lFim && cPa == cFim){
        lPa--;
        if (mapa [lPa][cPa] == "O"){
          cPa++;
        }
      }
      //Direita.
      else if(lPa == lFim && cPa < cFim){
        cPa++;
        if (mapa [lPa][cPa] == "O"){
          lPa++;
        }
      }
      //Esquerda.
      else if(lPa == lFim  && cPa > cFim){
        cPa--;
        if (mapa [lPa][cPa] == "O"){
          lPa++;
        }
      }
      //Se a posição atual for diferente de "F", printa "Passo:" e o mapa.
      if (mapa [lPa] [cPa] != "F"){
        mapa [lPa] [cPa] = "x";
        printf ("\nPasso: \n\n");
        for (l = 0; l < TAMANHO; l++){
          for (c = 0; c < TAMANHO; c++){
            printf("%s | ", mapa[l][c]);
          }
          printf ("\n");
        }
        printf ("\n");
      }
      //Senão, printa "chegou".
      else{
        printf("Chegou.");
      }
    }
  }while (lPa != lFim || cPa != cFim);
}