/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"

void ImprimirLinea(ofstream &arch,char c){
    for (int i = 0; i < 80; i++) {
        arch<<c;
    }
    arch<<endl;
}
