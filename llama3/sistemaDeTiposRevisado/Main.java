import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Object> numbers = new ArrayList<>();
        // Agregamos elementos al arreglo (int, float, char y string)
        numbers.add(5);
        numbers.add("30");
        numbers.add(40.0f);
        numbers.add('2');
        numbers.add(50);

        int threshold = 5; // Umbral a partir del cual se calculará el promedio

        double sum = 0;
        int count = 0;

        for (Object o : numbers) {
            if (o instanceof Number) { // Verificamos si el elemento es un número
                Number num = (Number) o;
                if (((double) num).compareTo(threshold) > 0) { // Comparación con umbral
                    sum += num.doubleValue(); // Sumamos el valor
                    count++; // Contamos el número de elementos que superan el umbral
                }
            }
        }

        if (count > 0) {
            double average = sum / count; // Calculamos el promedio
            System.out.println("Promedio de los valores mayores a " + threshold + ": " + average);
        } else {
            System.out.println("No hay elementos que superen el umbral");
        }
    }
}