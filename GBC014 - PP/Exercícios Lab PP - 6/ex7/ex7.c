#include <stdio.h>
#include <math.h>

struct coordenadas {
    double r;
    double a;
    double x;
    double y;
};

int main() {
    struct coordenadas polar;

    printf("Digite o raio: ");
    scanf("%lf", &polar.r);
    printf("Digite o argumento (a) em radianos: ");
    scanf("%lf", &polar.a);

    polar.x = polar.r * cos(polar.a);
    polar.y = polar.r * sin(polar.a);

    printf("Coordenadas cartesianas:\n");
    printf("x = %.2lf\n", polar.x);
    printf("y = %.2lf\n", polar.y);

    return 0;
}
