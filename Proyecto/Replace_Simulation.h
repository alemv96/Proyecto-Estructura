#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int cache_Size_Block(){
  system("cls");
  int size_Block , exitMenu;
  exitMenu = 0;

  do {
    printf("Aviso: Favor introducir un valor numerico.\n");
    printf("Introduzca el tamano del bloque en bytes\n");
    printf("1) 2 B\n");
    printf("2) 4 B\n");
    printf("3) 8 B\n");
    printf("4) 16 B\n");
    printf("5) 32 B\n");
    printf("6) 64 B\n");
    printf("7) 128 B\n");
    scanf("%d\n", &size_Block );

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
  int size_Set , exitMenu;
  exitMenu = 0;

  do{
    printf("Aviso: Favor introducir un valor numerico.\n");
    printf("Introduzca el tama~o del conjunto\n");
    printf("1) 2 conjuntos\n");
    printf("2) 4 conjuntos\n");
    printf("3) 8 conjuntos\n");
    printf("4) 16 conjuntos\n");
    scanf("%d\n", &size_Set);

      if (size_Set < 1 || size_Set > 4) {
          printf("el valor que introdujo no es el correcto");
          system("pause");
          system("cls");
      }else exitMenu = 1;

  }while(exitMenu == 0);

  switch (size_Block) {
    case 1: return 2;
    case 2: return 4;
    case 3: return 8;
    case 4: return 16;
  }

}

int replace_Politic(){
  int option, exitMenu;
  exitMenu = 0;

  do{
    printf("Aviso: Favor introducir un valor numerico.\n");
    printf("introduzca la politica de remplazo que desea");
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
