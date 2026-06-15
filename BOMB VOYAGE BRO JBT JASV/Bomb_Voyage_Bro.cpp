//Materia: Programación I, Paralelo 4
//Autores: Julian Blacutt Troche, José Armando Sánchez Velarde
//Fecha creación: 14/06/26
//Nombre del Proyecto: Bomb Voyage Bro
#include <iostream>

using namespace std;

struct DatosBomba
{
    int num_cables;//en toda dificultad
    char color_cables[30]; //en la dificultad más alta
    int num_botones; //en toda dificultad
    char texto_botones[30]; //en "veremos" para dificultades media y alta
    char codigo_num[30]; //en toda dificultad
    char letras_ocultas[30]; //en "veremos" para dificultades media y alta 
    char tipo_bomba[30]; //todavía en "veremos"
    int baterias; //establecer orden o un EasterEgg
    int interruptores; //todavía en "veremos"
}; //Algunas mecánicas pueden llegar a ser expandidas o eliminadas según nuestra conveniencia

int main()
{
    system ("chcp 65001");
    system ("cls");
    
    return 0;
}