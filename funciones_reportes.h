#ifndef FUNCIONES_REPORTES_H_INCLUDED
#define FUNCIONES_REPORTES_H_INCLUDED

void reportes1(){
    Cliente obj;
    Venta aux;
    int pos1=0, pos2, cont;

    while(obj.leerDeDisco(pos1++)){
        cont = 0;
        pos2 = 0;
        while(aux.leerDeDisco(pos2++)){
            if (obj.getDni()==aux.getDni()){
                cont++;
            }
        }
        cout<<"DNI CLIENTE: "<<obj.getDni()<<endl;
        cout<<"NUMERO DE VENTAS: "<<cont<<endl<<endl;
    }

}

void reportes2(){
    Cliente obj;
    int pos = 0, activos = 0, inactivos = 0;
    while (obj.leerDeDisco(pos++)){
        if(obj.getEstado()){
            activos++;
            continue;
        }
        inactivos++;
    }
    cout<<"CLIENTES ACTIVOS: "<<activos<<endl;
    cout<<"CLIENTES INACTIVOS: "<<inactivos<<endl;

}


#endif // FUNCIONES_REPORTES_H_INCLUDED
