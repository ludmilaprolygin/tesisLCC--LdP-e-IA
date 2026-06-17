public class DescuentoProducto {

    // Método que calcula el precio final con descuento
    public static double calcularPrecioFinal(double precioOriginal, int descuentoPorcentaje) {
        if (precioOriginal < 0 || descuentoPorcentaje < 0 || descuentoPorcentaje > 100) {
            throw new IllegalArgumentException("El precio y el descuento deben ser valores positivos y el descuento no puede superar el 100%.");
        }
        
        double descuento = (precioOriginal * descuentoPorcentaje) / 100;
        double precioFinal = precioOriginal - descuento;
        return precioFinal;
    }

    public static void main(String[] args) {
        // Ejemplo de uso
        String precioStr = "50";
        int descuentoStr = Integer.parseInt("10"); // Convertimos la cadena a entero
        
        double precioOriginal = Double.parseDouble(precioStr); // Convertimos la cadena a doble
        
        // Calculamos el precio final con el descuento
        double precioFinal = calcularPrecioFinal(precioOriginal, descuentoStr);
        
        System.out.println("El precio original es: $" + precioOriginal);
        System.out.println("El descuento es: " + descuentoStr + "%");
        System.out.println("El precio final después del descuento es: $" + precioFinal);
    }
}