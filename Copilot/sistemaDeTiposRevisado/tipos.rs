#[derive(Debug, Clone)]
enum Value {
    Int(i32),
    Float(f64),
    Char(char),
    Str(String),
}

fn to_f64(value: &Value) -> f64 {
    match value {
        Value::Int(n) => *n as f64,
        Value::Float(n) => *n,
        Value::Char(c) => c.to_digit(10).unwrap_or(0) as f64,
        Value::Str(s) => s.parse::<f64>().unwrap_or(0.0),
    }
}

fn promedio_mayores_a_umbral(values: &[Value], umbral: f64) -> f64 {
    let mut suma = 0.0;
    let mut cantidad = 0usize;

    for value in values {
        let numero = to_f64(value);
        if numero > umbral {
            suma += numero;
            cantidad += 1;
        }
    }

    if cantidad == 0 {
        0.0
    } else {
        suma / cantidad as f64
    }
}

fn main() {
    let values = vec![
        Value::Int(1),
        Value::Float(30.0),
        Value::Char('2'),
        Value::Str("40".to_string()),
        Value::Float(50.0),
    ];

    let result = promedio_mayores_a_umbral(&values, 25.0);
    println!("{result}");
}