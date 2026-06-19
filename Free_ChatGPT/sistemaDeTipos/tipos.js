"use strict";

function promedioMayoresQue(precios, umbral) {
    let suma = 0;
    let cantidad = 0;

    for (let i = 0; i < precios.length; i++) {
        const precio = precios[i];

        if (precio > umbral) {
            suma += precio;
            cantidad++;
        }
    }

    return cantidad === 0 ? 0 : suma / cantidad;
}

const precios = ["10", "20", "30", "40"];

console.log(promedioMayoresQue(precios, 25)); // 35
console.log(promedioMayoresQue(precios, 50)); // 0
console.log(precios); // [10, 20, 30, 40] (sin modificaciones)