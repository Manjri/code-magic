
int mult(char a, unsigned char b) {
    int r = 0;
    while (b) {
        if (b & 1) r += a;
        a = a << 1;     // multiply by 2
        b = b >> 1;     // divide by 2
    }
    return r;
}