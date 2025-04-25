//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Student {
//private:
//    char* fullName;
//
//public:
//    Student() {
//        fullName = nullptr;
//    }
//
//    Student(const char* name) {
//        int len = strlen(name);
//        fullName = new char[len + 1];
//        for (int i = 0; i <= len; ++i) {
//            fullName[i] = name[i];
//        }
//    }
//
//    ~Student() {
//        delete[] fullName;
//    }
//
//    void input() {
//        char buffer[100];
//        cout << "Введіть ПІБ: ";
//        cin.ignore();
//        cin.getline(buffer, 100);
//
//        int len = strlen(buffer);
//        delete[] fullName;
//        fullName = new char[len + 1];
//        for (int i = 0; i <= len; ++i) {
//            fullName[i] = buffer[i];
//        }
//    }
//
//    void output() const {
//        cout << "ПІБ: " << (fullName ? fullName : "невідомо") << endl;
//    }
//
//    void setFullName(const char* name) {
//        delete[] fullName;
//        int len = strlen(name);
//        fullName = new char[len + 1];
//        for (int i = 0; i <= len; ++i) {
//            fullName[i] = name[i];
//        }
//    }
//
//    const char* getFullName() const {
//        return fullName;
//    }
//};
//
//int main() {
//    Student st;
//    st.input();
//    st.output();
//
//    st.setFullName("Коваленко Ірина");
//    cout << "\nПісля зміни ПІБ:\n";
//    st.output();
//
//    return 0;
//}
