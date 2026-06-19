function calcularPromedioMayorUmbral(precios, umbral) {
  // Validar si el array está vacío o no hay precios mayores al umbral
  if (!precios || !precios.some(precio => precio > umbral)) return 0;

  // Crear una copia inmutable del array para asegurar que no se modifica la original
  const preciosFiltrados = [...precios].filter(precio => precio > umbral);

  // Calcular y devolver el promedio
  return preciosFiltrados.reduce((acumulador, precio) => acumulador + precio, 0) / preciosFiltrados.length;
}

const listaPrecios = ["10", "20", "30", "40", "50"];
const umbral = 25;
console.log(calcularPromedioMayorUmbral(listaPrecios, umbral)); // Output: 45 (promedio de 30 y 40)