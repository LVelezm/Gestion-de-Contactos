#include <iostream>
using namespace std;
struct ContactoEmail{
    string nombresCompletos;
    string telefono;
    string email;
};
ContactoEmail contactos[100];
int numContactos=0;
void agregarContacto(){
		cout<<endl;
        cout<<"Ingrese nombres completos: ";
        cin.ignore();
        getline(cin, contactos[numContactos].nombresCompletos);
        cout<<"Ingrese telefono: ";
        cin>>contactos[numContactos].telefono;
        cout<<"Ingrese email: ";
        cin>>contactos[numContactos].email;
        numContactos++;
        cout<<endl;
		cout<<"Contacto agregado"<<endl;
		cout<<endl;
}

void mostrarMenu(){
    cout<<"Menu:"<<endl;
    cout<<"a) Agregar un contacto"<<endl;
    cout<<"b) Eliminar un contacto"<<endl;
    cout<<"c) Mostrar listado general de contactos registrados hasta ese momento."<<endl;
    cout<<"d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, outlook.com, yahoo.com, etc.)"<<endl;
    cout<<"e) Salir del programa"<<endl;
    cout<<endl;
}
int main(){
    char opcion;
    do{
        mostrarMenu();
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        switch (opcion){
            case 'a':
                agregarContacto();
                break;
            case 'e':
            	cout<<endl;
                cout<<"saliendo.... "<<endl;
                break;
            default:
                cout<<"Opcion invalida. Intente nuevamente."<<endl;
        }
    }while(opcion!='e');
    return 0;
}