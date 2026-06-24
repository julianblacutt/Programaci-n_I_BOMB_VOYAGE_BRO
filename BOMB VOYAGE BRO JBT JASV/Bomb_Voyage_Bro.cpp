//Materia: Programación I, Paralelo 4
//Autores: Julian Blacutt Troche, José Armando Sánchez Velarde
//Fecha creación: 14/06/26
//Grupo: 2
//Nombre del Proyecto: Bomb Voyage Bro
#include <iostream>
#include <thread>
#include <chrono>
#include "LibFuncionesUniversales.h"
#include "Libdatosjugadores.h"

using namespace std;

void desplegarMenu();

int main()
{
    system("chcp 65001");
    system("cls");
    srand(time(0));
    cout << "ADVERTENCIA: Previo a iniciar el juego usted necesita el manual de" << endl;
    cout << "desarmado de bombas descargado en PDF o en físico. Mucha suerte!" << endl;
    system("pause");
    system("cls");
    cout << "Bienvenid@s a..." << endl;
    cout << "===============" << endl;
    cout << "BOMB VOYAGE BRO" << endl;
    cout << "===============" << endl;
    cout << "Un juego hecho para la materia Programación I tomando como" << endl;
    cout << "inspiración a llamado KEEP TALKING and NOBODY EXPLODES." << endl;
    cout << "Junto a un compañero deberán ser buenos comunicándose y actuando" << endl;
    cout << "bajo presión, recuerda que... el tiempo corre >:)" << endl;
    system("pause");
    desplegarMenu();
    return 0;
}

void desplegarMenu()
{
    int dificultad = 0;
    do
    {
        cout << "MENÚ DE DIFICULTADES" << endl;
        cout << "--------------------" << endl;
        cout << "¿Qué tan experimentados son desarmando bombas?" << endl;
        cout << "1. CARTUCHERO (NOVATO) [160s]" << endl; // tiempo de resolucion 2:40min
        cout << "2. C4 TR3RO (MEDIO) [250s]" << endl;    // tiempo de resolución 4:10min
        cout << "3. AMO DEL TSAR (PROFESIONAL) [370s]" << endl; // tiempo de resolución 6:10min
        cout << "4. Salir del Programa" << endl;
        cout << "Ingrese una opción válida por favor: ";
        cin >> dificultad;
        system("cls");
        
        switch (dificultad)
        {
        case 1: 
        { 
            cout << "Usted eligió la dificultad CARTUCHERO" << endl;
            tiempo_restante_segundos = 150; 
            
            DatosBomba bombaActual;
            inicializarBombaAleatoria(bombaActual, dificultad);

            // FIJADO: Se pasa el parámetro numérico que requiere la función Cronometro
            thread hiloTiempo(Cronometro, tiempo_restante_segundos);

            menuDesactivacionBomba(bombaActual, dificultad);

            hiloTiempo.join();

            cout << "\n=============================================" << endl;
            if (bomba_desactivada && errores < 3 && tiempo_restante_segundos > 0) {
                cout << "   ¡BOMBA DESACTIVADA CON ÉXITO!" << endl;
                cout << "     Buen viaje, bro. Has salvado el dia." << endl;
            } else {
                cout << "   ¡¡¡BOOOOOOM!!! GAME OVER" << endl;
                if (errores >= 3) cout << " Motivo: Alcanzaste el limite maximo de 3 errores." << endl;
                else cout << " Motivo: El tiempo se agoto por completo." << endl;
            }
            cout << "=============================================" << endl;
            system("pause");
            
            if (bomba_desactivada == true)
            {
                // FIJADO: Llamadas directas eliminando la palabra 'void'
                cin.ignore(); // Limpiamos el búfer antes de leer cadenas
                JugadoresCARTUCHERO();
                reporteDoc1();
            }
            break;
        } 
        
        case 2:
        {
            cout << "Usted eligió la dificultad C4 TR3RO" << endl;
            tiempo_restante_segundos = 250;
            DatosBomba bombaActual;
            inicializarBombaAleatoria(bombaActual, dificultad);

            thread hiloTiempo(Cronometro, tiempo_restante_segundos);

            menuDesactivacionBomba(bombaActual, dificultad);

            hiloTiempo.join();

            cout << "\n=============================================" << endl;
            if (bomba_desactivada && errores < 3 && tiempo_restante_segundos > 0) {
                cout << "   ¡BOMBA DESACTIVADA CON ÉXITO!" << endl;
                cout << "     Buen viaje, bro. Has salvado el dia." << endl;
            } else {
                cout << "   ¡¡¡BOOOOOOM!!! GAME OVER" << endl;
                if (errores >= 3) cout << " Motivo: Alcanzaste el limite maximo de 3 errores." << endl;
                else cout << " Motivo: El tiempo se agoto por completo." << endl;
            }
            cout << "=============================================" << endl;
            system("pause");
            
            if (bomba_desactivada == true)
            {
                cin.ignore();
                JugadoresC4_TR3RO();
                reporteDoc2();
            }
            break;
        }  
        case 3:
        {
            cout << "Usted eligió la dificultad AMO DEL TSAR" << endl;
            tiempo_restante_segundos = 360;
            DatosBomba bombaActual;
            inicializarBombaAleatoria(bombaActual, dificultad);

            thread hiloTiempo(Cronometro, tiempo_restante_segundos);

            menuDesactivacionBomba(bombaActual, dificultad);

            hiloTiempo.join();

            cout << "\n=============================================" << endl;
            if (bomba_desactivada && errores < 3 && tiempo_restante_segundos > 0) {
                cout << "   ¡BOMBA DESACTIVADA CON ÉXITO!" << endl;
                cout << "     Buen viaje, bro. Has salvado el dia." << endl;
            } else {
                cout << "   ¡¡¡BOOOOOOM!!! GAME OVER" << endl;
                if (errores >= 3) cout << " Motivo: Alcanzaste el limite maximo de 3 errores." << endl;
                else cout << " Motivo: El tiempo se agoto por completo." << endl;
            }
            cout << "=============================================" << endl;
            system("pause");
            
            if (bomba_desactivada == true)
            {
                cin.ignore();
                JugadoresAMODELTSAR();
                reporteDoc3();
            }
            break;
         }   
        default:
            if (dificultad <= 0 || dificultad > 4)
            {
                cout << "Debe ingresar una opción válida." << endl;
                system("pause");
            }
            break;
        }
    } while (dificultad != 4);
    
    system("cls");
    cout << "Usted eligió: Salir del Juego" << endl;
}