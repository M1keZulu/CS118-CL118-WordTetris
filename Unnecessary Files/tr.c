#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

HANDLE g_consOut;

void cls() {
    COORD topLeft = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
    if (!GetConsoleScreenBufferInfo(g_consOut, &csbi))
        return;
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    if (!FillConsoleOutputCharacter(g_consOut, ' ', dwConSize,
            topLeft, &cCharsWritten))
        return;
    if (!GetConsoleScreenBufferInfo(g_consOut, &csbi))
        return;
    if (!FillConsoleOutputAttribute(g_consOut, csbi.wAttributes,
            dwConSize, topLeft, &cCharsWritten))
        return;
    SetConsoleCursorPosition(g_consOut, topLeft);
}

void setPos(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(g_consOut, pos);
}

void writech(int col, int row, char c) {
    setPos(col, row);
    WriteConsole(g_consOut, &c, 1, NULL, NULL);
}

int main() {
    enum {reps = 10, bottom = 15, width = 80, sleep_time = 200};
    srand((unsigned)time(NULL));
    g_consOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cls();
    int n;
    for (n = 0; n < reps; n++) {
        char c = rand() % ('z'-'a') + 'a';
        int col = rand() % width;
        int i;
        for (i = 0; i < bottom; i++) {
            writech(col, i, c);
            Sleep(sleep_time);
            writech(col, i, ' ');
            if (_kbhit()) {
                char cc = _getch();
                if (tolower(cc) == c)
                    break;
            }
        }
        if (i == bottom) // letter got to bottom
            break;
    }
    cls();
    return 0;
}
