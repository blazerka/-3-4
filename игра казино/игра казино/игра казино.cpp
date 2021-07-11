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
    cout << "\n\t\t========����� ���������� � ������� ������=======\n\n";
    cout << "\n\n������� ���� ���:: ";
    getline(cin, playerName);
    cout << "\n\n�������� ��� ��������� ������: $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\n��� ������� ������ ���������� $ " << balance << "\n";
        // Get player's betting balance
        do
        {
            cout << "������, " << playerName << ", ������� ����� ��� ������ : $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "\n������ ������ �� ����� ���� ������ �������� �������"
                << "\n  ������� ������ ������\n ";
        } while (bettingAmount > balance);
        // Get player's numbers
        do
        {
            cout << "�������� ������� ����� �� 1 �� 10:";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\n����� ������ ���� �� 1 �� 10, � �� �����������!\n"
                << "������� ����� �����:\n ";
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
        {
            cout << "\n\n����������! �� �������!." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "����, ��� ��� �� ��������, �� ������������� � ��������� ��� �������! $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\n���������� ������� ��� : " << dice << "\n";
        cout << "\n" << playerName << ", ���� ������ $ " << balance << "\n";
        if (balance == 0)
        {
            cout << "� ��� ���� ������, ��� �� ������ ";
            break;
        }
        cout << "\n\n-->������ ������� ��� ���? (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "\n\n���� ������ �����:  $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t======������ ����������,������� ������!======\n";
    cout << "\t1. ������� ����� �� 1 �� 10\n";
    cout << "\t2. ���������� ������� 10 ������� ����� ������\n";
    cout << "\t3. ������������� ������ � �� ��������� ����� �� ������ �������\n\n";
}
