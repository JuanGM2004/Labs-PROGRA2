/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 28 de agosto de 2024, 11:11 a.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesBiblioteca.h"
#include "Estructuras.h"


/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream archLib("Libros.csv",ios::in);
    if(not archLib.is_open()){
        cout<<"No se pudo abrir el archivo libros"<<endl;
    }
    ifstream archCli("Cientes.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"No se pudo abrir el archivo clientes"<<endl;
    }
    struct Libro arrLib[360];
    struct Cliente arrCli[300];
    int cantLib=0,cantCli=0;
    while(archLib>>arrLib[cantLib])cantLib++;
    while(archCli>>arrCli[cantCli])cantCli++;
    strcpy(arrLib[cantLib].codigo,"FIN");
    
    ofstream archCliR("ReporteCli.txt",ios::out);
    ofstream archLibR("ReporteLib.txt",ios::out);
    
    for (int i = 0; i < cantLib; i++) {
        archLibR<<arrLib[i];
    }
    for (int i = 0; i < cantCli; i++) {
        archCliR<<arrCli[i];
    }

    
    return 0;
}

