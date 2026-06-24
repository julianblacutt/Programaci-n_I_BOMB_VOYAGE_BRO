#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Estructura de Datos de la Bomba e
struct DatosBomba {
    int num_cables; 
    char color_cables[30]; 
    int num_botones; 
    char color_botones[30]; 
    char texto_botones[30]; 
    char codigo_num[30]; 
    char distintivo_bomba[30]; 
    int baterias; 
};

// Variables Globales de Control de Juego
int errores = 0;
bool juego_terminado = false;
bool bomba_desactivada = false;
int tiempo_restante_segundos = 0;

// Estado de resolución de módulos individuales
bool modulo_cables_resuelto = false;
bool modulo_botones_resuelto = false;
bool modulo_codigo_resuelto = false;


// Función para simular un valor aleatorio en un rango determinado
int generarAleatorio(int min, int max) {
    if (min >= max) return min;
    return min + (rand() % (max - min + 1));
}

int obtenerLongitudCadena(const char* cad) {
    int len = 0;
    while (cad[len] != '\0') {
        len++;
    }
    return len;
}

bool compararCadenas(const char* cad1, const char* cad2) {
    int i = 0;
    while (cad1[i] != '\0' || cad2[i] != '\0') {
        if (cad1[i] != cad2[i]) return false;
        i++;
    }
    return true;
}

// Inversión manual de cadenas
void invertirCadena(char* cad, int longitud) {
    int inicio = 0;
    int fin = longitud - 1;
    while (inicio < fin) {
        char temporal = cad[inicio];
        cad[inicio] = cad[fin];
        cad[fin] = temporal;
        inicio++;
        fin--;
    }
}

// --- HILO DE CRONÓMETRO/TEMPORIZADOR ---
void Cronometro(int tiempoSegundos)
{
    system("cls");
    cout << "Iniciando conteo..." << endl;
    for (int i = 1; i <= tiempoSegundos; i--)
    {
        cout << i << " seg. " << "\r";
        // El programa se "congela" aquí por 1 segundo (1000 milisegundos)
        this_thread::sleep_for(chrono::seconds(1)); 
    }
    cout << "TIEMPO TERMINADO" << endl;
}

// --- GENERADOR DE CONFIGURACIÓN DE BOMBA ---
void inicializarBombaAleatoria(DatosBomba &bomba, int dificultad) {
    char banco_colores[4] = {'R', 'A', 'M', 'N'}; // Rojo, Azul, Amarillo, Negro
    char banco_letras[5] = {'O', 'A', 'D', 'T', 'S'};
    
    // Regla del Easter Egg de Baterías
    bomba.baterias = 0;
    if (dificultad == 1) { // Cartuchero: Alta probabilidad
        if (generarAleatorio(1, 100) <= 40) { // 40% probabilidad
            bomba.baterias = generarAleatorio(1, 3);
        }
    } else if (dificultad == 3) { // Amo del TSAR: Baja probabilidad
        if (generarAleatorio(1, 100) <= 10) { // 10% probabilidad
            bomba.baterias = generarAleatorio(1, 2);
        }
    }

    // Configuración de Cables
    if (dificultad == 1) {
        bomba.num_cables = 3;
    } else {
        bomba.num_cables = generarAleatorio(4, 5);
    }
    for (int i = 0; i < bomba.num_cables; i++) {
        bomba.color_cables[i] = banco_colores[generarAleatorio(0, 3)];
    }
    bomba.color_cables[bomba.num_cables] = '\0';

    // Configuración de Botones
    if (dificultad == 1) {
        bomba.num_botones = 1;
        bomba.color_botones[0] = banco_colores[generarAleatorio(0, 2)]; // Evitamos negro a veces para dar jugabilidad
        bomba.color_botones[1] = '\0';
        bomba.texto_botones[0] = '\0';
    } else {
        bomba.num_botones = generarAleatorio(2, 3);
        for(int i = 0; i < bomba.num_botones; i++) {
            bomba.color_botones[i] = banco_colores[generarAleatorio(0, 3)];
        }
        bomba.color_botones[bomba.num_botones] = '\0';
        
        int text_opt = generarAleatorio(0, 2);
        if (text_opt == 0) {
            bomba.texto_botones[0] = 'O'; bomba.texto_botones[1] = 'K'; bomba.texto_botones[2] = '\0';
        } else if (text_opt == 1) {
            bomba.texto_botones[0] = 'S'; bomba.texto_botones[1] = 'T'; bomba.texto_botones[2] = 'O'; bomba.texto_botones[3] = 'P'; bomba.texto_botones[4] = '\0';
        } else {
            bomba.texto_botones[0] = 'G'; bomba.texto_botones[1] = 'O'; bomba.texto_botones[2] = '\0';
        }
    }

    // Código Numérico (4 Dígitos siempre en formato texto)
    for (int i = 0; i < 4; i++) {
        bomba.codigo_num[i] = '0' + generarAleatorio(1, 9);
    }
    bomba.codigo_num[4] = '\0';

    // Distintivo de la Bomba
    for(int i = 0; i < 5; i++) {
        bomba.distintivo_bomba[i] = banco_letras[generarAleatorio(0, 4)];
    }
    bomba.distintivo_bomba[5] = '\0';
}

void mostrarDatosBomba(const DatosBomba &bomba) {
    cout << "\n=============================================" << endl;
    cout << "       ESPECIFICACIONES VISIBLES DE LA BOMBA " << endl;
    cout << "=============================================" << endl;
    cout << " > Cables Disponibles: " << bomba.num_cables << " -> [ ";
    for (int i = 0; i < bomba.num_cables; i++) cout << bomba.color_cables[i] << " ";
    cout << "]" << endl;
    cout << " > Cantidad de Botones: " << bomba.num_botones << endl;
    cout << " > Colores de Botones: [ ";
    for (int i = 0; i < bomba.num_botones; i++) cout << bomba.color_botones[i] << " ";
    cout << "]" << endl;
    
    if (obtenerLongitudCadena(bomba.texto_botones) > 0) {
        cout << " > Texto inscrito en Botones: " << bomba.texto_botones << endl;
    } else {
        cout << " > Texto inscrito en Botones: SIN TEXTO" << endl;
    }
    cout << " > Pantalla de Codigo: " << bomba.codigo_num << endl;
    cout << " > Distintivo del Chasis: " << bomba.distintivo_bomba << endl;
    cout << " > Compartimento de baterias internas: " << bomba.baterias << " baterias." << endl;
    cout << "=============================================" << endl;
}

// --- INTELIGENCIA DE RESOLUCIÓN DE MÓDULOS ---

void jugarCables(const DatosBomba &bomba, int dificultad) {
    cout << "\n--- MÓDULO: CABLES ---" << endl;
    cout << "Ingrese el indice del cable que desea cortar (0 a " << bomba.num_cables - 1 << "): ";
    int eleccion;
    cin >> eleccion;

    // Obtener respuesta correcta lógica simulada según manual simplificado
    int correcto = 0;
    if (dificultad == 1) {
        int rojos = 0, azules = 0, amarillos = 0;
        for(int i=0; i<3; i++) {
            if(bomba.color_cables[i] == 'R') rojos++;
            if(bomba.color_cables[i] == 'A') azules++;
            if(bomba.color_cables[i] == 'M') amarillos++;
        }
        if (rojos == 1) {
            for(int i=0; i<3; i++) if(bomba.color_cables[i] == 'R') correcto = i;
        } else if (bomba.color_cables[0] != bomba.color_cables[1] && bomba.color_cables[1] != bomba.color_cables[2] && bomba.color_cables[0] != bomba.color_cables[2]) {
            for(int i=0; i<3; i++) if(bomba.color_cables[i] == 'M') correcto = i;
        } else if (azules == 2) {
            for(int i=2; i>=0; i--) if(bomba.color_cables[i] == 'A') { correcto = i; break; }
        } else {
            correcto = 1;
        }
    } else {
        // Fallback básico para modularización avanzada C4-TR3RO / TSAR
        correcto = bomba.num_cables - 1; 
    }

    if (eleccion == correcto) {
        cout << "¡Seccion de cables superada con exito!" << endl;
        modulo_cables_resuelto = true;
    } else {
        errores++;
        cout << "¡CABLE INCORRECTO! Chispas y error registrado. (Errores: " << errores << "/3)" << endl;
    }
}

void jugarBotones(const DatosBomba &bomba, int dificultad) {
    cout << "\n--- MÓDULO: BOTÓN ---" << endl;
    cout << "Opciones de accion:\n1. Pulsar\n2. Mantener 3 segundos\n3. Pulsar dos veces\n4. No Pulsar\nSeleccione la accion correcta: ";
    int seleccion;
    cin >> seleccion;

    int accion_correcta = 1; 
    char color_evaluar = bomba.color_botones[0];

    if (obtenerLongitudCadena(bomba.texto_botones) == 0 || dificultad == 1) {
        if (color_evaluar == 'R') accion_correcta = 1;
        else if (color_evaluar == 'A') accion_correcta = 2;
        else if (color_evaluar == 'M') accion_correcta = 3;
        else if (color_evaluar == 'N') accion_correcta = 4;
    } else {
        if (compararCadenas(bomba.texto_botones, "OK")) accion_correcta = 1;
        else if (compararCadenas(bomba.texto_botones, "STOP")) accion_correcta = 2;
        else if (compararCadenas(bomba.texto_botones, "GO")) accion_correcta = 3;
    }

    if (seleccion == accion_correcta) {
        cout << "¡Presion de boton validada!" << endl;
        modulo_botones_resuelto = true;
    } else {
        errores++;
        cout << "¡ACCION ERRONEA! El sistema rechazo la pulsacion. (Errores: " << errores << "/3)" << endl;
    }
}

void jugarCodigo(const DatosBomba &bomba, int dificultad) {
    cout << "\n--- MÓDULO: CÓDIGO NUMÉRICO ---" << endl;
    char respuesta_esperada[30];
    for(int i = 0; i < 5; i++) respuesta_esperada[i] = bomba.codigo_num[i];

    int suma = 0;
    for (int i = 0; i < 4; i++) {
        suma += (bomba.codigo_num[i] - '0');
    }

    if (dificultad == 1) {
        if (suma % 2 == 0) {
            invertirCadena(respuesta_esperada, 4);
        }
    } else {
        int primer = bomba.codigo_num[0] - '0';
        int ultimo = bomba.codigo_num[3] - '0';
        if (primer > ultimo) {
            invertirCadena(respuesta_esperada, 4);
        } else if (primer == ultimo) {
            for (int i = 0; i < 4; i++) {
                int digito = (respuesta_esperada[i] - '0' + 1) % 10;
                respuesta_esperada[i] = '0' + digito;
            }
        }
    }

    cout << "Ingrese el codigo de desactivacion de 4 digitos: ";
    char entrada_usuario[30];
    cin >> entrada_usuario;

    if (compararCadenas(entrada_usuario, respuesta_esperada)) {
        cout << "¡Codigo aceptado! Modulo desbloqueado." << endl;
        modulo_codigo_resuelto = true;
    } else {
        errores++;
        cout << "¡CODIGO ERRONEO! Acceso Denegado. (Errores: " << errores << "/3)" << endl;
    }
}

// --- CONTROL PRINCIPAL DEL MENÚ DE LA BOMBA ---
void menuDesactivacionBomba(const DatosBomba &bomba, int dificultad) {
    while (!juego_terminado && !bomba_desactivada) {
        // Validar si el juego terminó por acumulación de fallos
        if (errores >= 3) {
            juego_terminado = true;
            break;
        }

        // Condición de Victoria: Todas las secciones están completadas
        if (modulo_cables_resuelto && modulo_botones_resuelto && modulo_codigo_resuelto) {
            bomba_desactivada = true;
            break;
        }

        mostrarDatosBomba(bomba);
        cout << "\nTiempo Restante: " << tiempo_restante_segundos << " segundos. | Errores: " << errores << "/3" << endl;
        cout << "=== MENU DE SECCIONES DE SEGURIDAD ===" << endl;
        cout << "1. Tratar Seccion: Cables " << (modulo_cables_resuelto ? "[RESUELTO]" : "[PENDIENTE]") << endl;
        cout << "2. Tratar Seccion: Boton Único " << (modulo_botones_resuelto ? "[RESUELTO]" : "[PENDIENTE]") << endl;
        cout << "3. Tratar Seccion: Código Numérico " << (modulo_codigo_resuelto ? "[RESUELTO]" : "[PENDIENTE]") << endl;
        
        if (bomba.baterias > 0) {
            cout << "4. [COMPARTIMENTO EXTRA] Arrancar baterias de emergencia" << endl;
        }
        cout << "0. Salir y rendirse (Game Over)" << endl;
        cout << "Seleccione el modulo a resolver de inmediato: ";
        
        int opcion;
        cin >> opcion;

        if (opcion == 0) {
            juego_terminado = true;
            break;
        }

        switch (opcion) {
            case 1:
                if (modulo_cables_resuelto) {
                    cout << "\n[Aviso] Esta seccion ya fue resuelta. Volviendo al menu..." << endl;
                } else {
                    jugarCables(bomba, dificultad);
                }
                break;
            case 2:
                if (modulo_botones_resuelto) {
                    cout << "\n[Aviso] Esta seccion ya fue resuelta. Volviendo al menu..." << endl;
                } else {
                    jugarBotones(bomba, dificultad);
                }
                break;
            case 3:
                if (modulo_codigo_resuelto) {
                    cout << "\n[Aviso] Esta seccion ya fue resuelta. Volviendo al menu..." << endl;
                } else {
                    jugarCodigo(bomba, dificultad);
                }
                break;
            case 4:
                if (bomba.baterias > 0) {
                    cout << "\n¡Has retirado las baterias fisicamente!" << endl;
                    cout << "La bomba se apaga por falta de energia de soporte." << endl;
                    bomba_desactivada = true;
                } else {
                    cout << "Opcion no valida." << endl;
                }
                break;
            default:
                cout << "Opcion invalida en el panel de control." << endl;
                break;
        }
    }
}