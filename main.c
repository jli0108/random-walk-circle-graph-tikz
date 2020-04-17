#include <stdio.h>
#include <math.h>

int main(void) {
    int i, n, r;

    /* generates TeX source code that draws a directed graph depicting
    random walk on a circle with radius r with n states using tikzpicture */

    printf("Enter number of states: ");
    scanf("%d", &n);
    printf("Enter circle radius: ");
    scanf("%d", &r);

    printf("\\begin{center}\n\\begin{tikzpicture}[->,auto,semithick]\n");


    for (i = 0; i < n; i++) {
        double x = (double) r*cos((double) (i*2*M_PI)/n);
        double y = (double) r*sin((double) (i*2*M_PI)/n);

        printf("    \\node[shape=circle,draw=black] (%d) at (%1.3lf, %1.3lf) {%d};\n", i, x, y, i);
    }
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("    \\path (%d) edge [bend right] node {} (0);\n", i);
        } else {
            printf("    \\path (%d) edge [bend right] node {} (%d);\n", i, i + 1);
        }

        if (i == 0) {
            printf("    \\path (%d) edge [bend right] node {} (%d);\n", i, n - 1);
        } else {
            printf("    \\path (%d) edge [bend right] node {} (%d);\n", i, i - 1);
        }
        
    }

    printf("\\end{tikzpicture}\n\\end{center}\n");
    return 0;
}
