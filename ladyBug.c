/* Lady-Bug.
 * Give the values of the 4 RSSI sensors of your robot (center, right, left, front).
 * Get the coordinates of the transmitter-target in robocentric (xs, ys, zs) based on Lady-Bug.
 */
#include <stdio.h>
#include <math.h>
const double r=0.5;

int main(){
    double s0, sL, sR, sF;
    // Input the sensors values
    printf("Give the 4 values of the sensors:\n");
    scanf("%lf",&s0);
    scanf("%lf",&sL);
    scanf("%lf",&sR);
    scanf("%lf",&sF);

    double beta, xs, ys, zs;
    // Calculate β^(2/3)
    beta = (2*pow(r,2.0)) / ((1.0/pow(sR,2.0/3)) + (1.0/pow(sL,2.0/3)) - (2.0/pow(s0,2.0/3)));
    //printf("beta = %.2f\n\n", beta);

    // Calculate target coordinates
    ys = (pow(r,2.0) - beta * (1.0/sF - 1.0/s0)) / (2*r);
    xs = (beta * (1.0/sF - 1.0/sR) + 2*r*ys) / (2*r);
    zs = sqrt(beta/pow(s0,2.0/3) - pow(xs,2.0) - pow(ys,2.0) );

    if(!isinf(xs) && !isinf(ys) && !isinf(zs) && !isnan(xs) && !isnan(ys) && !isnan(zs)){
        printf("(%.2f, %.2f, %.2f)",xs, ys, zs);
    }
    else{
        printf("Wrong Input");
    }
}