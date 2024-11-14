#include <stdio.h>
#include <stdlib.h>
#include "GUI.h"

// Caminho da pasta de ícones
#define ICON_PATH "GUI Interface/"

// Estrutura de um ícone com nome, arquivo e posição na barra de tarefas
typedef struct {
    const char *name;
    const char *filename;
    int x, y; // Coordenadas do ícone
} Icon;

// Lista dos ícones disponíveis
Icon icons[] = {
    {"Calculator", ICON_PATH "calculator.png", 50, 10},
    {"Calendar", ICON_PATH "calendar.png", 90, 10},
    {"Camera", ICON_PATH "camera.png", 130, 10},
    {"Clock", ICON_PATH "clock.png", 170, 10},
    {"Edge", ICON_PATH "edge.png", 210, 10},
    {"Email", ICON_PATH "email.png", 250, 10},
    {"Feedback", ICON_PATH "feedback.png", 290, 10},
    {"Gallery", ICON_PATH "gallery.png", 330, 10},
    {"Games", ICON_PATH "games.png", 370, 10},
    {"Maps", ICON_PATH "maps.png", 410, 10},
    {"Movies", ICON_PATH "movies.png", 450, 10},
    {"Music", ICON_PATH "music.png", 490, 10},
    {"My Files", ICON_PATH "my_files.png", 530, 10},
    {"People", ICON_PATH "people.png", 570, 10},
    {"Snip Tool", ICON_PATH "snip.png", 610, 10},
    {"Sound Recorder", ICON_PATH "sound_recorder.png", 650, 10},
    {"Store", ICON_PATH "store.png", 690, 10},
    {"Stream", ICON_PATH "stream.png", 730, 10},
    {"Weather", ICON_PATH "weather.png", 770, 10},
    {"Whiteboard", ICON_PATH "whiteboard.png", 810, 10}
};

// Função para carregar ícones na taskbar
void loadIcons() {
    for (int i = 0; i < sizeof(icons) / sizeof(icons[0]); i++) {
        // Carregar imagem do ícone na posição especificada
        drawIcon(icons[i].filename, icons[i].x, icons[i].y);
    }
}

// Função para detectar e processar o clique em um ícone
void onIconClick(int mouseX, int mouseY) {
    for (int i = 0; i < sizeof(icons) / sizeof(icons[0]); i++) {
        if (mouseX >= icons[i].x && mouseX <= icons[i].x + 32 &&
            mouseY >= icons[i].y && mouseY <= icons[i].y + 32) {
            
            // Abre a janela correspondente ao ícone clicado
            openWindow(icons[i].name);
            break;
        }
    }
}

// Função para abrir uma janela para o aplicativo correspondente
void openWindow(const char *appName) {
    printf("Abrindo %s...\n", appName);
    // Exibir a interface específica do aplicativo aqui
    // Exemplo: criar uma nova janela, carregar conteúdo relevante, etc.
}

int main() {
    initGUI(); // Inicializa a interface gráfica

    loadIcons(); // Carrega os ícones na taskbar

    // Loop de eventos para interatividade
    while (1) {
        int mouseX, mouseY;
        if (getMouseClick(&mouseX, &mouseY)) {
            onIconClick(mouseX, mouseY);
        }
    }

    return 0;
}
