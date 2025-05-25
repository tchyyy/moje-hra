#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int maxZivoty = 0, zivoty = 0, maxMana = 0, mana = 0, utok = 0;
    int zlato = 0, level = 1, zkusenosti = 0;
    bool Uhyb = false;

    string herniJmeno;
    cout << "Zadej sve herni jmeno: ";
    cin >> herniJmeno;

    string vyber;
    int potvrzeno = 0;

    while (potvrzeno == 0) {
        cout << endl << "Vyber si classu: (paladin / mag / lovec / warrior)" << endl;
        cin >> vyber;

        if (vyber == "paladin") {
            maxZivoty = 7; zivoty = 7; maxMana = 5; mana = 5; utok = 3; zlato = 10;
        } else if (vyber == "mag") {
            maxZivoty = 3; zivoty = 3; maxMana = 8; mana = 8; utok = 2; zlato = 20;
        } else if (vyber == "lovec") {
            maxZivoty = 5; zivoty = 5; maxMana = 6; mana = 6; utok = 4; zlato = 15;
        } else if (vyber == "warrior") {
            maxZivoty = 8; zivoty = 8; maxMana = 3; mana = 3; utok = 5; zlato = 5;
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
        }
    }

    cout << "Vitej ve hre, " << herniJmeno << "!" << endl;

    string moznaMonstra[] = {"M", "2xM", "M"};
    int bojovyPocet = 0;
    const int maxBojov = 50;

    while (bojovyPocet < maxBojov) {
        for (int i = 0; i < 5 && bojovyPocet < maxBojov; ++i) {
            string aktualni = moznaMonstra[rand() % 3];
            cout << endl << "Setkal jsi se s: " << aktualni << endl;

            if (aktualni == "M") {
                int zivotMonstra = 3;
                while (zivotMonstra > 0 && zivoty > 0) {
                    cout << "Utocis za " << utok << " zraneni." << endl;
                    zivotMonstra -= utok;

                    if (zivotMonstra <= 0) {
                        cout << "Zabil si monstrum! +5 zlata" << endl;
                        zlato += 5;
                        break;
                    }

                    bool zasah = true;
                    if (Uhyb && rand() % 2 == 0) {
                        cout << "Vyhnul ses utoku!" << endl;
                        zasah = false;
                    }

                    if (zasah) {
                        cout << "Monstrum te zasahlo za 1 zivot." << endl;
                        zivoty--;
                    }

                    if (zivoty <= 0) {
                        cout << "Zemrel jsi. Konec hry." << endl;
                        return 0;
                    }

                    cout << "Mas " << zivoty << " zivotu zbyva." << endl;
                }

            } else if (aktualni == "2xM") {
                int zivotM1 = 3, zivotM2 = 3;
                while ((zivotM1 > 0 || zivotM2 > 0) && zivoty > 0) {
                    int volba;
                    cout << "Vyber monstrum do ktereho pujdes (1 nebo 2): ";
                    cin >> volba;

                    if (volba == 1 && zivotM1 > 0) {
                        zivotM1 -= utok;
                        cout << "Utocis na monstrum 1. Zivoty: " << max(0, zivotM1) << endl;
                        if (zivotM1 <= 0) { cout << "Zabil jsi monstrum 1! +5 zlata" << endl; zlato += 5; }
                    } else if (volba == 2 && zivotM2 > 0) {
                        zivotM2 -= utok;
                        cout << "Utocis na monstrum 2. Zivoty: " << max(0, zivotM2) << endl;
                        if (zivotM2 <= 0) { cout << "Zabil jsi monstrum 2! +5 zlata" << endl; zlato += 5; }
                    } else {
                        cout << "Ty chces zabijet neco co si zabil?. :D" << endl;
                        continue;
                    }

                    if (zivotM1 > 0) {
                        if (!(Uhyb && rand() % 2 == 0)) {
                            cout << "Monstrum 1 te zasahuje." << endl;
                            zivoty--;
                        } else cout << "Vyhnul ses utoku monstra 1!" << endl;
                    }
                    if (zivotM2 > 0) {
                        if (!(Uhyb && rand() % 2 == 0)) {
                            cout << "Monstrum 2 te zasahuje." << endl;
                            zivoty--;
                        } else cout << "Vyhnul ses utoku monstra 2!" << endl;
                    }

                    if (zivoty <= 0) {
                        cout << "Zemrel jsi. Konec hry." << endl;
                        return 0;
                    }

                    cout << "Mas " << zivoty << " zivotu zbyva." << endl;
                }
            }

            bojovyPocet++;
        }


        cout << "Dorazil jsi do vesnice!" << endl;
        int volbaVesnice = 0;
        while (volbaVesnice != 5) {
            cout << "\n--- MENICKO ---" << endl;
            cout << "1. Vylecit zivoty (2 zlata za 1 zivot)" << endl;
            cout << "2. Zlepsit max zivoty (+15 za 50 zlata)" << endl;
            cout << "3. Koupit schopnost vyhnout se utoku (50%) - 25 zlata" << endl;
            cout << "4. Info o statu" << endl;
            cout << "5. Odejit z vesnice" << endl;
            cout << "Zadej volbu: ";
            cin >> volbaVesnice;

            switch (volbaVesnice) {
                case 1: {
                    int kolik;
                    cout << "Kolik zivotu chces doplnit? ";
                    cin >> kolik;
                    int maxHeal = maxZivoty - zivoty;
                    kolik = min(kolik, maxHeal);
                    int cena = kolik * 2;

                    if (zlato >= cena) {
                        zivoty += kolik;
                        zlato -= cena;
                        cout << "Doplnil sis " << kolik << " zivotu. Mas " << zivoty << "/" << maxZivoty << endl;
                    } else {
                        cout << "Nemas dost zlata." << endl;
                    }
                    break;
                }
                case 2:
                    if (zlato >= 50) {
                        maxZivoty += 15;
                        zivoty += 15;
                        zlato -= 50;
                        cout << "Zlepsil jsi max zivoty na " << maxZivoty << endl;
                    } else {
                        cout << "Nemas dost zlata." << endl;
                    }
                    break;
                case 3:
                    if (!Uhyb && zlato >= 25) {
                        Uhyb = true;
                        zlato -= 25;
                        cout << "Mas novou schopnost! 50% sance vyhnout se utoku." << endl;
                    } else if (Uhyb) {
                        cout << "Tuto schopnost uz mas." << endl;
                    } else {
                        cout << "Nemas dost zlata." << endl;
                    }
                    break;
                case 4:
                    cout << "Zivoty: " << zivoty << "/" << maxZivoty << ", Zlato: " << zlato;
                    cout << ", Schopnost uhybu: " << (Uhyb ? "ANO" : "NE") << endl;
                    break;
                case 5:
                    cout << "Opoustis vesnici." << endl;
                    break;
                default:
                    cout << "Neplatna volba." << endl;
            }
        }
    }


    cout << "Dosahl jsi uz dost zapasu. Ceka te hlavni boss!" << endl;
    cout << "Uz si myslis ze das bosse a nebo si porad neveris na to (ano/ne): ";

    return 0;
}
