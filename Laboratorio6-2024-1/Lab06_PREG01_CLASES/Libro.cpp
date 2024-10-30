/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: omen
 * 
 * Created on 28 de octubre de 2024, 6:13 p.m.
 */

#include "Libro.h"
#include "Utils.h"
#include "Estante.h"


Libro::Libro() {
    codigo=nullptr;
    nombre=nullptr;
    colocado=false;
}

Libro::Libro(const Libro& orig) {
    char cod[10]{},nom[50]{};
    orig.GetCodigo(cod);
    orig.GetNombre(nom);
    SetCodigo(cod);
    SetNombre(nom);
    SetAlto(orig.GetAlto());
    SetAncho(orig.GetAncho());
    SetColocado(orig.IsColocado());
}

Libro::~Libro() {
    if(codigo!=nullptr) delete codigo;
    if(nombre!=nullptr) delete nombre;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(char* nom) {
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nom)+1]{};
    strcpy(nombre,nom);
}

void Libro::GetNombre(char *nom) const {
    if(nombre==nullptr) nom[0]=0;
    else strcpy(nom,nombre);
}

void Libro::SetCodigo(char* cod) {
    if(codigo!=nullptr) delete codigo;
    codigo=new char[strlen(cod)+1]{};
    strcpy(codigo,cod);
}

void Libro::GetCodigo(char *cod) const {
    if(codigo==nullptr)cod[0]=0;
    else strcpy(cod,codigo);
}


void operator >>(ifstream &arch,Libro &lib){
    int alt,anch;
    char cod[10]{},nom[60]{};
    arch.getline(cod,10,',');
    if(arch.eof())return;
    arch.getline(nom,60,',');
    arch>>anch;
    arch.get();
    arch>>alt;
    arch.get();
    
    lib.SetCodigo(cod);
    lib.SetNombre(nom);
    lib.SetAlto(alt);
    lib.SetAncho(anch);
    
}


void operator <<(ofstream &arch,Libro &lib){
    char cod[10]{},nombre[60]{};
    lib.GetCodigo(cod);
    lib.GetNombre(nombre);
    arch<<left<<setw(10)<<cod<<setw(50)<<nombre<<setw(10)<<lib.GetAncho()<<
            setw(10)<<lib.GetAlto()<<endl;
}

