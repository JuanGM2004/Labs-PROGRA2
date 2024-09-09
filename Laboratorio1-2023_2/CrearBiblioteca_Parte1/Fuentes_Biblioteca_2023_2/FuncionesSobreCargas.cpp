/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;
#include "Estructuras.h"
#include "FuncionesSobreCargas.h"

bool operator >>(ifstream &arch,struct Cliente &cli){
    int dni,tele;
    char nomb[70];
    
    arch>>dni;
    if(arch.eof())return false;
    arch.get();
    arch.getline(nomb,70,',');
    arch>>tele;
    
    cli.dni=dni;
    strcpy(cli.nombre,nomb);
    cli.telefono=tele;
    cli.cantidadProductosEntrgados=0;
    cli.montoTotal=0;
    return true;
}
bool operator >>(ifstream &arch,struct Producto &pro){
    char cod[8]{},desc[60]{};
    int stock;
    double precio;
    arch.getline(cod,8,',');
    if(arch.eof())return false;
    arch.getline(desc,60,',');
    arch>>precio;
    arch.get();
    arch>>stock;
    strcpy(pro.codigo,cod);
    strcpy(pro.descripcion,desc);
    pro.stock=stock;
    pro.precio=precio;
    pro.cantidadClientesNoServidos=0;
    pro.cantidadClientesServidos=0;
    arch.get();
    return true;
}
bool operator >>(ifstream &arch,struct Pedido &ped){
    char cod[8]{};
    int dni;
    arch.getline(cod,8,',');
    arch>>dni;
    arch.get();
    if(arch.eof())return false;
    strcpy(ped.CodigoProducto,cod);
    ped.dniCliente=dni;
    return true;
}

void operator +=(struct Cliente *&arrcli,struct Pedido ped){
    int cant;
    for (int i = 0;arrcli[i].dni; i++) {
        if(arrcli[i].dni==ped.dniCliente){
            cant=arrcli[i].cantidadProductosEntrgados;
            strcpy(arrcli[i].productosEntregados[cant].codigo,ped.CodigoProducto);
            arrcli[i].productosEntregados[cant].precio=ped.precioProducto;
            arrcli[i].cantidadProductosEntrgados++;
            arrcli[i].montoTotal+=ped.precioProducto;
            break;
        }
    }
}

bool operator +=(struct Producto *&arrPro,struct Pedido &ped){
    int cant;
    for (int i = 0;strcmp(arrPro[i].codigo,"XXX"); i++) {
        if(strcmp(arrPro[i].codigo,ped.CodigoProducto)==0){
            if(arrPro[i].stock>0){
                cant=arrPro[i].cantidadClientesServidos;
                arrPro[i].clientesServidos[cant]=ped.dniCliente;
                arrPro[i].cantidadClientesServidos++;
                arrPro[i].stock--;
                ped.precioProducto=arrPro[i].precio;
                return true;
            }
            else{
                cant=arrPro[i].cantidadClientesNoServidos;
                arrPro[i].clientesNoServidos[cant]=ped.dniCliente;
                arrPro[i].cantidadClientesNoServidos++;
                ped.precioProducto=arrPro[i].precio;
                return false;
            }
            
        }

    }

}

void operator <<(ofstream &arch,struct Cliente &cli){
    arch<<left<<setw(10)<<cli.dni<<setw(50)<<cli.nombre<<setw(12)<<cli.telefono<<
            setw(10)<<cli.montoTotal<<setw(20)<<"Productos entregados: ";
    for (int i = 0; i < cli.cantidadProductosEntrgados; i++) {
        arch<<setw(10)<<cli.productosEntregados[i].codigo;
    }
    arch<<endl;

}

void operator <<(ofstream &arch,struct Producto &pro){
    arch<<left<<setw(10)<<pro.codigo<<setw(50)<<pro.descripcion<<setw(10)<<
            pro.precio<<setw(8)<<pro.stock<<endl;
    arch<<left<<setw(30)<<"Clientes atendidos: ";
    for (int i = 0; i < pro.cantidadClientesServidos; i++) {
        arch<<pro.clientesServidos[i]<<" ";
    }
    arch<<endl;
    arch<<left<<setw(30)<<"Clientes no atendidos";
    for (int i = 0; i < pro.cantidadClientesNoServidos; i++) {
        arch<<pro.clientesNoServidos[i]<<" ";
    }
    arch<<endl;
}
