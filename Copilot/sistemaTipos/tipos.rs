fn precio_final(precio: f64, descuento_texto: &str) -> f64 {
	let descuento: f64 = descuento_texto.parse().expect("descuento invalido");
	precio - (precio * descuento / 100.0)
}

fn main() {
	let precio_final = precio_final(50.0, "10");
	println!("{precio_final}");
}
