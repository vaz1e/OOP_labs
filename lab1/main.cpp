#include <iostream>

class FazzyNumber
{
private:
    float xl;
    float x;
    float xr;

public:
    FazzyNumber(float x, float e) : xl(x - e), x(x), xr(x + e){};
    FazzyNumber() : xl(0), x(0), xr(0){};
    ~FazzyNumber(){};
    friend FazzyNumber add(const FazzyNumber &a, const FazzyNumber &b)
    {
        FazzyNumber res;
        res.xl = a.x + b.x - a.xl - b.xl;
        res.x = a.x + b.x;
        res.xr = a.x + b.x + a.xr + b.xr;
        return res;
    }
    friend FazzyNumber subtract(const FazzyNumber &a, const FazzyNumber &b)
    {
        FazzyNumber res;
        res.xl = a.x - b.x - a.xl - b.xl;
        res.x = a.x - b.x;
        res.xr = a.x - b.x + a.xr + b.xr;
        return res;
    }
    friend FazzyNumber multiply(const FazzyNumber &a, const FazzyNumber &b)
    {
        FazzyNumber res;
        res.xl = a.x * b.x - b.x * a.xl - a.x * b.xl + a.xl * b.xl;
        res.x = a.x * b.x;
        res.xr = a.x * b.x + b.x * a.xl + a.x * b.xl + a.xl * b.xl;
        return res;
    }
    friend FazzyNumber divide(const FazzyNumber &a, const FazzyNumber &b)
    {
        FazzyNumber res;
        res.xl = (a.x - a.xl) / (b.x + b.xr);
        res.x = a.x / b.x;
        res.xr = (a.x + a.xr) / (b.x - b.xl);
        return res;
    }
    friend FazzyNumber reverse(const FazzyNumber &a)
    {
        FazzyNumber res;
        res.xl = 1 / (a.x + a.xr);
        res.x = 1 / a.x;
        res.xr = 1 / (a.x - a.xl);
        return res;
    }

    friend bool operator>(const FazzyNumber &a, const FazzyNumber &b)
    {
        if (a.x > b.x)
            return true;
        return false;
    }

    friend bool operator<(const FazzyNumber &a, const FazzyNumber &b)
    {
        if (a.x > b.x)
            return false;
        return true;
    }
    friend bool operator==(const FazzyNumber &a, const FazzyNumber &b)
    {
        if (a.x == b.x)
            return true;
        return false;
    }

    friend std::ostream &operator<<(std::ostream &out, const FazzyNumber &a)
    {
        out << "( " << a.xl << " ), ( " << a.x << " ), (" << a.xr << ")\n";
        return out;
    }
};

int main()
{
    int a,b,c,d;
    std::cin>>a>>b>>c>>d;
    FazzyNumber first(a, b);
    FazzyNumber second(c, d);
    FazzyNumber res;
    std::cout << "First " <<first;
    std::cout << "Second "<<second;
    res = add(first, second);
    std::cout << "Adding: " << res;
    res = subtract(first, second);
    std::cout << "Subtracting: " << res;
    res = multiply(first, second);
    std::cout << "Mupltiply: " << res;
    res = divide(first, second);
    std::cout << "Divide: " << res;
    first=reverse(first);
    std::cout<<"Reversed first "<<first;
    return 0;
}