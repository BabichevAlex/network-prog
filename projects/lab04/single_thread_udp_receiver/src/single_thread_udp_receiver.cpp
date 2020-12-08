#include "single_thread_udp_receiver.h"
#include<cmath>

void SquareEquation(int a, int b, int c);

bool process_receive_data(SOCKET socket) {
	sockaddr_in incom_addr;
	memset(&incom_addr, 0, sizeof(incom_addr));
	socklen_t len = sizeof(incom_addr);

    while (true) {
        char buffer[30] = "";
        int mas[3];
        int rc = recvfrom(socket, buffer, sizeof(buffer), 0, (sockaddr*)&incom_addr, &len);
        if (rc > 0) {
            int len = sizeof(mas) / sizeof(mas[0]);
            int i = 0;
            char *cds = strtok(buffer, " ");

            while (cds) {
                if (i < len) {
                    mas[i++] = atoi(cds);
                }
                cds = strtok(NULL, " ");
            }

            printf("first:%d\n", mas[0]);
            printf("second:%d\n", mas[1]);
            printf("third:%d\n", mas[2]);

            SquareEquation(mas[0], mas[1], mas[2]);
        }
        else {
            break;
        }
    }

	return true;
}

void SquareEquation(int a, int b, int c){
    int d = pow(b, 2) - 4 * a * c;
    int x1, x2;

    if(d > 0){
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        printf("Solution = %d, %d\n", x1, x2);
    }
    else if(d == 0){
        x1 = (-b + sqrt(d)) / (2 * a);
        printf("Solution = %d\n", x1);
    }
    else if(d < 0){
        printf("D < 0, solution doesn't exist\n");
    }
}