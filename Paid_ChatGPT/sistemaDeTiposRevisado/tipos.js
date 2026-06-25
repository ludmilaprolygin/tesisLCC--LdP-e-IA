function convertirANumero(valor) {
    if (typeof valor === "number") {
        return valor;
    }

    if (typeof valor === "string") {
        return Number(valor);
    }

    throw new Error("Tipo no soportado");
}

function promedioMayoresAUmbral(arreglo, umbral) {
    const umbralNum = convertirANumero(umbral);

    let suma = 0;
    let cantidad = 0;

    for (const elemento of arreglo) {
        const valor = convertirANumero(elemento);

        if (valor > umbralNum) {
            suma += valor;
            cantidad++;
        }
    }

    return cantidad === 0 ? 0 : suma / cantidad;
}

// Ejemplo de uso
const valores = [1, 2.5, 30, "40", 50];

console.log(promedioMayoresAUmbral(valores, 25));