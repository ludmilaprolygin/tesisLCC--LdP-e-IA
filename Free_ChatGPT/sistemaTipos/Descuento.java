package sistemaTipos;
public class Descuento {

    public static double precioFinal(double precio, String descuento) {
        double porcentaje = Double.parseDouble(descuento);
        return precio * (1 - porcentaje / 100);
    }

    public static void main(String[] args) {
        double resultado = precioFinal(50, "10");
        System.out.println(resultado);
    }
}