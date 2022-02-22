#include <stdio.h>

int main(void){
    double a1 = 0, b1 = 0, c1 = 0, d1 = 0, a2 = 0, b2 = 0,
           c2 = 0, d2 = 0, a3 = 0, b3 = 0, c3 = 0, d3 = 0;

    scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);
    scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2);
    scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3);

    double det3 = a1*b2*c3 + a2*b3*c1 + a3*b1*c2 - a1*b3*c2 - a2*b1*c3 - a3*b2*c1;

    if(det3 != 0){
        printf("One solution exists.");
        return 0;
    }

    double det3_ext = b1*c2*d3 + b2*c3*d1 + b3*c1*d2 - b1*c3*d2 - b2*c1*d3 - b3*c2*d1;
    if(det3_ext != 0){
        printf("No solutions.");
        return 0;
    }
    det3_ext = a1*c2*d3 + a2*c3*d1 + a3*c1*d2 - a1*c3*d2 - a2*c1*d3 - a3*c2*d1;
    if(det3_ext != 0){
        printf("No solutions.");
        return 0;
    }
    det3_ext = a1*b2*d3 + a2*b3*d1 + a3*b1*d2 - a1*b3*d2 - a2*b1*d3 - a3*b2*d1;
    if(det3_ext != 0){
        printf("No solutions.");
        return 0;
    }

    double det2 = b2*c3-b3*c2;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = a2*c3-a3*c2;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = a2*b3-a3*b2;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = b1*c3-b3*c1;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = a1*c3-a3*c1;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = a1*b3-a3*b1;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = b1*c2-b2*c1;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = a1*c2-a2*c1;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    det2 = a1*b2-a2*b1;
    if(det2 != 0){
        printf("Infinite number of solutions.");
        return 0;
    }

    double det2_ext = a1*d2 - a2*d1;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    det2_ext = a1*d3 - a3*d1;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    det2_ext = a2*d3 - a3*d2;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }
    det2_ext = b1*d2 - b2*d1;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    det2_ext = b1*d3 - b3*d1;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    det2_ext = b2*d3 - b3*d2;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    det2_ext = c1*d2 - c2*d1;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    det2_ext = c1*d3 - c3*d1;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    det2_ext = c2*d3 - c3*d2;
    if(det2_ext != 0){
        printf("No solutions.");
        return 0;
    }

    if(a1 != 0 || b1 != 0 || c1 != 0
     || a2 != 0 || b2 != 0 || c2 != 0
     || a3 != 0 || b3 != 0 || c3 != 0){
        printf("Ininite number of solutions");
        return 0;
    }

    if(d1 != 0 || d2 != 0 || d3 != 0){
        printf("No solutions.");
        return 0;
    }

    printf("Infinite number of solutions.");

    return 0;
}