use std::str::FromStr;
use std::cmp::PartialOrd;

trait NumericType: FromStr + PartialOrd {}
impl<T> NumericType for T where T: FromStr + PartialOrd {}

fn average_above_threshold<T>(values: &[T], threshold: &T) -> Option<f64>
where
    T: NumericType,
{
    let mut sum = 0.0;
    let mut count = 0;

    for value in values {
        if value > threshold {
            match T::from_str(&value.to_string()) {
                Ok(num_value) => {
                    sum += num_value as f64;
                    count += 1;
                },
                Err(_) => {}
            }
        }
    }

    if count == 0 {
        None
    } else {
        Some(sum / count as f64)
    }
}

fn main() {
    let valores = vec![1, 2, 3, 4, 5];
    let umbral = 3;

    let resultado = average_above_threshold(&valores, &umbral);

    println!("{:?}", resultado);
}
