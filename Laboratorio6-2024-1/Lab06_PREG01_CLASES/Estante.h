/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: omen
 *
 * Created on 28 de octubre de 2024, 6:31 p.m.
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include "Libro.h"
#include "Espacio.h"

class Estante {
private:
    char *codigo;
    int anchura;
    int altura;
    class Libro libros[10];
    class Espacio *espacios;
    int cantidad_libros;
    
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(char* cod);
    void GetCodigo(char *cod) const;
    void MostrarEstante(ofstream &);
    bool operator +=(Libro &lib);
    bool EspaciosSobrantes(int alt,int anch); 
    void DefinirEspacios(int alt,int anch);
    void InsertarLibro(Libro &lib);
    void MostrarLibros(ofstream &arch);
};
void operator >>(ifstream &arch,Estante &est);
void operator <<(ofstream &arch,Estante &est);

#endif /* ESTANTE_H */

