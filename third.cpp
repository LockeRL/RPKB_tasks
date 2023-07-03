#include <iostream>
#include <vector>
#include <cmath>

#define cout std::cout
#define endl std::endl

class WeatherData
{
public:
    explicit WeatherData(std::vector <double> temperatures) : temperatures(temperatures) {};

    void cleanData(double lower, double upper)
    {
        for (auto cur = temperatures.begin(); cur != temperatures.end();)
            if (*cur > upper || *cur < lower)
                cur = temperatures.erase(cur);
            else
                cur++;
    };

    int longestHeatWave(double threshold)
    {
        int longestWave = 0;
        int currentWave = 0;
        for (auto cur : temperatures)
        {
            if (cur > threshold)
                currentWave++;
            else
            {
                longestWave = std::max(longestWave, currentWave);
                currentWave = 0;
            }
        }
        longestWave = std::max(longestWave, currentWave);

        return longestWave;
    };

    void print()
    {
        for (auto elem : temperatures)
            cout << elem << " ";
        cout << endl;
    }
private:
    std::vector <double> temperatures;
};


int main()
{
    std::vector<double> vec1 = {99.1, 142.0, 85.0, 85.1, 84.6, 94.3, 124.9, 98.0, 101.0, 102.5};
    std::vector<double> vec2 = {100.5, 98.5, 102.0, 103.0, 87.5, 105.0, 90.3, 94.8, 109.1, 102.1, 107.4, 93.2};

    cout << "TEST 1\n";
    WeatherData *data1 = new WeatherData(vec1);
    data1->print();
    data1->cleanData(85.0, 120.0);
    data1->print();

    cout << "\nTEST 2\n";
    WeatherData *data2 = new WeatherData(vec2);
    data2->print();
    cout << "treshold 100.5 | " << data2->longestHeatWave(100.5) << endl;
    cout << "treshold 95.2 | " << data2->longestHeatWave(95.2) << endl;

    return 0;
}
