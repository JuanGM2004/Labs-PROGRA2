/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesRegistros.h
 * Author: omen
 *
 * Created on 8 de octubre de 2024, 2:58 p.m.
 */

#ifndef FUNCIONESREGISTROS_H
#define FUNCIONESREGISTROS_H



void *leeregistro(ifstream &arch);

void imprimeregistro(ofstream &arch,void *nodo);

int cmpregistro(void *li1,void *li2);

#endif /* FUNCIONESREGISTROS_H */

