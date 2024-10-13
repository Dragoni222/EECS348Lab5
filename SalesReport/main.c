#include <math.h>
#include <stdio.h>


int main(void) {
    FILE *file = fopen("C:/Users/joelh/Documents/CS/EECS348Lab6/SalesReport/SalesReport.txt", "r");
    if (file == NULL) {
        printf("no such file.");
        return 0;
    }
    double monthlySales[12];
    char buffer[100];
    int month = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        monthlySales[month] = atof(buffer);
        month++;
    }

    printf("Monthly Sales Report:\n");
    for (int i = 0; i < 12; i++) {
        printf("%f\n", monthlySales[i]);
    }


    int indexMinimum = 0;
    int indexMaximum = 0;
    float average = monthlySales[0];
    char monthNames[12][10] ={"January","February","March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double movingAverage[7] = {monthlySales[0],0,0,0,0,0,0};


    for (int i = 1; i < 12; i++) {
        if (monthlySales[i] > monthlySales[indexMaximum]) {
            indexMaximum  = i;
        }
        else if (monthlySales[i] < monthlySales[indexMinimum]) {
            indexMinimum  = i;
        }
        average += monthlySales[i];
        for(int j = 0; j < 7; j++) {
            if(i-j < 6 && i-j > -1) {
                movingAverage[j] += monthlySales[i];
            }
        }


    }
    average /= 12;
    printf("Sales summary report:\n");
    printf("Minimum sales: %f (%s)\n",monthlySales[indexMinimum], monthNames[indexMinimum] );
    printf("Maximum sales: %f (%s)\n",monthlySales[indexMaximum], monthNames[indexMaximum] );
    printf("Average: %f\n", truncf(average*100.0)/100.0);


    printf("Six-Month moving average report:\n");
    for(int i = 0; i < 7; i++) {
        movingAverage[i] /= 6;
        printf("%s-%s    %f\n", monthNames[i], monthNames[i+5], truncf(movingAverage[i]* 100.0)/100.0);
    }

    double decendingOrder[12] = {monthlySales[0],0,0,0,0,0,0,0,0,0,0,0};
    int decendingOrderIndex[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 1; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            if((monthlySales[i] > decendingOrder[j] && j == 0) || (monthlySales[i] > decendingOrder[j] && monthlySales[i] < decendingOrder[j - 1]) ) {
                for(int k = 10; k > j - 1; k--) {
                    decendingOrder[k+1] = decendingOrder[k];
                    decendingOrderIndex[k+1] = decendingOrderIndex[k];
                }
                decendingOrder[j] = monthlySales[i];
                decendingOrderIndex[j] = i;
                j = 12;
            }
        }
    }
    printf("Sales report (Highest to Lowest): \n");
    for(int i = 0; i < 12; i++) {
        printf("(%s) %f\n", monthNames[decendingOrderIndex[i]], decendingOrder[i]);
    }



    fclose(file);






    return 0;
}

