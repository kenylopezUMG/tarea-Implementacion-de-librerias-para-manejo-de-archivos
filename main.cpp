#include <iostream>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

int main() {
    // Pedimos al usuario que introduzca la ruta de la carpeta a listar
    cout << "Introduce la ruta de la carpeta a listar: ";
    string path;
    cin >> path;

    // Verificamos si la carpeta existe
    if (!fs::exists(path)) {
        cerr << "La carpeta especificada no existe." << endl;
        return 1;
    }

    // Iteramos sobre todos los archivos del directorio y sus subdirectorios
    for (const auto &entry : fs::recursive_directory_iterator(path)) {
        // Verificamos si el archivo es un archivo regular
        if (fs::is_regular_file(entry)) {
            // Obtenemos el tamaño del archivo en bytes
            long long size = fs::file_size(entry);

            // Mostramos el tamaño del archivo en bytes
            cout << entry.path().string() << " - " << size << " bytes" << endl;
        }
    }

    return 0;
}