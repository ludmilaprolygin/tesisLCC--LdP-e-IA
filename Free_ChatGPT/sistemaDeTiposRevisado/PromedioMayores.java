public class PromedioMayores {

    public static double promedioMayores(Object[] precios, double umbral) {
        double suma = 0.0;
        int cantidad = 0;

        for (Object precio : precios) {
            double valor = convertirANumero(precio);

            if (valor > umbral) {
                suma += valor;
                cantidad++;
            }
        }

        return cantidad == 0 ? 0 : suma / cantidad;
    }

    private static double convertirANumero(Object valor) {
        if (valor instanceof Integer) {
            return ((Integer) valor).doubleValue();
        }

        if (valor instanceof Float) {
            return ((Float) valor).doubleValue();
        }

        if (valor instanceof Double) {
            return (Double) valor;
        }

        if (valor instanceof Character) {
            return Double.parseDouble(String.valueOf(valor));
        }

        if (valor instanceof String) {
            return Double.parseDouble((String) valor);
        }

        throw new IllegalArgumentException(
            "Tipo no soportado: " + valor.getClass().getName()
        );
    }

    public static void main(String[] args) {
        Object[] precios = {
            10,
            30.0f,
            '2',
            "40",
            50
        };

        System.out.println(promedioMayores(precios, 25));
    }
}