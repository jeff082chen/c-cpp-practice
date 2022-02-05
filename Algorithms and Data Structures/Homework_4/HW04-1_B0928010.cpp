#include <iostream>
#include <string>
#include <cmath>

template <char variable>
class polynomial {

    struct term {
        int coef, expo;
        term* next;
        term(int coef = 0, int expo = 0, term* next = nullptr): coef(coef), expo(expo), next(next) {}
        auto to_string(void) const -> std::string;
    };

    //pointer to first term
    term* head;

    // copy/move
    void copy(const polynomial<variable>&);
    void move(polynomial<variable>&);

public:

    //construct, destructor
    polynomial(void): head(nullptr) {}
    ~polynomial(void);

    // copy/move constructor/assignment operator
    polynomial(const polynomial<variable>&);
    polynomial(polynomial<variable>&&);
    auto operator= (const polynomial<variable>&) -> polynomial<variable>&;
    auto operator= (polynomial<variable>&&) -> polynomial<variable>&;

    void add_node(int, int); //insert new term
    auto to_string(void) const -> std::string;

    auto operator* (const polynomial<variable>&) const -> polynomial<variable>;
    auto operator() (int) const -> int;

    template <char var>
    friend std::ostream& operator<< (std::ostream&, const polynomial<var>&);
};

template <char variable>
polynomial<variable>::~polynomial(void) {
    //delete all the term in polynomial
    while (this->head != nullptr) {
        term* next = this->head->next;
        delete this->head;
        this->head = next;
    }
}

template <char variable>
void polynomial<variable>::copy(const polynomial<variable>& poly) {
    // a is empty
    if (!poly.head) return;

    //copy a new polynomial from a
    this->head = new term(poly.head->coef, poly.head->expo);
    term* current = this->head;

    for (term* it = poly.head->next; it; it = it->next) {
        current->next = new term(it->coef, it->expo, current->next);
    }
}

template <char variable>
void polynomial<variable>::move(polynomial<variable>& poly) {
    //move entire polynomial from a
    this->head = poly.head;
    poly.head = nullptr;
}

template <char variable>
polynomial<variable>::polynomial(const polynomial<variable>& poly): polynomial<variable>() {
    this->copy(poly);
}

template <char variable>
polynomial<variable>::polynomial(polynomial<variable>&& poly): polynomial<variable>() {
    this->move(poly);
}

template <char variable>
polynomial<variable>& polynomial<variable>::operator= (const polynomial<variable>& poly) {
    this->~polynomial<variable>();
    this->copy(poly);
    return *this;
}

template <char variable>
polynomial<variable>& polynomial<variable>::operator= (polynomial<variable>&& poly) {
    this->~polynomial<variable>();
    this->move(poly);
    return *this;
}

template <char variable>
void polynomial<variable>::add_node(int coef, int expo) {
    //ignore it if coefficient == 0
    if (!coef) return;

    //if flag == true, the new term is the first term of polynomial;
    bool flag = !this->head || this->head->expo <= expo;

    //find the correct spot for new_term
    term* current = this->head;
    if (!flag)
        while (current->next && current->next->expo > expo)
            current = current->next;

    //spot is always 1.nullptr 2.point to a term <= new term
    term*& spot = flag ? this->head : current->next;

    //if spot is a nullptr or pointed to a term lower then the new term
    if (!spot || spot->expo < expo) {
        spot = new term(coef, expo, spot);
        return;
    }

    //combine terms that has same exponencial
    if (spot->coef += coef) return;

    //if coefficient == 0, remove it
    term* temp = spot;
    spot = spot->next;
    delete temp;
}

template <char variable>
std::string polynomial<variable>::to_string(void) const {
    std::string str = "";
    term* current = this->head;

    //if polynomial is empty
    if (!current) return "0";

    //first term
    if (current->coef < 0) str += "-";
    str += current->to_string();
    current = current->next;

    //rest of the polynomial
    while (current) {
        str += current->coef > 0 ? " + " : " - ";
        str += current->to_string();
        current = current->next;
    }

    return str;
}

template <char variable>
polynomial<variable> polynomial<variable>::operator* (const polynomial<variable>& multiplier) const {

    polynomial<variable> product;

    //iterate through the two multiplier
    //and insert the multiply result of each term
    for (term* i = this->head; i; i = i->next) {
        for (term* j = multiplier.head; j; j = j->next) {
            product.add_node(i->coef * j->coef, i->expo + j->expo);
        }
    }
    return product;
}

template <char variable>
int polynomial<variable>::operator() (int var) const {

    int res = 0;
    for (term* it = this->head; it; it = it->next) {
        res += it->coef * std::pow(var, it->expo);
    }
    return res;
}

template <char variable>
std::ostream& operator<< (std::ostream& os, const polynomial<variable>& poly) {

    os << poly.to_string();
    return os;
}

template <char variable>
std::string polynomial<variable>::term::to_string(void) const {

    if (!this->expo) { //constant term
        return std::to_string(std::abs(this->coef));
    }

    std::string str = "";

    //ignore coefficient if it's 1 or -1
    if (this->coef != 1 && this->coef != -1) str += std::to_string(std::abs(this->coef));

    //add the variable
    str.append(1, variable);

    //ignore exponencial if it's 1
    if (this->expo != 1) str += "^" + std::to_string(this->expo);

    return str;
}

int main(void) {

    int n, c, e;
    polynomial<'x'> a, b;

    std::cout << "input the amount of terms of first polynomial: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "no." << i + 1 << " term(coef, expo): ";
        std::cin >> c >> e;
        a.add_node(c, e);
    }
    std::endl(std::cout);

    std::cout << "input the amount of terms of second polynomial: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "no." << i + 1 << " term(coef, expo): ";
        std::cin >> c >> e;
        b.add_node(c, e);
    }
    std::endl(std::cout);

    polynomial<'x'> m;
    m = a * b;
    std::cout << "first polynomial:\n";
    std::cout << a << std::endl;
    std::cout << "second polynomial:\n";
    std::cout << b << std::endl;
    std::cout << "result:\n";
    std::cout << m << std::endl;
    return 0;
}
