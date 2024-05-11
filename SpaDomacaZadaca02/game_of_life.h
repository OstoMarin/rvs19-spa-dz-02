#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <vector>

class GameOfLife {
private:
    int sirina;
    int visina;
    std::vector<std::vector<bool>> trenutno_stanje;
    std::vector<std::vector<bool>> sljedece_stanje;

public:
    GameOfLife(int sirina, int visina);
    void postavi_stanje(const std::vector<std::vector<bool>>& pocetno_stanje);
    void izracunaj_sljedece_stanje();
    void osvjezi_stanje();
    void ispisi_stanje();
};

#endif
