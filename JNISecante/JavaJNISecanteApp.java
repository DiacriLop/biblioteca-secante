package JNISecante;

import libjniSecante.JavaSecante;

public class JavaJNISecanteApp {
    JavaSecante secante;

    static {
        System.loadLibrary("jniSecante");
    }

    public JavaJNISecanteApp() {
        secante = new JavaSecante();
    }

    public void ejecutarSecante(int opcion, double x0, double x1, int maxIter, double tol) {
        secante.ejecutarSecante(opcion, x0, x1, maxIter, tol);
    }

    public static void main(String[] args) {
        JavaJNISecanteApp app = new JavaJNISecanteApp();

        int opcion = 1;
        double x0 = 1.0;
        double x1 = 2.0;
        int maxIter = 50;
        double tol = 1e-6;

        System.out.println("Ejecutando");
        app.ejecutarSecante(opcion, x0, x1, maxIter, tol);
    }
}

