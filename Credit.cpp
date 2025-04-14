#include <iostream>
#include <math.h>

using namespace std;

class card
{
    private:
        string name;
        long cardNum;
        int expire[2];
        int security;
        int money;
        int type;
    public:
    card()
    {
        cout << "Enter you card name: ";
        cin >> name; 
        cout << "Enter you card Number: ";
        cin >> cardNum;
        cout << "Enter you card month: ";
        cin >> expire[0];
        cout << "Enter you card day: ";
        cin >> expire[1];
        cout << "Enter you card security: ";
        cin >> security;
        cout << "How much money do you have: ";
        cin >> money; 
    }
    int infocredit()
    {
        long Card = cardNum;
        int ch = 3;
        int n;

        if (pow(10, 14) < Card && pow(10, 15) > Card)
            n = 15;
        else if (pow(10, 15) < Card && pow(10, 16) > Card)
            n = 16;
        else
            n = 13;
        int pluser = 0;
        int d;

        for (int i = 0; i < n; i++)
        {
            long second = pow(10, i + 1);
            d = trunc((Card % second) * pow(10, -i));
            if ((i + 1) % 2 == 0)
            {
                d *= 2;
                if (d > 9)
                    d = d % 10 + (d % 100) * 0.1;
                pluser += d;
            }
            else
                pluser += d;
        }
        if (pluser % 10 == 0)
        {
            long c = pow(10, n);
            long t = (Card % c) * pow(10, 2 - n);
            if ((t == 37 || t == 34) && (n == 15))
                ch = 0;
            else if ((t >= 51 && t <= 55) && (n == 16))
                ch = 1;
            else if ((t > 39 && t < 50) && (n == 13 || n == 16))
                ch = 2;
        }
        type = ch;
        return ch;
    }
    friend int *moneyT(card account[], int n);
};

int *moneyT(card account[], int n)
{
    int sum[] = {0, 0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        if (account[i].type == 0)
        {
            sum[0] += account[i].money;
            sum[3] += account[i].money;
        }
        else if (account[i].type == 1)
        {
            sum[1] += account[i].money;
            sum[3] += account[i].money;
        }
        else if (account[i].type == 2)
        {
            sum[2] += account[i].money;
            sum[3] += account[i].money;
        }
        else 
            cout << "Wrong\n";
    }
    return sum;
}