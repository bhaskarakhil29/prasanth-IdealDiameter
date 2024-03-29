#include <bits/stdc++.h>

using namespace std;
const double PI = 3.14;
int main()
{
    double diameter_samples[151];
    iota(diameter_samples, diameter_samples + 151, 1);
    double flow, zl, zr, friction, ea, eb, pressure_at_a, x, hl, length;
    cout << "Enter value of Flow :";
    cin >> flow;
    cout << "Enter Elevation at A and Elevation at B: ";
    cin >> ea >> eb;
    cout << "Enter the Initial Pressure: ";
    cin >> pressure_at_a;
    cout << "Enter length :";
    cin >> length;
    double velocity, pressure;
    double min_vel = 0.08, max_vel = 1.5, min_pressure = 7, max_pressure = 20;
    double max_hl;
    for (int i = 0; i < 151; i++)
    {
        double velocity = (4 * flow * 1000) / ((PI) * (diameter_samples[i] * diameter_samples[i]) * 60);
        if (velocity >= min_vel && velocity <= max_vel)
        {
            double denominator = log(0.3 / (3.7 * diameter_samples[i])) * log(0.3 / (3.7 * diameter_samples[i]));
            friction = (1.325 / denominator);
            max_hl = (friction * 1000 * velocity * velocity * 1000) / (2 * 9.81 * diameter_samples[i]);
            hl = (friction * length * velocity * velocity * 1000) / (2 * 9.81 * diameter_samples[i]);
            pressure = ea + pressure_at_a - eb - hl;
            if (pressure >= min_pressure && pressure <= max_pressure && max_hl <= 10)
            {
                cout << "\nDiameter is " << diameter_samples[i] << "\nVeloctiy is " << velocity << "\nMax hl is " << max_hl << "\nPressure is " << pressure;
                return 0;
            }
            else
            {
                continue;
            }
        }
        else
        {
            continue;
        }
    }
    cout << "Not Found";
}
