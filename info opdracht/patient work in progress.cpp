#include <iostream>      
#include <string>        
using namespace std;     

struct Patient {
    string naam;         // Naam van de patiënt
    string symptomen;    // Symptomen van de patiënt
    int leeftijd;        // Leeftijd van de patiënt
    string adres;        // Adres van de patiënt
};

int main() {
    Patient patienten[10];   // Array voor max 10 patiënten
    int aantal = 0;          // Telt het aantal patiënten
    string input;            // Variabele voor algemene invoer
    int keuze;               // Variabele voor menu keuze

    while (true) {                           // Start oneindige loop voor menu
        cout << "======================\n";  // Print scheidingslijn
        cout << " Patiënten Menu\n";          // Print menu titel
        cout << "======================\n";  // Print scheidingslijn
        cout << "1. Patiënt toevoegen\n";    // Optie 1: toevoegen
        cout << "2. Patiënten laten zien\n";  // Optie 2: tonen
        cout << "3. Patiënt aanpassen\n";     // Optie 3: aanpassen
        cout << "Typ je keuze: ";               // Vraag keuze
        cin >> keuze;                         // Lees keuze
        cin.ignore();                         // Verwijder newline uit buffer

        if (keuze == 1) {                     // Keuze toevoegen patiënt
            do {                             // Begin herhaal-lus voor meerdere
                if (aantal == 10) {           // Check of max aantal bereikt is
                    cout << "Er kunnen niet meer patiënten toegevoegd worden.\n"; // Waarschuwing max
                    break;                    // Stop toevoegen
                }
                cout << "Geef naam: ";       // Vraag naam
                getline(cin, patienten[aantal].naam);   // Lees naam in

                cout << "Geef symptomen: ";  // Vraag symptomen
                getline(cin, patienten[aantal].symptomen);  // Lees symptomen

                cout << "Geef leeftijd: ";   // Vraag leeftijd
                while (!(cin >> patienten[aantal].leeftijd) || patienten[aantal].leeftijd < 0) {  // Controle invoer leeftijd
                    cout << "Typ een correcte leeftijd: ";  // Foutmelding
                    cin.clear();               // Reset invoer fout
                    cin.ignore(1000, '\n');   // Wis invoerbuffer
                }
                cin.ignore();                 // Wis newline na leeftijd
                
                cout << "Geef adres: ";      // Vraag adres
                getline(cin, patienten[aantal].adres); // Lees adres
                
                aantal++;                    // Verhoog aantal patiënten

                cout << "Wil je nog een patiënt toevoegen? (ja of nee): ";  // Vraag meer invoer
                getline(cin, input);         // Lees input
                
            } while (input == "ja" || input == "JA" || input == "Ja");   // Herhaal bij ja
        } 
        else if (keuze == 2) {              // Keuze patiënten tonen
            if (aantal == 0) {               // Check of patiëntenlijst leeg is
                cout << "Er zijn geen patiënten.\n";  // Meld leeg
            } else {
                for (int i = 0; i < aantal; i++) {  // Loop over alle patiënten
                    cout << "Patiënt " << i+1 << ":\n";  // Nummer patiënt
                    cout << "Naam: " << patienten[i].naam << "\n";  // Toon naam
                    cout << "Symptomen: " << patienten[i].symptomen << "\n"; // Toon symptomen
                    cout << "Leeftijd: " << patienten[i].leeftijd << "\n";   // Toon leeftijd
                    cout << "Adres: " << patienten[i].adres << "\n\n";       // Toon adres
                }
            }
        } 
        else if (keuze == 3) {              // Keuze patiënt aanpassen
            if (aantal == 0) {              // Check lege lijst
                cout << "Er zijn geen patiënten om aan te passen.\n";  // Meld leeg
            } else {
                cout << "Welke patiënt wil je aanpassen? (1 tot " << aantal << "): "; // Vraag nummer
                int num;
                cin >> num;                 // Lees nummer
                cin.ignore();               // Wis newline
                if (num < 1 || num > aantal) {  // Check geldig nummer
                    cout << "Dat is geen geldig nummer.\n";  // Meld fout
                } else {
                    cout << "Naam (huidig: " << patienten[num-1].naam << "): ";    // Toon huidig naam
                    getline(cin, patienten[num-1].naam);                          // Nieuw invoer naam

                    cout << "Symptomen (huidig: " << patienten[num-1].symptomen << "): ";  // Huidige symptomen
                    getline(cin, patienten[num-1].symptomen);                         // Nieuwe symptomen

                    cout << "Leeftijd (huidig: " << patienten[num-1].leeftijd << "): ";   // Huidige leeftijd
                    while (!(cin >> patienten[num-1].leeftijd) || patienten[num-1].leeftijd < 0) { // Check leeftijd
                        cout << "Typ een correcte leeftijd: ";                       // Foutmelding
                        cin.clear();                                                 // Reset invoer fout
                        cin.ignore(1000, '\n');                                     // Wis buffer
                    }
                    cin.ignore();                                                   // Wis newline na leeftijd

                    cout << "Adres (huidig: " << patienten[num-1].adres << "): ";   // Huidig adres
                    getline(cin, patienten[num-1].adres);                           // Nieuw adres

                    cout << "Patiënt aangepast.\n";                                 // Bevestiging
                }
            }
        } 
        else {                        // Ongeldige keuze
            cout << "Ongeldige keuze, probeer het nog eens.\n";  // Foutmelding
        }
        cout << "\n";                 // Lege regel ter scheiding
    }

    return 0;   // Programma klaar
}