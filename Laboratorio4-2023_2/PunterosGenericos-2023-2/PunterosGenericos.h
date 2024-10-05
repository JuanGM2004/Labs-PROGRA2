/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: omen
 *
 * Created on 25 de septiembre de 2024, 11:42 a.m.
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaproductos(void *&productos);
void *LeerDatos(ifstream &arch);
char *LeeCadena(ifstream &arch);

void cargaclientes(void *&clientes);
void *LeerCliente(ifstream &arch);

void cargapedidos(void *productos,void *&clientes);
int BuscarProducto(void *productos,char *cod);
bool Comparar(void *arr,char *cod);
int BuscarCliente(void *clientes,int dni);
bool Verificar(void *arr,int dni);
void *LeerPed(void *prod,char *cod,int dni,int cant);
void AgregarPedido(void *&cli,void *pedido,char *letra);


#endif /* PUNTEROSGENERICOS_H */

