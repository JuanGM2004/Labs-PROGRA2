/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: omen
 * 
 * Created on 28 de octubre de 2024, 6:31 p.m.
 */

#include "Utils.h"
#include "Estante.h"
#include "Espacio.h"
#include "FuncionesAuxiliares.h"


Estante::Estante() {
    codigo=nullptr;
    cantidad_libros=0;
}

Estante::Estante(const Estante& orig) {
    char cod[10]{};
    orig.GetCodigo(cod);
    SetCodigo(cod);
    SetAltura(orig.GetAltura());
    SetAnchura(orig.GetAnchura());
    SetCantidad_libros(orig.GetCantidad_libros());
    
}

Estante::~Estante() {
    if(codigo!=nullptr) delete codigo;
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(char* cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1]{};
    strcpy(codigo,cod);
}

void Estante::GetCodigo(char *cod) const {
    if(codigo==nullptr) cod[0]=0;
    else strcpy(cod,codigo);
}

void Estante::MostrarEstante(ofstream&arch){
    for (int i = 1; i <=altura*anchura; i++) {
        espacios[i-1].mostrarEspacio(arch);
        if(i%anchura==0)arch<<endl;
    }
}

void operator >>(ifstream &arch,Estante &est){
    int alt,anch;
    char cod[10]{};
    arch.getline(cod,10,',');
    if(arch.eof())return;
    arch>>alt;
    arch.get();
    arch>>anch;
    arch.get();
    
    est.SetCodigo(cod);
    est.SetAltura(alt);
    est.SetAnchura(anch);
    
    est.DefinirEspacios(alt,anch);
    
}
void Estante::DefinirEspacios(int alt,int anch){
    espacios=new class Espacio[alt*anch]{};
}

bool Estante::operator+=(Libro &lib){
    if(EspaciosSobrantes(lib.GetAlto(),lib.GetAncho())){
        lib.SetColocado(true);
        libros[cantidad_libros]=lib;
        InsertarLibro(lib);
        
        SetCantidad_libros(GetCantidad_libros()+1);
        return true;
    }
    lib.SetColocado(false);
    return false;
}

void Estante::InsertarLibro(Libro &lib){
    int inicio=0;
    
    while(espacios[inicio+(altura-1)*(anchura)].GetContenido()=='*')inicio++;
    for (int i = 0; i < lib.GetAncho(); i++) {
        for (int j = 0; j < lib.GetAlto(); j++) {
            espacios[inicio+i+(altura-j-1)*(anchura)].SetContenido('*');
            //espacios[inicio+(altura-j)*(anchura-1+i)];
        }
    }
}

bool Estante::EspaciosSobrantes(int alt, int anch){
    if(altura<alt) return false;
    int espacio;
    for ( espacio = 0; espacios[espacio+(altura-1)*(anchura)].GetContenido()=='*'; espacio++);
    return anch<=(anchura-espacio);
}


void operator <<(ofstream &arch,Estante &est){
    char cod[10]{};
    est.GetCodigo(cod);
    ImprimirLinea(arch,'-');
    arch<<left<<"Codigo Estante: "<<setw(10)<<cod<<"Cantidad de Libros: "<<
            est.GetCantidad_libros()<<endl;
    arch<<"Anchura del Estante: "<<setw(10)<<est.GetAnchura()<<
            "Altura del Estante :"<<est.GetAltura()<<endl;
    ImprimirLinea(arch,'-');
    arch<<endl;
    est.MostrarEstante(arch);
    arch<<endl;
    arch<<left<<setw(10)<<"CODIGO"<<setw(50)<<"NOMBRE"<<setw(10)<<"ANCHO"<<
            setw(10)<<"ALTO"<<endl;
    ImprimirLinea(arch,'.');
    est.MostrarLibros(arch);

    arch<<endl;
    
}

void Estante::MostrarLibros(ofstream& arch){
    for (int i = 0; i < cantidad_libros; i++) {
        arch<<libros[i];
    }

}