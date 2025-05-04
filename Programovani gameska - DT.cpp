#include <iostream>
using namespace std;

int main() {
    int M, x2M, x3M, MB, HB, V;
    int maxZivoty = 0, zivoty = 0, maxMana = 0, mana = 0, utok = 0, zlato = 0, level = 1, zkusenosti = 0;

    string herniJmeno;
    cout << "Zadej sve herni jmeno: ";
    cin >> herniJmeno;

    string vyber;
    int potvrzeno = 0;

    while (potvrzeno == 0) {
        cout << endl << "Vyber si classu: (paladin / mag / lovec / warrior)" << endl;
        cin >> vyber;

        if (vyber == "paladin") {
            maxZivoty = 7;
            zivoty = 7;
            maxMana = 5;
            mana = 5;
            utok = 3;
            zlato = 10;
            cout << "Class: Paladin" << endl;
        } else if (vyber == "mag") {
            maxZivoty = 3;
            zivoty = 3;
            maxMana = 8;
            mana = 8;
            utok = 2;
            zlato = 20;
            cout << "Class: Mag" << endl;
        } else if (vyber == "lovec") {
            maxZivoty = 5;
            zivoty = 5;
            maxMana = 6;
            mana = 6;
            utok = 4;
            zlato = 15;
            cout << "Class: Lovec" << endl;
        } else if (vyber == "warrior") {
            maxZivoty = 8;
            zivoty = 8;
            maxMana = 3;
            mana = 3;
            utok = 5;
            zlato = 5;
            cout << "Class: Warrior" << endl;
        } else {
            cout << "Neplatna classa. Zkus znovu." << endl;
            continue;
        }

        cout << "Zivoty: " << zivoty << "/" << maxZivoty << endl;
        cout << "Mana: " << mana << "/" << maxMana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Zlato: " << zlato << endl;

        string potvrzeni;
        cout << "Chces tuto classu? (ano/ne): ";
        cin >> potvrzeni;

        if (potvrzeni == "ano") {
            potvrzeno = 1;
            cout << "Classa byla vybrana." << endl;
        } else {
            cout << "Vyber si jinou classu." << endl;
        }
    }

            cout << "Vitej ve hre, " << herniJmeno << "!" << endl;
            cout << "Priprav se, budes bojovat!" << endl;

            string postavy[] = {"M", "2xM", "V", "3xM", "MB", "V", "M", "HB"};

        for (int i = 0; i < 8; i++) {
            string aktualni = postavy[i];
            cout << endl << "Setkal jsi se s: " << aktualni << endl;

        if (aktualni == "M") {
                int zivotMonstra = 3;
                while (zivotMonstra > 0 && zivoty > 0) {
                    cout << "Utocis za " << utok << " zraneni." << endl;
                zivotMonstra -= utok;

                if (zivotMonstra <= 0) {
                    cout << "Zabil si monstrum!" << endl;
                    break;
                }

                    cout << "Monstrum vraci uder! Ubrati 1 zivot." << endl;
                zivoty--;

                if (zivoty <= 0) {
                    cout << "Zemrel jsi. Konec hry." << endl;
                    return 0;
                }

                    cout << "Mas " << zivoty << " zivotu zbyva." << endl;
            }

        } else if (aktualni == "2xM") {
                int zivotM1 = 3, zivotM2 = 3;
                while ((zivotM1 > 0 || zivotM2 > 0) && zivoty > 0) {
                    cout << "Vyber monstrum do kteryho pujdes (1 nebo 2): ";
                int volba;
                    cin >> volba;

                if (volba == 1 && zivotM1 > 0) {
                    zivotM1 -= utok;
                    cout << "Utocis na monstrum 1. Zivoty: " << max(0, zivotM1) << endl;
                } else if (volba == 2 && zivotM2 > 0) {
                    zivotM2 -= utok;
                    cout << "Utocis na monstrum 2. Zivoty: " << max(0, zivotM2) << endl;
                } else {
                    cout << "Ty chces zabijet neco co si zabil?. :D" << endl;
                    continue;
                }


                if (zivotM1 > 0) {
                    cout << "Monstrum 1 te zasahuje za 1 zivot." << endl;
                    zivoty--;
                }
                if (zivotM2 > 0) {
                    cout << "Monstrum 2 te zasahuje za 1 zivot." << endl;
                    zivoty--;
                }

                if (zivoty <= 0) {
                    cout << "Zemrel jsi. Konec hry." << endl;
                    return 0;
                }

                    cout << "Mas " << zivoty << " zivotu zbyva." << endl;
            }
                    cout << "Porazil jsi dve monstra!" << endl;

            } else if (aktualni == "V") {
                    cout << "Dorazil jsi do vesnice. Tady si odpocines od monster a doplnis manu." << endl;
            zivoty = maxZivoty;
            mana = maxMana;
            } else {
                    cout << "Zatim mas klidos." << endl;
        }
    }

    cout << "Gratuluju, jsi na konci teto hry!" << endl;
    return 0;
}
