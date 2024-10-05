/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "UTILS.h"
#include "PunterosGenericos.h"

void cargaproductos(void *&productos){
    ifstream arch("Productos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    
    int cd=0;
    void *buff[200]{},*reg;
    while(true){
        reg=LeerDatos(arch);
        if(reg==nullptr)break;
        buff[cd]=reg;
        cd++;
    }
    void **aux=new void*[cd+1]{};
    for (int i = 0; i < cd; i++) {
        aux[i]=buff[i];
    }
    productos=aux;
}
void *LeerDatos(ifstream &arch){
    double *precio=new double;
    char *tipo=new char,*cod,*desc,ti;
    void **registro=new void*[4]{};
    cod=LeeCadena(arch);
    if(cod==nullptr)return nullptr;
    desc=LeeCadena(arch);
    arch>>*precio;
    arch.get();
    arch>>ti;
    *tipo=ti;
    registro[0]=cod;
    registro[1]=desc;
    registro[2]=precio;
    registro[3]=tipo;
    arch.get();
    return registro;
}

char *LeeCadena(ifstream &arch){
    char buff[80]{},*pt;
    arch.getline(buff,80,',');
    if(arch.eof())return nullptr;
    pt=new char[strlen(buff)+1]{};
    strcpy(pt,buff);
    return pt;
}

void cargaclientes(void *&clientes){
    ifstream arch("Clientes2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    void *arreglo[150]{},*reg;
    int cant=0;
    
    while(true){
        reg=LeerCliente(arch);
        if(reg==nullptr)break;
        arreglo[cant]=reg;
        cant++;
    }
    void **aux=new void*[cant+1]{};
    for (int i = 0; i < cant; i++) {
        aux[i]=arreglo[i];
    }
    clientes=aux;
}

void *LeerCliente(ifstream &arch){
    int *dni=new int,tele;
    char *nom;
    double *credito=new double;
    void **reg=new void*[4]{};
    
    arch>>*dni;
    if(arch.eof())return nullptr;
    arch.get();
    nom=LeeCadena(arch);
    arch>>tele;
    arch.get();
    arch>>*credito;
    reg[0]=dni;
    reg[1]=nom;
    reg[3]=credito;
    
    arch.get();
    return reg;
}

void cargapedidos(void *productos,void *&clientes){
    ifstream arch("Pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    int pos,posCli,dni,cant;
    char *cod;
    void **prods=(void**)productos,*pedido;
    while(true){
        cod=LeeCadena(arch);
        if(cod==nullptr)break;
        arch>>dni;
        arch.get();
        arch>>cant;
        arch.get();
        pos=BuscarProducto(productos,cod);
        pedido=LeerPed(prods[pos],cod,dni,cant);
        posCli=BuscarCliente(clientes,dni);
        if(posCli!=-1){
            void **arrcli=(void **)clientes;
            void **data=(void **)prods[pos];
            char *letra=(char *)data[3];
            AgregarPedido(arrcli[posCli],pedido,letra);
        }
        else{
            while(arch.get()!='\n');
        }
    }
    
}

int BuscarProducto(void *productos,char *cod){
    void **arr=(void **)productos;
    
    for (int i = 0;arr[i]; i++) {
        if(Comparar(arr[i],cod))return i;
    }
    return -1;

}

bool Comparar(void *arr,char *cod){
    void **datos=(void **)arr;
    char *codigo=(char *)datos[0];
    
    return strcmp(codigo,cod)==0;
}

int BuscarCliente(void *clientes,int dni){
    void **arr=(void **)clientes;
    for (int i = 0;arr[i]; i++) {
        if(Verificar(arr[i],dni))return i;
    }
    return -1;
    
}

bool Verificar(void *arr,int dni){
    void **datos=(void **)arr;
    int *d=(int *)datos[0];
    
    return *d==dni;
}

void *LeerPed(void *prod,char *cod,int dni,int cant){
    int *d=new int,*c=new int;
    void **triple=new void*[3];
    void **datos=(void **)prod;
    double *precio=(double *)datos[2],*monto=new double;
    *monto=(*precio)*cant;
    *d=dni;
    *c=cant;
    triple[0]=cod;
    triple[1]=c;
    triple[2]=monto;
    
    return triple;
}

void AgregarPedido(void *&cli,void *pedido,char *letra){
    void **datos=(void **)cli;
    
    void **ped=(void **)pedido;
    double *monto=(double *)ped[2];
    double *credito=(double *)datos[3];
    if(*monto<*credito){
        
        if(datos[2]==nullptr){
            void **arrPro=new void*[25]{};
            arrPro[0]=pedido;
            datos[2]=arrPro;
        }
        else{
            void**arr=(void **)datos[2];
            int pos=0;
            while(arr[pos])pos++;
            arr[pos]=pedido;
        }        
        
        if(*letra == 'S'){
            *credito-=*monto;
        }
        
        
        
        
    }
    
    
    
    
}


