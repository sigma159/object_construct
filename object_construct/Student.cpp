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
//        cout << "������ ϲ�: ";
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
//        cout << "ϲ�: " << (fullName ? fullName : "�������") << endl;
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
//    st.setFullName("��������� �����");
//    cout << "\nϳ��� ���� ϲ�:\n";
//    st.output();
//
//    return 0;
//}
