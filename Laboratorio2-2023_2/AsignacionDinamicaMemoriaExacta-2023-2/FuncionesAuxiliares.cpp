/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

void lecturaDeProductos(const char*nomb,char ***&productos,int *&stock,double *&precios){
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    char **buffPro[200]{};
    double buffPre[200]{},pre;
    int buffStock[200]{},cantPro=0,sto;
    while(true){
        LeerDoblete(arch,buffPro[cantPro]);
        if(arch.eof())break;
        arch>>pre;
        arch.get();
        arch>>sto;
        buffPre[cantPro]=pre;
        buffStock[cantPro]=sto;
        cantPro++;
        arch.get();
    }
    productos=new char**[cantPro+1]{};
    stock=new int[cantPro+1]{};
    precios=new double[cantPro+1]{};
    for (int i = 0; i < cantPro; i++) {
        productos[i]=buffPro[i];
        precios[i]=buffPre[i];
        stock[i]=buffStock[i];
    }
}

void LeerDoblete(ifstream &arch,char **&buffPro){
    buffPro=new char*[2];
    char *cod,*desc;
    cod=LeeCadena(arch);
    if(cod==nullptr)return;
    desc=LeeCadena(arch);
    buffPro[0]=cod;
    buffPro[1]=desc;
}

char *LeeCadena(ifstream &arch){
    char buff[80],*pt;
    arch.getline(buff,80,',');
    if(arch.eof())return nullptr;
    pt=new char[strlen(buff)+1];
    strcpy(pt,buff);
    return pt;
}


void pruebaDeLecturaDeProductos(const char*nomb,char ***productos,int *stock,double *precios){
    ofstream arch(nomb,ios::out);
    if(not arch.is_open()){
        arch<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"CODIGO"<<setw(60)<<"DESCRIPCION"<<right<<setw(10)<<"PRECIO"
            <<setw(10)<<"STOCK"<<endl;
    ImprimirLinea(arch,'=');
    for (int i = 0;stock[i]; i++) {
        ImprimirFila(arch,productos[i],stock[i],precios[i]);
        ImprimirLinea(arch,'-');
    }
}

void ImprimirFila(ofstream &arch,char **productos,int stock,double precios){
    arch<<left<<setw(10)<<productos[0]<<setw(60)<<productos[1]<<right<<setw(10)
            <<precios<<setw(10)<<stock<<endl;    
}

void ImprimirLinea(ofstream &arch,char a){
    for (int i = 0; i < 120; i++) {
        arch<<a;
    }
    arch<<endl;
}

void lecturaDePedidos(const char*nomb,int *&fechaPedidos,char ***&codigoPedidos
,int ***&dniCantPedidos){
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    int buffFecha[150]{},**buffDni[150]{},cantFech=0,fecha,a,m,d,dni,cant;
    char **buffCod[150]{},car,*cod;
    int pos,nd[150]{};
    while(true){
        cod=LeeCadena(arch);
        if(cod==nullptr)break;
        arch>>dni>>car>>cant>>car>>d>>car>>m>>car>>a;
        arch.get();
        fecha=a*10000+m*100+d;
        pos=BuscarFecha(fecha,buffFecha);
        
        if(pos==-1){
            Inicializar(buffFecha[cantFech],buffDni[cantFech],buffCod[cantFech],fecha,cod,dni,cant);
            nd[cantFech]=1;
            cantFech++;
        }
        else{
            AgregarDatos(buffCod[pos],buffDni[pos],nd[pos],cod,dni,cant);
            nd[pos]++;
        }
    }
    fechaPedidos=new int[cantFech+1]{};
    codigoPedidos=new char**[cantFech+1]{};
    dniCantPedidos=new int**[cantFech+1]{};
    for (int i = 0; i < cantFech; i++) {
        EspaciosExactos(nd[i],buffDni[i],buffCod[i]);
    }
    for (int i = 0; i < cantFech; i++) {
        fechaPedidos[i]=buffFecha[i];
        codigoPedidos[i]=buffCod[i];
        dniCantPedidos[i]=buffDni[i];
    }
    
}

int BuscarFecha(int fecha,int *buffFecha){
    for (int i = 0;buffFecha[i]; i++) {
        if(buffFecha[i]==fecha)return i;
    }
    return -1;
}

void Inicializar(int &buffFecha,int **&buffDni,char **&buffCod,int fecha,
        char *cod,int dni,int cant){
    int *doblete=new int[2];
    doblete[0]=dni;
    doblete[1]=cant;
    buffFecha=fecha;
    buffDni=new int*[50]{};
    buffDni[0]=doblete;
    buffCod=new char*[50]{};
    buffCod[0]=cod;
}

void AgregarDatos(char **&buffCod,int **&buffDni,int nd,char *cod,int dni,int cant){
    int *doblete=new int[2];
    doblete[0]=dni;
    doblete[1]=cant;
    buffCod[nd]=cod;
    buffDni[nd]=doblete;
}

void EspaciosExactos(int nd,int **&buffDni,char **&buffCod){
    
    int **dni=new int*[nd+1]{};
    char **cod=new char*[nd+1]{};
    for (int i = 0; i < nd; i++) {
        dni[i]=buffDni[i];
        cod[i]=buffCod[i];
    }
    
    buffCod=cod;
    buffDni=dni;
    
}



void pruebaDeLecturaDePedidos(const char*nomb,int *fechaPedidos,
        char ***codigoPedidos,int ***dniCantPedidos){
    ofstream arch(nomb,ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    arch<<right<<setw(50)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    for (int i = 0; fechaPedidos[i]; i++) {
        ImprimirLectura(arch,codigoPedidos[i],dniCantPedidos[i],fechaPedidos[i]);

    }
}

void ImprimirLectura(ofstream &arch,char **codigoPedidos,int **dniCantPedidos,int fechaPedidos){
    int a=fechaPedidos/10000,m,d=fechaPedidos%100;
    m=(fechaPedidos%10000)/100;
    for (int i = 0;codigoPedidos[i]; i++) {
        arch<<left<<setw(10)<<codigoPedidos[i];
        ImprimirPar(arch,dniCantPedidos[i]);
        arch<<right<<setfill('0')<<setw(2)<<d<<"/"<<setw(2)<<m<<"/"<<a<<setfill(' ')<<endl;
    }

}


void ImprimirPar(ofstream &arch,int *dniCantPedidos){
    arch<<left<<setw(12)<<dniCantPedidos[0]<<setw(10)<<dniCantPedidos[1];
}


void reporteDeEnvioDePedidos(const char*nomb,char***productos,int*stock,double *precios,
        int *fechaPedidos,char***codigoPedidos,int***dniCantPedidos){
    ofstream arch(nomb,ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    arch<<right<<setw(50)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    for (int i = 0; fechaPedidos[i]; i++) {
        ImprimirPedidos(arch,fechaPedidos[i],codigoPedidos[i],dniCantPedidos[i],productos,precios,stock);
    }

}


void ImprimirPedidos(ofstream &arch,int fechaPedidos,char **codigoPedidos,int **dniCantPedidos
,char ***productos,double *precios,int *stock){
    int a=fechaPedidos/10000,m,d=fechaPedidos%100;
    m=(fechaPedidos%10000)/100;
    ImprimirLinea(arch,'=');
    arch<<left<<setw(10)<<"FECHA: "<<d<<"/"<<m<<"/"<<a<<endl;
    ImprimirLinea(arch,'=');
    arch<<left<<setw(30)<<"Nro. DNI"<<setw(60)<<"Producto"<<setw(15)<<"Cantidad"<<
             setw(10)<<"Precio"<<setw(30)<<"Total de ingresos"<<endl;
    ImprimirLinea(arch,'-');
    double monto,total=0,montoperdido=0;
    int pos;
    for (int i = 0; codigoPedidos[i]; i++) {
        pos=BuscarProducto(codigoPedidos[i],productos);
        if(pos!=-1){
            monto=0;
            ImprimirPed(arch,i,codigoPedidos[i],dniCantPedidos[i],monto,montoperdido,precios[pos],productos[pos],stock[pos]);
            total+=monto;
            
        }
    }
    ImprimirLinea(arch,'-');
    arch<<left<<setw(30)<<"Total ingresado:"<<right<<setw(30)<<total<<endl;
    arch<<left<<setw(30)<<"Total perdido por falta de stock"<<right<<setw(30)<<montoperdido<<endl;
}
int BuscarProducto(char *cod,char ***productos){
    for (int i = 0; productos[i]; i++) {
        if(Comparar(cod,productos[i]))return i;
    }
    return -1;
}

bool Comparar(char *cod,char **productos){
    return strcmp(cod,productos[0])==0;
}


void ImprimirPed(ofstream &arch,int i,char *codigoPedidos,int *dniCantPedidos,double &monto,
        double &montoperdido, double pre,char **producto,int &stock){
    
    if(stock-dniCantPedidos[1]>0){
        monto=pre*dniCantPedidos[1];
        stock-=dniCantPedidos[1];
        arch<<left<<setw(2)<<i+1<<") "<<right<<setw(12)<<dniCantPedidos[0]<<setw(20)
            <<codigoPedidos<<"  "<<left<<setw(60)<<producto[1]<<setw(10)<<
            dniCantPedidos[1]<<setw(10)<<pre<<setw(14)<<monto<<endl;
    }
    else{
        montoperdido+=pre*dniCantPedidos[1];
        arch<<left<<setw(2)<<i+1<<") "<<right<<setw(12)<<dniCantPedidos[0]<<setw(20)
            <<codigoPedidos<<"  "<<left<<setw(60)<<producto[1]<<setw(10)<<
            dniCantPedidos[1]<<setw(10)<<pre<<setw(14)<<"SIN STOCK"<<endl;
    }
    
}

