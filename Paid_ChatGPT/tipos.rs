fn calcular_precio_final(precio: f64, descuento: f64) -> f64 {
    precio * (1.0 - descuento / 100.0)
}

fn main() {
    let descuento: f64 = "10".parse().unwrap();
    let precio_final = calcular_precio_final(50.0, descuento);

    println!("Precio final: {}", precio_final);
}