/*
 * What type of conversion happens in each of the following cases?
 *
 * Valid answers are:
 *   - No conversion needed
 *   - Numeric promotion
 *   - Numeric conversion
 *   - Won't compile due to narrowing conversion.
 *
 * Assume int and long are both 4 bytes.
 */

int main()
{
    int a { 5 }; // 1a -> No conversion
    int b { 'a' }; // 1b -> Numeric Promotion
    int c { 5.4 }; // 1c -> Error, narrowing
    int d { true }; // 1d -> Numeric Promotion
    int e { static_cast<int>(5.4) }; // 1e -> Numeric conversion

    double f { 5.0f }; // 1f -> Numeric promotion of float to double
    double g { 5 }; // 1g -> Numeric conversion of int to double

    // Extra credit section
    long h { 5 }; // 1h -> Numeric conversion

    float i { f }; // 1i (uses previously defined variable f) -> narrowing, error
                   // This is a narrowing conversion because double (f) to float could lose precision
    float j { 5.0 }; // 1j -> Numeric conversion 
                    // This is a numeric conversion of double literal to float
                    // Allowed because this specific value (5.0) can be represented exactly
}