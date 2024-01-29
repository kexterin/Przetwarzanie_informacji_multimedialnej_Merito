// Naiwny
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Używamy zadanego tekstu
    string tekst = "A flea and a fly flew up in a flue";
    string wzorzec = "fly flew";

    // Wypisujemy tekst
    cout << wzorzec <<endl;
    cout << tekst << endl;

    // Szukamy wzorca w tekście
    for (size_t i = 0; i < tekst.length() - wzorzec.length() + 1; i++)
    {
        string podciag = tekst.substr(i, wzorzec.length());
        cout << (podciag == wzorzec ? "^" : " ");
    }

    cout << endl << endl;
    return 0;
}