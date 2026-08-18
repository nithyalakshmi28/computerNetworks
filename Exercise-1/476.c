int findComplement(int num) {
    int totalBits = 32 - __builtin_clz(num);
    unsigned int mask = (1LL << totalBits) - 1;
    
    return num ^ mask;
}
