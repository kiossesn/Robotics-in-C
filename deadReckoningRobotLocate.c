/* Linear Dead Reckoning.
 * Give number of movements.
 * For each move give v (velocity m/sec), t (time of movement sec) and theta (degrees of move).
 * Get the position x, y, theta after each move.
 */
#include<stdio.h>
#include<math.h>
int main(){
    int N;
    float thetaDegrees,v,t,thetaRadians;
    float x=0,y=0,th=0;
    printf("Starting position (x=0,y=0,th=0)");
    printf("Give number of movements, N: ");
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        printf("Give degrees, velocity and time:\n");
        scanf("%f %f %f",&thetaDegrees, &v, &t);
        //(x',y',th')=(v*t*cos(th),v*t*sin(th),th)
        // Deg to rad
        thetaRadians=thetaDegrees*(M_PI/180);
        // Add to the previous theta
        th=th+thetaRadians;
        // Add to the previous x
        x=x+v*t*cos(th);
        // Add to the previous y
        y=y+v*t*sin(th);
        // Rad to deg
        thetaDegrees=th*180/M_PI;

        printf("Position after move:\n");
        printf("%.1f %.1f %.1f\n",x,y,thetaDegrees);
    }

    return 0;
}
