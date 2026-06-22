public final class Promedios {

    private Promedios() {
        // Utility class
    }

    public static double promedioMayoresA(double[] precios, double umbral) {
        if (precios == null || precios.length == 0) {
            return 0.0;
        }

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
        double[] precios = {10, 20, Double.NaN, 40, 50};

        System.out.println(Promedios.promedioMayoresA(precios, 25)); 
        System.out.println(Promedios.promedioMayoresA(precios, 50)); 
    }
}
