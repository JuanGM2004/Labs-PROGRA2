/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesBiblioteca.h
 * Author: omen
 *
 * Created on 28 de agosto de 2024, 11:04 a.m.
 */

#ifndef FUNCIONESBIBLIOTECA_H
#define FUNCIONESBIBLIOTECA_H

#include <fstream>
using namespace std;
#include "Estructuras.h"



bool operator >>(ifstream &arch, struct Libro &lib);
bool operator >>(ifstream &arch, struct Cliente &cli);
bool operator >>(struct LibroSolicitado &lib,struct Libro *&arrlib);
bool operator <<(struct Cliente &,struct LibroSolicitado &);
void operator ++(struct Cliente &cli);
void operator <<(ofstream &arch,const struct Libro &lib);
void operator <<(ofstream &arch,const struct Cliente &cli);

#endif /* FUNCIONESBIBLIOTECA_H */

