/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 25 de septiembre de 2024, 11:38 a.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
/*
 * 
 */
int main(int argc, char** argv) {

    void *productos,*clientes;
    
    cargaproductos(productos);
//    imprimeproductos(productos);
    cargaclientes(clientes);
    imprimeclientes(clientes);
    cargapedidos(productos,clientes);
    imprimerepfinal(clientes);
    return 0;
}

