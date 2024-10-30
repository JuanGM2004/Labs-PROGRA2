/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Espacio.h
 * Author: omen
 *
 * Created on 28 de octubre de 2024, 6:25 p.m.
 */

#ifndef ESPACIO_H
#define ESPACIO_H

#include "Utils.h"

class Espacio {
private:
    char contenido;
    int posx;
    int posy;
    
public:
    Espacio();
    Espacio(const Espacio& orig);
    virtual ~Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    void mostrarEspacio(ofstream &);

};

#endif /* ESPACIO_H */

