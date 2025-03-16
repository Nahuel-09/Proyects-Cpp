#include <iostream>
using namespace std;

struct Contact {
    int id;
    char name[100];
    char gender;
};

Contact contacts[100];
int contactCount = 0;  

int addContact() {
    if (contactCount >= 100) {
        cout << "No se pueden agregar más contactos.\n";
        return -1;
    }

    Contact newContact;
    cout << "Ingrese ID: ";
    cin >> newContact.id;
    cin.ignore();

    cout << "Ingrese Nombre: ";
    cin.getline(newContact.name, 100);

    cout << "Ingrese Genero (M/H): ";
    cin >> newContact.gender;

    contacts[contactCount++] = newContact;
    cout << "Contacto agregado exitosamente.\n";

    return 0;
}

int searchContact() {
    int searchId;
    cout << "Ingrese ID a buscar: ";
    cin >> searchId;

    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].id == searchId) {
            cout << "ID: " << contacts[i].id << "\n";
            cout << "Nombre: " << contacts[i].name << "\n";
            cout << "Genero: " << contacts[i].gender << "\n";
            return 0;
        }
    }
    cout << "Contacto no encontrado.\n";
    return 1;
}

int modifyContact() {
    int modId;
    cout << "Ingrese ID del contacto a modificar: ";
    cin >> modId;
    cin.ignore();

    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].id == modId) {
            cout << "Ingrese nuevo nombre: ";
            cin.getline(contacts[i].name, 100);

            cout << "Ingrese nuevo genero (M/H): ";
            cin >> contacts[i].gender;

            cout << "Contacto modificado correctamente.\n";
            return 1;
        }
    }
    cout << "Contacto no encontrado.\n";
    return 0;
}

int deleteContact() {
    int delId;
    cout << "Ingrese ID del contacto a eliminar: ";
    cin >> delId;

    for (int i = 0; i < contactCount; i++) {
        if (contacts[i].id == delId) {
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
            cout << "Contacto eliminado correctamente.\n";
            return 1;
        }
    }
    cout << "Contacto no encontrado.\n";
    return 0;
}

int listContacts() {
    if (contactCount == 0) {
        cout << "No hay contactos registrados.\n";
        return 0;
    }
    for (int i = 0; i < contactCount; i++) {
        cout << "ID: " << contacts[i].id << ", Nombre: " << contacts[i].name << ", Genero: " << contacts[i].gender << "\n";
    }
    return 0;
}

int menu() {
    int opc;
    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar Contacto\n";
        cout << "2. Buscar Contacto\n";
        cout << "3. Modificar Contacto\n";
        cout << "4. Eliminar Contacto\n";
        cout << "5. Listar Contactos\n";
        cout << "6. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opc;

        switch (opc) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: modifyContact(); break;
            case 4: deleteContact(); break;
            case 5: listContacts(); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opción no válida.\n"; continue;
        }
    } while (opc != 6);

    return 0;  
}

int main() {
    menu();
    return 0;
}
