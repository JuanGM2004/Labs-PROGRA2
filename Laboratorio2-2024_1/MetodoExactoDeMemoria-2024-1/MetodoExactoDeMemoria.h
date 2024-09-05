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

void atencionePedidos(const char*nomb,char ***libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);

int BuscarCli(int dni,int **pedidosClientes);
bool MismoDNI(int dni,int *pedidosClientes);

void Inicializar(int *&pedidosClientes,int dni);
void LlenarDatos(ifstream &arch,int *&buffCli,char **&buffLib,bool *&buffAten,int nro,
char ***libros,int **&stock);

char *leecadena(ifstream &arch);

void ClientesExactos(int *&pedidosClientes,int *&buffCli);
int BuscarLib(char ***libros,char *pt);

bool MismoCod(char **libros,char *pt);
bool HayStock(int *&stock);


void reporteDeEntregaDePedidos(const char*nomb,int **pedidosClientes,
        char ***pedidosLibros,bool **pedidosAtendidos);
void ImprimirLinea(ofstream &arch,char a);
void ImprimirCli(ofstream &arch,int *cli,char ***pedidosLibros,bool **pedidosAtendidos);
void ImprimirPedidos(ofstream &arch,char **pedidosLibros,bool *pedidosAtendidos,int pos,int);


#endif /* METODOEXACTODEMEMORIA_H */

