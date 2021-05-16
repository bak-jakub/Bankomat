#include <iostream>
#include <cstdlib>
using namespace std;
class Bankomat {
    int idtab[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int pintab[10] = { 1111,2222,3333,4444,5555,6666,7777,8888,9999,1000 };
    float stantab[10] = { 20, 40, 60, 80, 100, 120, 140, 160, 180, 200 };
private:
    int id, pin;
    float stan;
    void sprawdz(int _id, int _pin) {
        this->id = _id - 1;
        this->pin = _pin;
        if (pintab[id] == pin) {
            cout << "1.Stan konta \n2.Wyplac \n3.Wplac \n4.Zmiana pinu \n5.Transakcje\n Nacisnij dowolny inny przycisk aby wyjsc" << endl;
            char a;
            cin >> a;
            switch (a)
            {
            case '1':
                wypisz(id);
                break;
            case '2':
                cout << "Podaj kwote do wyplaty: ";
                float wyplata;
                cin >> wyplata;
                wyplac(wyplata);
                break;
            case '3':
                cout << "Podaj kwote do wplaty: ";
                float wplata;
                cin >> wplata;
                wplac(wplata);
                break;
            case '4':
                int a, b;
                cout<<"Podaj stary pin: "<<endl;
                cin>>a;
                cout<<"Podaj nowy pin: "<<endl;
                cin>>b;
                if(pintab[id]==a){
                    zmienpin(b);
                    cout<<"Pin zostal zmieniony"<<endl;
                    cout<<"id: ";
                    for(int i=0;i<10;i++){
                        cout<<idtab[i]<<" ";
                    }
                    cout<<endl;
                    cout<<"pin: ";
                    for(int i=0;i<10;i++){
                        cout<<pintab[i]<<" ";
                    }
                }
                else{
                    cout<<"Bledny pin"<<endl;
                }
                break;
            case '5':
                transakcje();
                break;
            default:
                system("pause");
                exit(0);
                break;
            }
        }
        else {
            cout << "Podano zly pin lub id" << endl;
        }
    }
    void wyplac(float ile) {
        stantab[id] -= ile;
        wypisz(id);
    }
    void wplac(float ile) {
        stantab[id] += ile;
        wypisz(id);
    }
    void zmienpin(int npin){
        pintab[id]=npin;
    }
public:
    Bankomat();
    void getInfo() {
        int id, pin;
        cout << "Podaj id i pin: ";
        cin >> id >> pin;
        sprawdz(id, pin);
    }
    void wypisz(int id) {
        cout << "Twoj stan konta:" << stantab[id] << endl;;
    }
    void transakcje() {
        int iletran, kwota;
        cout << "Podaj ilosc transakcji: " << endl;
        cin >> iletran;
        for (int i = 1; i <= iletran; i++) {
            cout << "Podaj " << i << " kwote: ";
            cin >> kwota;
            if ((stantab[id]-kwota)>0) {
                stantab[id] -= kwota;
                cout << "Pomyslnie zaplacono!" << endl;
            }
            else {
                cout << "Nie masz tyle na koncie!" << endl;
                break;
            }
        }
        wypisz(id);
    }
};
Bankomat::Bankomat() {
    getInfo();
}
int main()
{
    Bankomat ba1;
}
