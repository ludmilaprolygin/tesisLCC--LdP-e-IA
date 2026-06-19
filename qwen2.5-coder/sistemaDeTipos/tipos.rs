fn calcular_promedio_superiores(precios: &[f64], umbral: f64) -> f64 {
    let mut suma = 0.0;
    let mut contador = 0;

    for &precio in precios.iter() {
        if precio > umbral {
            suma += precio;
            contador += 1;
        }
    }

    if contador == 0 {
        return 0.0;
    }

    suma / contador as f64
}