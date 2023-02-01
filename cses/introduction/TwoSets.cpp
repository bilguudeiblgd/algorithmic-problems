#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

typedef struct {
    int * a;
    int * b;
} Path;


int main () {
    int n;
    cin >> n;

    int * arr = (int *) malloc(n * sizeof(*arr));
    for(int i = 0; i < n; i++)
        arr[i] = i+1;
    long long sum = n * (n+1)/ 2;
    if(sum % 2 == 0) {
        cout << "YES\n";

        if(n % 4 == 3) {
            printf("%d\n", n / 2);
            for(int i = 2; i <= n/2; i += 2) {
                printf("%d %d ", i, n-i);
            }
            printf("%d\n%d\n", n, n/2+1);
            for(int i = 1; i <= n/2; i += 2) {
                printf("%d %d ", i, n-i);
            }
            printf("\n");
        }
        else {
            printf("%d\n", n/2);
            for(int i = 1; i <= n/4; i++) {
                printf("%d %d ", 4*(i-1)+1, 4*(i));
            }
            printf("\n%d\n", n/2);
            for(int i = 1; i <= n/4; i++) {
                printf("%d %d ", 4*i-2, 4*i-1);
            }
            printf("\n");
        }
        
    }
    else {
        cout << "NO\n";
    }
    free(arr);
}
