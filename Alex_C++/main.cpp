#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <filesystem>

//---------------------------------------------------------------- Librerias creadas por nosotros
#include "clases.h"

//------------------------------ Algo nuestro
using namespace std;

#include <windows.h>

class MostrarAlgo
{
private:
    vector<string> archivos_en_directorio;

public:
    string path;

    MostrarAlgo();
    ~MostrarAlgo();

    void Mostrar_Archivos(const std::string &a_carpeta);
    vector<string> Obtener_Archivos_Sin_Extension();
};

MostrarAlgo::MostrarAlgo()
{
}

MostrarAlgo::~MostrarAlgo()
{
}

void MostrarAlgo::Mostrar_Archivos(const std::string &a_carpeta)
{
    WIN32_FIND_DATA ffd{};
    if (auto handle = FindFirstFile((a_carpeta + "/*.*").c_str(), &ffd))
    {
        do
        {
            std::cout << ffd.cFileName << '\n';
            archivos_en_directorio.push_back(ffd.cFileName);
        } while (FindNextFile(handle, &ffd) != 0);
    }
}

vector<string> MostrarAlgo::Obtener_Archivos_Sin_Extension()
{
    vector<string> salidas;
    for (int i = 2; i < archivos_en_directorio.size(); i++)
    {
        string aux = archivos_en_directorio[i];
        int fin = aux.find('.');
        //aux = aux.substr(0, (fin - 1));
        salidas.push_back(aux.substr(0, (fin)));
    }
    return salidas;
}

// Funciones Estaticas

void enviar_comando(string archivo)
{
    
    string cmd;
    cmd = "FSM " + archivo;
    int n = cmd.length();
    char comando[n + 1];

    strcpy(comando, cmd.c_str());
    cout << endl
         << "Comando: " << comando << endl
         << endl;
    system(comando);
    cout << endl << endl<< "*****************************" << endl << endl;

}

int main(int argc, char *argv[])
{
    system("MD Salidas");
    MostrarAlgo Lector;
    Lector.Mostrar_Archivos("Tablas");
    vector<string> archivos_en_carpeta = Lector.Obtener_Archivos_Sin_Extension();
    for (auto archivo : archivos_en_carpeta)
    {
        cout << "El archivo es " << archivo << endl;
        enviar_comando(archivo);
    }

    system("pause");
    return 0;
}
//----------------------------------------------------------------------------------------