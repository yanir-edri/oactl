/**
 * Author: Yanir Edri
 * License: ???
 * Description: CHT with some extras.
 * Time: $O(n\cdot\log{n})$ or $O(n)$, depending on implementation.
 * Status: I sure hope it does
 */
#pragma once

struct line {
    int m, b;
    int operator()(int x) const {
        return m * x + b;
    }
    int operator*(line l) const {
        return b*l.m-m*l.b;
    }
    line operator-(const line& o) const {
        return line{m-o.m,b-o.b};
    }
};
ii operator-(const ii& a, const ii& b) { return {a.x-b.x,a.y-b.y}; }
int operator*(const ii& a, const ii& b) { return a.y*b.x-a.x*b.y; }
namespace cht {
    ii s[maxn];
    int sz, p;
    void reset() { sz = p = 0; }
    void insert(ii l) {
        while (sz && s[sz - 1].x == l.x) {
            if (s[sz - 1].y < l.y) return;
            --sz;
        }
        while (sz >= 2 && (s[sz-1]-s[sz-2])*(l-s[sz-1]) < 0) --sz;
        s[sz++] = l;
    }
    int query(int x) {
        p = max<int>(0,min(p,sz-1));
        int ans = s[p].x*x+s[p].y,nans;
        while(p+1 < sz && (nans=s[p+1].x*x+s[p+1].y) <= ans) ++p, ans = nans;
        return ans;
    }
}
