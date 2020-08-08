#include <stdio.h>
//Tipo TTarjeta, registro que define los datos asociados a la tarjeta
typedef struct {
	int dni;
	int clave;
	float saldo;
	float montoMax;
}TTarjeta;

int main(){
	int dni, clave;
	TTarjeta tarj1, tarj2, tarj3, tarj4;
	TTarjeta tarjeta;
	int datosOk;


    int operacion;
    int extraccion;
    int finalizar;

    cargarTarjetas(&tarj1, &tarj2, &tarj3, &tarj4);
    ingresar(&dni, &clave);
   
 
        if (datosOk = 1){
         solicitarOperacion(&operacion, dni,  clave,   tarj1,  tarj2,  tarj3,  tarj4,  &datosOk,  &tarjeta);
         RealizarOperacion( &operacion, finalizar, tarj1, tarj2, tarj3, tarj4, &tarjeta);
        }
        else {
    return 0;

        }  


// Acci贸n que inicializa los datos de las tarjetas
void cargarTarjetas(TTarjeta * tarj1, TTarjeta * tarj2, TTarjeta * tarj3, TTarjeta * tarj4){
	//cargaTarjeta1
	tarj1->dni = 23225226;
	tarj1->clave = 1547;
	tarj1->saldo = 5800;
	tarj1->montoMax = 5000;
	//cargaTarjeta2
	tarj2->dni = 28228331;
	tarj2->clave = 5389;
	tarj2->saldo = 10000;
	tarj2->montoMax = 7000;
	//cargaTarjeta3
	tarj3->dni = 30456189;
	tarj3->clave = 2389;
	tarj3->saldo = 25000;
	tarj3->montoMax = 10000;
	//cargaTarjeta4
	tarj4->dni = 35283281;
	tarj4->clave = 2984;
	tarj4->saldo = 87990;
	tarj4->montoMax = 10000;
}

// Acci贸n que solicita los datos de ingreso al usuario
void ingresar(int * dni, int * clave){
	printf("Ingrese su dni : ");
	scanf("%d", dni);
	printf("Ingrese su clave : ");
	scanf("%d", clave);
}
void VerificarDatosIngreso(int dni, int clave,  TTarjeta tarj1, TTarjeta tarj2, TTarjeta tarj3, TTarjeta tarj4, int *datosOk, TTarjeta *tarjeta){
    int verdadero, falso;
    verdadero = 1;
    falso = 0;

    
    if ((dni == tarj1.dni) && (clave == tarj1.clave)) {
        datosOk = &verdadero;
        tarj1;
    }
    else {
        if ((dni == tarj2.dni) && (clave == tarj2.clave)) {
            datosOk = &verdadero;
            tarj2;
        }
        else {
            if ((dni == tarj3.dni) && (clave == tarj3.clave)) {
                datosOk = &verdadero;
                tarj3;
            }
            else {
                if ((dni == tarj4.dni) && (clave == tarj4.clave)) {
                    datosOk = &verdadero;
                    tarj4;
                }
                else {
                    (datosOk = &falso) && printf("Los datos ingresados no son correctos");
                }
            }
        }
    }
 
}
// Acci贸n que solicita la operaci贸n a realizar
void solicitarOperacion(int * op,int dni, int clave,  TTarjeta tarj1, TTarjeta tarj2, TTarjeta tarj3, TTarjeta tarj4, int *datosOk, TTarjeta *tarjeta){
	printf("Ingrese la operaci贸n que desea realizar");
	printf("1. Consultar saldo y l胢ite de extracci贸n");
	printf("2. Extraer dinero");
	printf("3. Actualizar clave");
	printf("4. Modificar l胢ite de extracci贸n");
	printf("5. Finalizar");
	scanf("%d", op);
}
void RealizarOperacion(int  op, float saldo, float montoMax, float extraccion, float limiteNuevo, int nuevaClave1, int nuevaClave2, int finalizar, TTarjeta t1, TTarjeta t2, TTarjeta t3, TTarjeta t4, TTarjeta * tarjeta){
if (op == 1) { //operacion 1: "Consultar saldo y l韒ite de extracci髇"
     if ((dni == tarj1.dni) && (clave == tarj1.clave)) {
         printf ("Su saldo actual es:$%f. \n Su maximo de extraccion es:$%f\n",tarj1.saldo, tarj1.montoMax);
     }
     else {
         if ((dni == tarj2.dni) && (clave == tarj2.clave)) {
             printf ("Su saldo actual es:$%f. \n Su maximo de extraccion es:$%f\n",tarj2.saldo, tarj2.montoMax);
         }
         else {
             if ((dni == tarj3.dni) && (clave == tarj3.clave)) {
                 printf ("Su saldo actual es:$%f. \n Su maximo de extraccion es:$%f\n",tarj3.saldo, tarj3.montoMax);
             }
             else {
                 printf ("Su saldo actual es:$%f. \n Su maximo de extraccion es:$%f\n",tarj4.saldo, tarj4.montoMax);
             }
         }
     }
}
}
}
