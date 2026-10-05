//Erika Ivana Salinas Juarez
//Ing. TI 
#include "Forma.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << fixed << setprecision(2);

    // ==========================================
    // CREAR DIFERENTES FORMAS
    // ==========================================

    Rectangulo rectangulo(
        "Rectangulo",
        "Rojo",
        Punto(1, 2),
        3,
        5
    );

    Elipse elipse(
        "Elipse",
        "Azul",
        Punto(3, 4),
        4,
        2
    );

    Cuadrado cuadrado(
        "Verde",
        Punto(5, 6),
        4
    );

    Circulo circulo(
        "Amarillo",
        Punto(7, 8),
        3
    );


    // ==========================================
    // PROBAR RECTANGULO
    // ==========================================

    cout << "======================================" << endl;
    cout << "       PRUEBA DEL RECTANGULO" << endl;
    cout << "======================================" << endl;

    rectangulo.Imprimir();

    cout << endl;
    cout << "Cambiando el tamano por un factor de 2..." << endl;

    rectangulo.CambiarTamano(2);

    rectangulo.Imprimir();


    // ==========================================
    // PROBAR COLOR
    // ==========================================

    cout << endl;
    cout << "Color actual del rectangulo: "
         << rectangulo.ObtenerColor() << endl;

    rectangulo.CambiarColor("Negro");

    cout << "Nuevo color: "
         << rectangulo.ObtenerColor() << endl;


    // ==========================================
    // ARREGLO DE PUNTEROS A FORMA
    // ==========================================

    Forma* formas[4];

    formas[0] = &rectangulo;
    formas[1] = &elipse;
    formas[2] = &cuadrado;
    formas[3] = &circulo;


    // ==========================================
    // CAMBIAR COLOR Y POSICION
    // ==========================================

    cout << endl;
    cout << "======================================" << endl;
    cout << " CAMBIANDO COLOR Y POSICION" << endl;
    cout << "======================================" << endl;

    for (int i = 0; i < 4; i++) {

        formas[i]->CambiarColor("Morado");

        formas[i]->Mover(10, 20);
    }


    // ==========================================
    // IMPRIMIR TODAS LAS FORMAS
    // ==========================================

    cout << endl;
    cout << "======================================" << endl;
    cout << "       TODAS LAS FORMAS" << endl;
    cout << "======================================" << endl;

    for (int i = 0; i < 4; i++) {

        formas[i]->Imprimir();
    }


    // ==========================================
    // MOSTRAR AREAS
    // ==========================================

    cout << endl;
    cout << "======================================" << endl;
    cout << "             AREAS" << endl;
    cout << "======================================" << endl;

    for (int i = 0; i < 4; i++) {

        cout << "Area de la forma "
             << i + 1
             << ": "
             << formas[i]->Area()
             << endl;
    }


    // ==========================================
    // ENCONTRAR AREA MAXIMA
    // ==========================================

    Forma* formaMayor = formas[0];

    for (int i = 1; i < 4; i++) {

        if (formas[i]->Area() > formaMayor->Area()) {

            formaMayor = formas[i];
        }
    }


    // ==========================================
    // MOSTRAR FORMA CON MAYOR AREA
    // ==========================================

    cout << endl;
    cout << "======================================" << endl;
    cout << "       FORMA CON MAYOR AREA" << endl;
    cout << "======================================" << endl;

    formaMayor->Imprimir();

    cout << endl;
    cout << "Area maxima: "
         << formaMayor->Area()
         << endl;


    // ==========================================
    // FIN
    // ==========================================

    cout << endl;
    cout << "Programa terminado correctamente." << endl;

    return 0;
}
