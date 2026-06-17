package llama3.sistemaTipos;
public class Tipos {
    public static void main(String[] args) {
        double price = 50;
        String discount = "10";
        
        double finalPrice = applyDiscount(price, discount);
        System.out.println("Precio final: " + finalPrice);
    }

    public static double applyDiscount(double price, String discount) {
        // Convertir el descuento a un valor numérico (porcentaje)
        int percentDiscount = Integer.parseInt(discount.replace("%", ""));
        
        // Calcular el precio final aplicando el descuento
        double finalPrice = price - (price * (percentDiscount / 100.0));
        
        return finalPrice;
    }
}