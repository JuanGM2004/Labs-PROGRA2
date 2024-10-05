/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: omen
 *
 * Created on 20 de septiembre de 2024, 3:07 p.m.
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

#include <fstream>
using namespace std;
//void AperturaDeUnArchivoDeTextosParaEscribir(std::ofstream& archivo, const char* nombreArchivo);
void cargaclienctes(void *&clientes);
void *LeerRegistro(ifstream &arch);
char *leeCadena(ifstream &arch,char a);
void creareserva(void *&reserva);
void *Leerlibros(ifstream &arch);
void AsignaEspacio(void *&reg,int cant);
void cargarreservar(void *clientes,void *&reserva);
int BuscarCliente(void *clientes,int dni);
bool Verificar(void *arrCli,int dni);
void IngresarDatos(void *arrcli,void *&reserva, char *cod);
bool Coincide(char *cod,void *libros);
void Ingresar(void *arrcli,void *&libros);
void Llenar(void *&par,void* arrcli);
void reporteFinal_2(void *reserva);
void ImprimirLinea(ofstream &arch,char a);
void ImprimirDatos(ofstream &arch,void *arrLib);


#endif /* PUNTEROSGENERICOS_H */

