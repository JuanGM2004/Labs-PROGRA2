/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: omen
 *
 * Created on 8 de septiembre de 2024, 10:31 p.m.
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void lecturaDeProductos(const char*nomb,char ***&productos,int *&stock,double *&precios);
void LeerDoblete(ifstream &arch,char **&buffPro);
char *LeeCadena(ifstream &arch);
void pruebaDeLecturaDeProductos(const char*nomb,char ***productos,int *stock,double *precios);
void ImprimirFila(ofstream &arch,char **productos,int stock,double precios);
void ImprimirLinea(ofstream &arch,char a);

void lecturaDePedidos(const char*nomb,int *&fechaPedidos,char ***&codigoPedidos
,int ***&dniCantPedidos);
void pruebaDeLecturaDePedidos(const char*nomb,int *fechaPedidos,
        char ***codigoPedidos,int ***dniCantPedidos);
void ImprimirLectura(ofstream &arch,char **codigoPedidos,int **dniCantPedidos,
        int fechaPedidos);
void ImprimirPar(ofstream &arch,int *dniCantPedidos);

int BuscarFecha(int fecha,int *buffFecha);
void Inicializar(int &buffFecha,int **&buffDni,char **&buffCod,int fecha,
        char *cod,int dni,int cant);
void AgregarDatos(char **&buffCod,int **&buffDni,int nd,char *cod,int dni,int cant);
void EspaciosExactos(int nd,int **&buffDni,char **&buffCod);



void reporteDeEnvioDePedidos(const char*nomb,char***productos,int*stock,double *precios,
        int *fechaPedidos,char***codigoPedidos,int***dniCantPedidos);
void ImprimirPedidos(ofstream &arch,int fechaPedidos,char **codigoPedidos,int **dniCantPedidos,
        char ***productos,double *precios,int *stock);
void ImprimirPed(ofstream &arch,int i,char *codigoPedidos,int *dniCantPedidos,
        double &monto,double &montoperdido,double pre,char **producto, int &stock);

int BuscarProducto(char *,char ***productos);
bool Comparar(char *cod,char **productos);

#endif /* FUNCIONESAUXILIARES_H */

