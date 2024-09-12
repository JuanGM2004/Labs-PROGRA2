/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 8 de septiembre de 2024, 9:57 p.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "FuncionesAuxiliares.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char ***productos,***codigoPedidos;
    int *stock,*fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos,stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",productos,stock,precios);
    
    lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,dniCantPedidos);
    
    reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,precios,
            fechaPedidos,codigoPedidos,dniCantPedidos);
    pruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt",productos,stock,precios);

    
    
    return 0;
}

