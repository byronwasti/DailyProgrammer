#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define sqrt(x)     (exp(log(x) / 2))
#define cuberoot(x) (exp(log(x) / 3))

static void cube(int volume) {
    double height = cuberoot(volume);

    printf("Cube:     %1$.2fm length, %1$.2fm width, %1$.2fm height\n", height);
}

static void cylinder(int volume) {
    double height = cuberoot(volume), radius = sqrt(volume / (height * M_PI));

    printf("Cylinder: %.2fm height, %.2fm diameter\n", height, radius * 2);
}

static void sphere(int volume) {
    double radius = cuberoot(3 * (volume / (4 * M_PI)));

    printf("Sphere:   %.2fm radius\n", radius);
}

static void cone(int volume) {
    double height = pow(cuberoot(volume), 2), radius = sqrt(3 * (volume / (M_PI * height)));

    printf("Cone:     %.2fm height, %.2fm radius\n", height, radius);
}

int main(int argc, char *argv[]) {
    int rc = 0, volume = 0;

    if (argc < 2) {
        printf("Usage: shipping <volume>\n");

        rc = 1;
        goto cleanup;
    }

    volume = atoi(argv[1]);

    cube(volume);
    cylinder(volume);
    sphere(volume);
    cone(volume);

cleanup:
    return rc;
}
