#include <iostream>
using namespace std;
struct ContactoEmail{
    string nombresCompletos;
    string telefono;
    string email;
    int id;
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
        contactos[numContactos].id=numContactos+1; 
        numContactos++;
        cout<<endl;
		cout<<"Contacto agregado"<<endl;
		cout<<endl;
}
void eliminarContacto(){
    if (numContactos>0){
        cout<<"Ingrese el numero de contacto a eliminar (1-"<<numContactos<<"): "<<endl;;
        int num;
        cin>>num;
        cout<<endl;
        if(num >= 1 && num <= numContactos){
            for(int i = num-1; i < numContactos-1; i++){
                contactos[i]=contactos[i + 1];
            }
            numContactos--;
            cout<<"Contacto eliminado"<<endl;
        }else{
            cout<<"Numero de contacto invalido."<<endl;
        }
    }else{
        cout<<"No hay contactos para eliminar."<<endl;
    }
}

void mostrarContactos(){
    if (numContactos>0){
        for (int i = 0; i < numContactos - 1; i++) {
            for (int j = i + 1; j < numContactos; j++) {
                if (contactos[i].id > contactos[j].id) {
                    ContactoEmail temp = contactos[i];
                    contactos[i] = contactos[j];
                    contactos[j] = temp;
                }
            }
        }
        for (int i = 0; i < numContactos; i++) {
            cout << "Contacto " << i + 1 << ":" << endl;
            cout << "Nombre: " << contactos[i].nombresCompletos << ", Telefono: " << contactos[i].telefono << ", Email: " << contactos[i].email << endl;
        }
    } else {
        std::cout << "No hay contactos registrados." << std::endl;
    }
}
void mostrarContactosOrdenados(){
    if (numContactos > 0) {
        char servidor1[20], servidor2[20];
        for (int i = 0; i < numContactos - 1; i++) {
            for (int j = i + 1; j < numContactos; j++) {
                int k = 0;
                while (contactos[i].email[k]!= '@') {
                    k++;
                }
                int l = 0;
                while (contactos[i].email[k + l]!= '\0') {
                    servidor1[l] = contactos[i].email[k + l];
                    l++;
                }
                servidor1[l] = '\0';

                k = 0;
                while (contactos[j].email[k]!= '@') {
                    k++;
                }
                l = 0;
                while (contactos[j].email[k + l]!= '\0') {
                    servidor2[l] = contactos[j].email[k + l];
                    l++;
                }
                servidor2[l] = '\0';

                if (strcmp(servidor1, servidor2) > 0) {
                    ContactoEmail temp = contactos[i];
                    contactos[i] = contactos[j];
                    contactos[j] = temp;
                }
            }
        }
        for (int i = 0; i < numContactos; i++) {
            cout << "Contacto " << i + 1 << ":" << endl;
            cout << "Nombre: " << contactos[i].nombresCompletos << ", Teléfono: " << contactos[i].telefono << ", Email: " << contactos[i].email <<endl;
        }
    }else{
        cout<<"No hay contactos registrados." <<endl;
    }
}

void mostrarMenu(){
	cout<<endl;
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
        cout<<endl;
        switch (opcion){
            case 'a':
                agregarContacto();
                break;
            case 'b':
                eliminarContacto();
                break;
            case 'c':
                mostrarContactos();
                break;
            case 'd':
                mostrarContactosOrdenados();
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