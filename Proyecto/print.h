#include <stdlib.h>
#include <stdio.h>

void print_Direct_Mapping(int Tag , int Line , int Bytes){
  int all_Array_Size = Tag + Line + Bytes;
  int tag_Array[Tag];
  int line_Array[Line];
  int bytes_Array[Bytes];
  int array_Completed[all_Array_Size];

    printf("Etiqueta : ");//solo muestro el tag.
    for (int counter = Tag - 1; counter >= 0 ; counter --){
      tag_Array[counter] = counter;
      printf("[ %d ]", tag_Array[counter]);
    }
    printf("\n");

    printf("Linea : ");//muestro solo la linea del mapeo.
    for (int counter = Line - 1; counter >= 0 ; counter --){
      line_Array[counter] = counter;
      printf("[ %d ]", line_Array[counter]);
    }
    printf("\n");

    printf("Bytes : ");//muestro solo los bytes/bloques de palabra del mapeo
    for (int counter = Bytes - 1 ; counter >= 0 ; counter --){
      bytes_Array[counter] = counter;
      printf("[ %d ]", bytes_Array[counter]);
    }

    system("pause");
    system("cls");
    printf("El mapeo directo le quedaria de la siguiente forma.\n");
    printf("tomando en cuenta que la etiqueta son los primeros %d \n" , Tag);
    printf("numeros,Seguido por los %d ", Line , "numeros\n");
    printf("de la linea y por ultimo estarian la cantidad\n");
    printf("de bloques(Bytes) que en este caso es: %d\n ", Bytes);
    system("pause");//pensar bien si se quiere de verdad colocar esa cantidad de comentarios.
    system("cls");

    printf("Arreglo completo");
    //muestro el arreglo completo;
    for (int counter = all_Array_Size - 1; counter >= 0 ; counter --){
      array_Completed[counter] = counter;
      printf("[ %d ]", array_Completed[counter]);
    }

  system("pause");
}

//me muestra por pantalla el mapeo asociativo por conjunto.
void print_Set_Associative_Cache(int Tag , int Set , int offset){
  int all_Array_Size = Tag + Set + offset;
  int tag_Array[Tag];
  int set_Array[Set];
  int offset_Array[offset];
  int array_Completed[all_Array_Size];

    printf("Etiqueta : ");//solo muestro el tag.
    for (int counter = Tag - 1; counter >= 0 ; counter --){
      tag_Array[counter] = counter;
      printf("[ %d ]", tag_Array[counter]);
    }
    printf("\n");

    printf("conjunto : ");//muestro solo el conjunto del mapeo.
    for (int counter = Set - 1; counter >= 0 ; counter --){
      set_Array[counter] = counter;
      printf("[ %d ]", set_Array[counter]);
    }
    printf("\n");

    printf("Offset : ");//muestro el offset
    for (int counter = offset - 1 ; counter >= 0 ; counter --){
      offset_Array[counter] = counter;
      printf("[ %d ]", offset_Array[counter]);
    }

    system("pause");
    system("cls");
    printf("El mapeo asociativo por conjunto quedaria de la siguiente forma:\n");
    printf("tomando en cuenta que la etiqueta son los primeros %d \n" , Tag);
    printf("numeros,Seguido por los %d ", Set , "numeros\n");
    printf("del conjunto y por ultimo estaria el offset\n");
    printf("que en este caso su valor es: %d\n ", offset);
    system("pause");//pensar bien si se quiere de verdad colocar esa cantidad de comentarios.
    system("cls");

    printf("Arreglo completo");
    //muestro el arreglo completo;
    for (int counter = all_Array_Size - 1; counter >= 0 ; counter --){
      array_Completed[counter] = counter;
      printf("[ %d ]", array_Completed[counter]);
    }

  system("pause");
}
