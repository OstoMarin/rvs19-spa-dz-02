#include "game_of_life.h"
#include <iostream>

GameOfLife::GameOfLife(int sirina, int visina) : sirina(sirina), visina(visina), trenutno_stanje(visina, std::vector<bool>(sirina)), sljedece_stanje(visina, std::vector<bool>(sirina)) {}

void GameOfLife::postavi_stanje(const std::vector<std::vector<bool>>& pocetno_stanje) {
    trenutno_stanje = pocetno_stanje;
}

void GameOfLife::izracunaj_sljedece_stanje() {
    for (int y = 0; y < visina; y++) {
        for (int x = 0; x < sirina; x++) {
            int zivi_susjedi = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;
                    int ny = y + dy, nx = x + dx;
                    if (ny >= 0 && ny < visina && nx >= 0 && nx < sirina && trenutno_stanje[ny][nx])
                        zivi_susjedi++;
                }
            }

            if (trenutno_stanje[y][x]) {
                sljedece_stanje[y][x] = zivi_susjedi == 2 || zivi_susjedi == 3;
            }
            else {
                sljedece_stanje[y][x] = zivi_susjedi == 3;
            }
        }
    }
}

void GameOfLife::osvjezi_stanje() {
    trenutno_stanje = sljedece_stanje;
}

void GameOfLife::ispisi_stanje() {
    for (int y = 0; y < visina; y++) {
        for (int x = 0; x < sirina; x++) {
            std::cout << (trenutno_stanje[y][x] ? '*' : ' ') << ' ';
        }
        std::cout << '\n';
    }
}
