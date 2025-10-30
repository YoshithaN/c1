#include <stdio.h>
#include <stdlib.h>

#define MAX 11 // Since maximum water is 10 liters

struct State {
    int a, b, c;              // Amounts in 10L, 7L, and 4L jugs
    struct State* parent;     // To track the path
};

struct QueueNode {
    struct State *state;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

// Create a new state
struct State* createState(int a, int b, int c, struct State *parent) {
    struct State* newState = (struct State*)malloc(sizeof(struct State));
    newState->a = a;
    newState->b = b;
    newState->c = c;
    newState->parent = parent;
    return newState;
}

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueue(struct Queue *q, struct State *state) {
    struct QueueNode *temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->state = state;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

struct State* dequeue(struct Queue *q) {
    if (q->front == NULL)
        return NULL;

    struct QueueNode *temp = q->front;
    struct State *state = temp->state;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return state;
}

// Print the path recursively
void printPath(struct State *state) {
    if (state == NULL)
        return;
    printPath(state->parent);
    printf("(%d, %d, %d)\n", state->a, state->b, state->c);
}

// Pouring logic
void pour(struct State *curr, struct Queue *q, int visited[MAX][MAX][MAX]) {
    int A = curr->a, B = curr->b, C = curr->c;
    int maxA = 10, maxB = 7, maxC = 4;

    int pourAmt;

    // A -> B
    pourAmt = (B + A > maxB) ? maxB - B : A;
    if (pourAmt > 0) {
        int na = A - pourAmt, nb = B + pourAmt, nc = C;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    // A -> C
    pourAmt = (C + A > maxC) ? maxC - C : A;
    if (pourAmt > 0) {
        int na = A - pourAmt, nb = B, nc = C + pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    // B -> A
    pourAmt = (A + B > maxA) ? maxA - A : B;
    if (pourAmt > 0) {
        int na = A + pourAmt, nb = B - pourAmt, nc = C;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    // B -> C
    pourAmt = (C + B > maxC) ? maxC - C : B;
    if (pourAmt > 0) {
        int na = A, nb = B - pourAmt, nc = C + pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    // C -> A
    pourAmt = (A + C > maxA) ? maxA - A : C;
    if (pourAmt > 0) {
        int na = A + pourAmt, nb = B, nc = C - pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }

    // C -> B
    pourAmt = (B + C > maxB) ? maxB - B : C;
    if (pourAmt > 0) {
        int na = A, nb = B + pourAmt, nc = C - pourAmt;
        if (!visited[na][nb][nc]) {
            visited[na][nb][nc] = 1;
            enqueue(q, createState(na, nb, nc, curr));
        }
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    int visited[MAX][MAX][MAX] = {0};

    struct State *start = createState(0, 7, 4, NULL);
    enqueue(&q, start);
    visited[0][7][4] = 1;

    while (!isEmpty(&q)) {
        struct State *curr = dequeue(&q);

        if (curr->b == 2 || curr->c == 2) {
            printf("\nSolution path:\n");
            printPath(curr);
            return 0;
        }

        pour(curr, &q, visited);
    }

    printf("No solution found.\n");
    return 0;
}
