public class PromedioPrecios {

    public static double calcularPromedioMayoresAUmbral(double[] precios, double umbral) {
        double suma = 0.0;
        int cantidad = 0;

        for (double precio : precios) {
            if (precio > umbral) {
                suma += precio;
                cantidad++;
            }
        }

        return cantidad == 0 ? 0.0 : suma / cantidad;
    }

    public static void main(String[] args) {
        double[] precios = {10, 20, 30, 40, 50};

        double promedio = calcularPromedioMayoresAUmbral(precios, 25);

        System.out.println(promedio); // 40.0
    }
}