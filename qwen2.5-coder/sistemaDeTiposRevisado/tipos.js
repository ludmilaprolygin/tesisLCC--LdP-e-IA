function calcularPromedioMayoresAUmbral(arreglo, umbral) {
  let suma = 0;
  let contador = 0;

  for (let i = 0; i < arreglo.length; i++) {
    // Convertir a número si es posible
    const valorComoNumero = parseFloat(arreglo[i]);
    
    if (!isNaN(valorComoNumero)) {
      if (valorComoNumero > umbral) {
        suma += valorComoNumero;
        contador++;
      }
    } else {
      console.warn(`El elemento ${arreglo[i]} no es un número válido`);
    }
  }

  // Calcular el promedio
  const promedio = contador > 0 ? suma / contador : 0;

  return promedio;
}

// Ejemplo de uso:
const miArreglo = [10, '20', 'casa', 30.0, '40', 50];
const umbral = 25;
console.log(calcularPromedioMayoresAUmbral(miArreglo, umbral)); // Output: 30