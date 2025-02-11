#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Función para ordenar usando el método burbuja
void ordenar(vector<string>& arr) {
    bool cambio;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        cambio = false;
        for (int j = 0; j < n - i - 1; j++) {
            // Comparar elementos adyacentes y cambiar si están en el orden incorrecto
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cambio = true;
            }
        }
        // Si no hubo cambios, el arreglo ya está ordenado
        if (!cambio) break;
    }
}

// Función para buscar un elemento en un arreglo
bool buscar(vector<string>& arr, string num) {
    cout << "\n----------------> Buscando el elemento: " << num << "\n";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "Comparando con posición " << i << ": " << arr[i] << "\n";
        // Si el elemento es encontrado, retornar true
        if (arr[i] == num) {
            cout << "---------------> Elemento encontrado en posición " << i << ".\n";
            return true;
        }
    }
    // Si el elemento no es encontrado, retornar false
    cout << " -------------------------------> Elemento no encontrado. :(            \n";
    return false;
}

// Menú principal
void menu() {
    vector<string> datos;
    int op;
    string val, num;

    do {
        // Mostrar opciones del menú
        cout << "\n--------------- MENU  -----------------\n";
        cout << "1. Ingresar Datos (Numeros o Texto)\n";
        cout << "2. Ordenar Datos\n";
        cout << "3. Buscar un Dato\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1:
                // Ingresar datos hasta que el usuario ingrese "-2"
                cout << "-------------------> Ingresa los datos (escribe -2 para terminar):\n";
                while (true) {
                    getline(cin, val);
                    if (val == "-2") break;
                    datos.push_back(val);
                }
                break;
            case 2:
                // Ordenar los datos si existen
                if (datos.empty()) {
                    cout << "No hay datos para ordenar.\n";
                } else {
                    cout << "--------------------------> Ordenando datos...\n";
                    ordenar(datos);
                    cout << "Datos ordenados: ";
                    for (const auto& d : datos) cout << d << " ";
                    cout << "\n";
                }
                break;
            case 3:
                // Buscar un dato si existen datos
                if (datos.empty()) {
                    cout << "No hay datos para buscar.\n";
                } else {
                    cout << "Ingresa el dato a buscar: ";
                    getline(cin, num);
                    buscar(datos, num);
                }
                break;
            case 4:
                // Salir del programa
                cout << "Saliendo... .............             :(           \n";
                break;
            default:
                // Opción no válida
                cout << " No válido               :(               \n";
        }
    } while (op != 4);
}

int main() {
    // Ejecutar el menú principal
    menu();
    return 0;
}
