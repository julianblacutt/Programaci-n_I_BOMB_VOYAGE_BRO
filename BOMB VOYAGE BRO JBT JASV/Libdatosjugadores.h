#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct DatosJugadores
{
    char nombre_equipo[30];
    char nombre_player1[30];
    char nombre_player2[30];
};

void JugadoresCARTUCHERO() 
{
    DatosJugadores team;
    ofstream archivo;

    cout << "Ahora pueden llenar los datos" << endl;
    cout << "Ingresen el nombre del equipo: ";
    cin.getline(team.nombre_equipo, 30);

    cout << "Ingrese su nombre J1: ";
    cin.getline(team.nombre_player1, 30);

    cout << "Ingrese su nombre J2: ";
    cin.getline(team.nombre_player2, 30);

    archivo.open("HeroesCARTUCHERO.bin", ios::binary | ios::app);
    archivo.write((char*)&team, sizeof(DatosJugadores));
    archivo.close();

    cout << "Se han registrado los datos de forma correcta." << endl;
}

void JugadoresC4_TR3RO() 
{
    DatosJugadores team;
    ofstream archivo;

    cout << "Ahora pueden llenar los datos" << endl;
    cout << "Ingresen el nombre del equipo: ";
    cin.getline(team.nombre_equipo, 30);

    cout << "Ingrese su nombre J1: ";
    cin.getline(team.nombre_player1, 30);

    cout << "Ingrese su nombre J2: ";
    cin.getline(team.nombre_player2, 30);

    archivo.open("HeroesC4-TR3RO.bin", ios::binary | ios::app);
    archivo.write((char*)&team, sizeof(DatosJugadores));
    archivo.close();

    cout << "Se han registrado los datos de forma correcta." << endl;
}

void JugadoresAMODELTSAR() 
{
    DatosJugadores team;
    ofstream archivo;

    cout << "Ahora pueden llenar los datos" << endl;
    cout << "Ingresen el nombre del equipo: ";
    cin.getline(team.nombre_equipo, 30);

    cout << "Ingrese su nombre J1: ";
    cin.getline(team.nombre_player1, 30);

    cout << "Ingrese su nombre J2: ";
    cin.getline(team.nombre_player2, 30);

    archivo.open("HeroesAMODELTSAR.bin", ios::binary | ios::app);
    archivo.write((char*)&team, sizeof(DatosJugadores));
    archivo.close();

    cout << "Se han registrado los datos de forma correcta." << endl;
}

void reporteDoc1() 
{
    ifstream archCartuchero;
    DatosJugadores team;

    archCartuchero.open("HeroesCARTUCHERO.bin", ios::binary);

    if (!archCartuchero.good()) 
    {
        cout << "No existen registros en el sistema." << endl;
        return;
    }

    cout << "Los Héroes de la dificultad CARTUCHERO" << endl;
    cout << "======================================" << endl;

    while (archCartuchero.read((char*)&team, sizeof(DatosJugadores))) 
    {
        cout << "\nNombre equipo: " << team.nombre_equipo << endl;
        cout << "Jugador1: " << team.nombre_player1 << endl;
        cout << "Jugador2: " << team.nombre_player2 << endl;
    }
    archCartuchero.close();
}

void reporteDoc2() 
{
    ifstream archC4tr3ro;
    DatosJugadores team;

    archC4tr3ro.open("HeroesC4-TR3RO.bin", ios::binary);

    if (!archC4tr3ro.good()) 
    {
        cout << "No existen registros en el sistema." << endl;
        return;
    }

    cout << "Los Héroes de la dificultad C4-TR3RO" << endl;
    cout << "======================================" << endl;

    while (archC4tr3ro.read((char*)&team, sizeof(DatosJugadores))) 
    {
        cout << "\nNombre equipo: " << team.nombre_equipo << endl;
        cout << "Jugador1: " << team.nombre_player1 << endl;
        cout << "Jugador2: " << team.nombre_player2 << endl;
    }
    archC4tr3ro.close();
}

void reporteDoc3() 
{
    ifstream archAmodelTsar;
    DatosJugadores team;

    archAmodelTsar.open("HeroesAMODELTSAR.bin", ios::binary);

    if (!archAmodelTsar.good()) 
    {
        cout << "No existen registros en el sistema." << endl;
        return;
    }

    cout << "Los Héroes de la dificultad AMO DEL TSAR" << endl;
    cout << "======================================" << endl;

    while (archAmodelTsar.read((char*)&team, sizeof(DatosJugadores))) 
    {
        cout << "\nNombre equipo: " << team.nombre_equipo << endl;
        cout << "Jugador1: " << team.nombre_player1 << endl;
        cout << "Jugador2: " << team.nombre_player2 << endl;
    }
    archAmodelTsar.close();
}