#include <jni.h>
#include <stdio.h>
#include <math.h>
#include "libjniSecante_JavaSecante.h" // Archivo de encabezado generado

double funcion1(double x) {
    return sin(x) + cos(x) - pow(x, 2) + 2 * x;
}

double funcion2(double x) {
    return pow(x, 3) - x - 1;
}

double funcion3(double x) {
    return log(x) + pow(x, 2) - 4;
}

JNIEXPORT void JNICALL Java_libjniSecante_JavaSecante_ejecutarSecante
(JNIEnv *env, jobject obj, jint opcion, jdouble x0, jdouble x1, jint maxIter, jdouble tol) {
    double (*f)(double);

    switch (opcion) {
        case 1:
            f = funcion1;
            break;
        case 2:
            f = funcion2;
            break;
        case 3:
            if (x0 <= 0 || x1 <= 0) {
                printf("Error: el valor inicial para log(x) debe ser mayor que 0.\n");
                return;
            }
            f = funcion3;
            break;
        default:
            printf("Opción no válida.\n");
            return;
    }

    double xi, f_x0, f_x1, f_xi;
    int iter = 0;

    printf("\nMétodo de la Secante\n");
    printf("Iteración\tx0\t\tx1\t\txi\t\tf(xi)\t\tError\n");

    do {
        f_x0 = f(x0);
        f_x1 = f(x1);

        xi = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
        f_xi = f(xi);

        double error = fabs((xi - x1) / xi) * 100;

        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f%%\n", iter + 1, x0, x1, xi, f_xi, error);

        x0 = x1;
        x1 = xi;
        iter++;

        if (error < tol) {
            printf("Convergencia alcanzada en %d iteraciones.\n", iter);
            printf("La raíz aproximada es: %.6f\n", xi);
            return;
        }

    } while (iter < maxIter);

    printf("Se alcanzó el número máximo de iteraciones sin convergencia.\n");
}

