class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(C <= E || G <= A || D <= F || H <= B) {
            return (C - A) * (D-B) + (G-E) * (H-F);
        }
        int x[] = {A, C, E, G};
        int y[] = {B, D, F, H};
        sort(x, x+4);
        sort(y, y+4);

        return (C - A) * (D-B) + (G-E) * (H-F) - (x[2]-x[1]) * (y[2] - y[1]);
    }
};
