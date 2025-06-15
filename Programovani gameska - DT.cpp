#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int maxZivoty = 0, zivoty = 0, maxMana = 0, mana = 0, utok = 0;
    int zlato = 0, level = 1, zkusenosti = 0;
    int pocetSouboju = 0;
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
    cout << "Priprav se, budes bojovat!" << endl;

    string typyPostav[] = {"M", "2xM", "M", "2xM", "M"};

    while (true) {
        for (int i = 0; i < 5; i++) {
            string aktualni = typyPostav[i % 5];
            cout << endl << "Setkal jsi se s: " << aktualni << endl;

            if (aktualni == "M") {
                int zivotMonstra = 3;
                while (zivotMonstra > 0 && zivoty > 0) {
                    cout << "Utocis za " << utok << " zraneni." << endl;
                    zivotMonstra -= utok;

                    if (zivotMonstra <= 0) {
                        cout << "Zabil si monstrum! +5 zlata" << endl;
                        zlato += 5;
                        pocetSouboju++;
                        cout << "Absolvoval jsi " << pocetSouboju << " souboju." << endl;
                        break;
                    }

                    bool zasah = true;

                    int volbaUh = 0;
                    if (mana >= 3) {
                        cout << "Chces pouzit 3 many na vyhnuti se utoku? (1 = ano, 0 = ne): ";
                        cin >> volbaUh;
                        if (volbaUh == 1) {
                            mana -= 3;
                            zasah = false;
                            cout << "Pouzil jsi 3 many a vyhnul se utoku!" << endl;
                        }
                    }

                    if (zasah && Uhyb && rand() % 2 == 0) {
                        cout << "Pasivne ses vyhnul utoku!" << endl;
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

                    for (int j = 1; j <= 2; j++) {
                        if ((j == 1 && zivotM1 > 0) || (j == 2 && zivotM2 > 0)) {
                            bool zasah = true;

                            int volbaUh = 0;
                            if (mana >= 3) {
                                cout << "Chces pouzit 3 many na vyhnuti se utoku od monstra " << j << "? (1 = ano, 0 = ne): ";
                                cin >> volbaUh;
                                if (volbaUh == 1) {
                                    mana -= 3;
                                    zasah = false;
                                    cout << "Pouzil jsi 3 many a vyhnul se utoku od monstra " << j << "!" << endl;
                                }
                            }

                            if (zasah && Uhyb && rand() % 2 == 0) {
                                cout << "Povedlo se ti uhnout! " << j << "!" << endl;
                                zasah = false;
                            }

                            if (zasah) {
                                cout << "Monstrum " << j << " te zasahuje." << endl;
                                zivoty--;
                            }
                        }
                    }

                    if (zivoty <= 0) {
                        cout << "Zemrel jsi. Konec hry." << endl;
                        return 0;
                    }

                    cout << "Mas " << zivoty << " zivotu zbyva." << endl;
                }
                pocetSouboju++;
                cout << "Absolvoval jsi " << pocetSouboju << " souboju." << endl;
            }
        }

        // Po každých 25 soubojích možnost jít na bosse
        if (pocetSouboju >= 25) {
            string rozhodnuti;
            cout << "\nMas za sebou " << pocetSouboju << " souboju, chces jit na bosse? (ano/ne): ";
            cin >> rozhodnuti;

            if (rozhodnuti == "ano") {
                cout << "Vstupujes do boje s bossem Vextile!" << endl;

                int bossZivoty = 30;
                int bossUtok = 3;
                int bossObrana = 1;

                while (zivoty > 0 && bossZivoty > 0) {
                    cout << "\nMas " << zivoty << " zivotu, boss ma " << bossZivoty << " zivotu." << endl;
                    cout << "Zadej 1 pro utok na bosse: ";
                    int volba;
                    cin >> volba;

                    if (volba == 1) {
                        int dmg = utok;

                        bool kriticky = (rand() % 100) < 15;
                        if (kriticky) {
                            dmg *= 2;
                            cout << "Kriticky utok!" << endl;
                        }

                        dmg -= bossObrana;
                        if (dmg < 0) dmg = 0;

                        bossZivoty -= dmg;
                        cout << "Uderil jsi bosse za " << dmg << " zraneni." << endl;

                        if (bossZivoty <= 0) {
                            cout << "GRATULUJU, vyhral si a ted si panem tohoto rajonu!" << endl;
                            zlato += 100;
                            pocetSouboju = 0;
                            break;
                        }
                    } else {
                        cout << "Nevykonal jsi utok, boss se pripravil." << endl;
                    }

                    int bossDmg = bossUtok;
                    bool bossKriticky = (rand() % 100) < 10;
                    if (bossKriticky) {
                        bossDmg *= 2;
                        cout << "Boss provedl kriticky utok!" << endl;
                    }

                    cout << "Boss te zasahl za " << bossDmg << " zraneni." << endl;
                    zivoty -= bossDmg;

                    if (zivoty <= 0) {
                        cout << "Zemrel jsi na bosse Vextile. Konec hry." << endl;
                        return 0;
                    }

                    cout << "Mas jeste " << zivoty << " zivotu." << endl;
                }
            } else {
                cout << "Pokracujes dal v boji, az do dalsich 25 souboju." << endl;
                pocetSouboju = 0;
            }
        }

        cout << "Dorazil jsi do vesnice!" << endl;
        int volbaVesnice = 0;

        while (volbaVesnice != 6) {
            cout << "\n--- VESNICKA ---" << endl;
            cout << "1. Vylecit zivoty (2 zlata za 1 zivot)" << endl;
            cout << "2. Zlepsit max zivoty (+15 za 50 zlata)" << endl;
            cout << "3. Koupit schopnost vyhnout se utoku (50% sance) - 100 zlata" << endl;
            cout << "4. Koupit manu (1 mana = 3 zlata)" << endl;
            cout << "5. Info o statu" << endl;
            cout << "6. Odejit z vesnice" << endl;
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
                        cout << "Zlepsil jsi max zivoty na " << maxZivoty << " a doplnil sis zivoty na " << zivoty << endl;
                    } else {
                        cout << "Nemas dost zlata." << endl;
                    }
                    break;
                case 3:
                    if (!Uhyb && zlato >= 100) {
                        Uhyb = true;
                        zlato -= 100;
                        cout << "Supr! Od ted mas 50% sanci ze se vyhnes utoku od zlobivce." << endl;
                    } else if (Uhyb) {
                        cout << "Tuhle schopnost uz mas." << endl;
                    } else {
                        cout << "Nemas dost zlata." << endl;
                    }
                    break;
                case 4: {
                    int kolik;
                    cout << "Kolik many chces koupit? ";
                    cin >> kolik;
                    int cena = kolik * 3;
                    if (zlato >= cena) {
                        mana += kolik;
                        if (mana > maxMana) mana = maxMana;
                        zlato -= cena;
                        cout << "Mas ted " << mana << "/" << maxMana << " many." << endl;
                    } else {
                        cout << "Nemas dost zlata." << endl;
                    }
                    break;
                }
                case 5:
                    cout << "Jmeno: " << herniJmeno << endl;
                    cout << "Zivoty: " << zivoty << "/" << maxZivoty << endl;
                    cout << "Mana: " << mana << "/" << maxMana << endl;
                    cout << "Utok: " << utok << endl;
                    cout << "Zlato: " << zlato << endl;
                    cout << "Level: " << level << endl;
                    cout << "Uhyb: " << (Uhyb ? "ano" : "ne") << endl;
                    break;
                case 6:
                    cout << "Odejdes z vesnice a pokracujes v kralovani, dokud to nevypnes, jeste jednou gratuluji." << endl;
                    break;
                default:
                    cout << "Neplatna volba." << endl;
                    break;
            }
        }
    }

    return 0;
}
