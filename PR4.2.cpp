#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "y" << " |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk + dx / 2) // додано dx/2 для уникнення проблем з точністю float/double
    {
        // Перевірка ділення на 0 для загального доданку 1/x
        if (x == 0)
        {
            cout << "|" << setw(7) << setprecision(2) << x
                << " |" << setw(10) << "не існує" << " |" << endl;
            x += dx;
            continue;
        }

        A = 1.0 / x + 4.0;

        if (x <= 1)
        {
            B = 8.0 + 0.65 * x;
        }
        else if (x <= 5)
        {
            // Перевірка на від'ємне або нульове x для ln(x)
            if (x <= 0)
            {
                cout << "|" << setw(7) << setprecision(2) << x
                    << " |" << setw(10) << "не існує" << " |" << endl;
                x += dx;
                continue;
            }

            double arg_ctg = (6.1 + x) / 2.0;
            // Перевірка ділення на 0 для ctg (якщо tan(arg) == 0)
            if (tan(arg_ctg) == 0)
            {
                cout << "|" << setw(7) << setprecision(2) << x
                    << " |" << setw(10) << "не існує" << " |" << endl;
                x += dx;
                continue;
            }

            B = log(x) + (1.0 / tan(arg_ctg)); // log(x) у C++ це натуральний логарифм ln(x)
        }
        else
        {
            B = sqrt(x + sqrt(2.0));
        }

        y = A - B;

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(3) << y
            << " |" << endl;

        x += dx;
    }
    cout << "---------------------------" << endl;

    return 0;
}