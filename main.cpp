# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

void cargarCadena(char *pal, int tam);
int BuscarClienteDni(int);
int BuscarCodigo(char*);
int BuscarVenta(int);


# include "clases.h"
# include "funciones_cliente.h"
# include "funciones_articulos.h"
# include "funciones_ventas.h"
# include "funciones_reportes.h"
# include "parcial_enriquez.h"


void MenuClientes();
void MenuArticulos();
void MenuVentas();
void MenuReportes();
void MenuConfiguracion();


int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-------------------------------"<<endl<<endl;
        cout<<"1) MENU CLIENTES"<<endl;
        cout<<"2) MENU ARTICULOS"<<endl;
        cout<<"3) MENU VENTAS"<<endl;
        cout<<"4) REPORTES"<<endl;
        cout<<"5) CONFIGURACION"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA"<<endl;
        cout<<endl<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: MenuClientes();
                    break;
            case 2: MenuArticulos();
                    break;
            case 3: MenuVentas();
                    break;
            case 4: MenuReportes();
                    break;
            case 5: MenuConfiguracion();
                    break;
            case 0: return 0;
                    break;


        }
        cout <<endl;
    }
    return 0;
}

void MenuClientes(){
int opc;
    while(true){
        system("cls");
        cout<<"MENU CLIENTES"<<endl;
        cout<<"-------------------------------"<<endl<<endl;
        cout<<"1) AGREGAR CLIENTE"<<endl;
        cout<<"2) LISTAR CLIENTE POR DNI"<<endl;
        cout<<"3) LISTAR TODOS LOS CLIENTES"<<endl;
        cout<<"4) MODIFICAR FECHA DE NACIMIENTO"<<endl;
        cout<<"5) ELIMINAR CLIENTE"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: AgregarCliente();
                    break;
            case 2: EncontrarClienteDni();
                    break;
            case 3: ListarClientes();
                    break;
            case 4: ModificarFechaCliente();
                    break;
            case 5: EliminarCliente();
                    break;
            case 0: return ;
                    break;


        }
        cout <<endl;
        system("pause");
    }

}

void MenuArticulos(){
int opc;
    while(true){
        system("cls");
        cout<<"MENU ARTICULOS"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR ARTICULO"<<endl;
        cout<<"2) LISTAR ARTICULO POR CODIGO"<<endl;
        cout<<"3) LISTAR TODOS LOS ARTICULOS"<<endl;
        cout<<"4) MODIFICAR PRECIO "<<endl;
        cout<<"5) ELIMINAR ARTICULO"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: AgregarArticulo();
                    break;
            case 2: ListarCodigo();
                    break;
            case 3: ListarArticulos();
                    break;
            case 4: ModificarPrecio();
                    break;
            case 5: EliminarArticulo();
                    break;
            case 0: return;
                    break;


        }
        cout <<endl;
        system("pause");

    }
}

void MenuVentas(){
int opc;
    while(true){
        system("cls");
        cout<<"MENU VENTAS"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) AGREGAR VENTA"<<endl;
        cout<<"2) LISTAR VENTA POR ID"<<endl;
        cout<<"3) LISTAR TODAS LAS VENTAS"<<endl;
        cout<<"4) MODIFICAR CANTIDAD "<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:AgregarVenta();
                    break;
            case 2:ListarVentasPorId();
                    break;
            case 3:ListarVentas();
                    break;
            case 4:ModificarCantidad();
                    break;
            case 0: return;
                    break;

        }
        cout <<endl;
        system("pause");
    }
}


void MenuReportes(){
int opc;
    while(true){
        system("cls");
        cout<<"MENU REPORTES"<<endl<<endl;
        cout<<"------------------"<<endl;
        cout<<"1) MOSTRAR POR CADA CLIENTE LA CANTIDAD DE VENTAS REGISTRADAS A ESE CLIENTE"<<endl;
        cout<<"2) INFORMAR LA CANTIDAD DE CLIENTES ACTIVOS Y LA CANTIDAD DE CLIENTES INACTIVOS"<<endl;
        cout<<"3) LISTAR LOS CLIENTES NACIDOS ENTRE 1980 Y 2000"<<endl;
        cout<<"4) ANIO CON MENOS VENTAS"<<endl;
        cout<<"5) GENERAR ARCHIVO CON LOS CLIENTES CON IMPORTES SINGULARES MAYORES A 50000"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: reportes1();
                    break;
            case 2: reportes2();
                    break;
            case 3: parcial1();
                    break;
            case 4: parcial2();
                    break;
            case 5: parcial3();
                    break;
            case 0: return;
                    break;


        }
        system("pause");
    }
}


void MenuConfiguracion(){
int opc;
    while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"------------------"<<endl<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS"<<endl;
        cout<<"4) RESTAURAR EL ARCHIVO DE CLIENTES"<<endl;
        cout<<"5) RESTAURAR EL ARCHIVO DE ARTICULOS"<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE VENTAS"<<endl;
        cout<<"7) ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"--------------------------------"<<endl<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: backupCliente();
                    break;
            case 2: backupArticulo();
                    break;
            case 3: backupVenta();
                    break;
            case 4: restaurarCliente();
                    break;
            case 5: restaurarArticulo();
                    break;
            case 6: restaurarVenta();
                    break;
            case 7: datosDeInicio();
                    break;
            case 0: return;
                    break;


        }
        cout <<endl;
        system("pause");
    }
}



void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
	pal[i]=cin.get();
	if(pal[i]=='\n') break;
	}
  pal[i]='\0';
  fflush(stdin);
}
