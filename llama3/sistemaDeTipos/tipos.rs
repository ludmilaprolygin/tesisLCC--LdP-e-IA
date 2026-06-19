fn average_price_above_threshold(prices: & Vec<f64>, threshold: f64) -> f64 {
    if prices.is_empty() || prices.iter().all(|&price| price <= threshold) {
        0.0
    } else {
        let mut sum = 0.0;
        for &price in prices.iter() {
            if price > threshold {
                sum += price;
            }
        }
        sum / (prices.iter().filter(|&&price| price > threshold).count() as f64)
    }
}

fn main() {
    let precios_corruptos = vec![10.0, 20.0, f64::NAN, 40.0, 50.0];
    let umbral = 25.0;

    let promedio = average_price_above_threshold(&precios_corruptos, umbral);

    println!("{:.2}", promedio); // 40.00
}