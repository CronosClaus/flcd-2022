#include <bits/stdc++.h>

using namespace std;

const int HASH_SIZE = 100;

typedef pair<string, int> HashEntry;

class HashTable{
public:
    HashTable(){
        table.resize(currentSize);
    };

    int getValue(int key){
        stringstream ss;
        ss<<key;
        string converted;
        ss>> converted;
        return getValue(converted);
    }

    int getValue(string key){
        int keyValue = keyExists( key );
        if(keyValue != -1){
            return keyValue;
        }
        else{
            int location = hashString( key );
            int index = newIndex();
            table[ location ].push_back(make_pair(key, index));
            return index;
        }
    }
    int keyExists(string key){
        int location = hashString( key );
        for(int i = 0; i < table[ location ].size(); i++){
            HashEntry entry = table[ location ][ i ];
            if(entry.first == key){
                return entry.second;
            }
        }
        return -1;
    }
private:
    vector<vector<HashEntry>> table;
    int currentSize = HASH_SIZE;
    int nextIndex = 0;

    int hashString(string key){
        int sum = 0;
        for(int i = 0; i < key.size(); i++){
            sum += key[ i ] * (1 << (i % 20));
        }
        return sum % currentSize;
    }
    int newIndex(){
        return nextIndex++;
    }
};

int main()
{
    HashTable st{};
    cout<< st.getValue("whatever") << '\n';
    cout<< st.getValue("whatever") << '\n';
    cout<< st.getValue("whatever2") << '\n';
    cout<< st.getValue("whatever3") << '\n';;
    cout<< st.getValue(4) << '\n';
    cout<< st.getValue(4) << '\n';
    return 0;
}
