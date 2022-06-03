#ifndef FUNCIONES_CLIENTE_H_INCLUDED
#define FUNCIONES_CLIENTE_H_INCLUDED

int BuscarClienteDni(int DNI){
    Cliente reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
        if(reg.getDni()==DNI){
            return pos;
        }
        pos++;
    }
    return -1;
}


void AgregarCliente(){
    Cliente temp;
    int dni, encontro, opc;
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    encontro = BuscarClienteDni(dni);
    if (encontro!=-1){
        system("cls");
        temp.leerDeDisco(encontro);
        if (temp.getEstado()){
            cout<<"YA EXISTE UN USUARIO CON ESE DNI.";
            return;
        }
        cout<<"ESTE CLIENTE FUE ELIMINADO: "<<endl;
        cout<<"1) RESTAURAR CLIENTE"<<endl;
        cout<<"2) CANCELAR"<<endl<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        if (opc==1){
            temp.setEstado(true);
            temp.modificarEnDisco(encontro);
            cout<<"CLIENTE RESTAURADO"<<endl;
        return;
        }
    }
    temp.Cargar(dni);
    if (temp.getFcliente().getAnio()<1920 || temp.getFcliente().getAnio()>2010){
        system("cls");
        cout<<"FECHA DE NACIMIENTO INVALIDA.";
        return;
    }
    temp.grabarEnDisco();
    system("cls");
    cout<<"CLIENTE AGREGADO EXITOSAMENTE.";
}


void EncontrarClienteDni(){
    int DNI, pos;
    Cliente obj;
    cout<<"INGRESE EL DNI: ";
    cin>>DNI;
    cout<<endl;
    pos = BuscarClienteDni(DNI);
    if (pos == -1){
        cout<<"NO SE ENCONTRO CLIENTE CON ESE DNI."<<endl;
        return;
    }
    obj.leerDeDisco(pos);
    if (obj.getEstado()==false){
        cout<<"EL CLIENTE FUE ELIMINADO.";
        return;
    }
    obj.Mostrar();
}


void ListarClientes(){
    Cliente obj;
    int pos=0;
    while (obj.leerDeDisco(pos++)==1){
        if (obj.getEstado()==true){
            obj.Mostrar();
            cout<<endl;
        }
    }

}


void ModificarFechaCliente(){
    Cliente obj;
    int dni, pos, cargo;
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<endl;
    pos = BuscarClienteDni(dni);
    if (pos == -1){cout<<"NO SE ENCONTRO CLIENTE CON ESE DNI."; return;}
    obj.leerDeDisco(pos);
    cout<<"INGRESE LA NUEVA FECHA DE NACIMIENTO: "<<endl;
    cargo = obj.cargarFechaNacimiento();
    if (cargo == 0) {obj.modificarEnDisco(pos);}
}

void EliminarCliente(){
    Cliente obj;
    int dni, pos, cargo;
    cout<<"INGRESE EL DNI: ";
    cin>>dni;
    cout<<endl;
    pos = BuscarClienteDni(dni);
    if (pos == -1){cout<<"NO SE ENCONTRO CLIENTE CON ESE DNI."; return;}
    obj.leerDeDisco(pos);
    if (obj.getEstado() == false){
        cout<<"ESTE CLIENTE YA FUE ELIMINADO.";
        return;
    }
    obj.setEstado(false);
    obj.modificarEnDisco(pos);
    cout<<"CLIENTE ELIMINADO.";
}


void backupCliente(){
    FILE *p;
    Cliente reg;
    int pos=0;
    p=fopen("clientes.dini","wb");
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

void restaurarCliente(){
    FILE *p;
    Cliente reg;
    int pos=0;
    p=fopen("clientes.dat","wb");
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

void datosDeInicio(){
    ///CLIENTES
    FILE *p;
    Cliente reg;
    int pos=0;
    p=fopen("clientes.dat","wb");
    if(p==NULL){
        cout<<"NO SE PUDIERON RESTAURAR LOS DATOS DE INICIO."<<endl;
        return;
    }
    while(reg.leerDeBkp(pos++)==1){
        fwrite(&reg,sizeof reg, 1, p);
    }
    fclose(p);
    if (pos == 0){
        cout<<"NO SE PUDIERON RESTAURAR LOS DATOS DE INICIO."<<endl;
        return;
    }

    ///VENTAS
    FILE *q;
    Venta reg2;
    pos=0;
    q=fopen("ventas.dat","wb");
    if(q==NULL){
        cout<<"NO SE PUDIERON RESTAURAR LOS DATOS DE INICIO."<<endl;
        return;
    }
    while(reg2.leerDeBkp(pos++)==1){
        fwrite(&reg2,sizeof reg2, 1, q);
    }
    fclose(q);
    if (pos == 0){
        cout<<"NO SE PUDIERON RESTAURAR LOS DATOS DE INICIO."<<endl;
        return;
    }

    ///ARTICULOS
    FILE *y;
    Articulo reg3;
    pos=0;
    y=fopen("articulos.dat","wb");
    if(y==NULL){
        cout<<"NO SE PUDIERON RESTAURAR LOS DATOS DE INICIO."<<endl;
        return;
    }
    while(reg3.leerDeDini(pos++)==1){
        fwrite(&reg3,sizeof reg3, 1, y);
    }
    fclose(y);
    if (pos == 0){
        cout<<"NO SE PUDIERON RESTAURAR LOS DATOS DE INICIO."<<endl;
        return;
    }
    cout<<"DATOS DE INICIO RESTAURADOS."<<endl;
    return;

}


#endif // FUNCIONES_CLIENTE_H_INCLUDED
