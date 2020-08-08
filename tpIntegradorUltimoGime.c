#include <stdio.h>
#include <math.h>

typedef struct {
    int dni;
    int clave;
    int saldo;
    int montoMax;
} TTarjeta;

void solicitarOperacion(int * op);
void ingresar(int * dniACargar, int * claveUsuario, TTarjeta * tarjetaIngresada);
int compararEstructuras (TTarjeta * tarjetaUsuario, TTarjeta * tarjetaRegistrada);

void cargarTarjetas(TTarjeta * t1, TTarjeta * t2, TTarjeta * t3, TTarjeta * t4);
void VerificarDatosIngreso(int dni, int clave,  TTarjeta t1, TTarjeta t2, TTarjeta t3, TTarjeta t4, int * datosOk, TTarjeta * tarjetaDelUsuario);
void RealizarOperacion(int op, int saldo, int montoMax, int extraccion, int limiteNuevo, int nuevaClave1, int nuevaClave2, int finalizar, TTarjeta * t1, TTarjeta * t2, TTarjeta * t3, TTarjeta * t4, TTarjeta * tarjeta);

int main() {
    int dni, clave;
    TTarjeta t1, t2, t3, t4;
    TTarjeta tarjeta;
    int datosOk;
    int nuevaClave1, nuevaClave2;
    int limiteNuevo, montoMax, saldo;

    int operacion;
    int extraccion;
    int finalizar;

    cargarTarjetas(&t1, &t2, &t3, &t4);
    ingresar(&dni, &clave, &tarjeta);
    VerificarDatosIngreso(dni, clave, t1, t2, t3, t4, &datosOk, &tarjeta);

    if (datosOk = 1) {
        finalizar = 0;

        while (!(finalizar)){
            solicitarOperacion(&operacion);
            RealizarOperacion(operacion, saldo, montoMax, extraccion, limiteNuevo, nuevaClave1, nuevaClave2, finalizar, &t1, &t2, &t3, &t4, &tarjeta);
        }
    }

    return 0;
}

// ACCION que inicializa los datos de las tarjetas
void cargarTarjetas(TTarjeta * t1, TTarjeta * t2, TTarjeta * t3, TTarjeta * t4) {
    //cargaTarjeta1
    t1->dni = 41153270;
    t1->clave = 1547;
    t1->saldo = 5800;
    t1->montoMax = 5000;
    //cargaTarjeta2
    t2->dni = 28228331;
    t2->clave = 5389;
    t2->saldo = 10000;
    t2->montoMax = 7000;
    //cargaTarjeta3
    t3->dni = 30456189;
    t3->clave = 2389;
    t3->saldo = 25000;
    t3->montoMax = 10000;
    //cargaTarjeta4
    t4->dni = 35283281;
    t4->clave = 2984;
    t4->saldo = 87990;
    t4->montoMax = 10000;
}

// ACCION que solicita los datos de ingreso al usuario
void ingresar(int * dniACargar, int * claveUsuario, TTarjeta * tarjetaIngresada) {
    int dni;
    int claves;
    printf("Ingrese su DNI : ");
    scanf("%d", &dni);

    printf("Ingrese su clave : ");
    scanf("%d", &claves);

    *dniACargar = dni;
    *claveUsuario = claves;

    tarjetaIngresada->dni = dni;
    tarjetaIngresada->clave = claves;
}

// ACCION dado el dni y clave determina si los datos son validos y cual es la tarjeta correspondiente
void VerificarDatosIngreso(int dni, int clave,  TTarjeta t1, TTarjeta t2, TTarjeta t3, TTarjeta t4, int * datosOk, TTarjeta * tarjetaDelUsuario) {
    int verdadero = 1;
    int falso = 0;

    *datosOk = falso;

    if ((dni == t1.dni) && (clave == t1.clave)) {
        *datosOk = verdadero;
        tarjetaDelUsuario = &t1;

    } else if ((dni == t2.dni) && (clave == t2.clave)) {
        *datosOk = verdadero;
        tarjetaDelUsuario= &t2;

    } else if ((dni == t3.dni) && (clave == t3.clave)) {
        *datosOk = verdadero;
        tarjetaDelUsuario = &t3;

    } else if ((dni == t4.dni) && (clave == t4.clave)) {
        *datosOk = verdadero;
        tarjetaDelUsuario = &t4;
    }
}

// Acción que solicita la operación a realizar
void solicitarOperacion(int * op) {
    printf("\n Ingrese la operacion que desea realizar\n");
    printf("1. Consultar saldo y limite de extraccion\n");
    printf("2. Extraer dinero\n");
    printf("3. Actualizar clave\n");
    printf("4. Modificar limite de extraccion\n");
    printf("5. Finalizar\n");
    scanf("%d", op);
}


// Acción que realiza la operacion seleccionada
void RealizarOperacion(int op, int saldo, int montoMax, int extraccion, int limiteNuevo, int nuevaClave1, int nuevaClave2, int finalizar, TTarjeta * t1, TTarjeta * t2, TTarjeta * t3, TTarjeta * t4, TTarjeta * tarjeta) {
    if (op == 1) { //operacion 1: "Consultar saldo y l�mite de extracci�n"
        if (tarjeta->dni == t1->dni) {
            printf ("Su saldo actual es:$%d. \n Su maximo de extraccion es:$%d \n",t1->saldo, t1->montoMax);

        } else if (tarjeta->dni == t2->dni) {
            printf ("Su saldo actual es:$%d. \n Su maximo de extraccion es:$%d \n",t2->saldo, t2->montoMax);

        } else if (tarjeta->dni == t3->dni) {
            printf ("Su saldo actual es:$%d. \n Su maximo de extraccion es:$%d \n",t3->saldo, t3->montoMax);

        } else {
            printf ("Su saldo actual es:$%d. \n Su maximo de extraccion es:$%d \n",t4->saldo, t4->montoMax);
        }

    } else if (op == 2) { ////operacion 2: "Extraer dinero"
        if(compararEstructuras(tarjeta, t1)) {
                printf ("Ingrese el monto que desea extraer: ");
                scanf ("%d", &extraccion);

                printf("Espere mientras procesamos su transaccion de retirar %d \n", extraccion);

            if (extraccion <= t1->montoMax && extraccion <= t1->saldo) {
                t1->saldo = t1->saldo - extraccion;
                printf ("\n La extraccion se ha realizado con exito. Su saldo actual es:$%d \n", t1->saldo);

            } else {
                if (extraccion > t1->montoMax) {
                    printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su monto maximo de extraccion \n");

                } else if (extraccion > t1->saldo) {
                    printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su saldo \n");
                }
            }

        } else if (compararEstructuras(tarjeta, t2)) {
            if(compararEstructuras(tarjeta, t2)) {
                    printf ("Ingrese el monto que desea extraer: ");
                    scanf ("%d", &extraccion);

                if ((extraccion <= t2->montoMax) && (extraccion <= t2->saldo)) {
                    t2->saldo = t2->saldo - extraccion;
                    printf ("\n La extraccion se ha realizado con exito. Su saldo actual es:$%d\n",t2->saldo);

                } else {
                    if (extraccion > t2->montoMax) {
                        printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su monto maximo de extraccion \n");

                    } else if (extraccion > t2->saldo) {
                        printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su saldo \n");
                    }
                }
            }

        } else if (compararEstructuras(tarjeta, t3)) {
            if(compararEstructuras(tarjeta, t3)) {
                    printf ("Ingrese el monto que desea extraer: ");
                    scanf ("%d", &extraccion);

                if ((extraccion <= t3->montoMax) && (extraccion <= t3->saldo)) {
                    t3->saldo = t3->saldo - extraccion;

                    printf ("\n La extraccion se ha realizado con exito. Su saldo actual es:$%d\n",t3->saldo);
                } else {
                    if (extraccion > t3->montoMax) {
                        printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su monto maximo de extraccion \n");

                    } else if (extraccion > t3->saldo) {
                        printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su saldo \n");
                    }
                }
            }

        } else if (compararEstructuras(tarjeta, t4)) {
            if(compararEstructuras(tarjeta, t4)) {
                    printf ("Ingrese el monto que desea extraer: ");
                    scanf ("%d", &extraccion);

                if ((extraccion <= t4->montoMax) && (extraccion <= t4->saldo)) {
                    t4->saldo = t4->saldo - extraccion;

                    printf ("\n La extraccion se ha realizado con exito. Su saldo actual es:$%d\n",t4->saldo);
                } else {
                    if (extraccion > t4->montoMax) {
                        printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su monto maximo de extraccion \n");

                    } else if (extraccion > t4->saldo) {
                        printf("\n La extraccion no se ha podido realizar porque el monto que desea extraer supera su saldo \n");
                    }
                }
            }
        }

    } else if (op == 3) { //operacion 3: "Actualizar clave"
        printf("Ingrese la nueva clave (solo se permite una clave numerica entre el rango: 0 - 9999): ");
        scanf("%d", &nuevaClave1);

        printf("Confirmacion de la nueva clave (ingresar nuevamente): ");
        scanf("%d", &nuevaClave2);

        if(compararEstructuras(tarjeta, t1)) {
            if (nuevaClave1 == nuevaClave2) {
                t1->clave = nuevaClave1;

                printf("La clave se ha actualizado con exito \n\n");

                printf("Ingrese su nueva contraseña para volver al menu principal:");
                scanf("%d",&t1->clave);

            } else if (nuevaClave1 != nuevaClave2) {
                printf("Las claves ingresadas no coinciden");
            }

        } else if (compararEstructuras(tarjeta, t2)) {
            if (nuevaClave1 == nuevaClave2) {
                t2->clave = nuevaClave1;

                printf("La clave se ha actualizado con exito \n\n");

                printf("Ingrese su nueva contraseña para volver al menu principal:");
                scanf("%d",&t2->clave);

            } else if (nuevaClave1 != nuevaClave2) {
                printf("Las claves ingresadas no coinciden");
            }

        } else if (compararEstructuras(tarjeta, t3)) {
            if (nuevaClave1 == nuevaClave2) {
                t3->clave = nuevaClave1;

                printf("La clave se ha actualizado con exito \n\n");

                printf("Ingrese su nueva contraseña para volver al menu principal:");
                scanf("%d",&t3->clave);

            } else if (nuevaClave1 != nuevaClave2) {
                printf("Las claves ingresadas no coinciden");
            }

        } else if (compararEstructuras(tarjeta, t4)) {
            if (nuevaClave1 == nuevaClave2) {
                t4->clave = nuevaClave1;

                printf("La clave se ha actualizado con exito \n\n");

                printf("Ingrese su nueva contraseña para volver al menu principal:");
                scanf("%d",&t4->clave);

            } else if (nuevaClave1 != nuevaClave2) {
                printf("Las claves ingresadas no coinciden");
            }
        }

    } else if (op == 4) {////operacion 4: "Modificar limite de extraccion"
        printf("Ingrese el nuevo limite de extraccion: ");
        scanf("%d",&limiteNuevo);

        if(compararEstructuras(tarjeta, t1)){
            t1->montoMax = limiteNuevo;
            printf("Su limite de extraccion ha sido actualizado con exito");

        } else if (compararEstructuras(tarjeta, t2)){
            t2->montoMax = limiteNuevo;
            printf("Su limite de extraccion ha sido actualizado con exito");

        } else if(compararEstructuras(tarjeta, t3)){
            t3->montoMax = limiteNuevo;
            printf("Su limite de extraccion ha sido actualizado con exito");

        } else if(compararEstructuras(tarjeta, t4)){
            t4->montoMax = limiteNuevo;
            printf("Su limite de extraccion ha sido actualizado con exito");
        }

    } else if (op == 5){//operacion 5: "finalizar"
        finalizar = 1;
        printf("Retire su tarjeta por favor \n");

    } else {
        printf("\n Opcion no valida \n");
    }
}

int compararEstructuras (TTarjeta * tarjetaUsuario, TTarjeta * tarjetaRegistrada) {
    int logicToReturn = 1;

    if(tarjetaUsuario->dni != tarjetaRegistrada->dni) {
        logicToReturn = 0;
    }

    if(tarjetaUsuario->clave != tarjetaRegistrada->clave) {
        logicToReturn = 0;
    }

    return logicToReturn;
}