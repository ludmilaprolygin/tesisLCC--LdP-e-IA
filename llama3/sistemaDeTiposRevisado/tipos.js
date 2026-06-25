function calculateMeanAboveThreshold(arr, threshold) {
  const filteredValues = arr.filter((val) => {
    if (typeof val === 'string') {
      return parseFloat(val) > threshold;
    } else if (typeof val === 'number' || val instanceof Float32Array) {
      return val > threshold;
    }
    throw new Error(`Invalid value type: ${typeof val}`);
  });

  const sum = filteredValues.reduce((acc, val) => acc + val, 0);
  const mean = sum / filteredValues.length;

  return mean;
}

console.log(calculateMeanAboveThreshold([1, 30.0, 2, 40, '50'], 25)); 