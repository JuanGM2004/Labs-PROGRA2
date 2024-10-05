/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 20 de septiembre de 2024, 2:18 p.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "MuestraPunteroGenerico.h"
#include "PunterosGenericos.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    void *clientes,*reserva;
    
    cargaclienctes(clientes);
//    muestraclientes(clientes);
    creareserva(reserva);
    muestrareservas(reserva);
    cargarreservar(clientes,reserva);
    reporteFinal_2(reserva);
//    reportefinal(reserva);
    
    
    return 0;
}

