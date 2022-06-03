#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED



///CLASE FECHA

class Fecha{
private:
    int dia, mes, anio;
public:
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){if(d>0&&d<=31) dia=d;}
    void setMes(int m){if(m>0&&m<13) mes=m;}
    void setAnio(int a){anio=a;}
    void Cargar(){
        int d, m, a;
        do{cout<<"DIA: ";
        cin>>d;}while (d<0||d>31);
        do{cout<<"MES: ";
        cin>>m;} while (m<0||m>12);
        do{cout<<"ANIO: ";
        cin>>a;} while (a>2022 || a<0);
        setDia(d);
        setMes(m);
        setAnio(a);
    }
    void Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    };
};




///CLASE CLIENTE

class Cliente{
private:
    int dni;
    char nombre[30];
    char apellido[30];
    char email[40];
    char telefono[20];
    Fecha fcliente;
    bool estado;
public:

///GETS
    const int getDni(){return dni;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
	Fecha getFcliente(){return fcliente;}
    const bool getEstado(){return estado;}

///SETS
    void setDni(const int d){dni=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido,a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setFcliente(const Fecha fc){fcliente=fc;}
    void setEstado(const bool es){estado=es;}

///CARGAR
    void Cargar(int d=0){
        char n[30],a[30],e[40],t[20];
        if(d!=0){
            dni=d;
        }
        else{
            cout<<"INGRESE EL DNI: ";
            cin>>d;
        }
        cout<<"INGRESE EL NOMBRE: ";
        cargarCadena(n,29);
        cout<<"INGRESE EL APELLIDO: ";
        cargarCadena(a,29);
        cout<<"INGRESE EL EMAIL: ";
        cargarCadena(e,39);
        cout<<"INGRESE EL TELEFONO: ";
        cargarCadena(t,19);
        cout<<"INGRESE LA FECHA DE NACIMIENTO: "<<endl;
        fcliente.Cargar();
        estado=true;
        setDni(d);
        setNombre(n);
        setApellido(a);
        setEmail(e);
        setTelefono(t);
    }

    int cargarFechaNacimiento(){
        Fecha obj;
        obj.Cargar();
        if (obj.getAnio()<1920 || obj.getAnio()>2010){
            system("cls");
            cout<<"FECHA DE NACIMIENTO INVALIDA.";
            return -1;
        }
        cout<<"FECHA DE NACIMIENTO MODIFICADA.";
        setFcliente(obj);
        return 0;
    }

///MOSTRAR
    void Mostrar(){
        cout<<"DNI: "<<dni<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Apellido: "<<apellido<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Telefono: "<<telefono<<endl;
        cout<<"Fecha de nacimiento: ";
        fcliente.Mostrar();
    }

///ARCHIVOS
    int leerDeDisco(int pos){
        FILE *p;
        p=fopen("clientes.dat", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Cliente)*pos,0);
        int leyo=fread(this,sizeof(Cliente),1,p);
        fclose(p);
        return leyo;
    }

    int grabarEnDisco(){
        FILE *p;
        p=fopen("clientes.dat", "ab");
        if(p==NULL) return -1;
        int escribio=fwrite(this,sizeof(Cliente),1,p);
        fclose(p);
        return escribio;
    }

    int modificarEnDisco(int pos){
        FILE *p;
        p=fopen("clientes.dat", "rb+");
        if(p==NULL) return -1;
        fseek(p,sizeof(Cliente)*pos,0);
        int escribio=fwrite(this,sizeof(Cliente),1,p);
        fclose(p);
        return escribio;
    }

    int leerDeBkp(int pos){
        FILE *p;
        p=fopen("clientes.bkp", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Cliente)*pos,0);
        int leyo=fread(this,sizeof(Cliente),1,p);
        fclose(p);
        return leyo;
    }

    int leerDeDini(int pos){
        FILE *p;
        p=fopen("clientes.dini", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Cliente)*pos,0);
        int leyo=fread(this,sizeof(Cliente),1,p);
        fclose(p);
        return leyo;
    }
};




///CLASE ARTICULO

class Articulo{
private:
    char codigo[5], descripcion[30];
    float precio;
    int stock;
    bool estado;
public:

///GETS
    const char* getCodigo(){return codigo;}
    const char* getDescripcion(){return descripcion;}
    const float getPrecio(){return precio;}
    const int getStock(){return stock;}
    const bool getEstado(){return estado;}

///SETS
    void setCodigo(const char *c){strcpy(codigo,c);}
    void setDescripcion(const char *d){strcpy(descripcion,d);}
    void setPrecio(const float p){precio=p;}
    void setStock(const int s){stock=s;}
    void setEstado(const bool e){estado=e;}

///MOSTRAR
    void mostrar(){
    cout<<"Codigo de articulo: "<<codigo<<endl;
    cout<<"Descripcion: "<<descripcion<<endl;
    cout<<"Precio unitario: "<<precio<<endl;
    cout<<"Stock: "<<stock<<endl;
    }

///CARGAR
    void cargar(char* c=0){
    char d[30];
    float p;
    int s;
    if(c!=0){
        setCodigo(c);
    }
    else {
        cout<<"Codigo de articulo: ";
        cargarCadena(c,4);
        setCodigo(c);
    }

    cout<<"Descripcion: ";
    cargarCadena(d,29);
    setDescripcion(d);
    cout<<"Precio unitario: ";
    cin>>p;
    setPrecio(p);
    cout<<"Stock: ";
    cin>>s;
    setStock(s);
    setEstado(true);
    }

    float modificarPrecioNuevo(float precioNuevo){
        if (precioNuevo<0){
            system("cls");
            cout<<"PRECIO UNITARIO INVALIDO.";
            return -1;
        }
        else {
            precio=precioNuevo;
            return 0;
        }
    }

///ARCHIVOS
    int leerDeDisco(int pos){
    FILE *p;
    p=fopen("articulos.dat", "rb");
    if(p==NULL) return -1;
    fseek(p,sizeof(Articulo)*pos,0);
    int leyo=fread(this,sizeof(Articulo),1,p);
    fclose(p);
    return leyo;
    }

    int grabarEnDisco(){
    FILE *p;
    p=fopen("articulos.dat", "ab");
    if(p==NULL) return -1;
    int escribio=fwrite(this,sizeof(Articulo),1,p);
    fclose(p);
    return escribio;
    }

    int modificarEnDisco(int pos){
    FILE *p;
    p=fopen("articulos.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p,sizeof(Articulo)*pos,0);
    int escribio=fwrite(this,sizeof(Articulo),1,p);
    fclose(p);
    return escribio;
    }

    int leerDeBkp(int pos){
        FILE *p;
        p=fopen("articulos.bkp", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Articulo)*pos,0);
        int leyo=fread(this,sizeof(Articulo),1,p);
        fclose(p);
        return leyo;
    }

    int leerDeDini(int pos){
        FILE *p;
        p=fopen("articulos.dini", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Articulo)*pos,0);
        int leyo=fread(this,sizeof(Articulo),1,p);
        fclose(p);
        return leyo;
    }
};




///CLASE VENTA

class Venta{
private:
    int idVenta;
    char codigo[5];
    int dni, cantidad;
    float importe;
    Fecha fVenta;
    bool estado;
public:

///GETS
    const int getIdVenta(){return idVenta;}
    char* getCodigo(){return codigo;}
    const int getDni(){return dni;}
    const int getCantidad(){return cantidad;}
    const float getImporte(){return importe;}
    Fecha getFVenta(){return fVenta;}
    const bool getEstado(){return estado;}

///SETS
    void setIdVenta(const int id){idVenta=id;}
    void setCodigo(const char *cod){strcpy(codigo, cod);}
    void setDni(const int d){dni=d;}
    void setCantidad(const int c){cantidad=c;}
    void setImporte(const int im){importe=im;}
    void setFVenta(const Fecha fv){fVenta=fv;}
    void setEstado(const bool e){estado=e;}

///CARGAR
    int Cargar(int i=0){
        Articulo obj2;
        int encontroA;
        if(i!=0){
            idVenta=i;
        }
        else{
            cout<<"INGRESE EL ID DE VENTA: ";
            cin>>idVenta;
        }

        cout<<"INGRESE EL CODIGO DE ARTICULO: ";
        cargarCadena(codigo, 4);
        encontroA = BuscarCodigo(codigo);
        if (encontroA == -1){
                cout<<"NO EXISTE ESE ARTICULO";
                return -1;
        }
        obj2.leerDeDisco(encontroA);
        cout<<"INGRESE EL DNI: ";
        cin>>dni;
        if (BuscarClienteDni(dni)== -1){
            cout<<"NO EXISTE ESE CLIENTE"<<endl;
            return -1;
        }
        do{cout<<"INGRESE LA CANTIDAD DE UNIDADES: ";
        cin>>cantidad;} while (cantidad<1);
        if (cantidad>obj2.getStock()){
            cout<<"LA CANTIDAD ES MAYOR AL STOCK DISPONIBLE"<<endl;
            return -1;
        }
        obj2.setStock(obj2.getStock() - cantidad);
        obj2.modificarEnDisco(encontroA);
        importe = obj2.getPrecio()*cantidad;
        cout<<"INGRESE LA FECHA DE VENTA: "<<endl;
        fVenta.Cargar();
        estado=true;
        return 0;
    }

///MOSTRAR
    void Mostrar(){
        cout<<"ID DE VENTA: "<<idVenta<<endl;
        cout<<"CODIGO DE ARTICULO: "<<codigo<<endl;
        cout<<"DNI DEL CLIENTE: "<<dni<<endl;
        cout<<"CANTIDAD DE UNIDADES: "<<cantidad<<endl;
        cout<<"IMPORTE TOTAL: "<<importe<<endl;
        cout<<"FECHA DE VENTA: ";
        fVenta.Mostrar();
    }

///ARCHIVOS
    int grabarEnDisco(){
        FILE *p;
        p=fopen("ventas.dat", "ab");
        if(p==NULL) return -1;
        int escribio=fwrite(this,sizeof(Venta),1,p);
        fclose(p);
        return escribio;
    }

    int leerDeDisco(int pos){
        FILE *p;
        p=fopen("ventas.dat", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Venta)*pos,0);
        int leyo=fread(this,sizeof(Venta),1,p);
        fclose(p);
        return leyo;
    }


    int modificarEnDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat", "rb+");
    if(p==NULL) return -1;
    fseek(p,sizeof(Venta)*pos,0);
    int escribio=fwrite(this,sizeof(Venta),1,p);
    fclose(p);
    return escribio;
    }

    int leerDeBkp(int pos){
        FILE *p;
        p=fopen("ventas.bkp", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Venta)*pos,0);
        int leyo=fread(this,sizeof(Venta),1,p);
        fclose(p);
        return leyo;
    }

    int leerDeDini(int pos){
        FILE *p;
        p=fopen("ventas.dini", "rb");
        if(p==NULL) return -1;
        fseek(p,sizeof(Venta)*pos,0);
        int leyo=fread(this,sizeof(Venta),1,p);
        fclose(p);
        return leyo;
    }
};




#endif // CLASES_H_INCLUDED
