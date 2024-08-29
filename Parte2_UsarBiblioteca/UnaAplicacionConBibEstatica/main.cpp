/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 28 de agosto de 2024, 11:31 a.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "FuncionesAuxiliares.h"
#include "Estructuras.h"
#include "FuncionesBiblioteca.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    struct Libro arrLib[360];
    struct Cliente arrCli[300];
    LeerLibros(arrLib);
    LeerClientes(arrCli);
    LeePedidos("Pedidos.txt",arrCli,arrLib);
    EmitirReporte("Reporte de ventas.txt",arrCli);
    
    return 0;
}

