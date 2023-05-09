#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

class FrequencyTracker
{
public:
    int frequencies[200001];
    unordered_map<int, int> freqMap;
    FrequencyTracker()
    {
        memset(frequencies, 0, sizeof(int) * 200001);
        freqMap.clear();
    }

    void add(int number)
    {
        if (freqMap.find(number) == freqMap.end())
        {
            int freqency = ++freqMap[number];
            frequencies[freqency]++;
        }
        else
        {
            int prevFreqency = freqMap[number];
            frequencies[prevFreqency]--;
            int newFrequency = ++freqMap[number];
            frequencies[newFrequency]++;
        }
    }

    void deleteOne(int number)
    {
        if (freqMap.find(number) == freqMap.end())
        {
            return;
        }
        else
        {
            int prevFreqency = freqMap[number];
            frequencies[prevFreqency]--;
            int newFrequency = --freqMap[number];
            if (newFrequency == 0)
            {
                freqMap.erase(number);
            }
            else
            {
                frequencies[newFrequency]++;
            }
        }
    }

    bool hasFrequency(int frequency)
    {
        return (frequencies[frequency] > 0) ? true : false;
    }
};

int main()
{
    FrequencyTracker *obj = new FrequencyTracker();
    obj->deleteOne(9);
    obj->deleteOne(8);
    obj->deleteOne(1);
    obj->deleteOne(4);
    bool result = obj->hasFrequency(1);
    cout << result << endl; // false
    obj->add(10);
    obj->deleteOne(5);
    result = obj->hasFrequency(1);
    cout << result << endl; // true
    obj->deleteOne(10);
    obj->deleteOne(9);
    obj->deleteOne(10);
    result = obj->hasFrequency(1);
    cout << result << endl; // false
    obj->add(4);
    result = obj->hasFrequency(1);
    cout << result << endl; // true
    obj->deleteOne(4);
    result = obj->hasFrequency(1);
    cout << result << endl; // false
    result = obj->hasFrequency(1);
    cout << result << endl; // false
    obj->add(10);
    result = obj->hasFrequency(1);
    cout << result << endl; // true
    obj->add(2);
    obj->deleteOne(1);
    result = obj->hasFrequency(2);
    cout << result << endl; // false
    obj->add(7);
    result = obj->hasFrequency(1);
    cout << result << endl; // true
    result = obj->hasFrequency(1);
    cout << result << endl; // true
    obj->add(6);
}