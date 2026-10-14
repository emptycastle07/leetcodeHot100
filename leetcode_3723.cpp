#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sum = 10, num = 1;
    string s = "";

    if ( 9*num < sum || sum <= 0 ) { cout << s; }
    while (true){
        if ( sum-9 >= 0 ) {
            sum -= 9;
            s.push_back('9');
        }
        else break;
    }
    if (s.size() < num) s.push_back('0' + sum);
    else;
    for (int i = s.size(); i < num ; i++){
        s.push_back('0');
    }
    cout << s;
    return 0;
}