package libjniSecante;

public class JavaSecante {

    // Método nativo para ejecutar el método de la secante en una función seleccionada
    public native void ejecutarSecante(int opcion, double x0, double x1, int maxIter, double tol);

    public static void main(String[] args) {
        JavaSecante secante = new JavaSecante();
        int opcion = 1;  // Puedes cambiar la opción para seleccionar la función en C
        double x0 = 1.0;
        double x1 = 2.0;
        int maxIter = 100;
        double tol = 1e-6;

        secante.ejecutarSecante(opcion, x0, x1, maxIter, tol);
    }

 
}

