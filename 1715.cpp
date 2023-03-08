#include <iostream>
#include <algorithm>
#include <utility>
 
using namespace std;
 
int N, K, arr[110], t, c[110], cnt, shd[110], res;
 
int main(){
    cin >> N >> K;
 
    for(int i=1; i<=K; i++){
        cin >> t;
        arr[t]++;
        shd[i] = t;
    }
 
    for(int i=1; i<=K; i++){
        if(c[shd[i]]){
            arr[shd[i]]--;
        }
        else{
            if(cnt < N){
                c[shd[i]] = 1;
                arr[shd[i]]--;
                cnt++;
            }
            else{
                int p = 0, last[110] = {0}, tmp = 0;
                for(int j=1; j<i; j++){
                    if(c[shd[j]]){
                        if(arr[shd[j]] == 0) p = shd[j];
                    }
                }
                if(p == 0){
                    for(int j=i+1; j<=K; j++) {
                        if(c[shd[j]] && last[shd[j]] == 0) last[shd[j]] = j;
                    }
                    for(int j=1; j<=K; j++){
                        if(last[shd[j]]) tmp = max(tmp, last[shd[j]]);
                    }
                    p = shd[tmp];
                }
                c[p] = 0;
                res++;
                c[shd[i]] = 1;
                arr[shd[i]]--;
            }
        }
    }
 
    cout << res << endl;
 
    return 0;
}