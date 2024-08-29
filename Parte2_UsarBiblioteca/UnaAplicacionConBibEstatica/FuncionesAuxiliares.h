/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: omen
 *
 * Created on 28 de agosto de 2024, 11:36 a.m.
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include "Estructuras.h"

void LeerLibros(struct Libro *arrLib);
void LeerClientes(struct Cliente *arrCli);
void LeePedidos(const char*nombArch,struct Cliente *arrcli,struct Libro *arrLib);
int Buscar(int dni,const struct Cliente *arrcli);
void EmitirReporte(const char*nomb,const struct Cliente *arrCli);


#endif /* FUNCIONESAUXILIARES_H */

