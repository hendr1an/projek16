/**
 * @mainpage Documentation Circular Queues
 *
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data Queues dengan pendekatan circular array.
 *
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 *
 * @section cara penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. insert
 * 2. delete
 * 3. display
 * 4. exit
 *
 * @author profil
 *  - nama : M. Gyan Hendriansyah
 *  - nim  : 20230140204
 *  - kelas: F
 *
 * @brief Circular Queue implementation with static array
 * @version 0.1
 * @date 2025-06-25
 * @copyright m.gyan.ft23@mail.umy.ac.id (c) 2025
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queue
 */
class Queues {
private:
    int FRONT;       ///< variable private front untuk menyimpan posisi depan antrian
    int REAR;        ///< variable private rear untuk menyimpan posisi belakang antrian
    static const int max = 5; ///< variable private max untuk menyimpan ukuran maksimum antrian
    int queue_array[max];     ///< variable private queue_array untuk menyimpan elemen antrian

public:
    /**
     * @brief Construct a new Queues object
     * Set default queue ke null (FRONT = -1 dan REAR = -1)
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief Method untuk memasukkan data dalam antrian
     * Data dimasukkan ke dalam variable queue_array
     */
    void insert() {
        int num; ///< variable num untuk menyimpan nilai input
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        } else {
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief Method untuk menghapus data dalam antrian
     * Data dihapuskan dari dalam variable queue_array
     */
    void remove() {
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }

        // Cetak elemen yang akan dihapus
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Cek jika hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        } else {
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief Method untuk menampilkan data dalam antrian
     * Data ditampilkan yang berada dalam variable queue_array
     */
    void display() {
        int FRONT_position = FRONT; ///< variable front_position untuk menandakan posisi element pertama
        int REAR_position = REAR;   ///< variable rear_position untuk menandakan posisi element terakhir

        // Cek apakah antrian kosong
        if (FRONT_position == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
        } else {
            // Iterasi dari FRONT ke akhir array
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            // Kembali ke awal array dan iterasi sampai REAR
            FRONT_position = 0;
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
        }
        cout << endl;
    }
};

int main() {
    Queues q;
    char ch;

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1':
                q.insert();
                break;
            case '2':
                q.remove();
                break;
            case '3':
                q.display();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid option[]" << endl;
                break;
            }
        } catch (exception &e) {
            cout << "Check for the values entered." << endl;
        }
    }
    return 0;
}
