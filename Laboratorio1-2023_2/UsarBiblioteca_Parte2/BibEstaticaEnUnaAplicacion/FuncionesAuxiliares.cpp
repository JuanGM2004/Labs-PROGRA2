/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "FuncionesAuxiliares.h"
#include "FuncionesSobreCargas.h"
#include "AperturaDeArchivos.h"
#include "Estructuras.h"


void LeerClientes(const char*nomb,struct Cliente *arrCli){
    ifstream archCli;
    AperturaDeUnArchivoDeTextosParaLeer(archCli,nomb);
    int cant=0;
    while(archCli>>arrCli[cant])cant++;
    arrCli[cant].dni=0;
}

void LeerProductos(const char*nomb,struct Producto *arrPro){
    ifstream archPro;
    AperturaDeUnArchivoDeTextosParaLeer(archPro,nomb);
    int cant=0;
    while(archPro>>arrPro[cant])cant++;
    strcpy(arrPro[cant].codigo,"XXX");
}

void LeerPedidos(const char*nomb,struct Pedido *arrPed){
    ifstream archPed;
    AperturaDeUnArchivoDeTextosParaLeer(archPed,nomb);
    int cant=0;
    while(archPed>>arrPed[cant])cant++;
    arrPed[cant].dniCliente=0;
}

void AtenderPedidos(struct Pedido *arrPed,struct Producto *arrPro,
        struct Cliente *arrCli){
    for (int i = 0;arrPed[i].dniCliente; i++) {
        if(arrPro+=arrPed[i]){
            arrCli+=arrPed[i];
        }
    }
}


void EmitirReporteCli(const char*nomb,struct Cliente *arrCli){
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nomb);
    for (int i = 0;arrCli[i].dni; i++) {
        archRep<<arrCli[i];
    }

}
void EmitirReportePro(const char*nomb,struct Producto *arrPro){
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,nomb);
    for (int i = 0;strcmp(arrPro[i].codigo,"XXX"); i++) {
        archRep<<arrPro[i];

    }

}
