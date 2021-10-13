int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    const int b[10] = {3, 4, 2, 6, 5, 3, 7, 3, 5, 6};
    int s = 0;
    for (int i = 0; i < 10; ++i) {
        a[i] += b[i];
        s += a[i];
    }
    return 0;
}