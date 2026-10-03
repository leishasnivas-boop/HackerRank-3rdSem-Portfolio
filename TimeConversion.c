#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* timeConversion(char* s) {
    char* result = (char*)malloc(9 * sizeof(char));
    int hours;
    char period[3];

    // Extract hours and AM/PM indicator
    sscanf(s, "%2d:%*2c:%*2c%2s", &hours, period);

    // Convert hours based on AM/PM rules
    if (strcmp(period, "AM") == 0) {
        if (hours == 12) {
            hours = 0;
        }
    } else { // PM
        if (hours != 12) {
            hours += 12;
        }
    }

    // Format into 24-hour time (HH:MM:SS)
    snprintf(result, 9, "%02d%.6s", hours, s + 2);
    return result;
}

int main(void) {
    char s[11];
    if (scanf("%10s", s) != 1) {
        return 1;
    }

    char* result = timeConversion(s);
    printf("%s\n", result);

    free(result);
    return 0;
}