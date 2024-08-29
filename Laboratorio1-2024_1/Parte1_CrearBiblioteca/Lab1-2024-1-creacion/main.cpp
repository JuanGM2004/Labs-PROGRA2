/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: omen
 *
 * Created on 26 de agosto de 2024, 5:36 p.m.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"

/*
 * 
 */
int main(int argc, char** argv) {

    
    ifstream arch("Libros.csv",ios::in);
    ofstream archRep("Reporte.txt",ios::out);
    struct Libro arrLibros[360];
    struct Cliente arrCli[300];
    int cantLib=0,cantCli=0;
    while(arch>>arrLibros[cantLib]){
        archRep<<left<<setw(10)<<cantLib<<arrLibros[cantLib].codigo<<endl;
        cantLib++;

    }
    strcpy(arrLibros[cantLib].codigo,"FIN");
    ifstream archCli("Cientes.csv",ios::in);
    ofstream archCliR("ReporteCli.txt",ios::out);
    while(archCli>>arrCli[cantCli]){
        archCliR<<left<<setw(10)<<cantCli<<arrCli[cantCli].nombre<<endl;
        cantCli++;
    
    }
    
    return 0;
}

