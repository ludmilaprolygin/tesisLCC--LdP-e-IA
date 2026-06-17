package sistemaTipos;
public class Descuento {

    public static double calcularPrecioFinal(double precio, double descuento) {
        return precio * (1.0 - descuento / 100.0);
    }

    public static void main(String[] args) {
        double precioFinal = calcularPrecioFinal(50, Double.parseDouble("10"));

        System.out.println("Precio final: " + precioFinal);
    }
}