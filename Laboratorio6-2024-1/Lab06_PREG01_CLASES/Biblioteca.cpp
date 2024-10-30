/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: omen
 * 
 * Created on 28 de octubre de 2024, 6:53 p.m.
 */

#include "Biblioteca.h"
#include "FuncionesAuxiliares.h"
Biblioteca::Biblioteca() {
    cantidad_estantes=0;
    cantidad_libros=0;
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::cargar_libros(){
    ifstream arch("libros.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    
    int can;
    while(true){
        arch>>libros[cantidad_libros];
        if(arch.eof())break;
        cantidad_libros++;
    }
    
    
}

void Biblioteca::cargar_estantes(){
    ifstream arch("estantes.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(true){
        arch>>estantes[cantidad_estantes];
        if(arch.eof())break;
        cantidad_estantes++;
    }
    
}

void Biblioteca::posicionar_libros(){
    int num=0;
    for (int i = 0; i < cantidad_libros and num<cantidad_estantes; i++) {
        if(not (estantes[num]+=libros[i])){
            num++;
            i--;
        }
    }

}

void Biblioteca::mostrar_datos(){
    ofstream arch("Librosrep.txt",ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    for (int i = 0; i < cantidad_libros; i++) {
        arch<<libros[i];
    }
    
    ofstream archEst("Estantes.txt",ios::out);
    if(not archEst.is_open()){
        cout<<"No se pudo abri el archivo"<<endl;
        exit(1);
    }
    ImprimirLinea(archEst,'=');
    archEst<<setw(55)<<"Informacion del posicionamiento de Libros"<<endl;
    archEst<<setw(50)<<"en los estantes de la Biblioteca"<<endl;
    ImprimirLinea(archEst,'=');
    archEst<<left<<setw(20)<<"Cantidad de Estantes: "<<cantidad_estantes<<endl;
    
    for (int i = 0; i < cantidad_estantes; i++) {
        archEst<<estantes[i];
//        ImprimirLinea(archEst,'-');
    }

}