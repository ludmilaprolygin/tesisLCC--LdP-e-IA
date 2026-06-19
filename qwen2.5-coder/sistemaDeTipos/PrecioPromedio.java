package qwen2.5-coder.sistemaDeTipos;

import java.util.List;

public class PrecioPromedio {

    public static double calcularPrecioPromedio(List<Double> precios, double umbral) {
        // Clonar la lista original para no modificarla
        List<Double> preciosFiltrados = precios.stream()
                                               .filter(precio -> precio > umbral)
                                               .toList();
        
        // Si la lista filtrada está vacía, retornar 0
        if (preciosFiltrados.isEmpty()) {
            return 0;
        }
        
        // Calcular el promedio de los precios filtrados
        double suma = 0;
        for (Double precio : preciosFiltrados) {
            suma += precio;
        }
        return suma / preciosFiltrados.size();
    }

    public static void main(String[] args) {
        List<Double> precios = List.of(10.5, 20.7, 3.2, 15.4, 8.9);
        double umbral = 10;
        double promedio = calcularPrecioPromedio(precios, umbral);
        System.out.println("El precio promedio es: " + promedio);
    }
}
