#include <iostream>
#include "matrix.h"

int main() {
    const matrix<int> helpMatrix1({{1, 2, 123}, {3, 4, 2}, {5, 6, 7}});
//    const matrix<int> helpMatrix2({{1, 4, 0}, {3, 5, 2}, {1, 6, 3}});
//    const matrix<int>& h1ref = helpMatrix1;
//    const matrix<int>& h2ref = helpMatrix2;


    matrix<int> a({{1, 2}, {3, 4, 2}, {5, 6, 7, 8}});
    std::cout << "Matrix A initialized by initializer_list\n" << a << std::endl;
    std::cout << "Output A by iterators";
    for (auto & it : a) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    matrix<int> b = a;
    std::cout << "\nMatrix B initialized by copy A\n" << b;


    matrix<int> c(2,3);
    c.set_elem(1, 1, 1990);
    c.set_elem(1, 2, 21);
    std::cout << "\nMatrix C initialized by default constructor and 2 elements set\n" << c;


    matrix<int> d(std::move(a));
    std::cout << "Matrix D initialized by std::move\n" << d << std::endl << "Matrix A after std::move\n" << a << std::endl;

    matrix<int> e = helpMatrix1;
    std::cout << "Matrix E initialized by unary operation =\n" << e << std::endl;

//    e+=d;
//    std::cout << "Matrix E after unary operation += with matrix D\n" << e << std::endl;
//
//    e-=d;
//    std::cout << "Matrix E after unary operation -= with matrix D\n" << e << std::endl;

    matrix<int> f = d * e;
        std::cout << "Matrix F after binary operation * matrix's D and E\n" << e << std::endl;


    matrix<int> p1({{1, 2}, {3, 4}});
    matrix<int> p2({{1, 2}, {3, 4}});

    std::cout << "Matrix p1\n" << p1 << "\nMatrix p2\n" << p2 << std::endl;


    f = p1 + p2;
    std::cout << "Matrix F after binary operation + matrix's p1 and p2\n" << f << std::endl;

    f = p1 - p2;
    std::cout << "Matrix F after binary operation - matrix's p1 and p2\n" << f << std::endl;

    f = p1 + 2;
    std::cout << "Matrix F after binary operation + matrix p1 and 2\n" << f << std::endl;

    f = p1 - 2;
    std::cout << "Matrix F after binary operation - matrix p1 and 2\n" << f << std::endl;

    f = p1 * 2;
    std::cout << "Matrix F after binary operation * matrix p1 and 2\n" << f << std::endl;

    f = p1 / 2;
    std::cout << "Matrix F after binary operation / matrix p1 and 2\n" << f << std::endl;

    std::cout << "p1 matrix element (0; 0): " << p1.get_elem(0,0) << std::endl;

    std::cout << "\nCheck if F is square " << f.is_square() << " and if C is square " << c.is_square() << std::endl;

    std::cout << "\nLet's get row and column count of C: rows - " << c.get_row() << ", columns - " << c.get_columns() << std::endl;

    return 0;
}
