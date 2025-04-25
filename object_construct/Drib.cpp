//#include <iostream>
//using namespace std;
//
//class Fraction {
//private:
//    int numerator;
//    int denominator;
//
//    int gcd(int a, int b) {
//        a = abs(a);
//        b = abs(b);
//        while (b != 0) {
//            int temp = b;
//            b = a % b;
//            a = temp;
//        }
//        return a;
//    }
//
//    void reduce() {
//        int divisor = gcd(numerator, denominator);
//        numerator /= divisor;
//        denominator /= divisor;
//
//        if (denominator < 0) {
//            numerator = -numerator;
//            denominator = -denominator;
//        }
//    }
//
//public:
//    Fraction() : numerator(0), denominator(1) {}
//
//    Fraction(int num) : numerator(num), denominator(1) {}
//
//    Fraction(int num, int den) : numerator(num), denominator(den) {
//        if (denominator == 0) {
//            cout << "Помилка: знаменник не може бути нулем. Встановлено 1." << endl;
//            denominator = 1;
//        }
//        reduce();
//    }
//
//    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}
//
//    void input() {
//        cout << "Введіть чисельник: ";
//        cin >> numerator;
//        cout << "Введіть знаменник: ";
//        cin >> denominator;
//        if (denominator == 0) {
//            cout << "Знаменник не може бути нулем. Встановлено 1 за замовчуванням." << endl;
//            denominator = 1;
//        }
//        reduce();
//    }
//
//    inline int getNumerator() const {
//        return numerator;
//    }
//
//    inline int getDenominator() const {
//        return denominator;
//    }
//
//    inline void display() const {
//        cout << numerator << "/" << denominator << endl;
//    }
//
//    Fraction add(const Fraction& other) const {
//        return Fraction(
//            numerator * other.denominator + other.numerator * denominator,
//            denominator * other.denominator
//        );
//    }
//
//    Fraction subtract(const Fraction& other) const {
//        return Fraction(
//            numerator * other.denominator - other.numerator * denominator,
//            denominator * other.denominator
//        );
//    }
//
//    Fraction multiply(const Fraction& other) const {
//        return Fraction(
//            numerator * other.numerator,
//            denominator * other.denominator
//        );
//    }
//
//    Fraction divide(const Fraction& other) const {
//        if (other.numerator == 0) {
//            cout << "Помилка: ділення на нуль! Повертається дріб 0/1." << endl;
//            return Fraction(0, 1);
//        }
//        return Fraction(
//            numerator * other.denominator,
//            denominator * other.numerator
//        );
//    }
//};
//
//int main() {
//    Fraction a(3, 4);
//    Fraction b(2);
//    Fraction c = a.multiply(b);
//
//    cout << "Дріб a: ";
//    a.display();
//
//    cout << "Дріб b: ";
//    b.display();
//
//    cout << "Добуток a * b: ";
//    c.display();
//
//    return 0;
//}
