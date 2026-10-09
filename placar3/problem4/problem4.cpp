# include <iostream>
# include <string>

# define MAXDIGITS 100
# define PLUS 1  
# define MINUS -1 

typedef long long ll;

typedef struct {
    char digits [MAXDIGITS]; 
    int signbit; 
    int lastdigit;
} bignum ;

void ll_to_bignum(ll s, bignum *n) {
    int i;
    ll t;

    if (s >= 0 ) n->signbit = PLUS;
    else n->signbit = MINUS;

    for (i=0; i<MAXDIGITS; i++) n->digits[i] = (char) 0;
    n->lastdigit = -1;

    t = (s >= 0) ? s : -s;
    while (t > 0) {
        n->lastdigit ++;
        n->digits [n->lastdigit] = (char) (t % 10);
        t = t / 10;
    }

    if (s==0) n->lastdigit = 0;
}