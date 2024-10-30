/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: omen
 *
 * Created on 28 de octubre de 2024, 6:13 p.m.
 */

#ifndef LIBRO_H
#define LIBRO_H

#include "Utils.h"

class Libro {
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(char* nom);
    void GetNombre(char *) const;
    void SetCodigo(char* cod);
    void GetCodigo(char *) const;

};
void operator >>(ifstream &arch,Libro &lib);
void operator <<(ofstream &arch,Libro &lib);

#endif /* LIBRO_H */

