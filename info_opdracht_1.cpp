#include <iostream> 
#include <string>   
using namespace std;

struct Patient {
    string naam;         
    string symptomen;    
    int leeftijd;        
    string adres;       
    string afspraakDatum; 
};

int main() {
    Patient patienten[10]; 
    int aantal = 0;        
    string input;          
    int keuze;             

    while (true) { 
        
        cout << "======================\n";
        cout << " Patienten Menu\n";
        cout << "======================\n";
        cout << "1. Patient toevoegen\n";
        cout << "2. Patienten laten zien\n";
        cout << "3. Patient aanpassen\n";
        cout << "4. Afspraakdatum toevoegen/wijzigen\n";
        cout << "Typ je keuze: ";
        cin >> keuze;       
        cin.ignore();       

        if (keuze == 1) {   
            do {
                if (aantal == 10) {
                    cout << "Er kunnen niet meer patienten toegevoegd worden.\n";
                    break;
                }
                cout << "Geef naam: ";
                getline(cin, patienten[aantal].naam); 

                cout << "Geef symptomen: ";
                getline(cin, patienten[aantal].symptomen); 

                cout << "Geef leeftijd: ";
                
                while (!(cin >> patienten[aantal].leeftijd) || patienten[aantal].leeftijd < 0) {
                    cout << "Typ een correcte leeftijd: ";
                    cin.clear(); 
                    cin.ignore(1000, '\n'); 
                }
                cin.ignore(); 

                cout << "Geef adres: ";
                getline(cin, patienten[aantal].adres); 

                cout << "Afspraakdatum: ";
                getline(cin, patienten[aantal].afspraakDatum); 

                aantal++; 

                cout << "Wil je nog een patient toevoegen? (ja of nee): ";
                getline(cin, input); 

            } while (input == "ja" || input == "JA" || input == "Ja"); 

        } else if (keuze == 2) { 
            if (aantal == 0) {
                cout << "Er zijn geen patienten.\n";
            } else {
                for (int i = 0; i < aantal; i++) { 
                    cout << "Patient " << i+1 << ":\n";
                    cout << "Naam: " << patienten[i].naam << "\n";
                    cout << "Symptomen: " << patienten[i].symptomen << "\n";
                    cout << "Leeftijd: " << patienten[i].leeftijd << "\n";
                    cout << "Adres: " << patienten[i].adres << "\n";
                    cout << "Afspraakdatum: " << patienten[i].afspraakDatum << "\n\n";
                }
            }

        } else if (keuze == 3) { 
            if (aantal == 0) {
                cout << "Er zijn geen patienten om aan te passen.\n";
            } else {
                cout << "Welke patient wil je aanpassen? (1 tot " << aantal << "): ";
                int num;
                cin >> num;
                cin.ignore();
                if (num < 1 || num > aantal) { 
                    continue; 
                }
                
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
        } else if (keuze == 4) { 
            if (aantal == 0) {
                cout << "Er zijn geen patienten om een afspraakdatum voor in te stellen.\n";
            } else {
                cout << "Welke patient wil je een afspraakdatum voor instellen? (1 tot " << aantal << "): ";
                int num;
                cin >> num;
                cin.ignore();
                if (num < 1 || num > aantal) { 
                    continue; 
                }
                cout << "Afspraakdatum: ";
                getline(cin, patienten[num-1].afspraakDatum);
                cout << "Afspraakdatum bijgewerkt.\n";
            }
        } else {
            
            cout << "Ongeldige keuze, probeer weer.\n";
        }

        cout << "\n"; 
    }

    return 0; 
}
