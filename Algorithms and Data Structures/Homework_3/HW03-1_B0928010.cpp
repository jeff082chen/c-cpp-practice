#include <iostream>
#include <limits>

class Quadratic {
    // ax^2 + bx + c
    // a as quadratic term, b as linear term, c as constant term
    double a, b, c;

public:
    Quadratic(void): a(0), b(0), c(0) {} // default constractor
    Quadratic(double a, double b, double c): a(a), b(b), c(c) {}

    // operator+, return a Quadratic object
    auto operator+ (const Quadratic& addend) const -> Quadratic;

    // operator << and >> for print and read
    friend std::ostream& operator<< (std::ostream& os, const Quadratic& self);
    friend std::istream& operator>> (std::istream& is, Quadratic& self);

    // member function eval, conputing a value of a given x
    auto eval(double x) -> double;
};

auto Quadratic::operator+ (const Quadratic& addend) const -> Quadratic {
    return Quadratic(this->a + addend.a, this->b + addend.b, this->c + addend.c);
}

std::ostream& operator<< (std::ostream& os, const Quadratic& self) {
    os << self.a << "x^2 + " << self.b << "x + " << self.c;
    return os;
}

std::istream& operator>> (std::istream& is, Quadratic& self) {
    is >> self.a >> self.b >> self.c;
    if (is.fail()) throw "input fail";
    return is;
}

auto Quadratic::eval(double x) -> double {
    return this->a * x * x + this->b * x + this->c;
}

int main(void) {
    Quadratic a, b;
    int x;

    while (true) {
        try {
            std::cout << "input quadratic function ax^2 + bx + c in the form of 'a b c'\n";
            std::cout << "1st quadratic function: ";
            std::cin >> a;
            std::cout << "2nd quadratic function: ";
            std::cin >> b;
            break;
        }
        catch (const char* error) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << error << std::endl;
        }
        std::endl(std::cout);
    }

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::endl(std::cout);

    std::cout << "input a number as x: ";
    std::cin >> x;
    std::cout << "a(x) = " << a.eval(x) << std::endl;
    std::cout << "b(x) = " << b.eval(x) << std::endl;
    return 0;
}
