#include <iostream> // Om dingen op het scherm te zetten
#include <string>   // Voor tekst gebruiken
using namespace std; // Zodat we geen std:: hoeven typen

// Struct = groepje van gegevens voor 1 patient
struct Patient {
    string naam;         // Naam van de patient
    string symptomen;    // Wat heeft de patient
    int leeftijd;        // Hoe oud is de patient
    string adres;        // Waar woont de patient
    string afspraakDatum; // Afspraakdatum van de patient
};

int main() {
    Patient patienten[10]; // Max 10 patients opslaan
    int aantal = 0;        // Houdt bij hoeveel patients we hebben
    string input;          // Voor 'ja' of 'nee' invoer
    int keuze;             // Wat kiest de gebruiker

    while (true) { // Herhaal steeds weer
        // Menu laten zien
        cout << "======================\n";
        cout << " Patienten Menu\n";
        cout << "======================\n";
        cout << "1. Patient toevoegen\n";
        cout << "2. Patienten laten zien\n";
        cout << "3. Patient aanpassen\n";
        cout << "4. Afspraakdatum toevoegen/wijzigen\n";
        cout << "Typ je keuze: ";
        cin >> keuze;       // Lees de keuze in
        cin.ignore();       // Weg met enter in buffer

        if (keuze == 1) {   // Patient toevoegen
            do {
                if (aantal == 10) { // Check of vol is
                    cout << "Er kunnen niet meer patienten toegevoegd worden.\n";
                    break;
                }
                cout << "Geef naam: ";
                getline(cin, patienten[aantal].naam); // Lees naam

                cout << "Geef symptomen: ";
                getline(cin, patienten[aantal].symptomen); // Lees symptomen

                cout << "Geef leeftijd: ";
                // Zorg dat leeftijd geldig is
                while (!(cin >> patienten[aantal].leeftijd) || patienten[aantal].leeftijd < 0) {
                    cout << "Typ een correcte leeftijd: ";
                    cin.clear(); // Herstel fout
                    cin.ignore(1000, '\n'); // Verwijder fout invoer
                }
                cin.ignore(); // Weg met enter

                cout << "Geef adres: ";
                getline(cin, patienten[aantal].adres); // Lees adres

                cout << "Afspraakdatum: ";
                getline(cin, patienten[aantal].afspraakDatum); // Lees afspraakdatum

                aantal++; // Tel eentje erbij

                cout << "Wil je nog een patient toevoegen? (ja of nee): ";
                getline(cin, input); // Lees ja of nee

            } while (input == "ja" || input == "JA" || input == "Ja"); // Ga door als ja

        } else if (keuze == 2) { // Patienten laten zien
            if (aantal == 0) {
                cout << "Er zijn geen patienten.\n";
            } else {
                for (int i = 0; i < aantal; i++) { // Loop door alle patienten
                    cout << "Patient " << i+1 << ":\n";
                    cout << "Naam: " << patienten[i].naam << "\n";
                    cout << "Symptomen: " << patienten[i].symptomen << "\n";
                    cout << "Leeftijd: " << patienten[i].leeftijd << "\n";
                    cout << "Adres: " << patienten[i].adres << "\n";
                    cout << "Afspraakdatum: " << patienten[i].afspraakDatum << "\n\n";
                }
            }

        } else if (keuze == 3) { // Patient aanpassen
            if (aantal == 0) {
                cout << "Er zijn geen patienten om aan te passen.\n";
            } else {
                cout << "Welke patient wil je aanpassen? (1 tot " << aantal << "): ";
                int num;
                cin >> num;
                cin.ignore();
                if (num < 1 || num > aantal) { // Check of nummer klopt
                    continue; // Terug naar hoofdmenu
                }
                // Toon huidige info en vraag nieuwe waarde
                cout << "Naam (huidig: " << patienten[num-1].naam << "): ";
                getline(cin, patienten[num-1].naam);

                cout << "Symptomen (huidig: " << patienten[num-1].symptomen << "): ";
                getline(cin, patienten[num-1].symptomen);

                cout << "Leeftijd (huidig: " << patienten[num-1].leeftijd << "): ";
                while (!(cin >> patienten[num-1].leeftijd) || patienten[num-1].leeftijd < 0) {
                    cout << "Typ een correcte leeftijd: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                cin.ignore();

                cout << "Adres (huidig: " << patienten[num-1].adres << "): ";
                getline(cin, patienten[num-1].adres);

                cout << "Afspraakdatum: ";
                getline(cin, patienten[num-1].afspraakDatum);

                cout << "Patient aangepast.\n";
            }
        } else if (keuze == 4) { // Afspraakdatum toevoegen/wijzigen
            if (aantal == 0) {
                cout << "Er zijn geen patienten om een afspraakdatum voor in te stellen.\n";
            } else {
                cout << "Welke patient wil je een afspraakdatum voor instellen? (1 tot " << aantal << "): ";
                int num;
                cin >> num;
                cin.ignore();
                if (num < 1 || num > aantal) { // Check of nummer klopt
                    continue; // Terug naar hoofdmenu
                }
                cout << "Afspraakdatum: ";
                getline(cin, patienten[num-1].afspraakDatum);
                cout << "Afspraakdatum bijgewerkt.\n";
            }
        } else {
            // Ongeldige keuze
            cout << "Ongeldige keuze, probeer het nog eens.\n";
        }

        cout << "\n"; // Lege regel voor netheid
    }

    return 0; // Klaar
}