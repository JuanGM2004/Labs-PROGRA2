/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 10 de octubre de 2024, 12:29 p.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Utils.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int numcamiones;
    double pesomaximo;
    void *flota;
    
    numcamiones=5;
    pesomaximo=10;
    cargacamiones(flota,numcamiones,pesomaximo,leenumero,calculanumero,"numeros.txt");
//    qsort(flota,numcamiones,sizeof(void*),cmpnumero);
    
    return 0;
}

