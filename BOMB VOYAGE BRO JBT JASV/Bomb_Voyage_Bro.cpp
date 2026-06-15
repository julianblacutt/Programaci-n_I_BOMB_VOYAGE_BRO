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

void desplegarMenu();
int main()
{
    system ("chcp 65001");
    system ("cls");
    
    cout<<"ADVERTENCIA: Previo a iniciar el juego usted necesita el manual de"<<endl;
    cout<<"desarmado de bombas descargado en PDF o en físico. Mucha suerte!"<<endl;
    system("pause");
    system ("cls");
    cout<<"Bienvenid@s a..."<<endl;
    cout<<"==============="<<endl;
    cout<<"BOMB VOYAGE BRO"<<endl;
    cout<<"==============="<<endl;
    cout<<"Un juego hecho para la materia Programación I tomando como"<<endl;
    cout<<"inspiración a llamado KEEP TALKING and NOBODY EXPLODES."<<endl;
    cout<<"Junto a un compañero deberán ser buenos comunicándose y actuando"<<endl;
    cout<<"bajo presión, recuerda que... el tiempo corre >:)"<<endl;
    system("pause");
    system("cls");
    desplegarMenu();
    return 0;
}
void desplegarMenu()
{
    int op=0;
    do
    {
        cout<<"MENÚ DE DIFICULTADES"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"¿Qué tan experimentados son desarmando bombas?"<<endl;
        cout<<"1. CARTUCHERO (NOVATO)"<<endl;
        cout<<"2. C4 TR3RO (MEDIO)"<<endl;
        cout<<"3. AMO DEL TSAR (PROFESIONAL)"<<endl;
        cout<<"4. Salir del Programa"<<endl;
        cout<<"Ingrese una opción válida por favor: ";
        cin>>op;
        system("cls");
        switch (op)
        {
        case 1:
            cout<<"Usted a eligió la dificultad CARTUCHERO"<<endl;
            system("pause");
            break;
        case 2:
            cout<<"Usted eligió la dificultad C4 TR3RO"<<endl;
            system("pause");
            break;
        case 3:
            cout<<"Usted eligió la dificultad AMO DEL TSAR"<<endl;
            system("pause");
            break;
        default:
            if (op<=0||op>4)
            {
                cout<<"Debe ingresar una opción válida."<<endl;
                system("pause");
            }
            break;
        }
    } while (op!=4);
    system("cls");
    cout<<"Usted eligió: Salir del Juego"<<endl;
}