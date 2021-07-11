#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();
int main()

{
    setlocale(LC_ALL, "Rus");
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========ÄÎÁÐÎ ÏÎÆÀËÎÂÀÒÜ Â ÌÈÐÎÂÎÅ ÊÀÇÈÍÎ=======\n\n";
    cout << "\n\nÂÂÅÄÈÒÅ ÂÀØÅ ÈÌß:: ";
    getline(cin, playerName);
    cout << "\n\nÍÀÏÈØÈÒÅ ÂÀØ ÍÀ×ÀËÜÍÛÉ ÁÀËÀÍÑ: $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nÂÀØ ÒÅÊÓÙÈÉ ÁÀËÀÍÑ ÑÎÑÒÀÂËßÅÒ $ " << balance << "\n";
        // Get player's betting balance
        do
        {
            cout << "ÏÐÈÂÅÒ, " << playerName << ", ÂÂÅÄÈÒÅ ÑÓÌÌÓ ÄËß ÑÒÀÂÊÈ : $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "\nÁÀËÀÍÑ ÑÒÀÂÊÈ ÍÅ ÌÎÆÅÒ ÁÛÒÜ ÁÎËÜØÅ ÒÅÊÓÙÅÃÎ ÁÀËÀÍÑÀ"
                << "\n  ÂÂÅÄÈÒÅ ÁÀËÀÍÑ ÇÀÍÀÂÎ\n ";
        } while (bettingAmount > balance);
        // Get player's numbers
        do
        {
            cout << "ÏÎÏÐÎÁÓÉ ÓÃÀÄÀÒÜ ×ÈÑËÎ ÎÒ 1 ÄÎ 10:";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\n×ÈÑËÎ ÄÎËÆÍÎ ÁÛÒÜ ÎÒ 1 ÄÎ 10, ß ÆÅ ÏÐÅÄÓÏÐÅÄÈË!\n"
                << "ÂÂÅÄÈÒÅ ×ÈÑËÎ ÑÍÎÂÀ:\n ";
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
        {
            cout << "\n\nÏÎÇÄÐÀÂËÀÞ! ÒÛ ÂÛÉÃÐÀË!." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "ÎÎÎÉ, ÊÀÊ ÒÀÊ ÒÛ ÏÐÎÈÃÐÀË, ÍÅ ÐÀÑÑÒÐÀÈÂÀÉÑß Â ÑËÅÄÓÞÙÈÉ ÐÀÇ ÏÎÂÅÇÅÒ! $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\nÂÛÉÃÐÛØÍÛÌ ÍÎÌÅÐÎÌ ÁÛË : " << dice << "\n";
        cout << "\n" << playerName << ", ÒÂÎÉ ÁÀËÀÍÑ $ " << balance << "\n";
        if (balance == 0)
        {
            cout << "Ó ÂÀÑ ÍÅÒÓ ÂÀËÞÒÛ, ×ÒÎ ÁÛ ÈÃÐÀÒÜ ";
            break;
        }
        cout << "\n\n-->ÕÎ×ÅØÜ ÑÛÃÐÀÒÜ ÅÙÅ ÐÀÇ? (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "\n\nÒÂÎÉ ÁÀËÀÍÑ ÐÀÂÅÍ:  $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t======ÄÎÁÐÎÉ ÏÎÆÀËÎÂÀÒÜ,ÏÐÀÂÈËÀ ÊÀÇÈÍÎ!======\n";
    cout << "\t1. ÂÂÎÄÈÒÜ ×ÈÑËÀ ÎÒ 1 ÄÎ 10\n";
    cout << "\t2. ÏÎÁÅÄÈÒÅËÜ ÏÎËÓ×ÈÒ 10 ÊÐÀÒÍÓÞ ÑÓÌÌÓ ÑÒÀÂÊÈ\n";
    cout << "\t3. ÍÅÏÐÅÅÌËÅÌÍÀß ÑÒÀÂÊÀ È ÂÛ ÏÎÒÅÐßÅÒÅ ÑÓÌÌÓ ÈÇ ÑÂÎÅÃÎ ÁÀËÀÍÑÀ\n\n";
}
