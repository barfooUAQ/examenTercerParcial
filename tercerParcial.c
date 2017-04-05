#include <stdio.h>
#include<stdlib.h>

void Capturar(int *renglones, int *columnas, float matriz[50][50]);
void ProcedimientoPorColumna(int columna, float constante, float matriz[50][50],int renglones,int columnas);
void FiltrarMatriz(int renglones, int columnas, float matriz[50][50]);
void MatrizAVector(int renglones, int columnas, float matriz[50][50]);

int main(void)
{
    int opcion,columnas,renglones,numeroColumna;
    float matriz[50][50],constante;
    do{
        printf("====================================\n");
        printf("1 Capturar Matriz.\n");
        printf("2 Procedimiento por columna.\n");
        printf("3 Filtrar Matriz.\n");
        printf("4 Matriz a vector.\n");
        printf("5 Finalizar.\n");
        printf("\nSeleccione la opcion deseada:\t");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion){
        case 1: Capturar(&renglones,&columnas,matriz);break;
        case 2: {
            printf("Proporcione el numero de la columna:\t");
            scanf("%d",&numeroColumna);
            printf("Proporcione el valor de la contante:\t");
            scanf("%f",&constante);
            ProcedimientoPorColumna(numeroColumna,constante,matriz,renglones,columnas);
            break;
        }
        case 3: FiltrarMatriz(renglones,columnas,matriz);break;
        case 4: MatrizAVector(renglones,columnas,matriz);break;
        }
    }
    while(opcion!=5);
}

void Capturar(int *renglones, int *columnas, float matriz[50][50]){
    int i,j;
    printf("Proporcione el numero de renglones:\t");
    scanf("%d",&*renglones);
    printf("Proporcione el numero de columnas:\t");
    scanf("%d",&*columnas);
    printf("\n\nProporcione los valores para cada posicion de la matriz:\n\n");
    for(i=0;i<*renglones;i++){
        for(j=0;j<*columnas;j++){
            printf("matriz[%d][%d]:\t",i+1,j+1);
            scanf("%f",&matriz[i][j]);
        }
    }
    return;
}

void ProcedimientoPorColumna(int columna, float constante, float matriz[50][50],int renglones,int columnas){
    int i,j;
    for(i=0;i<renglones;i++){
        matriz[i][columna-1]*= constante;
    }
    printf("Matriz con los nuevos valores para la columna #%d\n\n",columna);
    for(i=0;i<renglones;i++){
        for(j=0;j<columnas;j++){
            printf("%.2f\t",matriz[i][j]);
        }
        printf("\n\n");
    }
    return;
}

void FiltrarMatriz(int renglones, int columnas, float matriz[50][50]){
    int i,j;
    float inferior,superior,incluidos[50][50],excluidos[50][50];
    printf("Proporcione el limite inferior:\t");
    scanf("%f",&inferior);
    printf("Proporcione el limite superior:\t");
    scanf("%f",&superior);
    for(i=0;i<renglones;i++){
        for(j=0;j<columnas;j++){
            if(matriz[i][j]>=inferior&&matriz[i][j]<=superior){
                incluidos[i][j]=matriz[i][j];
                excluidos[i][j]=0;
            }
            else{
                excluidos[i][j]=matriz[i][j];
                incluidos[i][j]=0;
            }
        }
    }
    printf("Matriz con los datos dentro del rango:\n");
    for(i=0;i<renglones;i++){
        for(j=0;j<columnas;j++){
            printf("%.2f\t",incluidos[i][j]);
        }
        printf("\n\n");
    }
    printf("Matriz con los datos fuera del rango:\n");
    for(i=0;i<renglones;i++){
        for(j=0;j<columnas;j++){
            printf("%.2f\t",excluidos[i][j]);
        }
        printf("\n\n");
    }
    return;
}

void MatrizAVector(int renglones, int columnas, float matriz[50][50]){
    int i,j,longitudVectorAuxiliar;
    float vectorAuxiliar[100],auxiliar,minimo,maximo,mediana;
    for(i=0;i<renglones;i++){
        for(j=0;j<columnas;j++){
            vectorAuxiliar[i*columnas+j]=matriz[i][j];
        }
    }
    longitudVectorAuxiliar=renglones*columnas;
    for(i=0;i<longitudVectorAuxiliar-1;i++){
        for(j=i+1;j<longitudVectorAuxiliar;j++){
            if(vectorAuxiliar[i]<vectorAuxiliar[j]){
                auxiliar=vectorAuxiliar[i];
                vectorAuxiliar[i]=vectorAuxiliar[j];
                vectorAuxiliar[j]=auxiliar;
            }
        }
    }
    maximo=vectorAuxiliar[0];
    minimo=vectorAuxiliar[longitudVectorAuxiliar-1];
    if(longitudVectorAuxiliar%2!=0){
        mediana=vectorAuxiliar[longitudVectorAuxiliar/2];
    }
    else{
        mediana=(vectorAuxiliar[longitudVectorAuxiliar/2]+vectorAuxiliar[(longitudVectorAuxiliar/2)-1])/2;
    }
    printf("Minimo =\t%.2f\n",minimo);
    printf("Maximo =\t%.2f\n",maximo);
    printf("Mediana=\t%.2f\n",mediana);
    return;
}


/*
PASO DE PARAMETROS POR VALOR
Es cuando una funcion recibe como parametros los valores de una variable definida en otro bloque de codigo.
En este caso dichos valores no pueden ser modificados sino solo utilizados por el codigo contenido en la definicion de la funcion que los recibe.
En el programa de arriba se puede observar este comportamiento en las en las llamadas a las funciones de las opciones 2,3 y 4

PASO DE PARAMETROS POR REFERENCIA.
Es cuando se utilizan apuntadores y los operadores * & para definir las referencias.
En este caso el apuntador hace referencia a la direccion de la variable y por lo tanto es posible modificar el contenido de dicha variable desde otro bloque de codigo.
Este comportamiento se puede observar en la llamada a la funcion de la opcion 1 del programa de arriba.
En este caso la direccion se envia como parametro con el operador & seguido del nombre dela variable y se recibe como parametro en la definicio de la funcion con el operador *




*/
