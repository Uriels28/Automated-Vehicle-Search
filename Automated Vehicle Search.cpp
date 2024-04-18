#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
  // Lectura de la cantidad de vehículos y consultas
  int n, q;
  cout << "Ingrese la cantidad de vehiculos en la coleccion: ";
  cin >> n;
  cout << "Ingrese la cantidad de consultas: ";
  cin >> q;

  // Lectura de los ID de los vehículos
  vector<int> ids(n);
  cout << "Ingrese los ID de los vehiculos (en orden creciente):" << endl;
  for (int i = 0; i < n; i++) {
    cout << "ID del vehiculo " << i + 1 << ": ";
    cin >> ids[i];
  }

  // Búsqueda de cada vehículo
  for (int i = 0; i < q; i++) {
    int k; // ID del vehículo a buscar
    cout << "\nIngrese el ID del vehiculo a buscar en la consulta " << i + 1 << ": ";
    cin >> k;

    // Inicialización de variables
    int s = sqrt(n);
    int scanner_position = 0;
    int moves = 0;
    bool found = false;

    // Búsqueda del vehículo
    while (!found && scanner_position < n) {
      // Leer ID en la posición actual
      int current_id = ids[scanner_position];

      // Avanzar S pasos
      if (current_id < k) {
        scanner_position += s;
        moves += s;
      }

      // Verificar si se encuentra el vehículo
      if (current_id == k) {
        found = true;
      } else if (current_id > k) {
        // Retroceder S pasos
        scanner_position -= s;
        moves += s;

        // Búsqueda lineal
        while (!found && scanner_position < n) {
          current_id = ids[scanner_position];
          moves++;

          if (current_id == k) {
            found = true;
          }

          scanner_position++;
        }
      }
    }

    // Imprimir el número de movimientos y el ID encontrado (si se encontró)
    if (found) {
      cout << "\nSe encontraron " << moves << " movimientos para encontrar el vehiculo con ID " << k << endl;
    } else {
      cout << "\nNo se encontro el vehiculo con ID " << k << endl;
    }
  }

  return 0;
}
