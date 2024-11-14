#ifndef GUI_H
#define GUI_H

// Inicializa a interface gráfica
void initGUI();

// Desenha um ícone específico na posição (x, y)
void drawIcon(const char *filename, int x, int y);

// Obtém as coordenadas de um clique do mouse
// Retorna 1 se houve clique, e 0 caso contrário
int getMouseClick(int *x, int *y);

// Abre uma janela correspondente ao aplicativo especificado
void openWindow(const char *appName);

#endif // GUI_H
