function promedioMayoresAUmbral(valores, umbral) {
  let suma = 0;
  let cantidad = 0;

  for (const valor of valores) {
    const numero = Number(valor);

    if (numero > umbral) {
      suma += numero;
      cantidad++;
    }
  }

  return cantidad === 0 ? 0 : suma / cantidad;
}

console.log(promedioMayoresAUmbral([1, 30.0, 2, 40, '50'], 25)); 