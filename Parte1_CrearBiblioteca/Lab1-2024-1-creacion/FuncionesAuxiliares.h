/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: omen
 *
 * Created on 26 de agosto de 2024, 5:39 p.m.
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

bool operator >>(ifstream &arch, struct Libro &lib);
bool operator >>(ifstream &arch, struct Cliente &cli);
bool operator >>(struct LibroSolicitado &lib,struct Libro *&arrlib);
bool operator <<(struct Cliente &,struct LibroSolicitado &);
void operator ++(struct Cliente &cli);
void operator <<(ofstream &arch,const struct Libro &lib);
void operator <<(ofstream &arch,const struct Cliente &cli);


#endif /* FUNCIONESAUXILIARES_H */

