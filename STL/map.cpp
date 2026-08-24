#include <iostream>
#include <map>
using namespace std;

int WinMain() {
    map<int, string> m = {{1, "Geeks"},
             {2, "For"}, {3, "Geeks"}};

    // Finding element with key 0
    auto it = m.find(0);
    
    if (it != m.end())
        cout << it->first << " " << it->second;
    else cout << "Key not Found!";
    return 0;
}
