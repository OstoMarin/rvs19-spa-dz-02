#include "game_of_life.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

int main() {
    int sirina = 40;
    int visina = 20;
    GameOfLife igra(sirina, visina);

    srand(time(NULL));

    std::vector<std::vector<bool>> pocetno_stanje(visina, std::vector<bool>(sirina));
    for (int y = 0; y < visina; y++) {
        for (int x = 0; x < sirina; x++) {
            pocetno_stanje[y][x] = (rand() % 100) < 25;
        }
    }

    igra.postavi_stanje(pocetno_stanje);

    while (true) {
        system("cls");
        igra.ispisi_stanje();
        igra.izracunaj_sljedece_stanje();
        igra.osvjezi_stanje();

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
