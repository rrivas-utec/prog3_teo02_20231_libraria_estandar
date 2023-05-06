#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
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
    deq.push_back(10);
    deq.push_back(20);
    deq.push_back(30);
    deq.push_back(40);
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
}


void ejemplo_list() {
    list<int> lst;
    print("Contenido del std::list: ", lst.begin(), lst.end());
    // Insertar al final
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    print("Contenido del std::list: ", lst.begin(), lst.end());
    auto it = lst.begin();
    lst.insert(it, 5);
    it = lst.begin() + 2;
    print("Contenido del std::list: ", lst.begin(), lst.end());
    lst.insert(it, 15);
    it = lst.begin() + 4;
    print("Contenido del std::list: ", lst.begin(), lst.end());
    lst.insert(it, 25);
    print("Contenido del std::list: ", lst.begin(), lst.end());
}

int main() {
//    ejemplo_arreglos();
//    ejemplo_vectores();
//    ejemplo_deque();
    ejemplo_list();
    return 0;
}
