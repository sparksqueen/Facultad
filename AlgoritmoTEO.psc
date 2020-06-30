//Algunas lineas estan comentadas doblemente porque no afectan al código y se pueden reactivar para realizar una comprobacion de que el codigo funciona como debe.
//Estas lineas son 22, 30 y 31
Algoritmo Encontrar9
		Definir Num como entero 
		Cantidad=10;
		i <- 1
		Dimension Num[Cantidad] // arreglo 
		flag = falso //uso "flag" como booleano de comprobación
		Escribir "Estoy programado para buscar el numero 9"
		
			Para i<-1 Hasta Cantidad Hacer
				Escribir "¿Que numero quiere escribir en el indice ",i , "?";
					Leer Num[i]
			Fin Para //pide ingresar los numeros de a uno
				
			Para i<-1 Hasta Cantidad Hacer 
				Escribir Num[i] 
			FinPara  // vuelve a escribir los valores ingresados para mejor visibilidad
	
			Para i<-1 Hasta Cantidad Hacer
				Mientras flag = falso Y i<=Cantidad Hacer
						//Escribir "Buscando numero" //comprobacion para saber si el Algoritmo responde como es esperado
						Si Num[i]=9 Entonces
							flag = verdadero
							SiNo flag = falso
						Fin Si
						
						Si flag = verdadero Entonces
							Escribir "El numero 9 esta en la posicion ", i
						//SiNo                  //comprobacion para saber si el Algoritmo responde como es esperado
						//	Escribir "El numero 9 no se ha encontrado en la posicion ", i    //comprobacion para saber si el Algoritmo responde como es esperado
						Fin Si
						i <- i+1
					FinMientras // intenté usar solamente "mientras", pero me saltaba un error que decia que el indice 0 no correspondia al arreglo. 
					//luego de eso intenté definir que realice la accion "mientras" solo si i>1 pero no funcionó, por lo que decidí encadenar un para solo para darle la orden de hasta cuando tiene que ejecutar "mientras"
				Fin Para
	
	si flag = falso Entonces
		Escribir "El Numero 9 no se ha encontrado"
		Fin si
				//Error 303
				//Mientras (i<=Cantidad Y no flag) Hacer
				//Escribir "procesando"
				//	Si Num[i]=9 Entonces
				//		flag = verdadero
				//		SiNo i <- i+1
				//	Fin Si
				//FinMientras
					
		
		
		
FinAlgoritmo
