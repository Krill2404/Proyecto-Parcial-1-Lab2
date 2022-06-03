#ifndef FUNCIONES_ARTICULOS_H_INCLUDED
#define FUNCIONES_ARTICULOS_H_INCLUDED



int BuscarCodigo(char* codigo){
    Articulo reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(strcmp(reg.getCodigo(),codigo)==0){
            return pos;
        }
        pos++;
    }
    return -1;
}

void AgregarArticulo(){
    Articulo obj;
    char codigo[5];
    int encontroArt, opc;
    cout<<"INGRESE EL CODIGO: ";
    cargarCadena(codigo, 4);
    encontroArt = BuscarCodigo(codigo);
    if (encontroArt!=-1){
        system("cls");
        obj.leerDeDisco(encontroArt);
        if (obj.getEstado()){
            cout<<"YA EXISTE UN ARTICULO CON ESE DNI.";
            return;
        }
        cout<<"ESTE ARTICULO FUE ELIMINADO: "<<endl;
        cout<<"1) RESTAURAR ARTICULO"<<endl;
        cout<<"2) CANCELAR"<<endl<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        if (opc==1){
            obj.setEstado(true);
            obj.modificarEnDisco(encontroArt);
            cout<<"ARTICULO RESTAURADO"<<endl;
        return;
        }
    }
    obj.cargar(codigo);
    if(obj.getPrecio()<0){
        system("cls");
        cout<<"PRECIO UNITARIO INVALIDO";
        return ;
    }
    obj.grabarEnDisco();
    system("cls");
    cout<<"ARTICULO CARGADO EXITOSAMENTE";


}




void ListarCodigo(){
    char codigo[5];
    int pos;
    Articulo obj;
    cout<<"INGRESE EL CODIGO: ";
    cargarCadena(codigo, 4);
    cout<<endl;
    pos = BuscarCodigo(codigo);
    if (pos == -1){
        cout<<"NO SE ENCONTRO EL ARTICULO CON ESE CODIGO"<<endl;
        return;
    }
    obj.leerDeDisco(pos);
    if(obj.getEstado()==false){
        cout<<"EL CODIGO DEL ARTICULO FUE ELIMINADO";
        return;
    }
    obj.mostrar();
}



void ListarArticulos(){
    Articulo obj;
    int pos=0;
    while (obj.leerDeDisco(pos++)==1){
        if (obj.getEstado()==true){
            obj.mostrar();
            cout<<endl;
        }
    }
}


void ModificarPrecio(){
    char codigo[5];
    int pos;
    float cargo, precioNuevo;
    Articulo obj;
    cout<<"INGRESE EL CODIGO: ";
    cargarCadena(codigo, 4);
    cout<<endl;
    pos = BuscarCodigo(codigo);
    if (pos == -1){
        cout<<"NO SE ENCONTRO EL ARTICULO CON ESE CODIGO";
        return;
    }
    obj.leerDeDisco(pos);
    cout<<"INGRESE EL NUEVO PRECIO: "<<endl;
    cin>>precioNuevo;
    cout<<endl;
    cargo = obj.modificarPrecioNuevo(precioNuevo);
    if (cargo == 0){
        obj.modificarEnDisco(pos);
        cout<<"EL PRECIO UNITARIO FUE CARGADO CORRECTAMENTE"<<endl;
    }


}


void EliminarArticulo(){
    Articulo obj;
    int pos, cargo;
    char codigo[5];
    cout<<"INGRESE EL CODIGO: ";
    cargarCadena(codigo, 4);
    cout<<endl;
    pos = BuscarCodigo(codigo);
    if(pos == -1){
        cout<<"NO SE ENCONTRO EL ARTICULO CON ESE CODIGO";
        return;
    }
    obj.leerDeDisco(pos);
    if(obj.getEstado() == false){
        cout<<"ESTE ARTICULO YA FUE ELIMINADO.";
        return;
    }
    obj.setEstado(false);
    obj.modificarEnDisco(pos);
    cout<<"ARTICULO ELIMINADO.";
}


void backupArticulo(){
    FILE *p;
    Articulo reg;
    int pos=0;
    p=fopen("articulos.bkp","wb");
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

void restaurarArticulo(){
    FILE *p;
    Articulo reg;
    int pos=0;
    p=fopen("articulos.dat","wb");
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


#endif // FUNCIONES_ARTICULOS_H_INCLUDED
