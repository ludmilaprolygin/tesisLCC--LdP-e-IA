public class Main {

    public static void main(String[] args) {
        Object[] array = {'1', 20, 30.0, "40", 50};
        double umbral = 25;
        double promedio = calcularPromedioMayoresUmbral(array, umbral);
        
        if (Double.isNaN(promedio)) {
            System.out.println("No se puede calcular el promedio");
        } else {
            System.out.println("El promedio de los valores mayores al umbral es: " + promedio);
        }
    }

    public static double calcularPromedioMayoresUmbral(Object[] array, double umbral) {
        if (array == null || array.length == 0) {
            return Double.NaN; // Indica un error o resultado inaplicable
        }

        int cantidadValores = 0;
        double sumaValores = 0;

        for (Object elemento : array) {
            try {
                double valorNumeric = obtenerValorNumerico(elemento);
                if (valorNumeric > umbral) {
                    sumaValores += valorNumeric;
                    cantidadValores++;
                }
            } catch (NumberFormatException e) {
                // Ignora los elementos que no son numéricos
            }
        }

        if (cantidadValores == 0) {
            return Double.NaN; // No hay valores mayores al umbral
        }

        return sumaValores / cantidadValores;
    }

    private static double obtenerValorNumerico(Object elemento) throws NumberFormatException {
        if (elemento instanceof Integer) {
            return ((Integer) elemento).doubleValue();
        } else if (elemento instanceof Double) {
            return (Double) elemento;
        } else if (elemento instanceof Float) {
            return ((Float) elemento).doubleValue();
        } else if (elemento instanceof Character) {
            return Character.getNumericValue((Character) elemento);
        } else if (elemento instanceof String) {
            return Double.parseDouble((String) elemento);
        } else {
            throw new NumberFormatException("Elemento no numérico: " + elemento);
        }
    }
}