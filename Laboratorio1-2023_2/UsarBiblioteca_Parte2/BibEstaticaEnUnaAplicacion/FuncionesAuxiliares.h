/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: omen
 *
 * Created on 5 de septiembre de 2024, 9:44 p.m.
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void LeerClientes(const char*nomb,struct Cliente *arrCli);
void LeerProductos(const char*nomb,struct Producto *arrPro);
void LeerPedidos(const char*nomb,struct Pedido *arrPed);
void AtenderPedidos(struct Pedido *arrPed,struct Producto *arrPro,
        struct Cliente *arrCli);
void EmitirReporteCli(const char*nomb,struct Cliente *arrCli);
void EmitirReportePro(const char*nomb,struct Producto *arrPro);

#endif /* FUNCIONESAUXILIARES_H */

