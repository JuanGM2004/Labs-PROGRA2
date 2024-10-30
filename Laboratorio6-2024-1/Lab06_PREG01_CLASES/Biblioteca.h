/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: omen
 *
 * Created on 28 de octubre de 2024, 6:53 p.m.
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estante.h"
#include "Libro.h"

class Biblioteca {
private:
    class Estante estantes[10];
    class Libro libros[10];
    int cantidad_estantes;
    int cantidad_libros;
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
    void cargar_libros();
    void cargar_estantes();
    void posicionar_libros();
    void mostrar_datos();

};

#endif /* BIBLIOTECA_H */

