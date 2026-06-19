function calcularPrecioPromedio(superiorUMbral, precios) {
  if (!precios.length || !precios.every(precio => precio <= superiorUMbral)) {
    return 0;
  }

  const superioresAlUMbral = precios.filter(precio => precio > superiorUMbral);
  return superioresAlUMbral.reduce((acumulador, precio) => acumulador + precio, 0) / superioresAlUMbral.length;
}

const listaPrecios = ["10", "20", "30", "40", "50"];
const umbral = 25;
console.log(calcularPrecioPromedio(listaPrecios, umbral)); // Output: 45 (promedio de 30 y 40)