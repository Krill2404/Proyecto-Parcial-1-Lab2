#ifndef FUNCIONES_VENTAS_H_INCLUDED
#define FUNCIONES_VENTAS_H_INCLUDED

int BuscarVenta(int id){
    Venta reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getIdVenta()==id){
            return pos;
        }
        pos++;
    }
    return -1;
}

void AgregarVenta(){
    Venta obj, aux;
    Articulo obj2;
    int id,encontro, pos = 0, cargo, stock, pos2;
    while (aux.leerDeDisco(pos++)==1);
    id = pos;
    cargo = obj.Cargar(id);
    if (cargo == -1){return;}
    obj.grabarEnDisco();
    system("cls");
    cout<<"VENTA AGREGADA EXITOSAMENTE.";

}

void ListarVentas(){
    Venta obj;
    int pos=0;
    while (obj.leerDeDisco(pos++)==1){
        if (obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ListarVentasPorId(){
    Venta obj;
    int pos=0;
    int id;
    cout<<"INGRESE EL ID DE VENTA A BUSCAR: ";
    cin>>id;
    while (obj.leerDeDisco(pos++)==1){

        if(BuscarVenta(id)==-1){
            cout<<"NO SE ENCONTRO NINGUNA VENTA CON ESE ID"<<endl;
            return;
        }

        if(obj.getEstado()==true && obj.getIdVenta()==id){
            obj.Mostrar();
            cout<<endl;
            return;
        }
    }

}

void ModificarCantidad(){
    int id,cn,encontro,cargo, encontroA, stock;
    Venta obj;
    Articulo obj2;
    cout<<"INGRESE EL ID: ";
    cin>> id;
    cout<<endl;
    encontro=BuscarVenta(id);
    if(encontro == -1){
        cout<<"NO EXISTE VENTA CON ESE ID."<<endl;
        return;
    }
    obj.leerDeDisco(encontro);
    cout<<"INGRESE LA CANTIDAD NUEVA: ";
    cin>>cn;
    if (cn<1){
        cout<<"CANTIDAD INVALIDA"<<endl;
        return;
    }
    encontroA = BuscarCodigo(obj.getCodigo());
    obj2.leerDeDisco(encontroA);
    stock = obj2.getStock() + obj.getCantidad() - cn;
    obj2.setStock(stock);
    obj2.modificarEnDisco(encontroA);
    obj.setImporte(cn*obj2.getPrecio());
    obj.setCantidad(cn);
    obj.modificarEnDisco(encontro);
    cout<<"LA CANTIDAD FUE CARGADA CORRECTAMENTE"<<endl;



}

void backupVenta(){
    FILE *p;
    Venta reg;
    int pos=0;
    p=fopen("ventas.bkp","wb");
    if(p==NULL){
        cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD."<<endl;
        return;
    }
    while(reg.leerDeDisco(pos++)==1){
        fwrite(&reg,sizeof reg, 1, p);
    }
    fclose(p);
    if (pos == 0){
        cout<<"NO SE PUDO REALIZAR LA COPIA DE SEGURIDAD."<<endl;
        return;
    }
    cout<<"COPIA DE SEGURIDAD REALIZADA."<<endl;
}

void restaurarVenta(){
    FILE *p;
    Venta reg;
    int pos=0;
    p=fopen("ventas.dat","wb");
    if(p==NULL){
        cout<<"NO SE PUDO RESTAURAR LA COPIA DE SEGURIDAD."<<endl;
        return;
    }
    while(reg.leerDeBkp(pos++)==1){
        fwrite(&reg,sizeof reg, 1, p);
    }
    fclose(p);
    if (pos == 0){
        cout<<"NO SE PUDO RESTAURAR LA COPIA DE SEGURIDAD."<<endl;
        return;
    }
    cout<<"COPIA DE SEGURIDAD RESTAURADA."<<endl;
}



#endif // FUNCIONES_VENTAS_H_INCLUDED
