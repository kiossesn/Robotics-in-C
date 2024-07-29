/* Give your robot's coordinates and angle (xr, yr, theta).
 * Give coordinates (xA, yA) of point Ti of the path.
 * Give coordinates (xB, yB) of point Ti+1 of the path.
 * Get distances dn (normalized by v) and un (normalized by vn)
 */
#include <stdio.h>
#include <math.h>
double dot_product(double u[], double v[]) {
    double result = 0;
    for (int i = 0; i < 2; i++) {
        result += u[i] * v[i];
    }
    return result;
}

int main() {
    float xr, yr, xA, yA, xB, yB, theta, thetaRadians, xxA, yyA, xxB, yyB;
    printf("Give the coordinates of the robot\n");
    scanf("%f", &xr);
    scanf("%f", &yr);
    printf("Give the angle of the robot\n");
    scanf("%f", &theta);
    printf("Give the coordinates of the Ti\n");
    scanf("%f", &xA);
    scanf("%f", &yA);
    printf("Give the coordinates of the Ti+1\n");
    scanf("%f", &xB);
    scanf("%f", &yB);

    double v[2];
    v[0]=xB-xA;
    v[1]=yB-yA;
    double r[2];
    r[0]=xr-xA;
    r[1]=yr-yA;
    double vn[2];
    vn[0]=yB-yA;
    vn[1]=-(xB-xA);
    double dn= dot_product(r,vn)/ dot_product(vn,vn);
    double un= dot_product(r,v)/ dot_product(v,v);
    printf("dn = %.2f\n",dn);
    printf("un = %.2f",un);
}