#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable
{
    int BUCKET;              // Number of buckets
    vector<list<int>> table; // Vector of lists to store keys

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
        table[index].push_back(key);
    }

    void deleteItem(int key)
    {
        int index = hashFunction(key);// 4

        // Find the key in the list
        list<int>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++)
        {
            cout<<*i<<endl;
            if (*i == key)
                break;
        }

        // If key is found, remove it
        if (i != table[index].end())
            table[index].erase(i);
    }

    void displayHash()
    {
        for (int i = 0; i < BUCKET; i++)
        {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main()
{
    // Create a hash table with 7 buckets
    int keys[] = {24, 52, 91, 67, 48, 83,44,54};
    int n = sizeof(keys) / sizeof(keys[0]);

    HashTable h;

    // Insert keys into the hash table
    for (int i = 0; i < n; i++)
        h.insertItem(keys[i]);

    // Display the hash table
    h.displayHash();

    // Delete a key from the hash table
    h.deleteItem(54);

    // Display the hash table after deletion
    cout << "After deleting 12:\n";
    h.displayHash();

    return 0;
}