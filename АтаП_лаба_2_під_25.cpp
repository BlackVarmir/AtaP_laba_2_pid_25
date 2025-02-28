#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

void sortEvenAscending(int** pointers, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*pointers[j] > *pointers[j + 1]) {
                // Ручний обмін значень
                int temp = *pointers[j];
                *pointers[j] = *pointers[j + 1];
                *pointers[j + 1] = temp;
            }
        }
    }
}

void sortOddDescending(int** pointers, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*pointers[j] < *pointers[j + 1]) {
                // Ручний обмін значень
                int temp = *pointers[j];
                *pointers[j] = *pointers[j + 1];
                *pointers[j + 1] = temp;
            }
        }
    }
}


void Task1() {
    srand(time(0));

    int n;
    cout << "Введіть розмір масиву (n >= 2): ";
    cin >> n;

    if (n < 2) {
        cerr << "Помилка: масив замалий для елементів з парними номерами.\n";
		return;
    }

    double* arr = new double[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = (rand() % 2001 - 1000) / 100.0; 
    }

    cout << "Згенерований масив: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    double* min_ptr = &arr[1];
    for (double* p = arr + 3; p < arr + n; p += 2) {
        if (*p < *min_ptr) {
            min_ptr = p;
        }
    }

    cout << "Мінімальний елемент серед парних номерів: " << *min_ptr << "\n";

    delete[] arr;
}

void Task2() {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    if (n < 3) {
        cout << "Масив замалий для пошуку трійок." << endl;
        return;
    }

    double* arr = new double[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) / 100.0;
    }

    cout << "Згенерований масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    double* start = arr;
    double* end = arr + (n - 3);
    bool found = false;

    cout << "Знайдені ділянки:" << endl;
    for (double* p = start; p <= end; p++) {
        if (p[0] > p[1] && p[1] > p[2]) {
            int position = p - arr;
            cout << "Позиція " << position + 1 << ": ";
            cout << p[0] << " > " << p[1] << " > " << p[2] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Ділянок з трьома спадаючими елементами не знайдено." << endl;
    }

    delete[] arr; 
}

void Task3() {
    int n;
    cout << "Введіть розмір масиву n: ";
    cin >> n;

    if (n <= 1) {
        cout << "Масив замалий для порівняння сусідів." << endl;
        return;
    }

    int* arr = new int[n];
    int* indices = new int[n - 1];
    int count = 0;

    srand(time(0));

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }

    cout << "Згенерований масив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* ptr = arr + 1;
    for (int i = 1; i < n; ++i, ++ptr) {
        if (*ptr > *(ptr - 1)) {
            indices[count] = i + 1;
            count++;
        }
    }

    cout << "Кількість елементів: " << count << endl;
    cout << "Номери елементів: ";
    for (int j = 0; j < count; ++j) {
        cout << indices[j] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] indices;
}

void Task4() {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    int* arr = new int[n];
    srand(time(nullptr));

    for (int* ptr = arr; ptr < arr + n; ptr++) {
        *ptr = rand() % 100 - 50;
    }

    cout << "Згенерований масив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int count = 0;
    for (int* ptr = arr; ptr < arr + n; ptr++) {
        if (*ptr < 0) count++;
    }

    int** addresses = new int* [count];
    int index = 0;

    for (int* ptr = arr; ptr < arr + n; ptr++) {
        if (*ptr < 0) {
            addresses[index++] = ptr;
        }
    }

    cout << "Кількість елементів менших за 0: " << count << endl;
    if (count > 0) {
        cout << "Адреси: ";
        for (int i = 0; i < count; i++) {
            cout << addresses[i] << " ";
        }
        cout << endl;
    }

    delete[] arr;
    delete[] addresses;
}

void Task5() {
    srand(time(0));

    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    double* arr = new double[n];

    for (double* p = arr; p < arr + n; p++) {
        if (rand() % 2 == 0) {
            *p = (rand() % 20) * 5.0;
        }
        else {
            *p = (rand() % 100) + 1.0;
        }
    }

    cout << "Початковий масив:\n";
    for (double* p = arr; p < arr + n; p++) {
        cout << *p << " ";
    }
    cout << endl;

    double* sums = new double[n];
    int sum_count = 0;
    double current_sum = 0.0;

    for (double* p = arr; p < arr + n; p++) {
        if (*p == 0 || fmod(*p, 5.0) == 0) {
            sums[sum_count++] = current_sum;
        }
        current_sum += *p;
    }

    int new_size = n + sum_count;
    double* new_arr = new double[new_size];

    double* src = arr;
    double* dest = new_arr;
    int sum_index = 0;

    while (src < arr + n) {
        *dest = *src;
        dest++;

        if (*src == 0 || fmod(*src, 5.0) == 0) {
            if (sum_index < sum_count) {
                *dest = sums[sum_index];
                dest++;
                sum_index++;
            }
        }
        src++;
    }

    cout << "Результуючий масив:\n";
    for (double* p = new_arr; p < new_arr + new_size; p++) {
        cout << *p << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] sums;
    delete[] new_arr;
}

void Task6() {
    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    int* arr = new int[n];
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Початковий масив:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n\n";

    int even_count = n / 2;
    int odd_count = (n + 1) / 2;

    int** even_ptrs = new int* [even_count];
    int** odd_ptrs = new int* [odd_count];

    for (int i = 0, e = 0, o = 0; i < n; i++) {
        if (i % 2 == 1) even_ptrs[e++] = &arr[i];
        else odd_ptrs[o++] = &arr[i];
    }

    sortEvenAscending(even_ptrs, even_count);
    sortOddDescending(odd_ptrs, odd_count);

    cout << "Результат:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    delete[] even_ptrs;
    delete[] odd_ptrs;
    delete[] arr;
}

int main() {
    while (true) {

		cout << "Виберіть завдання (1-6) або 0 для виходу: ";
    int in;
    cin >> in;

		if (in == 0) {
			break;
		}

    switch (in) {
    case 1:
        Task1();
			cout << endl;
        break;
	case 2:
		Task2();
			cout << endl;
		break;
    case 3:
        Task3();
			cout << endl;
        break;
	case 4:
		Task4();
			cout << endl;
		break;
	case 5:
		Task5();
			cout << endl;
		break;
	case 6:
		Task6();
			cout << endl;
		break;
    default:
        cout << "Невірний вибір! Введіть 1, 2, 3, 4, 5 або 6 щоб вибрати завдання" << endl;
        break;
    }
    }

    return 0;
}