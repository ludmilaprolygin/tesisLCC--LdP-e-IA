package Free_ChatGPT.sistemaDeTipos;

public class Precios {
    public static double promedioMayoresQue(double[] precios, double umbral) {
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

        System.out.println(promedioMayoresQue(precios, 25)); 
        System.out.println(promedioMayoresQue(precios, 50)); 
    }
}
