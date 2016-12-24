#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int cache_Size_Block(){
  system("cls");
  int size_Block , exitMenu;
  exitMenu = 0;

  do {
    printf("Aviso: Favor introducir un valor numerico.\n");
    printf("Introduzca el tamano del bloque en bytes\n");
    printf("1) 2 \n");
    printf("2) 4 \n");
    printf("3) 8 \n");
    printf("4) 16 \n");
    printf("5) 32 \n");
    printf("6) 64 \n");
    printf("7) 128 \n");
    scanf("%d", &size_Block );

      if (size_Block < 1 || size_Block > 7){
          printf("el valor que introdujo no es el correcto");
          system("pause");
          system("cls");
        }else exitMenu = 1;

  }while (exitMenu == 0);

    switch (size_Block) {
      case 1: return 2;
      case 2: return 4;
      case 3: return 8;
      case 4: return 16;
      case 5: return 32;
      case 6: return 64;
      case 7: return 128;
    }
}

int set_Quantity(){
  system("cls");
  int size_Set , exitMenu;
  exitMenu = 0;

  do{
    printf("Aviso: Favor introducir un valor numerico.\n");
    printf("Introduzca el tama~o del conjunto\n");
    printf("1) 2 conjuntos\n");
    printf("2) 4 conjuntos\n");
    printf("3) 8 conjuntos\n");
    printf("4) 16 conjuntos\n");
    scanf("%d", &size_Set);

      if (size_Set < 1 || size_Set > 4) {
          printf("el valor que introdujo no es el correcto");
          system("pause");
          system("cls");
      }else exitMenu = 1;

  }while(exitMenu == 0);

  switch (size_Set) {
    case 1: return 2;
    case 2: return 4;
    case 3: return 8;
    case 4: return 16;
  }

}

int replace_Politic(){
  system("cls");
  int option, exitMenu;
  exitMenu = 0;

  do{
    printf("Aviso: Favor introducir un valor numerico.\n");
    printf("introduzca la politica de remplazo que desea\n");
    printf("1) FIFO\n");
    printf("2) LFU\n");
    printf("3) RANDOM \n");
    scanf("%d", &option);

      if (option < 1 || option > 4) {
        printf("el valor que introdujo no es el correcto");
        system("pause");
        system("cls");
      }else exitMenu = 1;

  }while(exitMenu == 0);

  switch (option) {
    case 1 : return 1;//FIFO
    case 2 : return 2;//LFU
    case 3 : return 3;//RANDOM
  }

}

int get_Quantity_Sequence(){
  system("cls");
  int option , exitMenu;
  exitMenu = 0;

    do{
      printf("Aviso: Favor introducir un valor numerico.\n");
      printf("introduzca la cantidad de secuencias de direcciones\n");
      printf("(MAXIMO 20 SECUENCIAS)\n");
      scanf("%d" , &option);

        if (option > 20 || option < 1){
          printf("no pude introducir este valor, vuelva a intentarlo\n");
          system("pause");
          system("cls");
        }else exitMenu = 1;

    }while(exitMenu == 0);

  return option;
}

void Random_Replacement(int cache_Blocks , int set_Qtty , char sequence_Instuct[] , int quantity_Instruct/*faltan parametros*/){
  char cache_Matrix[cache_Blocks][set_Qtty];   int array_N = 0;

  //rellenare la matriz con "-"
    for (int rows = 0 ; rows < (cache_Blocks / set_Qtty) ; rows ++)
      for(int columns = 0 ; columns < set_Qtty ; columns ++)
        cache_Matrix[cache_Blocks][columns] = '-';

    while (array_N < quantity_Instruct){
      int conflict_Misses = 0; int hits = 0; int compulsory_Misses = 0;
      int capacity_Misses =0; int counter_Row = (cache_Blocks / set_Qtty)*(sequence_Instuct[array_N] % set_Qtty);
      int counter_Column = 0; int counter_Matrix = 0;

      if (counter_Matrix = 0 ){//posiciona los valores cuando todas las casillas estan vacias

        if (verify_Hits(sequence_Instuct[array_N] , cache_Matrix , cache_Blocks , counter_Row , set_Qtty) == 0){
          counter_Row += get_Rows_Displace(cache_Matrix , counter_Row , cache_Blocks , set_Qtty);
          counter_Column = get_Empty_Column(cache_Matrix , counter_Row , cache_Blocks , set_Qtty);
          cache_Matrix[counter_Row][counter_Column] = sequence_Instuct[array_N];
          counter_Matrix = verify_Space_Matrix(cache_Matrix , counter_Row , set_Qtty , cache_Blocks);
          compulsory_Misses ++;
        }else  hits ++;


      }else{//posiciona todos los valores cuando las casillas estan llenas

      }

      array_N ++;
    }
}

int verify_Space_Matrix(char cache_Matrix[][] , int counter_Row , int set_Qtty , int cache_Blocks){
  int counter_Column = 0; int booleano = 0; int exit_Counter = 0; int counter_Auxiliar = 0;

    do {

      if (cache_Matrix[counter_Row][counter_Column] == '-') exit_Counter = 1;
      else{
        counter_Auxiliar ++;
        counter_Column ++;
      }

      if (counter_Auxiliar == set_Qtty / cache_Blocks) booleano = 1;
      else{
        if (counter_Column == set_Qtty){
          counter_Column = 0;
          counter_Row ++ ;
        }
      }
    } while(exit_Counter != 1 && counter_Auxiliar < set_Quantity / cache_Blocks);

    return booleano;
}

//verifica si el valor que voy a insertar ya se encuentra dentro de la matriz.
int verify_Hits(char number_To_Compare , char cache_Matrix[][] ,int cache_Blocks, int counter_Row ,int set_Qtty){
  int counter_Column = 0; int booleano = 0; int verify_Hit = 0; int exit_Counter = 0;

    do {
      if (cache_Matrix[counter_Row][counter_Column] == number_To_Compare){
        verify_Hit = 1;
        booleano = 1;
      } else counter_Column ++;

      if (counter_Column == set_Qtty){
        counter_Column = 0;
        counter_Row ++;
      }

      exit_Counter ++ ;
  } while(cache_Matrix[counter_Row][counter_Column] != '-' || exit_Counter < cache_Blocks / set_Qtty || booleano == 0);
  //creo que tengo condiciones de mas, revisar!.
  return verify_Hit;
}

//me devuelve cuanto se desplaza una columna para colocar el valor que se indica. Solo funciona cuando se sabe que existen casillas vacias, de lo contrario sera ciclo infinito.
int get_Rows_Displace(char cache_Matrix[][] , int counter_Row , int cache_Blocks , int set_Qtty){
  int row_Displace = 0; int booleano = 0;

    while (counter_Column < set_Qtty && booleano == 0){
      if (cache_Matrix[counter_Row][counter_Column] == '-') booleano = 1;
      else  counter_Column ++;

      if (counter_Column == set_Qtty){
        counter_Column = 0;
        row_Displace ++;
      }
    }
  return row_Displace;
}

int get_Empty_Column(char cache_Matrix[][] , int counter_Row , int cache_Blocks , int set_Qtty){
  int counter_Column = 0; int booleano = 0;

    while (counter_Column < set_Qtty && booleano == 0){

      if (cache_Matrix[counter_Row][counter_Column] == '-') booleano = 1;
      else  counter_Column ++;

      if (counter_Column == set_Qtty && booleano == 0){
        counter_Column = 0;
        counter_Row ++;
      }
    }
  return counter_Column;
}
