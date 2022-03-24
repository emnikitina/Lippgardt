#include "Point.hpp"
#include "Manipulator.hpp"

using namespace std;


int main()
{
    Manipulator<double> M1, M2;
    Point<double> P;

    cout << "The first manupulator\ninput x y R, press enter and input name\n";
    cin >> M1;
    cout << "The second manupulator\ninput x y R, press enter and input name\n";
    cin >> M2;
    cout << "Input point coordinate: x y\n";
    cin >> P;
    cout << M1.chooseManupulator(M2, P) << endl;

    return 0;
}