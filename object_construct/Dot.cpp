//#include <iostream>
//#include <fstream>
//using namespace std;
//
//class Point {
//private:
//    double x, y, z;
//
//public:
//    void input() {
//        cout << "Введіть координати X, Y, Z: ";
//        cin >> x >> y >> z;
//    }
//
//    void output() const {
//        cout << "Координати точки: X = " << x << ", Y = " << y << ", Z = " << z << endl;
//    }
//
//    double getX() const { return x; }
//    double getY() const { return y; }
//    double getZ() const { return z; }
//
//    void setX(double value) { x = value; }
//    void setY(double value) { y = value; }
//    void setZ(double value) { z = value; }
//
//    void saveToFile(const string& filename) const {
//        ofstream file(filename);
//        if (file.is_open()) {
//            file << x << " " << y << " " << z;
//            file.close();
//            cout << "Дані збережено у файл \"" << filename << "\".\n";
//        }
//        else {
//            cout << "Не вдалося відкрити файл для запису.\n";
//        }
//    }
//
//    void loadFromFile(const string& filename) {
//        ifstream file(filename);
//        if (file.is_open()) {
//            file >> x >> y >> z;
//            file.close();
//            cout << "Дані завантажено з файлу \"" << filename << "\".\n";
//        }
//        else {
//            cout << "Не вдалося відкрити файл для читання.\n";
//        }
//    }
//};
//
//int main() {
//    Point p;
//    p.input();
//    p.output();
//
//    p.saveToFile("point.txt");
//
//    Point anotherPoint;
//    anotherPoint.loadFromFile("point.txt");
//    anotherPoint.output();
//
//    return 0;
//}
//
