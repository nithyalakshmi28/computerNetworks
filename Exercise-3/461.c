int hammingDistance(int x, int y) {
    unsigned int xorResult = x ^ y;
    int distance = 0;
    while (xorResult > 0) {
        xorResult &= (xorResult - 1); 
        distance++;
    }
    
    return distance;
}
