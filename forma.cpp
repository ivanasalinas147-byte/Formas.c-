//Erika Ivana Salinas Juarez
//Ing. TI 
#include "Forma.h"
#include <cmath>

const double PI = 3.14159265358979323846;

// ==================== PUNTO ====================

Punto::Punto(double x, double y) {
    this->x = x;
    this->y = y;
}

void Punto::Imprimir() const {
    cout << "(" << x << ", " << y << ")";
}

void Punto::Mover(double x, double y) {
    this->x = x;
    this->y = y;
}

// ==================== FORMA ====================

Forma::Forma(string nombre, string color, Punto centro) {
    this->nombre = nombre;
    this->color = color;
    this->centro = centro;
}

Forma::~Forma() {
}

void Forma::Imprimir() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Color: " << color << endl;
    cout << "Centro: ";
    centro.Imprimir();
    cout << endl;
}

string Forma::ObtenerColor() const {
    return color;
}

void Forma::CambiarColor(string nuevoColor) {
    color = nuevoColor;
}

void Forma::Mover(double x, double y) {
    centro.Mover(x, y);
}

// ==================== RECTANGULO ====================

Rectangulo::Rectangulo(string nombre, string color, Punto centro,
                       double menor, double mayor)
    : Forma(nombre, color, centro) {
    ladoMenor = menor;
    ladoMayor = mayor;
}

void Rectangulo::Imprimir() const {
    cout << endl;
    cout << "===== RECTANGULO =====" << endl;

    Forma::Imprimir();

    cout << "Lado menor: " << ladoMenor << endl;
    cout << "Lado mayor: " << ladoMayor << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimetro: " << Perimetro() << endl;
}

double Rectangulo::Area() const {
    return ladoMenor * ladoMayor;
}

double Rectangulo::Perimetro() const {
    return 2 * ladoMenor + 2 * ladoMayor;
}

void Rectangulo::CambiarTamano(double factor) {
    if (factor > 0) {
        ladoMenor = ladoMenor * factor;
        ladoMayor = ladoMayor * factor;
    }
}

// ==================== ELIPSE ====================

Elipse::Elipse(string nombre, string color, Punto centro,
               double R, double r)
    : Forma(nombre, color, centro) {
    radioMayor = R;
    radioMenor = r;
}

void Elipse::Imprimir() const {
    cout << endl;
    cout << "===== ELIPSE =====" << endl;

    Forma::Imprimir();

    cout << "Radio mayor: " << radioMayor << endl;
    cout << "Radio menor: " << radioMenor << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimetro aproximado: " << Perimetro() << endl;
}

double Elipse::Area() const {
    return PI * radioMayor * radioMenor;
}

double Elipse::Perimetro() const {
    double a = radioMayor;
    double b = radioMenor;

    double h = pow(a - b, 2) / pow(a + b, 2);

    return PI * (a + b) *
           (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
}

// ==================== CUADRADO ====================

Cuadrado::Cuadrado(string color, Punto centro, double lado)
    : Rectangulo("Cuadrado", color, centro, lado, lado) {
}

void Cuadrado::Imprimir() const {
    cout << endl;
    cout << "===== CUADRADO =====" << endl;

    Forma::Imprimir();

    cout << "Lado: " << ladoMenor << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimetro: " << Perimetro() << endl;
}

// ==================== CIRCULO ====================

Circulo::Circulo(string color, Punto centro, double radio)
    : Elipse("Circulo", color, centro, radio, radio) {
}

void Circulo::Imprimir() const {
    cout << endl;
    cout << "===== CIRCULO =====" << endl;

    Forma::Imprimir();

    cout << "Radio: " << radioMayor << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimetro: " << Perimetro() << endl;
}
