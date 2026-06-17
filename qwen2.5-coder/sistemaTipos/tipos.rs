use std::str::FromStr;

fn calcular_precio_final(precio: f64, descuento: &str) -> Option<f64> {
    // Intenta parsear el descuento a un número flotante
    match f64::from_str(descuento) {
        Ok(d) => {
            // Asegúrate de que el descuento esté entre 0 y 1 (0% - 100%)
            if d >= 0.0 && d <= 1.0 {
                let descuento_amount = precio * d;
                Some(precio - descuento_amount)
            } else {
                None // Descuento no válido
            }
        },
        Err(_) => None, // No se pudo convertir la cadena a número flotante
    }
}

fn main() {
    // Llamada a la función con precio 50 y descuento "10%"
    let precio_final = calcular_precio_final(50.0, "10");
    
    match precio_final {
        Some(precio) => println!("El precio final es: {}", precio),
        None => println!("Descuento no válido"),
    }
}