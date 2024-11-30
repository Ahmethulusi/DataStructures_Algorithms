

// Bağlı Liste  

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int veri;
    struct Node* sonraki;
};

void ekle(struct Node** bas, int veri) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    yeni->veri = veri;
    yeni->sonraki = *bas;
    *bas = yeni;
}

void yazdir(struct Node* bas) {
    struct Node* temp = bas;
    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }
}

int main() {
    struct Node* bas = NULL;

    ekle(&bas, 5);
    ekle(&bas, 10);
    ekle(&bas, 15);

    yazdir(bas);

    return 0;
}

// Yığın (Stack)

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Stack {
    int dizi[MAX];
    int ust;
};

void init(struct Stack* s) {
    s->ust = -1;
}

int isFull(struct Stack* s) {
    return s->ust == MAX - 1;
}

int isEmpty(struct Stack* s) {
    return s->ust == -1;
}

void push(struct Stack* s, int veri) {
    if (!isFull(s)) {
        s->dizi[++(s->ust)] = veri;
    }
    else {
        printf("Yığın dolu!\n");
    }
}

int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->dizi[(s->ust)--];
    }
    else {
        printf("Yığın boş!\n");
        return -1; // Hata durumu
    }
}

int main() {
    struct Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Pop: %d\n", pop(&s));
    printf("Pop: %d\n", pop(&s));

    return 0;
}

// Kuyruk (Queu)

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Queue {
    int dizi[MAX];
    int on, arka;
};

void init(struct Queue* q) {
    q->on = -1;
    q->arka = -1;
}

int isFull(struct Queue* q) {
    return (q->arka + 1) % MAX == q->on;
}

int isEmpty(struct Queue* q) {
    return q->on == -1;
}

void enqueue(struct Queue* q, int veri) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->on = 0;
        }
        q->arka = (q->arka + 1) % MAX;
        q->dizi[q->arka] = veri;
    }
    else {
        printf("Kuyruk dolu!\n");
    }
}

int dequeue(struct Queue* q) {
    if (!isEmpty(q)) {
        int veri = q->dizi[q->on];
        if (q->on == q->arka) {
            q->on = q->arka = -1; // Kuyruğu boşalt
        }
        else {
            q->on = (q->on + 1) % MAX;
        }
        return veri;
    }
    else {
        printf("Kuyruk boş!\n");
        return -1; // Hata durumu
    }
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    return 0;
}


// Binary Search (İkili Arama)

#include <stdio.h>

int binarySearch(int dizi[], int boyut, int hedef) {
    int sol = 0, sag = boyut - 1;

    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;

        if (dizi[orta] == hedef) {
            return orta; // Hedef bulundu
        }
        if (dizi[orta] < hedef) {
            sol = orta + 1;
        }
        else {
            sag = orta - 1;
        }
    }
    return -1; // Hedef bulunamadı
}

int main() {
    int dizi[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int boyut = sizeof(dizi) / sizeof(dizi[0]);
    int hedef = 7;

    int sonuc = binarySearch(dizi, boyut, hedef);
    if (sonuc != -1) {
        printf("Hedef %d dizinin %d. indeksinde bulundu.\n", hedef, sonuc);
    }
    else {
        printf("Hedef bulunamadı.\n");
    }

    return 0;
}


// Bubble Sort Sıralama Algoritması

#include <stdio.h>

void bubbleSort(int dizi[], int boyut) {
    for (int i = 0; i < boyut - 1; i++) {
        for (int j = 0; j < boyut - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                // Değiştir
                int temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

int main() {
    int dizi[] = { 64, 34, 25, 12, 22, 11, 90 };
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    bubbleSort(dizi, boyut);

    printf("Sıralı dizi: \n");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

