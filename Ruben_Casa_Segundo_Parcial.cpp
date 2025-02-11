#include <iostream>     
#include <vector>       // Para utilizar el contenedor vector
#include <unordered_map>// Para utilizar el contenedor unordered_map
#include <queue>        // Para utilizar el contenedor queue
#include <stack>        // Para utilizar el contenedor stack
#include <set>          // Para utilizar el contenedor set
#include <algorithm>    // Para utilizar funciones de algoritmos estándar como remove

using namespace std;

class Grafo {
private:
    unordered_map<int, vector<int>> adjList; // Lista de adyacencia para representar el grafo

public:
    // Agrega un nodo al grafo
    void agNodo(int nodo) {
        if (adjList.find(nodo) != adjList.end()) {
            cout << "-----------------------------> El nodo " << nodo << "     ya existe.     " << endl;
        } else {
            adjList[nodo] = vector<int>();
        }
    }

    // Elimina un nodo del grafo
    void elimNodo(int nodo) {
        if (adjList.find(nodo) == adjList.end()) {
            cout << "-----------------------------> El nodo " << nodo << "     no existe.     " << endl;
            return;
        }
        adjList.erase(nodo);
        for (auto& pair : adjList) {
            pair.second.erase(remove(pair.second.begin(), pair.second.end(), nodo), pair.second.end());
        }
    }

    // Agrega una arista entre dos nodos
    void agArista(int nodo1, int nodo2) {
        if (adjList.find(nodo1) == adjList.end() || adjList.find(nodo2) == adjList.end()) {
            cout << "------------------------------> Uno o ambos nodos no existen." << endl;
            return;
        }
        adjList[nodo1].push_back(nodo2);
        adjList[nodo2].push_back(nodo1); // Para grafo no dirigido
    }

    // Elimina una arista entre dos nodos
    void elimArista(int nodo1, int nodo2) {
        if (adjList.find(nodo1) == adjList.end() || adjList.find(nodo2) == adjList.end()) {
            cout << "Uno o ambos nodos no existen.          ---->  :(" << endl;
            return;
        }
        adjList[nodo1].erase(remove(adjList[nodo1].begin(), adjList[nodo1].end(), nodo2), adjList[nodo1].end());
        adjList[nodo2].erase(remove(adjList[nodo2].begin(), adjList[nodo2].end(), nodo1), adjList[nodo2].end());
    }

    // Muestra el grafo
    void mostGrafo() {
        for (auto const& pair : adjList) {
            int nodo = pair.first;
            const vector<int>& vecinos = pair.second;
            cout << "Nodo " << nodo << ": ";
            for (int vecino : vecinos) {
                cout << vecino << " ";
            }
            cout << endl;
        }
    }

    // Verifica si un nodo existe en el grafo
    bool existeNodo(int nodo) {
        return adjList.find(nodo) != adjList.end();
    }

    // Realiza un recorrido en profundidad (DFS) desde un nodo de inicio
    void DFS(int inicio) {
        stack<int> pila;
        set<int> visitados;
        pila.push(inicio);
        while (!pila.empty()) {
            int nodoActual = pila.top();
            pila.pop();
            if (visitados.find(nodoActual) == visitados.end()) {
                cout << nodoActual << " ";
                visitados.insert(nodoActual);
                for (int vecino : adjList[nodoActual]) {
                    pila.push(vecino);
                }
            }
        }
        cout << endl;
    }

    // Realiza un recorrido en anchura (BFS) desde un nodo de inicio
    void BFS(int inicio) {
        queue<int> cola;
        set<int> visitados;
        cola.push(inicio);
        visitados.insert(inicio);

        while(!cola.empty()) {
            int nodoActual = cola.front();
            cola.pop();
            cout << nodoActual << " ";
            for (int vecino : adjList[nodoActual]) {
                 if(visitados.find(vecino) == visitados.end()) {
                    cola.push(vecino);
                    visitados.insert(vecino);
                }
            }
        }
        cout << endl;
    }

    // Verifica si el grafo es conexo
    bool esConexo() {
        if (adjList.empty()) return true; // Grafo vacío es conexo
        int inicio = adjList.begin()->first;
        set<int> visitados;
        stack<int> pila;

        pila.push(inicio);
        visitados.insert(inicio);

        while (!pila.empty()) {
            int nodoActual = pila.top();
            pila.pop();

            for (int vecino : adjList[nodoActual]) {
                if (visitados.find(vecino) == visitados.end()) {
                    pila.push(vecino);
                    visitados.insert(vecino);
                }
            }
        }

        return visitados.size() == adjList.size();
    }
};

int main() {
    Grafo grafo;
    int opc, nodo, nodo1, nodo2;
    do {
        cout << "\n--------------------------MENU-----------------------" << endl;
        cout << "1. Agregar nodo" << endl;
        cout << "2. Eliminar nodo" << endl;
        cout << "3. Agregar arista" << endl;
        cout << "4. Eliminar arista" << endl;
        cout << "5. Mostrar grafo" << endl;
        cout << "6. Verificar si existe un nodo" << endl;
        cout << "7. Verificar si el grafo es conexo" << endl;
        cout << "8. Recorrido DFS" << endl;
        cout << "9. Recorrido BFS" << endl;
        cout << "0. Salir" << endl;
        cout << "-------------------> Ingrese una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingrese el nodo a agregar: ";
                cin >> nodo;
                grafo.agNodo(nodo);
                break;
            case 2:
                cout << "Ingrese el nodo a eliminar: ";
                cin >> nodo;
                grafo.elimNodo(nodo);
                break;
            case 3:
                cout << "Ingrese el nodo 1: ";
                cin >> nodo1;
                cout << "Ingrese el nodo 2: ";
                cin >> nodo2;
                grafo.agArista(nodo1, nodo2);
                break;
            case 4:
                cout << "Ingrese el nodo 1: ";
                cin >> nodo1;
                cout << "Ingrese el nodo 2: ";
                cin >> nodo2;
                grafo.elimArista(nodo1, nodo2);
                break;
            case 5:
                grafo.mostGrafo();
                break;
            case 6:
                cout << "Ingrese el nodo a verificar: ";
                cin >> nodo;
                if(grafo.existeNodo(nodo)){
                   cout << "El nodo existe en el grafo" << endl;
                }else{
                    cout << "El nodo no existe en el grafo" << endl;
                }
                break;
            case 7:
                if(grafo.esConexo()) {
                    cout << "El grafo es conexo." << endl;
                } else {
                    cout << "El grafo no es conexo." << endl;
                }
                break;
            case 8:
                cout << "Ingrese el nodo de inicio para DFS: ";
                cin >> nodo;
                grafo.DFS(nodo);
                break;
            case 9:
                cout << "Ingrese el nodo de inicio para BFS: ";
                cin >> nodo;
                grafo.BFS(nodo);
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opc != 0);
    return 0;
}