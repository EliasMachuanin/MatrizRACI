#include<stdio.h>
#include<string.h>
#include<conio.h>

//estructuras
struct nombres{
	char nombre[30];
};

struct tarea{
	char nombre[30];
};

struct RACI{
	char cargo[3];
};
//inicio 
int main(){
	int numero_de_tareas, numero_de_involucrados, i=0, j=0, k=0, largoT=0, largoI=0, respuesta=1, contR=0, contA=0, contC=0, contI=0, contO=0, bandera=0, aPorLinea=0, A=0, R=0, aEnCargo=0, rEnCargo=0, iEnCargo=0, cEnCargo=0, totalI;
	int menu, contM=0, guardar=0;
	char nombreMatriz[30];
	float nivelBurocracia;
	FILE *archivo;
	while(contM==0){
	system("cls");
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("                                                       MENU\n\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------\n\n\n\n");
	printf("     1- CREAR NUEVA MATRIZ.\n\n");
	printf("     2- CARGAR MATRIZ GUARDADA.\n\n");
	printf("     0- SALIR.\n\n");
	scanf("%d", &menu);
	system("cls");
		switch(menu){
			case 0:{
				contM++;
				break;
			}
			case 1:{
				printf("Ingrese el numero de tareas: ");
	scanf("%d", &numero_de_tareas);
	while(numero_de_tareas<=0){
		system("cls");
		printf("Ingrese el numero de tareas (debe ser mayor a 0): ");
		scanf("%d", &numero_de_tareas);	
	}
	printf("Ingrese el numero de involucrados: ");
	scanf("%d", &numero_de_involucrados);
	while(numero_de_involucrados<=0){
		system("cls");
		printf("Ingrese el numero de involucrados (debe ser mayor a 0): ");
		scanf("%d", &numero_de_involucrados);	
	}
	struct RACI RACI[numero_de_tareas][numero_de_involucrados];
	struct nombres involucrados[numero_de_involucrados];
	struct tarea tareas[numero_de_tareas];
	system("cls");
	
	for(i=0;i<numero_de_tareas;i++){
		for(j=0;j<numero_de_involucrados;j++){
			for(k=0;k<3;k++){
			RACI[i][j].cargo[k]='\0';	
			}
		}
	}
	
	for(i=0;i<numero_de_involucrados;i++){
		printf("Ingrese el nombre del %d involucrado: ", i+1);
		scanf("%s", &involucrados[i].nombre);
		while(involucrados[i].nombre[largoI] != '\0'){
		largoI++;
	}
	for(j=largoI;j<30;j++){
		involucrados[i].nombre[j]=' ';
		fflush(stdout);
	}
		fflush(stdin);
		system("cls");
		largoI=0;
	}
	
	for(i=0;i<numero_de_tareas;i++){
		printf("Ingrese la %d tarea: ", i+1);
		scanf("%s", &tareas[i].nombre);
		while(tareas[i].nombre[largoT] != '\0'){
		largoT++;
	}
	for(j=largoT;j<30;j++){
		tareas[i].nombre[j]=' ';
		fflush(stdout);
	}
		fflush(stdin);
		system("cls");
		largoT=0;
	}
	while(respuesta==1){
	contR=0, contA=0, contC=0, contI=0, contO=0, bandera=0, aPorLinea=0, A=0, R=0, aEnCargo=0, rEnCargo=0, iEnCargo=0, cEnCargo=0;
	system("cls");
	printf("                             ");
	for(i=0;i<numero_de_involucrados;i++){
			printf("%s", involucrados[i].nombre);
		}
	for(i=0;i<numero_de_tareas;i++){
		printf("\n\n\n\n");
		for(k=0;k<30;k++){
		printf("%c", tareas[i].nombre[k]);	
		}
		for(j=0;j<numero_de_involucrados;j++){
			if(RACI[i][j].cargo[0] == '\0'){
				printf("[%d ; %d]                  ", i, j);
				
			} 
			else{
				printf("[");
				for(k=0;k<3;k++){
				printf("%c", RACI[i][j].cargo[k]);
			}
			printf("]                      ");
			}
			
			}
		}	
	printf("\n\n\n\n");
	printf("Ingrese las coordenadas en las que desea escribir: ");
	scanf("%d %d", &i, &j);
	printf("\n\nIngrese cual letra asignara a la casilla seleccionada: ");
	scanf("%s", &RACI[i][j].cargo);
	system("cls");
	printf("                             ");
	for(i=0;i<numero_de_involucrados;i++){
			printf("%s                   ", involucrados[i].nombre);
		}
	for(i=0;i<numero_de_tareas;i++){
		printf("\n\n\n\n");
		for(k=0;k<30;k++){
		printf("%c", tareas[i].nombre[k]);	
		}
		for(j=0;j<numero_de_involucrados;j++){
			if(RACI[i][j].cargo[0] == '\0'){
				printf("[%d ; %d]                  ", i, j);
				
			} 
			else{
				printf("[");
				for(k=0;k<3;k++){
				printf("%c", RACI[i][j].cargo[k]);
			}
			printf("]                      ");
			}
			
			}
		}	
	printf("\n\n\n\n¿Desea Modificar algo mas? (1-SI, 2-NO).\n");
	scanf("%d", &respuesta);
	
	
	if(respuesta != 1){
		system("cls");
		printf("                             ");
		for(i=0;i<numero_de_involucrados;i++){
			printf("%s                   ", involucrados[i].nombre);
			}
		for(i=0;i<numero_de_tareas;i++){
		printf("\n\n\n\n");
		for(k=0;k<30;k++){
		printf("%c", tareas[i].nombre[k]);	
			}
		for(j=0;j<numero_de_involucrados;j++){
			if(RACI[i][j].cargo[0]=='\0'){
				printf("[%d ; %d]                  ", i, j);
			
				} 
			else{
				printf("[");
				for(k=0;k<3;k++){
				printf("%c", RACI[i][j].cargo[k]);
				}
			printf("]                      ");
					}
			}
			}
			//verificacion 
				for(i=0;i<numero_de_tareas;i++){
					if(contA>1){
						aPorLinea=1;  //error, mas de una 'A' por linea.
					}
					if(i!=0){
					if(contA==0){
						A=1;
						}              //error, al menos una A o R por linea.
					if(contR==0){
						R=1;
					}
					}
					contR=0, contA=0;
					for(j=0;j<numero_de_involucrados;j++){
						
						aEnCargo=0, rEnCargo=0, iEnCargo=0, cEnCargo=0;
						for(k=0;k<3;k++){
								switch(RACI[i][j].cargo[k]){
								case 'R':{
								contR++;
								if((iEnCargo>0)||(cEnCargo>0)||(rEnCargo>0)){
								bandera=1;
								}
								rEnCargo++;
								break;
							}
								case 'A':{
								contA++;
								if((iEnCargo>0)||(cEnCargo>0)||(aEnCargo>0)){
								bandera=1;	
								}
								aEnCargo++;
								break;
							}	
								case 'C':{
								cEnCargo++;
								if(k!=0){
								bandera=1;
								}
								break;
							}
								case 'I':{
								contI++;
								iEnCargo++;
								if(k!=0){
								bandera=1;
								}
								break;
							}
								case 'r':{
								contR++;
								if((iEnCargo>0)||(cEnCargo>0)||(rEnCargo>0)){
								bandera=1;	
								}
								rEnCargo++;
								break;
							}
								case 'a':{
								contA++;
								if((iEnCargo>0)||(cEnCargo>0)||(aEnCargo>0)){
								bandera=1;	
								}
								aEnCargo++;
								break;
							}	
								case 'c':{
								cEnCargo++;
								if(k!=0){
								bandera=1;
								}
								break;
							}
								case 'i':{
								contI++;
								iEnCargo++;
								if(k!=0){
								bandera=1;
								}
								break;
							}
							case '\0':{
								break;
							}
							default:{
								contO++;
								break;
						}
					}
				}				
			}
		}
		
		if(contA>1){
			aPorLinea=1;
		}
		if(contA==0){
			A=1;
		}              //error, al menos una A o R por linea.
		if(contR==0){
			R=1;
		}
		
		if(contO>0){
			printf("\n\n\nEn la matriz solo pueden ingresarse las letras 'R', 'A', 'C', 'I'.");
			respuesta=1;
		}
	    if(bandera==1){
	    printf("\n\n\nNo puede haber mas de una letra por casilla, a excepcion de la 'A' y 'R'.");
				respuesta=1;	
		}
		if(aPorLinea==1){
			printf("\n\n\nSe permite unicamente una 'A' por tarea.");
				respuesta=1;
		}		
		if(A==1){
				printf("\n\n\nCada tarea debe tener al menos una 'A'.");
				respuesta=1;
			}
		if(R==1){
				printf("\n\n\nCada tarea debe tener al menos una 'R'.");
				respuesta=1;
			}
			if(respuesta==1){
				printf("\n\n\nPresione '1' para corregir los errores.\n");
				scanf("%d", &respuesta);
				system("cls");
				while(respuesta != 1){
					system("cls");
				printf("                             ");
				for(i=0;i<numero_de_involucrados;i++){
				printf("%s                   ", involucrados[i].nombre);
				}
				for(i=0;i<numero_de_tareas;i++){
				printf("\n\n\n\n");
				for(k=0;k<30;k++){
				printf("%c", tareas[i].nombre[k]);	
				}
				for(j=0;j<numero_de_involucrados;j++){
				if(RACI[i][j].cargo[0]=='\0'){
				printf("[%d ; %d]                  ", i, j);
			
				} 
				else{
				printf("[");
				for(k=0;k<3;k++){
				printf("%c", RACI[i][j].cargo[k]);
				}
				printf("]                      ");
			}
		}
	}
				printf("\n\n\n                         -------------------ERROR-------------------\n\n\nPresione '1' para corregir los errores.\n");
				scanf("%d", &respuesta);
				system("cls");
				
			}		
		}		
	}
}

for(i=0;i<numero_de_tareas;i++){
		for(j=0;j<numero_de_involucrados;j++){
			for(k=0;k<3;k++){
				if(RACI[i][j].cargo[0]=='\0'){
			RACI[i][j].cargo[k]=126;
			}	
		}
	}
}
system("cls");
	printf("                             ");
	for(i=0;i<numero_de_involucrados;i++){
			printf("%s                   ", involucrados[i].nombre);
		}
	for(i=0;i<numero_de_tareas;i++){
		printf("\n\n\n\n");
		for(k=0;k<30;k++){
		printf("%c", tareas[i].nombre[k]);	
		}
		for(j=0;j<numero_de_involucrados;j++){
			if(RACI[i][j].cargo[0] == '\0'){
				printf("[%d ; %d]                  ", i, j);
				
			} 
			else{
				printf("[");
				for(k=0;k<3;k++){
				printf("%c", RACI[i][j].cargo[k]);
			}
			printf("]                      ");
			}
			
			
			}
		}
		printf("\n\n\n\n");
		totalI=((numero_de_involucrados*numero_de_tareas)-(numero_de_involucrados));
		nivelBurocracia=((float)(contI*100)/(totalI));
		printf("Dado que el total estimado de 'I' es %d, y que la matriz consta de %d 'I'. El procentaje de espacios ocupados con 'I' es de %0.1f%c.", totalI, contI, nivelBurocracia, 37);
		printf("\n\n\n\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------\n\n");
		printf("                                                 MATRIZ RACI FINALIZADA\n\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------\n\n");
		printf("\n\nDesea guardar su matriz? (1-SI  0-NO) ");
		scanf("%d", &guardar);
		if(guardar==1){
		printf("\n\nCon cual nombre desea guardar su matriz? ");
		scanf("%s", &nombreMatriz);
			archivo=fopen(nombreMatriz, "wb");
			fwrite(&numero_de_involucrados, sizeof(numero_de_involucrados), 1, archivo);
			fwrite(&numero_de_tareas, sizeof(numero_de_tareas), 1, archivo);
			fwrite(&involucrados, sizeof(struct nombres), 1, archivo);
			fwrite(&tareas, sizeof(struct tarea), 1, archivo);
			fwrite(&RACI, sizeof(struct RACI), 1, archivo);
			printf("\n\nGUARDADO EXITOSAMENTE");
			fclose(archivo);
			//delay(300);
		}

		break;
	}
				
			case 2:{
				printf("\n\nIngrese el nombre de la matriz que desea cargar: ");
			scanf("%s", &nombreMatriz);
			archivo=fopen(nombreMatriz, "rb");
			if(archivo==NULL){
				printf("\n\nMartiz no encontrada.");
			}
			else{
			fread(&numero_de_involucrados, sizeof(numero_de_involucrados), 1, archivo);
			fread(&numero_de_tareas, sizeof(numero_de_tareas), 1, archivo);
			struct RACI RACI[numero_de_tareas][numero_de_involucrados];
			struct nombres involucrados[numero_de_involucrados];
			struct tarea tareas[numero_de_tareas];
			fread(&involucrados, sizeof(struct nombres), 1, archivo);
			fread(&tareas, sizeof(struct tarea), 1, archivo);
			fread(&RACI, sizeof(struct RACI), 1, archivo);
			fclose(archivo);
			system("cls");
	printf("                             ");
	for(i=0;i<numero_de_involucrados;i++){
			printf("%s", involucrados[i].nombre);
		}
	for(i=0;i<numero_de_tareas;i++){
		printf("\n\n\n\n");
		for(k=0;k<30;k++){
		printf("%c", tareas[i].nombre[k]);	
		}
		for(j=0;j<numero_de_involucrados;j++){
			if(RACI[i][j].cargo[0] == '\0'){
				printf("[%d ; %d]                  ", i, j);
				
			} 
			else{
				printf("[");
				for(k=0;k<3;k++){
				printf("%c", RACI[i][j].cargo[k]);
			}
			printf("]                      ");
			}
			
			}
		}	
	}
		printf("\n\n\n\nPresione cualquier tecla para continuar: ");
		scanf("%s", &nombreMatriz);
				break;
			}
		}	
	}
	printf("\n\nPresione cualquier tecla para carrar la ventana.\n\n");
}
