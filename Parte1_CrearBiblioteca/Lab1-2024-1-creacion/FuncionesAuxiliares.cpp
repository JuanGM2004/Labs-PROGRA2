/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "Estructuras.h"


bool operator >>(ifstream &arch, struct Libro &lib){
    char cod[10],titu[80],autor[80];
    int stock;
    double precio;
    
    arch.getline(cod,10,',');
//    if(arch.eof())return false;
    arch.getline(titu,80,',');
    arch.getline(autor,80,',');
    arch>>stock;
    arch.get();
    arch>>precio;
    strcpy(lib.autor,autor);
    strcpy(lib.codigo,cod);
    strcpy(lib.tiltulo,titu);
    lib.stock=stock;
    lib.precio=precio;
    arch.get();
    if(arch.eof())return false;

    return true;
}


bool operator >>(ifstream &arch, struct Cliente &cli){
    int dni;
    char nom[80];
    arch>>dni;
    if(arch.eof())return false;
    arch.get();
    arch.getline(nom,80,'\n');
    cli.dni=dni;
    strcpy(cli.nombre,nom);
    return true;
}


bool operator >>(struct LibroSolicitado &lib,struct Libro *&arrlib){
    for(int i=0;strcmp(arrlib[i].codigo,"FIN")!=0;i++){
        if(strcmp(arrlib[i].codigo,lib.codigoDelLibro)==0){
            if(arrlib[i].stock>0){
                arrlib[i].stock--;
                lib.precio=arrlib[i].precio;
                lib.atendido=true;
            }
            else{
                lib.atendido=false;
            }
        }
    }
    
}

bool operator <<(struct Cliente &cli,struct LibroSolicitado &lib){
    if(cli.cantDeLibros<30){
        cli.librosSolicitados[cli.cantDeLibros]=lib;
        cli.cantDeLibros++;
        return true;
    }
    return false;
}

void operator ++(struct Cliente &cli){
    for (int i = 0; i < cli.cantDeLibros; i++) {
         cli.pagoTotal += cli.librosSolicitados[i].precio;
    }
}

void operator <<(ofstream &arch,const struct Libro &lib){
    arch<<left<<setw(10)<<lib.codigo<<setw(60)<<lib.tiltulo<<setw(50)<<lib.autor
            <<setw(10)<<lib.stock<<right<<setw(10)<<lib.precio<<endl;
}

void operator <<(ofstream &arch,const struct Cliente &cli){
    arch<<left<<setw(12)<<cli.dni<<setw(60)<<cli.nombre<<endl;
    arch<<"Libros entregados:"<<endl;
    arch<<left<<setw(10)<<" "<<setw(16)<<"Pedido No."<<setw(12)<<"Codigo"<<"Precio"<<endl;
    for (int i = 0; i < cli.cantDeLibros; i++) {
            arch<<left<<setw(10)<<" "<<setw(14)<<cli.librosSolicitados[i].numeroDePedido
                    <<setw(12)<<cli.librosSolicitados[i].codigoDelLibro<<
                    cli.librosSolicitados[i].precio<<endl;


    }

}

