fn calculate_price_with_discount(price: f64, discount: &str) -> f64 {
    let percentage: f64 = discount.parse().unwrap();
    let discount_amount = price * (percentage as f64 / 100.0);
    price - discount_amount
}

fn main() {
    let price = 50.0;
    let discount = "10";
    let final_price = calculate_price_with_discount(price, discount);
    println!("El precio final es: {}", final_price);
}