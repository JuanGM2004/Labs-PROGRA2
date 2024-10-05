/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoExactoDeMemoria.h
 * Author: omen
 *
 * Created on 16 de septiembre de 2024, 7:40 p.m.
 */

#ifndef METODOEXACTODEMEMORIA_H
#define METODOEXACTODEMEMORIA_H

void lecturaDeLibros(const char*nomb,char ***&libros,int **&stock);
void IncrementarEspacios(char ***&libros,int **&stock,int &capacidad, int &cantidad);
char** LeerTriplete(ifstream &arch);
char *leeCadena(ifstream &arch,char a);
int *LeerDoblete(ifstream &arch);
void pruebaDeLecturaDeLibros(const char*nomb,char ***libros,int **stock);
void ImprimirLinea(ofstream &arch,char **libros,int *stock);
void atencionDePedidos(const char*nomb,char ***libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);
void IncreCli(int **&pedidosClientes,int &capCli,int &cantidad);
int BuscarCliente(int **pedidosClientes,int dni);
bool EsCliente(int *pedidosClientes,int dni);
void AsignarDatos(ifstream &arch,int *&pedidosClientes,int nro,int dni,int cap);
void IncreDatCli(int *&pedidosClientes,int &cap,int dni);
void Incremento(char ***&pedidosLibros,bool **&pedidosAtendidos,int &capacidad,
        int &cantidad,int nro);


#endif /* METODOEXACTODEMEMORIA_H */

