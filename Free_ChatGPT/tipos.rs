fn precio_final(precio: f64, descuento: &str) -> f64 {
    let descuento: f64 = descuento.parse().unwrap();
    precio * (1.0 - descuento / 100.0)
}

fn main() {
    let resultado = precio_final(50.0, "10");
    println!("{}", resultado);
}