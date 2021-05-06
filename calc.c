#include <stdio.h>
#include <math.h>
int main(void){
        printf("\n");
        printf("=== Calculator ===");
        printf("\n");

        char c;
        int runningTotal = 0;
        int operation = 0;

        while(c!=EOF) {
                c = getchar();
                int total = 0;
                if(c>=49 && c<=57) {
                        while(c!=10 && c!=EOF) {
                                if(c>=48 && c<=57) {
                                        while(c>=48 && c<=57) {
                                                int newNumber = c -48;
                                                total = total*10;
                                                total = total + newNumber;
                                                c = getchar();
                                        }
                                if(operation!=0)
                                        runningTotal = execute(operation, runningTotal, total);
                                        operation = 0;
                                }
                                if(runningTotal==0) {
                                        runningTotal = total;
                                        total = 0;
                                }
                                if(c=='+') {
                                        operation = 43;
                                        c = getchar();
                                }
                                else if(c=='-') {
                                        operation = 45;
                                        c = getchar();
                                }
                                else if(c=='*') {
                                        operation = 42;
                                        c = getchar();
                                }
                                else if(c=='/') {
                                        operation = 47;
                                        c = getchar();
                                }
                                else if(c=='^') {
                                        operation = 94;
                                        c = getchar();
                                }
                                else if(c=='%') {
                                        operation = 37;
                                        c = getchar();
                                }
                                if(c==' ')
                                        c = getchar();

                        }
                }
                else if(c==48) {
                        c = getchar();
                        if(c==120 || c==88) {
                                c = getchar();
                                while(c!=10 && c!=EOF) {
                                        char str[50];
                                        int hold = 0;
                                        while(c>=48 && c<=57 || c>=65 && c<=70) {
                                                str[hold] = c;
                                                hold++;
                                                c = getchar();
                                        }
                                        total = convertHex(str, hold);
                                        if(operation!=0)
                                                runningTotal = execute(operation, runningTotal, total);
                                                operation = 0;
                                        }
                                        if(runningTotal==0) {
                                                runningTotal = total;
                                                total = 0;
                                        }
                                        if(c=='+') {
                                                operation = 43;
                                                c = getchar();
                                        }
                                        else if(c=='-') {
                                                operation = 45;
                                                c = getchar();
                                        }
                                        else if(c=='*') {
                                                operation = 42;
                                                c = getchar();
                                        }
                                        else if(c=='/') {
                                                 operation = 47;
                                                 c = getchar();
                                        }
                                        if(c==' ')
                                                c = getchar();

                        }
                        else if(c==66 || c==98) {
                                c = getchar();
                                while(c!=10 && c!=EOF) {
                                        char str[50];
                                        int hold = 0;
                                        while(c>=48 && c<=57 || c>=65 && c<=70) {
                                                str[hold] = c;
                                                hold++;
                                                c = getchar();
                                        }
                                        total = convertBinary(str, hold);
                                        if(operation!=0)
                                                runningTotal = execute(operation, runningTotal, total);
                                                operation = 0;
                                        }
                                        if(runningTotal==0) {
                                                runningTotal = total;
                                                total = 0;
                                        }
                                        if(c=='+') {
                                                operation = 43;
                                                c = getchar();
                                        }
                                        else if(c=='-') {
                                                operation = 45;
                                                c = getchar();
                                        }
                                        else if(c=='*') {
                                                operation = 42;
                                                c = getchar();
                                        }
                                        else if(c=='/') {
                                                 operation = 47;
                                                 c = getchar();
                                        }
                                        if(c==' ')
                                                c = getchar();

                        }
                        else {
                                printf("ERROR: expected number.\n");
                        }
                }
                if(c!=EOF) {
                        printf("= ");
                        printf("%d", runningTotal);
                        printf("\n");
                        runningTotal = 0;
                }
        }
}

int execute(int op, int run, int tot) {
        if(op==43) {
                run+=tot;
                return run;
        }
        else if(op==45) {
                run-=tot;
                return run;
        }
        else if(op==42) {
                run = run * tot;
                return run;
        }
        else if(op==47) {
                run = run/tot;
                return run;
        }
        else if(op==37) {
                run = run%tot;
                return run;
        }
        else if(op==94) {
                run = pow(run,tot);
                return run;
        }
}

int convertHex(char str[], int num) {
        int x;
        int power = 0;
        int number;
        int total = 0;
        int q = 0;
        for(x = num-1; x>=0; x--) {
                int w;
                if(str[x]>=65 && str[x]<=70)
                        w = str[x] - 55;
                else
                        w = str[x] -  48;
                q = w * (pow(16,power));
                total+=q;
                power++;
        }
        return total;
}

int convertBinary(char str[], int num) {
        int x;
        int power = 0;
        int number;
        int total = 0;
        int q = 0;
        for(x = num-1; x>=0; x--) {
                int w = str[x] - 48;
                q = w  * (pow(2,power));
                total+=q;
                power++;
        }
        return total;
}
