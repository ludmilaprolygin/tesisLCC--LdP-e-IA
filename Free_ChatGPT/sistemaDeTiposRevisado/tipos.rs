enum Valor {
    Int(i32),
    Float(f64),
    Char(char),
    Str(String),
}

fn a_numero(v: &Valor) -> f64 {
    match v {
        Valor::Int(n) => *n as f64,
        Valor::Float(n) => *n,
        Valor::Char(c) => c.to_string().parse::<f64>().unwrap(),
        Valor::Str(s) => s.parse::<f64>().unwrap(),
    }
}

fn promedio_mayores(precios: &[Valor], umbral: f64) -> f64 {
    let mut suma = 0.0;
    let mut cantidad = 0;

    for precio in precios {
        let valor = a_numero(precio);

        if valor > umbral {
            suma += valor;
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
    let precios = vec![
        Valor::Int(10),
        Valor::Float(30.0),
        Valor::Char('2'),
        Valor::Str(String::from("40")),
        Valor::Str(String::from("50")),
    ];

    let promedio = promedio_mayores(&precios, 15.0);

    println!("{}", promedio);
}