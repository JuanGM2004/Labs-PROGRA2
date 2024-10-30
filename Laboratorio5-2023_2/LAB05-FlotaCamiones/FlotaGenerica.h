/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: omen
 *
 * Created on 10 de octubre de 2024, 1:29 p.m.
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

void cargacamiones(void *flota,int numcamiones,double pesomaximo,void *(*leenumero)(ifstream &),void *(*calculanumero)(void *),const char*nomb);
void inicializarPila(void *&flota);
void push(void *dato,void *flota);


#endif /* FLOTAGENERICA_H */

