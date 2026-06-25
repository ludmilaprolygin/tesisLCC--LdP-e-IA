public final class Main {
    public static double averageAboveThreshold(Object[] values, double threshold) {
        if (values == null || values.length == 0) {
            return 0.0;
        }

        double sum = 0.0;
        int count = 0;

        for (Object value : values) {
            double number = toDouble(value);
            if (number > threshold) {
                sum += number;
                count++;
            }
        }

        return count == 0 ? 0.0 : sum / count;
    }

    private static double toDouble(Object value) {
        if (value instanceof Integer i) {
            return i.doubleValue();
        }
        if (value instanceof Float f) {
            return f.doubleValue();
        }
        if (value instanceof Double d) {
            return d;
        }
        if (value instanceof Long l) {
            return l.doubleValue();
        }
        if (value instanceof Short s) {
            return s.doubleValue();
        }
        if (value instanceof Byte b) {
            return b.doubleValue();
        }
        if (value instanceof Character c) {
            return Character.getNumericValue(c);
        }
        if (value instanceof String str) {
            return Double.parseDouble(str);
        }

        throw new IllegalArgumentException("Unsupported value type: " + value.getClass());
    }

    public static void main(String[] args) {
        Object[] values = { 1, 30.0f, '2', "40", 50L };

        double result = averageAboveThreshold(values, 25.0);
        System.out.println(result); 
    }
}