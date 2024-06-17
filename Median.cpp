#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<bool, double> CalcMedian(vector<double> samples, int size) {
    pair<bool, double> exit = { false, 0.0 };
    if (samples.empty()) {
        return exit;
    }
    sort(samples.begin(), samples.end());
    if (size % 2 == 0) {
        exit = { true, (samples[(size - 1) / 2] + samples[size / 2]) / 2.0 };
    }
    else {
        exit = { true, samples[size / 2] };
    }
    return exit;
}

int main() {
    int size;
    cin >> size;

    vector<double> samples;
    for (int i = 0; i < size; ++i) {
        double sample;
        cin >> sample;
        samples.push_back(sample);
    }

    pair<bool, double> result = CalcMedian(samples, size);
    if (result.first) {
        cout << result.second << endl;
    }
    else {
        cout << "Empty vector"s << endl;
    }
}