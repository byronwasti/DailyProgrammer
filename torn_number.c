#include <stdio.h>
#include <math.h>

int noDuplicates(int n) {
    int digitCount[10] = {0};

    digitCount[(n % 10)]++;
    digitCount[(n % 100) / 10]++;
    digitCount[(n % 1000) / 100]++;
    digitCount[(n % 10000) / 1000]++;
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] > 1)
            return 0;
    }
    return 1;
}

int isTorn(int n) {
    if (noDuplicates(n))
        return (n == (pow((n/100) + (n % 100) ,2)));
    return 0;
}


int main(int argc, const char * argv[])
{
    for (int i = 1000; i < 10000; i++) {
        if (isTorn(i))
            printf("%d\n", i);
    }
    return 0;
}
