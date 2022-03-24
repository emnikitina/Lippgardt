#include "Point.hpp"
#include "Manipulator.hpp"

using namespace std;


int main()
{
    Manipulator<double> M1, M2;
    Point<double> P;
    int num;

    cout << "The first manupulator\ninput x y R, press enter and input name\n";
    cin >> M1;
    cout << "The second manupulator\ninput x y R, press enter and input name\n";
    cin >> M2;
    cout << "Input number of points\n";
    cin >> num;
    while (num)
    {
        cout << "Input point coordinate: x y\n";
        cin >> P;
        M1.chooseManupulator(M2, P);
        num--;
    }
    cout << M1;
    cout << M2;

    return 0;
}