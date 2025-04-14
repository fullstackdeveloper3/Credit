#include "../Credit/Credit.cpp"

int main(void)
{
    int size_of_array;
    int total, amex, master, visa;
    total = amex = master = visa = 0;

    cout << "Enter the number of the account: ";
    cin >> size_of_array;
    card account[size_of_array];
    int *moneyall = moneyT(account, size_of_array);

    for (int i = 0; i < size_of_array; i++)
    {
        int type = account[i].infocredit();
        if (type == 0)
        {
            amex++;
            total++;
        }
        else if (type == 1)
        {
            master++;
            total++;
        }
        else if (type == 2)
        {
            visa++;
            total++;
        }
        else
            cout << "Wrong";
    }
    cout << "Total = " << total << endl;
    cout << "Amex = " << amex << endl;
    cout << "Master = " << master << endl;
    cout << "Visa = " << visa << endl;
}