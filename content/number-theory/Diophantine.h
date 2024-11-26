/**
 * Author: cp-algorithms.com
 * License: ???
 * Description: Finds a solution (or solutions) to the linear diophantine equation $ax+by=c$,
 * where $a,b,c$ are integers.
 * Time: $O(\log(n))$.
 * Status: A little bit broken when given non-positive integers.
 */
#pragma once

bool find_any_sol(int a, int b, int c, int &x0, int &y0, int &g) {
    g = euclid(abs(a), abs(b), x0, y0);
    if (c % g) return false;
    x0 *= c / g, y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
void shift_sol(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b, y -= cnt * a;
}
// Finds all solutions to the equation: ax + by = c, such that x is in [minx, maxx] and y is in [miny, maxy].
int find_all_sols(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    if(a == 0 && b == 0) return c == 0 ? (maxx-minx+1)*(maxy-miny+1) : 0;
    if(a == 0) {
        if(c%b != 0 || miny > c/b || maxy < c/b) return 0;
        return maxx-minx+1;
    }
    if(b == 0) {
        if(c%a != 0 || minx > c/a || maxy< c/a) return 0;
        return maxy-miny+1;
    }
    int x, y, g;
    if (!find_any_sol(a, b, c, x, y, g)) return 0;
    a /= g, b /= g;
    int sign_a = a>0?1:-1, sign_b=b>0?1:-1;
    shift_sol(x, y, a, b, (minx - x) / b);
    if (x < minx) shift_sol(x, y, a, b, sign_b);
    if (x > maxx) return 0;
    int lx1 = x;
    shift_sol(x, y, a, b, (maxx - x) / b);
    if (x > maxx) shift_sol(x, y, a, b, -sign_b);
    int rx1 = x;
    shift_sol(x, y, a, b, -(miny - y) / a);
    if (y < miny) shift_sol(x, y, a, b, -sign_a);
    if (y > maxy) return 0;
    int lx2 = x;
    shift_sol(x, y, a, b, -(maxy - y) / a);
    if (y > maxy) shift_sol(x, y, a, b, sign_a);
    int rx2 = x;
    if (lx2 > rx2) swap(lx2, rx2);
    int lx = max(lx1, lx2), rx = min(rx1, rx2);
    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}
