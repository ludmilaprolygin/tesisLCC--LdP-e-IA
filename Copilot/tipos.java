public class tipos {
	public static double precioFinal(double precio, String descuentoTexto) {
		double descuento = Double.parseDouble(descuentoTexto);
		return precio - (precio * descuento / 100.0);
	}

	public static void main(String[] args) {
		double precioFinalResultado = precioFinal(50, "10");
		System.out.println(precioFinalResultado);
	}
}
