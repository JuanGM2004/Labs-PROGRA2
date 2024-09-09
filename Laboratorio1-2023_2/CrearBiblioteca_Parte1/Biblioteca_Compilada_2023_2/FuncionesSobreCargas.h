/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesSobreCargas.h
 * Author: omen
 *
 * Created on 5 de septiembre de 2024, 9:13 p.m.
 */

#ifndef FUNCIONESSOBRECARGAS_H
#define FUNCIONESSOBRECARGAS_H

bool operator >>(ifstream &arch,struct Cliente &cli);
bool operator >>(ifstream &arch,struct Producto &pro);
bool operator >>(ifstream &arch,struct Pedido &ped);

void operator +=(struct Cliente *&arrcli,struct Pedido ped);
bool operator +=(struct Producto *&arrPro,struct Pedido &ped);

void operator <<(ofstream &arch,struct Cliente &cli);
void operator <<(ofstream &arch,struct Producto &pro);

#endif /* FUNCIONESSOBRECARGAS_H */

