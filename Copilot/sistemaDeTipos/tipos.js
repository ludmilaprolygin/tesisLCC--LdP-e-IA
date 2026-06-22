function promedioMayoresAUmbral(precios, umbral) {
  let suma = 0;
  let cantidad = 0;

  for (const precio of precios) {
    if (precio > umbral) {
      suma += precio;
      cantidad++;
    }
  }

  return cantidad === 0 ? 0 : suma / cantidad;
}