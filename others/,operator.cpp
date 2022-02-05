#include <iostream>
#include <vector>

using std::vector;
using std::move;
using std::for_each;
using std::cout;
using std::endl;

template<typename T>
struct vector_maker {
    vector<T> vec;
    
    auto operator, (const T& val) -> vector_maker& {
        vec.push_back(val);
        return *this;
    }
    
    auto operator() (void) -> std::vector<T> {
        return move(vec);
    }
    
    auto operator() (vector<int>& vec) {
        vec = move(this->vec);
    }
};

auto main(void) -> int {
    auto a = (vector_maker<int>(), 1, 2, 3, 4, 5, 6, 7)();
    for_each(a.begin(), a.end(), [](auto num){ cout << num << ' '; });
    endl(cout);
    
    vector<int> b;
    (vector_maker<int>(), 10, 20, 30, 40, 50)(b);
    for_each(b.begin(), b.end(), [](auto num){ cout << num << ' '; });
    endl(cout);
    return 0;
}
