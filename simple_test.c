#include <stdio.h>
int main() {
    /*char a = 0;
    while (a < 64) {
        a += 2;
    }*/

    int a[40];
    int sum = 0;
    int s = -10000;
    for (int i = 0; i < 40; ++i) {
        a[i] = (i * 2) % 5;
        sum += a[i];
        s = s + sum / 4 + 6;
    }
    
    int c = 9;
    for (int i = 0; i < 100; ++i) {
        switch(i%10) {
            case 1:
                c--;
                break;
            case 3:
                c++;
                break;
            case 7:
                c += 10;
                break;
            default:
                c -= 2;
                break;
        }
    }
    
    return c;
}
