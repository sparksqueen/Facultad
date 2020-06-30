/*TP GRUPAL Nº 2:

Resolver los siguientes ejercicios teniendo en cuenta:

1.Cada ejercicio antes de comenzar debe mostrar por pantalla a todos los integrantes del equipo de trabajo.

2.Se debe enviar el archivo .cpp con el ejercicio funcional y resolviendo lo planteado.

3.Pueden agregar al programa todo tipo de opciones que gusten, pero siempre debe cumplir con todo lo solicitado.


Ejercicio 3:

Teniendo en cuenta el ejemplo 2 de la clase FOR; 
realizar un programa que me solicite con scanf o cin el ingreso de un numero comprobando 
con do while que este sea >0 y <60 caso contrario deberá volver a ingresar el número, y a
partir de este número ingresado que el programa realice una cuenta regresiva.*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;



int main ()
{
printf("Equipo nro 9: Maximiliano Salza, Ezequiel Spaccarotella, Yaideem Solis, Juan Tello; Paola Diaz, Ignacio Balo, Angeles P, Gustavo F. Fusari, Miguel Gagliardo \n \n"); //Angeles Peña*
int n;
printf ("Ingrese un numero menor a 60 \n");
scanf ("%d",&n);


//con do while siempre iniciaba el loop pidiendo "un numero válido" aunque el ingresado lo fuera, lo dejo comentado ya que es lo pedido en el ej.
while(n<=0 || n>= 60){ 
	printf ("Ingrese un numero valido \n");
	scanf ("%d",&n);
}

/*do{
	printf ("Ingrese un numero valido \n");
	scanf ("%d",&n);
}while(n<=0 || n>= 60)*/



for(n<60; n>0; n--){
printf("%d \t",n);
}


system("Pause");

return 0;
}



