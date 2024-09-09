/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 5 de septiembre de 2024, 10:29 a.m.
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "FuncionesSobreCargas.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
/*
 * 
 */
int main(int argc, char** argv) {

    ifstream archCli,archPro,archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPro,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.csv");
    
    struct Cliente arrCli[150]{};
    struct Producto arrPro[180]{};
    struct Pedido arrPed[600]{};
    int cantCli=0,cantPro=0,cantPed=0;
    while(archCli>>arrCli[cantCli])cantCli++;
    arrCli[cantCli].dni=0;
    
    while(archPro>>arrPro[cantPro])cantPro++;
    strcpy(arrPro[cantPro].codigo,"XXX");
    
    while(archPed>>arrPed[cantPed])cantPed++;
    arrPed[cantPed].dniCliente=0;
    ofstream archCliR,archProR,archPedR;
    AperturaDeUnArchivoDeTextosParaEscribir(archCliR,"ReporteClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archProR,"ReporteProductos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archPedR,"ReportePedidos.txt");
    
    for (int i = 0;arrCli[i].dni; i++) {
        archCliR<<arrCli[i];
    }
    for (int i = 0;strcmp(arrPro[i].codigo,"XXX"); i++) {
        archProR<<arrPro[i];

    }
    for (int i = 0;arrPed[i].dniCliente; i++) {
        archPedR<<left<<setw(10)<<arrPed[i].dniCliente<<setw(12)<<
                arrPed[i].CodigoProducto<<endl;

    }

    
    
    return 0;
}

