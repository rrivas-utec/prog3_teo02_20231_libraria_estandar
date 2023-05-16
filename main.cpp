#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <fstream>
using namespace std;

template <typename Iterator>
void print(const string& label, Iterator start, Iterator stop) {
    cout << label;
    for (auto it = start; it != stop; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void ejemplo_arreglos() {
    array<int, 4> arr = {10, 20, 30, 40};
    array arr2 = {100, 200, 300, 400};

    print("Contenido std::array: ", arr.begin(), arr.end());

    for (size_t i = 0; i < arr.size() + 2; ++i)
        cout << arr[i] << " ";
    cout << endl;

    for (size_t i = 0; i < arr.size(); ++i)
        cout << arr.at(i) << " ";
    cout << endl;
}


void ejemplo_vectores() {
    vector<int> vec;
    print("Contenido del std::vector: ", vec.begin(), vec.end());
    // Insertar al final
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    print("Contenido del std::vector: ", vec.begin(), vec.end());
    auto it = vec.begin();
    vec.insert(it, 5);
    it = vec.begin() + 2;
    print("Contenido del std::vector: ", vec.begin(), vec.end());
    vec.insert(it, 15);
    it = vec.begin() + 4;
    print("Contenido del std::vector: ", vec.begin(), vec.end());
    vec.insert(it, 25);
    print("Contenido del std::vector: ", vec.begin(), vec.end());
}

void ejemplo_deque() {
    deque<int> deq;
    print("Contenido del std::vector: ", deq.begin(), deq.end());
    // Insertar al final
    deq.push_back(50);
    deq.push_back(10);
    deq.push_back(60);
    deq.push_back(30);
    print("Contenido del std::deque: ", deq.begin(), deq.end());
    auto it = deq.begin();
    deq.insert(it, 5);
    it = deq.begin() + 2;
    print("Contenido del std::deque: ", deq.begin(), deq.end());
    deq.insert(it, 15);
    it = deq.begin() + 4;
    print("Contenido del std::deque: ", deq.begin(), deq.end());
    deq.insert(it, 25);
    print("Contenido del std::deque: ", deq.begin(), deq.end());
    sort(begin(deq), end(deq));
    print("Contenido del std::deque: ", deq.begin(), deq.end());
}


void ejemplo_list() {
    list<int> lst;
    print("Contenido del std::list: ", lst.begin(), lst.end());
    // Insertar al final
    lst.push_back(30);
    lst.push_back(10);
    lst.push_back(40);
    lst.push_back(20);
    print("Contenido del std::list: ", lst.begin(), lst.end());
    auto it = lst.begin();
    lst.insert(it, 5);
    it = next(begin(lst), 2);                       // lst.begin() + 2;
    print("Contenido del std::list: ", lst.begin(), lst.end());
    lst.insert(it, 15); // Deshabilitar
//    advance(it, 2)

    it = next(begin(lst), 2);                                                   // lst.begin() + 4;
    print("Contenido del std::list: ", lst.begin(), lst.end());
    lst.insert(it, 25);
    print("Contenido del std::list: ", lst.begin(), lst.end());
    lst.sort();
//    sort(begin(lst), end(lst));
    print("Contenido del std::list: ", lst.begin(), lst.end());
}


void ejemplo_iteradores() {
    vector<int> vec(10);
    iota(vec.begin(), vec.end(), 10);  // Llenar de valores consecutivo
                                                    // a partir del 10
    print("Contenido de std::vector: ", begin(vec), end(vec));

    auto it1 = begin(vec) + 3;
    cout << *it1 << endl;

    auto it2 = next(begin(vec), 3);
    cout << *it2  << endl;

    advance(it1, 1);
    cout << *it1 << endl;

    advance(it1, -1);
    cout << *it1 << endl;

    auto it3 = prev(it1, 2);
    cout << *it3 << endl;

    using iterator_type = decltype(it3);
    typename iterator_type::value_type var_int = 10;
    cout << var_int << endl;
}

template <typename Iterator>
auto average(Iterator start, Iterator stop) {
    using iterator_type = decltype(start); // decltype = obtiene el tipo de dato de start
    typename iterator_type::value_type initial = 0;
    auto total = accumulate(start, stop, initial);
    auto avg = total / distance(start, stop);
    return avg;
}

void ejemplo_promedio() {
    list<double> lst = {10.5, 20.4, 22.2};
    cout << average(begin(lst), end(lst));
}

void ejemplo_adaptador_stream() {
    fstream file("../archivo.txt");
    auto begin = istream_iterator<int>(file);
    auto end = istream_iterator<int>();
    auto total = accumulate(begin, end, 0);
    cout << total << endl;
}

int main() {
//    ejemplo_arreglos();
//    ejemplo_vectores();
//    ejemplo_deque();
//    ejemplo_list();
//    ejemplo_iteradores();
//    ejemplo_promedio();
    ejemplo_adaptador_stream();
    return 0;
}
