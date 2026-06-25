enum Valor {
    Int(i32),
    Float(f64),
    Char(char),
    Str(String),
}

fn convertir_a_numero(valor: &Valor) -> f64 {
    match valor {
        Valor::Int(i) => *i as f64,
        Valor::Float(f) => *f,
        Valor::Char(c) => c.to_digit(10).unwrap() as f64,
        Valor::Str(s) => s.parse::<f64>().unwrap(),
    }
}

fn promedio_mayores_a_umbral(arreglo: &[Valor], umbral: &Valor) -> f64 {
    let umbral_num = convertir_a_numero(umbral);

    let mut suma = 0.0;
    let mut cantidad = 0;

    for elemento in arreglo {
        let valor = convertir_a_numero(elemento);

        if valor > umbral_num {
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
    let valores = vec![
        Valor::Char('1'),
        Valor::Float(2.5),
        Valor::Int(30),
        Valor::Str("40".to_string()),
        Valor::Str("50".to_string()),
    ];

    let umbral = Valor::Int(25);

    let promedio = promedio_mayores_a_umbral(&valores, &umbral);

    println!("{:.2}", promedio);
}