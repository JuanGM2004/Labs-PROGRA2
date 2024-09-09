/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 5 de septiembre de 2024, 9:40 p.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
/*
 * 
 */
int main(int argc, char** argv) {

    struct Cliente arrCli[150]{};
    struct Producto arrPro[180]{};
    struct Pedido arrPed[600]{};
    
    LeerClientes("Clientes.csv",arrCli);
    LeerProductos("Productos.csv",arrPro);
    LeerPedidos("Pedidos.csv",arrPed);
    AtenderPedidos(arrPed,arrPro,arrCli);
    
    EmitirReporteCli("ReporteClientes.txt",arrCli);
    EmitirReportePro("ReporteProductos.txt",arrPro);
    
    
    return 0;
}

