public class Promedio {

    public static double promedioMayoresAUmbral(Object[] arreglo, Object umbral) {
        double suma = 0;
        int cantidad = 0;

        double umbralNum = convertirANumero(umbral);

        for (Object elemento : arreglo) {
            double valor = convertirANumero(elemento);

            if (valor > umbralNum) {
                suma += valor;
                cantidad++;
            }
        }

        return (cantidad == 0) ? 0 : suma / cantidad;
    }

    private static double convertirANumero(Object valor) {
        if (valor instanceof Integer) {
            return ((Integer) valor).doubleValue();
        } else if (valor instanceof Float) {
            return ((Float) valor).doubleValue();
        } else if (valor instanceof Double) {
            return (Double) valor;
        } else if (valor instanceof Character) {
            return Character.getNumericValue((Character) valor);
        } else if (valor instanceof String) {
            return Double.parseDouble((String) valor);
        } else {
            throw new IllegalArgumentException("Tipo no soportado");
        }
    }

    public static void main(String[] args) {
        Object[] valores = {'1', 20.0, "30", 40, 50.0};

        double promedio = promedioMayoresAUmbral(valores, 25);

        System.out.println(promedio);
    }
}