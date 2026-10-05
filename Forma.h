//Erika Ivana Salinas Juarez
//Ing. TI 
#ifndef FORMA_H
#define FORMA_H

#include <iostream>
#include <string>
using namespace std;

// ==================== PUNTO ====================

class Punto {
private:
    double x;
    double y;

public:
    Punto(double x = 0, double y = 0);

    void Imprimir() const;
    void Mover(double x, double y);
};

// ==================== FORMA ====================

class Forma {
protected:
    string color;
    Punto centro;
    string nombre;

public:
    Forma(string nombre, string color, Punto centro);
    virtual ~Forma();

    virtual void Imprimir() const;

    string ObtenerColor() const;
    void CambiarColor(string nuevoColor);

    void Mover(double x, double y);

    // Métodos virtuales puros
    virtual double Area() const = 0;
    virtual double Perimetro() const = 0;
};

// ==================== RECTANGULO ====================

class Rectangulo : public Forma {
protected:
    double ladoMenor;
    double ladoMayor;

public:
    Rectangulo(string nombre, string color, Punto centro,
               double menor, double mayor);

    void Imprimir() const override;

    double Area() const override;
    double Perimetro() const override;

    void CambiarTamano(double factor);
};

// ==================== ELIPSE ====================

class Elipse : public Forma {
protected:
    double radioMayor;
    double radioMenor;

public:
    Elipse(string nombre, string color, Punto centro,
           double R, double r);

    void Imprimir() const override;

    double Area() const override;
    double Perimetro() const override;
};

// ==================== CUADRADO ====================

class Cuadrado : public Rectangulo {
public:
    Cuadrado(string color, Punto centro, double lado);

    void Imprimir() const override;
};

// ==================== CIRCULO ====================

class Circulo : public Elipse {
public:
    Circulo(string color, Punto centro, double radio);

    void Imprimir() const override;
};

#endif