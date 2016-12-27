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

  char cache_Matrix[cache_Blocks / set_Qtty][set_Qtty];   int array_N = 0;  int conflict_Misses = 0; int hits = 0; int compulsory_Misses = 0;
  int capacity_Misses =0; int counter_Column = 0; int empty_Boxes = 1; int exit_Counter = 0; int counter_Auxiliar = 0; int counter_Row;
  int verify_Matrix = 0;   srand (time(NULL));


//revisar porque la matriz no agarra y es como si estuviera en null.
  //rellenare la matriz con "-"
    for (int rows = 0 ; rows < (cache_Blocks / set_Qtty) ; rows ++)
      for(int columns = 0 ; columns < set_Qtty ; columns ++)
        cache_Matrix[rows][columns] = '-';

        for(int row = 0 ; row < cache_Blocks / set_Qtty ; row ++){
          for(int column = 0 ; column < set_Qtty ; column ++){
            printf("[ %c ]", cache_Matrix[row][column]);
          }
          printf("\n");
        }
        system("pause");

    /*printf(" %c ", cache_Matrix[0][0]);
    system("pause");

    printf("anadi los valores a la matriz - - - ");
    system("pause");*/

    while (array_N < quantity_Instruct){
    int counter = 0; int exit_Value = 0;
    counter_Row = (cache_Blocks / set_Qtty)*(sequence_Instuct[array_N] % set_Qtty);
    printf("entre al ciclo");
    system("pause");

      while(counter < cache_Blocks / set_Qtty && exit_Value == 0){
         system("pause");
          if (sequence_Instuct[array_N] == cache_Matrix[counter_Row][counter_Column]){
            hits ++;
            exit_Value = 1;
          }
          else counter_Column ++;

          if (counter_Column == set_Qtty){
            counter_Row ++;
            counter_Column = 0;
          }
          counter ++;
      }

      if (exit_Value == 0){//quiere decir que no consiguio ningun valor que se repitiera, por lo tanto puede ser colocado.
        counter_Row = (cache_Blocks / set_Qtty)*(sequence_Instuct[array_N] % set_Qtty);
        counter_Column = 0;
        counter = 0;

        //para entrar en el ciclo pregunto si hay casillas disponibles.
        if(verify_Matrix = 0){
          while(counter < cache_Blocks / set_Qtty){
            if (cache_Matrix[counter_Row][counter_Column] == '-'){
                cache_Matrix[counter_Row][counter_Column] = sequence_Instuct[array_N];
                compulsory_Misses ++;
                break;
              }
              else counter_Column ++;

              if (counter == cache_Blocks / set_Qtty) verify_Matrix = 1; // quiere decir que no hay casillas vacias, por lo tanto hay falla por capacidad.
              else{
                if (counter_Column == set_Qtty){
                  counter_Column = 0;
                  counter_Row ++;
                }
              }
              counter ++;
            }
        }else{
          counter_Row = (cache_Blocks / set_Qtty)*(sequence_Instuct[array_N] % set_Qtty);
          capacity_Misses ++;
          cache_Matrix[counter_Row +  rand()%(1)][rand()%(cache_Blocks/set_Qtty)] = sequence_Instuct[array_N];
        }
      }
      array_N ++;
     }

     //muestro la matriz
     for(int row = 0 ; row < cache_Blocks / set_Qtty ; row ++){
       for(int column = 0 ; column < set_Qtty ; column ++){
         printf("[ %s ]", cache_Matrix[row][column]);
       }
       printf("\n");
     }
     system("pause");
}
