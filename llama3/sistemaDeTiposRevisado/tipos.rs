fn average_greater_than(arr: &Vec<&dyn std::any::Any + '_>, threshold: f64) -> Option<f64> {
    let mut sum: f64 = 0.0;
    let mut count: i32 = 0;

    for val in arr {
        match val.as_any().downcast_ref::<f64>() {
            Some(fval) => {
                if *fval > threshold {
                    sum += fval;
                    count += 1;
                }
            }
            Some(ival) => {
                let num = match *ival {
                    '0'...'9' => *ival as i32 - '0' as i32,
                    _ => panic!("Invalid character"),
                };
                if (num as f64) > threshold {
                    sum += (num as f64);
                    count += 1;
                }
            }
            None => match val.as_str() {
                Some(s) => {
                    let num = s.parse::<f64>().unwrap_or(f64::NaN);
                    if num > threshold {
                        sum += num;
                        count += 1;
                    }
                }
                _ => panic!("Invalid string"),
            },
        }
    }

    if count == 0 {
        None
    } else {
        Some(sum / (count as f64))
    }
}
