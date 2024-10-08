/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaGenerica.h
 * Author: omen
 *
 * Created on 7 de octubre de 2024, 8:28 p.m.
 */

#ifndef BIBLIOTECAGENERICA_H
#define BIBLIOTECAGENERICA_H
#include <fstream>
using namespace std;
void crealista(void *&pedidos1,void *(*lee)(ifstream &),const char*nomb);
void insertalista(void *lista,void *nodo);
void inicializarlista(void *&pedidos1);
bool listavacia(void *lista);
void imprimelista(void *pedidos1,void (*imprime)(ofstream &,void *),const char*nomb);
void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,int (*cmp)(void *,void *));
void *quitalista(void *&ped);


#endif /* BIBLIOTECAGENERICA_H */

