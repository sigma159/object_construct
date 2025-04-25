#include <iostream>
#include <fstream>
using namespace std;

const int MAX_CONTACTS = 100;
const int PHONE_LEN = 20;
const int INFO_LEN = 100;

class Contact {
    char* name;
    char homePhone[PHONE_LEN];
    char workPhone[PHONE_LEN];
    char mobilePhone[PHONE_LEN];
    char extraInfo[INFO_LEN];

public:
    Contact(const char* initName = "", const char* home = "", const char* work = "", const char* mobile = "", const char* extra = "") {
        int len = 0;
        while (initName[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i <= len; ++i)
            name[i] = initName[i];

        copy(homePhone, home, PHONE_LEN);
        copy(workPhone, work, PHONE_LEN);
        copy(mobilePhone, mobile, PHONE_LEN);
        copy(extraInfo, extra, INFO_LEN);
    }

    ~Contact() {
        delete[] name;
    }

    void setContact(const char* newName, const char* home, const char* work, const char* mobile, const char* extra) {
        delete[] name;
        int len = 0;
        while (newName[len] != '\0') len++;
        name = new char[len + 1];
        for (int i = 0; i <= len; ++i)
            name[i] = newName[i];

        copy(homePhone, home, PHONE_LEN);
        copy(workPhone, work, PHONE_LEN);
        copy(mobilePhone, mobile, PHONE_LEN);
        copy(extraInfo, extra, INFO_LEN);
    }

    void print() const {
        cout << "ϲ�: " << name << endl;
        cout << "�������: " << homePhone << endl;
        cout << "�������: " << workPhone << endl;
        cout << "��������: " << mobilePhone << endl;
        cout << "��������� ����������: " << extraInfo << endl;
        cout << "--------------------------\n";
    }

    bool matchName(const char* searchName) const {
        int i = 0;
        while (name[i] && searchName[i]) {
            if (name[i] != searchName[i]) return false;
            i++;
        }
        return name[i] == '\0' && searchName[i] == '\0';
    }

    const char* getName() const { return name; }
    const char* getHomePhone() const { return homePhone; }
    const char* getWorkPhone() const { return workPhone; }
    const char* getMobilePhone() const { return mobilePhone; }
    const char* getExtraInfo() const { return extraInfo; }

private:
    void copy(char* dest, const char* src, int size) {
        int i = 0;
        while (i < size - 1 && src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
};

void printMenu() {
    cout << "\n1. ������ ��������\n";
    cout << "2. �������� ��� ��������\n";
    cout << "3. ����� �������� �� ϲ�\n";
    cout << "4. �������� ��������\n";
    cout << "5. �������� � ����\n";
    cout << "6. ����������� � �����\n";
    cout << "0. �����\n";
    cout << "��� ����: ";
}

int main() {
    Contact* contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (count >= MAX_CONTACTS) {
                cout << "��������� �������� ��������!\n";
                continue;
            }

            char name[100], home[PHONE_LEN], work[PHONE_LEN], mobile[PHONE_LEN], extra[INFO_LEN];

            cout << "������ ϲ�: "; cin.getline(name, 100);
            cout << "������� �������: "; cin.getline(home, PHONE_LEN);
            cout << "������� �������: "; cin.getline(work, PHONE_LEN);
            cout << "�������� �������: "; cin.getline(mobile, PHONE_LEN);
            cout << "��������� ����������: "; cin.getline(extra, INFO_LEN);

            contacts[count++] = new Contact(name, home, work, mobile, extra);

        }
        else if (choice == 2) {
            for (int i = 0; i < count; ++i)
                contacts[i]->print();

        }
        else if (choice == 3) {
            char searchName[100];
            cout << "������ ϲ� ��� ������: ";
            cin.getline(searchName, 100);

            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (contacts[i]->matchName(searchName)) {
                    contacts[i]->print();
                    found = true;
                }
            }
            if (!found) cout << "�������� �� ��������.\n";

        }
        else if (choice == 4) {
            char delName[100];
            cout << "������ ϲ� �������� ��� ���������: ";
            cin.getline(delName, 100);

            bool deleted = false;
            for (int i = 0; i < count; ++i) {
                if (contacts[i]->matchName(delName)) {
                    delete contacts[i];
                    for (int j = i; j < count - 1; ++j)
                        contacts[j] = contacts[j + 1];
                    count--;
                    deleted = true;
                    cout << "������� ���������.\n";
                    break;
                }
            }
            if (!deleted) cout << "�������� �� ��������.\n";

        }
        else if (choice == 5) {
            ofstream out("contacts.txt");
            if (!out) {
                cout << "�� ������� ������� ����.\n";
                continue;
            }

            out << count << endl;
            for (int i = 0; i < count; ++i) {
                out << contacts[i]->getName() << endl;
                out << contacts[i]->getHomePhone() << endl;
                out << contacts[i]->getWorkPhone() << endl;
                out << contacts[i]->getMobilePhone() << endl;
                out << contacts[i]->getExtraInfo() << endl;
            }

            out.close();
            cout << "��������� � ����.\n";

        }
        else if (choice == 6) {
            ifstream in("contacts.txt");
            if (!in) {
                cout << "���� �� ��������.\n";
                continue;
            }

            for (int i = 0; i < count; ++i)
                delete contacts[i];
            count = 0;

            in >> count;
            in.ignore();

            for (int i = 0; i < count; ++i) {
                char name[100], home[PHONE_LEN], work[PHONE_LEN], mobile[PHONE_LEN], extra[INFO_LEN];

                in.getline(name, 100);
                in.getline(home, PHONE_LEN);
                in.getline(work, PHONE_LEN);
                in.getline(mobile, PHONE_LEN);
                in.getline(extra, INFO_LEN);

                contacts[i] = new Contact(name, home, work, mobile, extra);
            }

            in.close();
            cout << "����������� � �����.\n";
        }

    } while (choice != 0);

    for (int i = 0; i < count; ++i)
        delete contacts[i];

    return 0;
}