/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: omen
 *
 * Created on 29 de agosto de 2024, 8:34 p.m.
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

void lecturaDeLibros(const char*nombArch,char ***&libros,int **&stock);
void LeerTriplete(ifstream &arch,char **&buffLib);
void LeerPar(ifstream &arch,int *&buffStock);
char *LeeCadena(ifstream &arch);
void pruebaDeLecturaDeLibros(const char*nombArch, char ***libros,
         int **stock);
void ImpresionDeDatos(ofstream &arch, char **libro, int *stock);

#endif /* METODOEXACTODEMEMORIA_H */

