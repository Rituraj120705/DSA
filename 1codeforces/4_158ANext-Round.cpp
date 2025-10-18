#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,k;
    cin >> n >> k;

    int score[50];


    for (int i=0; i<n; i++){
        cin >> score[i];
    }

    int cutoff = score[k-1];

    int count = 0;

    for(int i=0 ; i<n ; i++){
        if(score[i] >= cutoff && score[i] > 0){
            count++;
        }
    }

    cout << count << endl;
    return 0;


}