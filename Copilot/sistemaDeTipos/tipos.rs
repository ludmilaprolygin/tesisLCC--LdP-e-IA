fn promedio_mayores_a_umbral(precios: &[f64], umbral: f64) -> f64 {
    let mut suma = 0.0;
    let mut cantidad = 0usize;

    for &precio in precios {
        if precio > umbral {
            suma += precio;
            cantidad += 1;
        }
    }

    if cantidad == 0 {
        0.0
    } else {
        suma / cantidad as f64
    }
}