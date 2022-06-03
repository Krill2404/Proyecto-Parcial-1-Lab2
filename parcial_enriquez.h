#ifndef PARCIAL_ENRIQUEZ_H_INCLUDED
#define PARCIAL_ENRIQUEZ_H_INCLUDED


///SOLO USAMOS CLIENTES.DAT
///NO HACE FALTA CREAR CLASES O ESTRUCTURAS DE DATOS EN ESTE CASO
///NO TOMA CLIENTES CON ESTADO FALSO
void parcial1(){
    Cliente obj;
    int pos=0;
    while (obj.leerDeDisco(pos++)==1){
        if (!obj.getEstado()){continue;}
        if (obj.getFcliente().getAnio() > 1979 && obj.getFcliente().getAnio() < 2001)
            obj.Mostrar();
            cout<<endl;
    }

}

///SOLO USAMOS VENTAS.DAT
///FUE NECESARIO USAR UN VECTOR PARA GUARDAR EL NUMERO DE VENTAS DE CADA ANIO
void parcial2(){
    Venta obj;
    int minv, menorVentas, ventasAnio[33] = {0}, pos=0;
    while (obj.leerDeDisco(pos++)==1){
        ventasAnio[obj.getFVenta().getAnio()-1990]++;

    }
    minv  = ventasAnio[0];
    menorVentas = 0;
    for (int i=0;i<33;i++){
        if (ventasAnio[i] < minv){
            minv = ventasAnio[i];
            menorVentas = i;
        }

    }
    cout<<"EL ANIO CON MENOS VENTAS ES EL "<< menorVentas + 1990<<" ("<<minv<<")"<<endl;

}


///USAMOS CLIENTES.DAT Y VENTAS.DAT
///GENERAMOS ARCHIVO ClientesImporte50000.dat
///PARA ALMACENAR LA INFORMACION DE LOS CLIENTES CON COMPRAS CON UN IMPORTE MAYOR A 50000
///NO TOMA CLIENTES CON ESTADO FALSO
void parcial3(){
    FILE *p;
    p=fopen("ClientesImporte50000.dat", "wb");
    if(p==NULL) return;
    Cliente obj;
    Venta aux;
    int pos=0, pos2, escribio;
    while (obj.leerDeDisco(pos++)==1){
        if (!obj.getEstado()){continue;}
        pos2 = 0;
        while (aux.leerDeDisco(pos2++)==1){
            if (aux.getImporte()>50000 && aux.getDni()==obj.getDni()){
                obj.Mostrar();
                escribio=fwrite(&obj,sizeof(Cliente),1,p);
                break;
            }
        }


    }
    cout<<"ARCHIVO GENERADO CORRECTAMENTE"<<endl;
    fclose(p);

}

#endif // PARCIAL_ENRIQUEZ_H_INCLUDED
