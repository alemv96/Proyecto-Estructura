#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int size_Main_Memory(){
  system("cls");
  int size_MM;
    //falta validar.
    printf("Introduzca el tamano de la memoria principal\n");
    printf("1) 256 KB\n");
    printf("2) 512 KB\n");
    printf("3) 1 MB\n");
    printf("4) 2 MB\n");
    printf("5) 4 MB\n");
    printf("6) 8 MB\n");
    printf("7) 16 MB\n");
    printf("8) 32 MB\n");
    scanf("%d", &size_MM);

    switch (size_MM) {
      case 1: return pow(2 , 18);
      case 2: return pow(2 , 19);
      case 3: return pow(2 , 20);
      case 4: return pow(2 , 21);
      case 5: return pow(2 , 22);
      case 6: return pow(2 , 23);
      case 7: return pow(2 , 24);
      case 8: return pow(2 , 25);
    }
}
//funcion que me retorna el valor que el usuario escoja de la memoria cache.
int size_Cache_Memory(){
  system("cls");
  int size_MC;
  //falta validar;
  printf("Introduzca el tama~o de la memoria cache\n");
  printf("1) 64 B\n");
  printf("2) 128 B\n");
  printf("3) 256 B\n");
  printf("4) 512 B\n");
  printf("5) 1 kB\n");
  scanf("%d", &size_MC);

  switch (size_MC) {
    case 1: return pow(2 , 16);//recordar de cambiar el 16 a  6
    case 2: return pow(2 , 7);
    case 3: return pow(2 , 8);
    case 4: return pow(2 , 9);
    case 5: return pow(2 , 10);
  }
}
//funcion que me retorna cantidad de bloques
int size_Block_Memory(){

  system("cls");
  int size_Block;
    //falta validar.
    printf("Introduzca el tamano del bloque en bytes\n");
    printf("1) 2 B\n");
    printf("2) 4 B\n");
    printf("3) 8 B\n");
    printf("4) 16 B\n");
    printf("5) 32 B\n");
    scanf("%d", &size_Block);

    switch (size_Block) {
      case 1: return pow(2 , 1);
      case 2: return pow(2 , 2);
      case 3: return pow(2 , 3);
      case 4: return pow(2 , 4);
      case 5: return pow(2 , 5);
    }
}
//retorna valor del conjunto de la memoria.
int size_Set_Memory(){
  system("cls");

  int size_Track;//tamano del conjunto en bloques.
  //falta validar.
  printf("Introduzca el tama~o del conjunto en bloques \n");
  printf("1) 2 bloques\n");
  printf("2) 4 bloques\n");
  printf("3) 8 bloques\n");
  scanf("%d", &size_Track);

  switch (size_Track) {
    case 1: return pow (2 , 1);
    case 2: return pow (2 , 2);
    case 3: return pow (2 , 3);
  }
}

//funcion que me devolvera el tamano del conjunto de memoria.
int get_V_Set(int cacheValue , int track){//obtengo d.
  return cacheValue - track;
}

//funcion que me retorna el exponente de cada valor dado.
int get_Exponent_Value(int number){
  int exponent = 0;

    while (number != 1){
      number = number/2;
      exponent ++;
    }

  return exponent;
}

//funcion que me retorna la longitud de la etiqueta(TAG) en memoria.
int get_TAG_Value(int MM_Value , int line_Size , int words_Size){
  return MM_Value - line_Size - words_Size;
}
//funcion que rertorna el tamano del bloque.
int get_Line_Value(int MC_Exponent , int blocks_Size_Exp){
  return  MC_Exponent - blocks_Size_Exp;
}
