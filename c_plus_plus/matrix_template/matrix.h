#pragma once

#include <initializer_list>
#include <ostream>
#include <iterator>
#include <algorithm>

template <class Type>
class matrix {
public:
    matrix() : rowCount(0), columnCount(0), size(0), data(nullptr) {}

    matrix(unsigned int rowSize, unsigned int columnSize) : rowCount(rowSize), columnCount(columnSize), size(rowSize * columnSize) {
        data = new Type[size];
    }

    matrix(const matrix<Type>& other) : rowCount(other.rowCount), columnCount(other.columnCount), size(other.size) {
        data = new Type[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }


    matrix(matrix<Type>&& other) noexcept
        : rowCount(other.rowCount), columnCount(other.columnCount), size(other.size), data(other.data) {
        other.columnCount = 0;
        other.rowCount = 0;
        other.size = 0;
        other.data = nullptr;
    }


    explicit matrix(std::initializer_list<std::initializer_list<Type>> lst) {
        if (lst.size() == 0) {
            throw std::invalid_argument("Matrix cannot be constructed from an empty initializer list");
        }

        auto rows = lst.size();
        unsigned cols = 0;

        for (const auto& row : lst) {
            if (row.size() == 0) {
                throw std::invalid_argument("Matrix cannot be constructed from an initializer list with empty rows");
            }
            cols = std::max(cols, static_cast<unsigned>(row.size()));
        }

        rowCount = rows;
        columnCount = cols;
        size = rows * cols;
        data = new Type[size];

        for (unsigned i = 0u; i < rows; i++) {
            auto it = lst.begin();
            std::advance(it, i);
            for (unsigned j = 0u; j < cols; j++) {
                if (j < it->size()) {
                    data[i * columnCount + j] = *std::next(it->begin(), j);
                } else {
                    data[i * columnCount + j] = 0;
                }
            }
        }
    }

    ~matrix() {
        delete[] data;
    }


    // unary operations
    matrix<Type>& operator =(const matrix<Type>& other) {
        rowCount = other.rowCount;
        columnCount = other.columnCount;
        size = other.size;

        delete[] data;
        data = new Type[columnCount * rowCount];
        for (int i = 0; i < columnCount*rowCount; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }


    matrix<Type>& operator +=(const matrix<Type>& other) {
        if (rowCount == other.rowCount && columnCount == other.columnCount) {
            for (int i = 0; i < columnCount * rowCount; ++i) {
                this->data[i] += other.data[i];
            }
        } else {
            throw std::invalid_argument("Matrix's must have equal measures");
        }

        return *this;
    }


    matrix<Type>& operator -=(const matrix<Type>& other) {
        if (rowCount == other.rowCount && columnCount == other.columnCount) {
            for (int i = 0; i < this->size; ++i) {
                this->data[i] -= other.data[i];
            }
        } else {
            throw std::invalid_argument("Matrix's must have equal measures");
        }

        return *this;
    }


    // binary operations
    template<typename T>
    friend matrix<T> operator *(const matrix<T>& m1, const matrix<T>& m2) {
        if (m1.rowCount != m2.columnCount) {
            throw std::invalid_argument("Cannot multiply matrixes");
        }

        matrix<T> res(m1.rowCount, m2.columnCount);

        for (int row = 0; row < m1.rowCount; ++row) {
            for (int col = 0; col < m2.columnCount; ++col) {
                T ans = 0;
                for (int elem = 0; elem < m1.columnCount; ++elem) {
                    ans += elem;
                }

                res(row + 1, col + 1) = ans;
            }
        }

        return res;
    }


    template<typename T>
    friend matrix<T> operator +(const matrix<T>& m1, const matrix<T>& m2) {
        if (m1.rowCount != m2.rowCount || m1.columnCount != m2.columnCount) {
            throw std::invalid_argument("Cannot addict matrixes");
        }

        matrix<T> res(m1.rowCount, m1.columnCount);
        res = m1;
        res += m2;
        return res;
    }


    template<typename T>
    friend matrix<T> operator -( matrix<T>& m1,  matrix<T>& m2) {
        if (m1.rowCount != m2.rowCount || m1.columnCount != m2.columnCount) {
            throw std::invalid_argument("Cannot subtract matrixes");
        }

        matrix<T> res(m1.rowCount, m1.columnCount);
        res = m1;
        res -= m2;
        return res;
    }


    // binary with num
    template<typename T>
    friend matrix<T> operator +(const matrix<T>& m, double num) {
        matrix<T> res(m.rowCount, m.columnCount);
        res = m;

        for (int i = 0; i < res.size; ++i) {
            res.data[i] += num;
        }

        return res;
    }


    template<typename T>
    friend matrix<T> operator -(const matrix<T>& m, double num) {
        matrix<T> res(m.rowCount, m.columnCount);
        res = m;

        for (int i = 0; i < res.size; ++i) {
            res.data[i] -= num;
        }

        return res;
    }


    template<typename T>
    friend matrix<T> operator *(const matrix<T>& m, double num) {
        matrix<T> res(m.rowCount, m.columnCount);
        res = m;

        for (int i = 0; i < res.size; ++i) {
            res.data[i] *= num;
        }

        return res;
    }


    template<typename T>
    friend matrix<T> operator /(const matrix<T>& m, double num) {
        matrix<T> res(m.rowCount, m.columnCount);
        res = m;

        for (int i = 0; i < res.size; ++i) {
            res.data[i] /= num;
        }

        return res;
    }


    friend std::ostream& operator <<(std::ostream& os, matrix<Type>& matr) {
        for (auto i = 0u; i < matr.rowCount; ++i) {
            for (auto j = 0u; j < matr.columnCount; ++j) {
                os << matr.get_elem(i, j) << " ";
            }
            os << "\n";
        }
        return os;
    }


    friend std::ostream& operator <<(std::ostream& os, const matrix<Type>& matr) {
        for (auto i = 0u; i < matr.rowCount; ++i) {
            for (auto j = 0u; j < matr.columnCount; ++j) {
                os << matr.get_elem(i, j) << " ";
            }
            os << "\n";
        }
        return os;
    }


    void set_elem(unsigned int i, unsigned int j, const Type& elem) {
        if (i >= rowCount || j >= columnCount) {
            throw std::invalid_argument("Out of matrix bounds");
        }

        data[i * columnCount + j] = elem;
    }


    Type& get_elem(unsigned int i, unsigned int j) const {
        if (i >= rowCount || j >= columnCount) {
            throw std::invalid_argument("Out of matrix bounds");
        }

        return data[i * columnCount + j];
    }


    Type& operator ()(unsigned int i, unsigned int j) {
        i--, j--;

        if (i >= rowCount || j >= columnCount) {
            throw std::invalid_argument("Out of matrix bounds");
        }

        return data[i * rowCount + j];
    }


    bool is_square() {
        return rowCount == columnCount;
    }


     [[nodiscard]] unsigned get_row() const {
        return rowCount;
    }


    [[nodiscard]] unsigned get_columns() const {
        return columnCount;
    }


public:
    class Iterator;
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(&(data[size])); }

    friend std::ostream& operator <<(std::ostream& os, Iterator& it) {
        os << it;
        return os;
    }
private:
    unsigned int rowCount;
    unsigned int columnCount;
    unsigned int size;
    Type* data;
};

template <class T>
class matrix<T>::Iterator {
public:
    explicit Iterator(T* ptr) : data(ptr) {}
    T& operator*() const { return *data; }
    T* operator->() { return data; }
    Iterator& operator++() { data++; return *this; }
    Iterator operator++(int) { const Iterator tmp = *this; ++(*this); return tmp; }
    Iterator& operator--() { data--; return *this; }
    Iterator operator--(int) { const Iterator tmp = *this; --(*this); return tmp; }
    friend bool operator== (const Iterator& a, const Iterator& b) { return a.data == b.data; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.data != b.data; };

private:
    T* data;
};
