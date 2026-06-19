function calcularPromedioMayoresAUmbral(precios, umbral) {
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

// Ejemplo de uso
const precios = ["10", "20", "30", "40", "50"];
const promedio = calcularPromedioMayoresAUmbral(precios, 25);

console.log(promedio); // 40