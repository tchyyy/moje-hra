#include <iostream>
using namespace std;

int main() {


    int M, x2M, x3M, MB, HB, V;
    int maxZivoty = 0, zivoty = 0, maxMana = 0, mana = 0, utok = 0, zlato = 0, level = 1, zkusenosti = 0;

        string herniJmeno;
        cout << "Zadej sve herni jmeno: ";
        cin >> herniJmeno;

        cout << "Vitej ve hre, " << herniJmeno << "!" << endl;
        cout << "Mas " << zivoty << " zivotu." << endl;
        cout << "Priprav se budes bojovat!" << endl;

        string postavy[] = {"M", "2xM", "V", "3xM", "MB", "V", "M", "HB"};

            for (int i = 0; i < 8; i++) {
        string aktualni = postavy[i];

        cout << endl << "Setkal jsi se s: " << aktualni << endl;


        zivoty--;
        cout << "Mas " << zivoty << " zivotu zbyva." << endl;

            if (zivoty == 0) {
            cout << "Zemrel jsi. Konec hry." << endl;
            break;
        }
    }

        string vyber;


    int potvrzeno;

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
        cout << "Zivoty: " << zivoty << "/" << maxZivoty << endl;
        cout << "Mana: " << mana << "/" << maxMana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Zlato: " << zlato << endl;
            } else if (vyber == "mag") {
                maxZivoty = 3;
                zivoty = 3;
                maxMana = 8;
                mana = 8;
                utok = 2;
                zlato = 20;

        cout << "Class: Mag" << endl;
        cout << "Zivoty: " << zivoty << "/" << maxZivoty << endl;
        cout << "Mana: " << mana << "/" << maxMana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Zlato: " << zlato << endl;

            } else if (vyber == "lovec") {
                maxZivoty = 5;
                zivoty = 5;
                maxMana = 6;
                mana = 6;
                utok = 4;
                zlato = 15;

        cout << "Class: Lovec" << endl;
        cout << "Zivoty: " << zivoty << "/" << maxZivoty << endl;
        cout << "Mana: " << mana << "/" << maxMana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Zlato: " << zlato << endl;
            } else if (vyber == "warrior") {
                maxZivoty = 8;
                zivoty = 8;
                maxMana = 3;
                mana = 3;
                utok = 5;
                zlato = 5;

        cout << "Class: Warrior" << endl;
        cout << "Zivoty: " << zivoty << "/" << maxZivoty << endl;
        cout << "Mana: " << mana << "/" << maxMana << endl;
        cout << "Utok: " << utok << endl;
        cout << "Zlato: " << zlato << endl;





            } else {
        cout << "Neplatna classa. Zkus znovu." << endl;
            continue;
        }

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

    return 0;
}

