#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
using namespace std;

void capturar_valor(int &var,int min,int max);

char entero_a_caracter(int num);

int main(){
	
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
	int matriz[4][4];
	char matriz_esp[4][4];
	
	int num_1,num_2,num_3,pos_x,pos_y,op;
	int contador=0;
	char op_f[2];
	bool flag_1=false;
	bool flag_2=false;
	bool flag_3=false;
	int intentos;
	
	do{
		
		intentos=5;
		
		//Lleno la matriz con 0 en todas sus posiciones.
		
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				matriz[i][j]=0;
			}
		}
		
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				matriz_esp[i][j]='x';
			}
		}
		
		//Damos la bienvenida al programa.
		
		menu:
					
		system("cls");
		
		cout<<"\n";
		cout<<"-------ESBA - GRUPO 9 - HERRAMIENTAS DE PROGRAMACIÓN-------"<<endl;
		cout<<"\n";
		cout<<"Ezequiel Spaccarotella."<<endl;
		cout<<"Maximiliano Salza."<<endl;
		cout<<"Yaideem Solis."<<endl;
		cout<<"Juan Tello."<<endl;
		cout<<"Paola Díaz."<<endl;
		cout<<"Ignacio Balo."<<endl;
		cout<<"Angeles Peña."<<endl;
		cout<<"Gustavo Fusari."<<endl;
		cout<<"Miguel Gagliardo."<<endl;
		cout<<"\n";
	
		//--------------------------------------------------------------------------
		
		cout<<"Bienvenido!\n"<<endl;
		cout<<"1 - Jugar"<<endl;
		cout<<"2 - Salir\n"<<endl;
		
		cout<<"Ingrese la opción deseada:";
		cin>>op;
		fflush(stdin);
		
		switch(op){
			
			case 1:
				system("cls");
				//Solicito al usuario ingresar 3 valores, y los ubico en posiciones aleatorias dentro de la matriz.
				cout<<"Ingrese valores del 1 al 9...\n"<<endl;
				capturar_valor(num_1,1,9);
				capturar_valor(num_2,1,9);
				capturar_valor(num_3,1,9);
				system("cls");
				
				//Introducimos esos valores en ubicaciones aleatorias de nuestra matriz. (limite la aleatoriedad de las filas para evitar que se superpongan las posiciones)
				matriz[rand()%1][rand()%3]=num_1;
				matriz[1+rand()%2][rand()%3]=num_2;
				matriz[3][rand()%3]=num_3;
				
				//Comienza el Juego.
				cout<<"Hemos escondido los valores dentro de una Matriz de [4]x[4]"<<endl;
				cout<<"\nSi los encuentras, los veraz reflejados en la matriz!"<<endl;
				cout<<"\n";
				for(int i=0;i<4;i++){
					for(int j=0;j<4;j++){
						if(j==3){
							cout<<matriz_esp[i][j];
						}else{
							cout<<" "<<matriz_esp[i][j]<<" - ";	
						}
					}
					cout<<endl;
				}
			
				cout<<"\n";
				cout<<"Indica las posiciones en donde crees que se encuentran!"<<endl;
				cout<<"\nCuentas con 5 intentos, mucha suerte!"<<endl;
		
				cout<<"\nLa partida comienza en: ";
				for(int i=10;i>0;i--){
					cout<<i<<"...";
					Sleep(1000);
				}
				system("cls");
				
				while(intentos>0){
					
					cout<<"Intentos disponibles: "<<intentos<<endl;
					cout<<"\n";
					for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							if(j==3){
								cout<<matriz_esp[i][j];
							}else{
								cout<<" "<<matriz_esp[i][j]<<" - ";	
							}
						}
						cout<<endl;
					}
					
					//PROFESOR: SI ENCONTRO ESTO, PUEDE COMPROBAR MEJOR EL FUNCIONAMIENTO DEL PROGRAMA DESCOMENTANDO LA SIGUIENTE INSTRUCCION! :)
					
					/*cout<<"\n";
					for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							if(j==3){
								cout<<matriz[i][j];
							}else{
								cout<<" "<<matriz[i][j]<<" - ";	
							}
						}
						cout<<endl;
					};*/
					
					cout<<"\nIngrese valor de la fila [x][ ]: ";
					cin>>pos_x;
					pos_x=pos_x-1;
					
					while(pos_x<0||pos_x>3||cin.fail()||cin.bad()){
						cin.clear();
						cin.ignore(80,'\n');
						cout<<"Solo existen 4 filas y 4 columnas, ingrese un valor valido:";
						cin>>pos_x;
						pos_x=pos_x-1;
					}
				
					cout<<"\nIngrese valor de la columna [ ][x]: ";
					cin>>pos_y;
					pos_y=pos_y-1;
					
					while(pos_y<0||pos_y>3||cin.fail()||cin.bad()){
						cin.clear();
						cin.ignore(80,'\n');
						cout<<"Solo existen 4 filas y 4 columnas, ingrese un valor valido:";
						cin>>pos_y;
						pos_y=pos_y-1;
					}
					
					if(matriz[pos_x][pos_y]==num_1){
						cout<<"\nEncontraste "<<num_1<<endl;
						flag_1=true;
						matriz_esp[pos_x][pos_y]=entero_a_caracter(num_1);
					
					}else if(matriz[pos_x][pos_y]==num_2){
						cout<<"\nEncontraste "<<num_2<<endl;
						flag_2=true;
						matriz_esp[pos_x][pos_y]=entero_a_caracter(num_2);
					
					}else if(matriz[pos_x][pos_y]==num_3){
						cout<<"\nFelicitaciones!! Encontraste el valor: "<<num_3<<endl;
						flag_3=true;
						matriz_esp[pos_x][pos_y]=entero_a_caracter(num_3);
					}else{
						cout<<"\nAgua! Intentalo nuevamente..."<<endl;
						matriz_esp[pos_x][pos_y]='.';
					}
					
					intentos--;
					Sleep(3000);
					system("cls");
					if(flag_1 && flag_2 && flag_3){
						break;
					}
				}
			
				break;
				
			case 2:
				goto fin;
			
			default:
				cout<<"\nPor favor ingrese una opación valida!";
				Sleep(1500);
				cin.clear();
				goto menu;
		};
		
		if(flag_1 && flag_2 && flag_3){
			cout<<"Felicidades, has ganado!"<<endl;
		}else{
			cout<<"Lo sentimos, has perdido..."<<endl;
		};
		
		cout<<"\nIngrese [si] para seguir juegando o [no] para salir del programa."<<endl;
		cout<<"\nDesea continuar?:";
		cin>>op_f;
		
		while(strcmp(op_f,"si")!=0 && strcmp(op_f,"no")!=0){
			system("cls");
			cout<<"La opcion ingresada no es valida..."<<endl;
			cout<<"\nIngrese [si] para seguir juegando o [no] para salir del programa."<<endl;
			cout<<"\nDesea continuar?:";
			cin>>op_f;
		};
		
	}while(strcmp(op_f,"no")!=0);
	
	fin:
	
	system("PAUSE");
	return 0;
}

//Pasamos el parametro de la variable a modificar por "referencia" para poder sustituirlo.
void capturar_valor(int &var,int min,int max){
	
	cout<<"Ingrese un valor: ";
	cin>>var;
	fflush(stdin);
	
	while(var<min||var>max||cin.fail()||cin.bad()){
		cin.clear();
		system("cls");
		cout<<"El valor ingresado es invalido, ingrese uno del 1 al 9."<<endl;
		cout<<"Ingrese un valor: ";
		cin>>var;
		fflush(stdin);
	};
};

char entero_a_caracter(int num){
	return num + '0';
};





