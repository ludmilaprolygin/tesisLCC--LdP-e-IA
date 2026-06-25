function promedioMayores(precios, umbral) {
    let suma = 0;
    let cantidad = 0;

    const umbralNum = Number(umbral);

    for (const precio of precios) {
        const valor = Number(precio);

        if (valor > umbralNum) {
            suma += valor;
            cantidad++;
        }
    }

    return cantidad === 0 ? 0 : suma / cantidad;
}

console.log(promedioMayores([10, '2', 30.0, "40", 50], 25));