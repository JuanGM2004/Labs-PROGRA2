/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 28 de octubre de 2024, 6:10 p.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Biblioteca.h"


/*
 * 
 */
int main(int argc, char** argv) {
    Biblioteca biblio;
    biblio.cargar_libros();
    biblio.cargar_estantes();
    biblio.posicionar_libros();
    biblio.mostrar_datos();
    return 0;
}

