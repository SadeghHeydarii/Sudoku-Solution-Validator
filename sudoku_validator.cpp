#include <iostream>
#include <pthread.h>
using namespace std;

int arr[9][9];
bool ans = 1;
pthread_mutex_t lock;

void* check_rows(void* arg) {
    bool isSeen[9] = {0};
    for (int i = 0; i < 9; i++) {
        fill(isSeen, isSeen + 9, 0);
        for (int j = 0; j < 9; j++) {
            if (!isSeen[arr[i][j] - 1]) {
                isSeen[arr[i][j] - 1] = 1;
            } else {
                pthread_mutex_lock(&lock);
                ans = 0;
                pthread_mutex_unlock(&lock);
                pthread_exit(NULL);
            }
        }
    }
    pthread_exit(NULL);
}

void* check_cols(void* arg) {
    bool isSeen[9] = {0};
    for (int i = 0; i < 9; i++) {
        fill(isSeen, isSeen + 9, 0);
        for (int j = 0; j < 9; j++) {
            if (!isSeen[arr[j][i] - 1]) {
                isSeen[arr[j][i] - 1] = 1;
            } else {
                pthread_mutex_lock(&lock);
                ans = 0;
                pthread_mutex_unlock(&lock);
                pthread_exit(NULL);
            }
        }
    }
    pthread_exit(NULL);
}

void* check_box(void* arg) {
    int num = *(int*)arg;
    int start_row = (num / 3) * 3;
    int start_col = (num % 3) * 3;
    bool isSeen[9] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!isSeen[arr[start_row+i][start_col+j] - 1]) {
                isSeen[arr[start_row+i][start_col+j] - 1] = 1;
            } else {
                pthread_mutex_lock(&lock);
                ans = 0;
                pthread_mutex_unlock(&lock);
                pthread_exit(NULL);
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    const int NUM_THREADS = 11;
    pthread_t threads[NUM_THREADS];
    int indices[9]; // آرایه‌ی جدا برای شماره مربع‌ها

    // مقداردهی ماتریس
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    pthread_mutex_init(&lock, NULL);

    pthread_create(&threads[0], NULL, check_cols, NULL);
    pthread_create(&threads[1], NULL, check_rows, NULL);

    for (int i = 0; i < 9; i++) {
        indices[i] = i; // مقداردهی جدا
        pthread_create(&threads[i+2], NULL, check_box, (void*)&indices[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    cout << ans << endl;

    return 0;
}
