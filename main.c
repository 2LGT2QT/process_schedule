#include<stdio.h>

int main() {
    int n, pid[50], burst[50], wait[50], ta[50], quant, prty[50], ar[50], sum = 0, ch, compl[50], temp, b2[50], flag = 0;

    printf("\nEnter the no of processes : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter the PID of Process #%d : ", i + 1);
        scanf("%d", &pid[i]);

        printf("Enter the Burst time of Process #%d : ", i + 1);
        scanf("%d", &burst[i]);

    }

    printf("\n\n1.FCFS\n2.SJF\n3.Priority\n4.Round Robin\nEnter your choice : ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    wait[i] = 0;
                    ta[i] = burst[i] + wait[i];
                } else {
                    wait[i] = wait[i - 1] + burst[i - 1];
                    ta[i] = wait[i] + burst[i];
                }
            }
            printf("\n\nPID\t\t\t Burst\t\t\t Wait Time\t\t\t Turnaround Time\n"
                   "---------------------------------------------------------------");
            for (int i = 0; i < n; i++) {
                printf("\n%d\t\t\t %d\t\t\t\t %d\t\t\t\t\t %d", pid[i], burst[i], wait[i], ta[i]);
            }

            break;


        case 2:

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (burst[i] > burst[j]) {
                        temp = burst[j];
                        burst[j] = burst[i];
                        burst[i] = temp;

                        temp = pid[j];
                        pid[j] = pid[i];
                        pid[i] = temp;
                    }
                }
            }


            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    wait[i] = 0;
                    ta[i] = burst[i] + wait[i];
                } else {
                    wait[i] = wait[i - 1] + burst[i - 1];
                    ta[i] = wait[i] + burst[i];
                }
            }


            printf("\n\nPID\t\t\t Burst\t\t\t Wait Time\t\t\t Turnaround Time\n"
                   "---------------------------------------------------------------");

            for (int i = 0; i < n; i++) {
                printf("\n%d\t\t\t %d\t\t\t\t %d\t\t\t\t\t %d", pid[i], burst[i], wait[i], ta[i]);
            }

            break;


        case 3:
            for (int k = 0; k < n; k++) {
                printf("Enter the PID of process #%d : ", pid[k]);
                scanf("%d", &prty[k]);
            }


            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (prty[i] > prty[j]) {
                        temp = prty[j];
                        prty[j] = prty[i];
                        prty[i] = temp;

                        temp = burst[j];
                        burst[j] = burst[i];
                        burst[i] = temp;

                        temp = pid[j];
                        pid[j] = pid[i];
                        pid[i] = temp;
                    }
                }
            }


            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    wait[i] = 0;
                    ta[i] = burst[i] + wait[i];
                } else {
                    wait[i] = wait[i - 1] + burst[i - 1];
                    ta[i] = wait[i] + burst[i];
                }
            }


            printf("\n\nPriority\t\t\t PID\t\t\t Burst\t\t\t Wait Time\t\t\t Turnaround Time\n"
                   "------------------------------------------------------------------------------");

            for (int i = 0; i < n; i++) {
                printf("\n%d\t\t\t\t\t %d\t\t\t\t %d\t\t\t\t %d\t\t\t\t\t %d", prty[i], pid[i], burst[i], wait[i],
                       ta[i]);
            }

            break;


        case 4:
            for (int i = 0; i < n; i++) {
                printf("\nEnter the arrival time for PID #%d : ", pid[i]);
                scanf("%d", &ar[i]);

                b2[i] = burst[i];
            }

            printf("\nEnter the Time Quantum : ");
            scanf("%d", &quant);
            while (flag == 0) {
                flag = 1;
                for (int j = 0; j < n; j++) {
                    if (b2[j] <= quant && b2[j] != 0) {
                        sum += b2[j];
                        compl[j] = sum;
                        b2[j] = 0;

                    } else if (b2[j] > quant && b2[j] != 0) {
                        sum += quant;
                        b2[j] -= quant;
                        flag = 0;
                    }

                }

            }

            printf("\n\nPID\t\t\tArrival Time\t\t\tBurst Time\t\t\tCompletion Time\t\t\tTurnaround Time\t\t\tWait time\n"
                   "-----------------------------------------------------------------------------------------------------------------");
            for (int i = 0; i < n; i++) {
                ta[i] = compl[i] - ar[i];
                wait[i] = ta[i] - burst[i];

                printf("\n%d\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d", pid[i], ar[i], burst[i], compl[i], ta[i], wait[i]);
            }


            break;
    }


    return 0;
}
