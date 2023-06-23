#include <iostream>
#include <string>
#include <Vector>

using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> a;
    a.push_back(3);
    a.push_back(44);
    a.push_back(32);
    a.push_back(10);
    a.push_back(3);
    
    for(int iten : a){
        cout<<"mang "<<": "<<iten<<endl;
    }
    return 0;
}
