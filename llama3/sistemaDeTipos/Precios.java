package llama3.sistemaDeTipos;

public class Precios{
  public static double promedioPreciosMayores(int[] precios, int umbral) {
    if (precios.length == 0) { // si la lista está vacía
        return 0;
    }

    List<Integer> preciosMayores = new ArrayList<>();
    for (int precio : precios) {
        if (precio > umbral) {
            preciosMayores.add(precio);
        }
    }

    if (preciosMayores.isEmpty()) { // si no hay elementos que superen el umbral
        return 0;
    }

    int suma = 0;
    for (int precio : preciosMayores) {
        suma += precio;
    }
    return (double)suma / preciosMayores.size();
}

public static void main(String[] args) {
        double[] precios = {10, 20, Double.NaN, 40, 50};

        System.out.println(promedioPreciosMayores(precios, 25)); 
        System.out.println(promedioPreciosMayores(precios, 50)); 
    }
}