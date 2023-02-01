#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main() {
    int n, target;
    cin >> n >> target;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int i = 0;
    int j = 1;
    int sum = 0;
    int count = 0;
    sum += arr[i];
    while(j < n || i < n) {
       
        // printf("sum: %d\n",sum);
        // printf("i: %d j: %d\n", i,j);
        
        if(sum == target) {
            count ++;
            sum -= arr[i];
            i++;
            continue;
        }
        if(sum > target) {  
            sum -= arr[i];
            i++;
            continue;
        }
        if(j == n) {
            sum -= arr[i];
            i++;
            continue;
        }
        if(sum < target) {
            sum += arr[j];
            j++;
            continue;
        }
    }
    if(sum == target) {
        count++;
    }

    printf("%d\n", count);

    // printf("")
        
}
