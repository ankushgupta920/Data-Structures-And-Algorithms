#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
    int BUCKET;        // Number of buckets
    vector<int> table; // Vector of lists to store keys

    public:
    HashTable()
    {
        BUCKET = 10;
        table.resize(BUCKET);
    }
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void insertItem(int key)
    {
        int index = hashFunction(key);
        table[index] = key;
        cout << " pushing " << key << " at index " << index << endl;
    }

    void displayHash()
    {
        int i = 0;
        for (auto x : table)
        {
            cout << i++ << " --> " << x << endl;
        }
    }
};

int main()
{
    int keys[] = {24, 52, 91, 67, 48, 83};
    int n = sizeof(keys) / sizeof(keys[0]);

    HashTable h;

    for (int i = 0; i < n; i++)
        h.insertItem(keys[i]);

    h.displayHash();


    return 0;
}