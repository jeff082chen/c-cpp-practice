#include<iostream>

class Currency {
    
protected:
    
    int x1, x2, x3, x4;
    
public:
    
    Currency(void): x1(10), x2(10), x3(10), x4(10) {}
    
    int getX1(void) { return x1; };
    int getX2(void) { return x2; };
    int getX3(void) { return x3; };
    int getX4(void) { return x4; };
    
    void setBankNotes(int x1, int x2, int x3, int x4) {
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
        this->x4 = x4;
    }
    
    int total(void) {
        return x1 * 100 + x2 * 500 + x3 * 1000 + x4 * 2000;
    }
};

class Japan : public Currency {
    
    double rate;
    int y1, y2, y3;
    
public:
    
    Japan(void): y1(0), y2(0), y3(0), rate(0.26) {}
    
    int getY1(void) { return y1; };
    int getY2(void) { return y2; };
    int getY3(void) { return y3; };
    
    void setRate(double rate) {
        this->rate = rate;
    }
    
    double getAmount(void) {
        y1 = y2 = y3 = 0;
        double amount = total() / rate;
        double temp = amount;
        while (amount >= 10000) {
            ++y3;
            amount -= 10000;
        }
        while (amount >= 5000) {
            ++y2;
            amount -= 5000;
        }
        while (amount >= 1000) {
            ++y1;
            amount -= 1000;
        }
        return temp;
    }
};

class China : public Currency {
    
    double rate;
    int z1, z2, z3, z4, z5, z6;
    
public:
    
    China(void): z1(0), z2(0), z3(0), z4(0), z5(0), z6(0), rate(4.3) {}
    
    int getZ1(void) { return z1; };
    int getZ2(void) { return z2; };
    int getZ3(void) { return z3; };
    int getZ4(void) { return z4; };
    int getZ5(void) { return z5; };
    int getZ6(void) { return z6; };
    
    void setRate(double rate) {
        this->rate = rate;
    }
    
    double getAmount(void) {
        z1 = z2 = z3 = z4 = z5 = z6 = 0;
        double amount = total() / rate;
        double temp = amount;
        while (amount >= 100) {
            ++z6;
            amount -= 100;
        }
        while (amount >= 50) {
            ++z5;
            amount -= 50;
        }
        while (amount >= 20) {
            ++z4;
            amount -= 20;
        }
        while (amount >= 10) {
            ++z3;
            amount -= 10;
        }
        while (amount >= 5) {
            ++z2;
            amount -= 5;
        }
        z1 = amount;
        return temp;
    }
};

int main(void) {
    Japan j;
    China c;
    std::cout << "initial value:\n";
    std::cout << "NT$" << j.total() << " in total\n";
    std::cout << "NT2000: " << j.getX4() << '\n';
    std::cout << "NT1000: " << j.getX3() << '\n';
    std::cout << "NT500: " << j.getX2() << '\n';
    std::cout << "NT100: " << j.getX1() << '\n';
    std::endl(std::cout);
    std::cout << "after conversion to JP:\n";
    std::cout << "￥" << (int)j.getAmount() << " in total\n";
    std::cout << "￥10000: " << j.getY3() << '\n';
    std::cout << "￥5000: " << j.getY2() << '\n';
    std::cout << "￥1000: " << j.getY1() << '\n';
    std::endl(std::cout);
    std::cout << "after conversion to CH:\n";
    std::cout << "B￥" << (int)c.getAmount() << " in total\n";
    std::cout << "B￥100: " << c.getZ6() << '\n';
    std::cout << "B￥50: " << c.getZ5() << '\n';
    std::cout << "B￥20: " << c.getZ4() << '\n';
    std::cout << "B￥10: " << c.getZ3() << '\n';
    std::cout << "B￥5: " << c.getZ2() << '\n';
    std::cout << "B￥1: " << c.getZ1() << '\n';
    std::endl(std::cout);
    
    int x1, x2, x3, x4;
    std::cout << "How many NT2000 do you have? ";
    std::cin >> x4;
    std::cout << "How many NT1000 do you have? ";
    std::cin >> x3;
    std::cout << "How many NT500 do you have? ";
    std::cin >> x2;
    std::cout << "How many NT100 do you have? ";
    std::cin >> x1;
    j.setBankNotes(x1, x2, x3, x4);
    c.setBankNotes(x1, x2, x3, x4);
    
    std::endl(std::cout);
    std::cout << "after set the new value:\n";
    std::cout << "NT$" << j.total() << " in total\n";
    std::cout << "NT2000: " << j.getX4() << '\n';
    std::cout << "NT1000: " << j.getX3() << '\n';
    std::cout << "NT500: " << j.getX2() << '\n';
    std::cout << "NT100: " << j.getX1() << '\n';
    std::endl(std::cout);
    std::cout << "after conversion to JP:\n";
    std::cout << "￥" << (int)j.getAmount() << " in total\n";
    std::cout << "￥10000: " << j.getY3() << '\n';
    std::cout << "￥5000: " << j.getY2() << '\n';
    std::cout << "￥1000: " << j.getY1() << '\n';
    std::endl(std::cout);
    std::cout << "after conversion to CH:\n";
    std::cout << "B￥" << (int)c.getAmount() << " in total\n";
    std::cout << "B￥100: " << c.getZ6() << '\n';
    std::cout << "B￥50: " << c.getZ5() << '\n';
    std::cout << "B￥20: " << c.getZ4() << '\n';
    std::cout << "B￥10: " << c.getZ3() << '\n';
    std::cout << "B￥5: " << c.getZ2() << '\n';
    std::cout << "B￥1: " << c.getZ1() << '\n';
    return 0;
}
