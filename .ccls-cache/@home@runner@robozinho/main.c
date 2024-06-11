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
    
    int lInicio = 0;
    int cInicio = 0;
    int lPa = lInicio;
    int cPa = cInicio;
    int lFim = 1;
    int cFim = 4;
    int ObsC = 2;
    int ObsL = 1;
    mapa [lInicio][cInicio] = "I";
    mapa [lFim][cFim] = "F";
    mapa [ObsL][ObsC] = "O";  

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