/* MOVE2GOAL
 * Give the coordinates of your robot (xr,yr,theta) and the target (xt,yt) (in global system).
 * Get the vector of movement to the goal.
 * If the distance between robot and target is <= 0.5 the vector measure should be equal to the distance.
 * If the distance between robot and target is > 0.5 the vector measure should be equal to 0.5.
 */
#include<stdio.h>
#include<math.h>

int main(){
    float xr,yr,xt,yt,theta;
    //printf("Give the coordinates of the robot\n");
    scanf("%f",&xr);
    scanf("%f",&yr);
    //printf("Give the angle of the robot\n");
    scanf("%f",&theta);
    //printf("Give the coordinates of the target\n");
    scanf("%f",&xt);
    scanf("%f",&yt);
    //printf("xr = %.2f, yr = %.2f, xt = %.2f, yt= %.2f\n",xr,yr,xt,yt);

    // Deg to rad
    double thetaRadians=theta*(M_PI/180);
    //printf("%f\n", thetaRadians);
    //printf("atan = %.2f\n", atan2(yt-yr,xt-xr));

    // Find the distance between robot and target
    double d = sqrt(pow((xt-xr),2.0)+pow((yt-yr),2.0));
    //printf("d = %f\n",d);

    // Find the angle of move2goal vector
    double phi = atan2(yt-yr,xt-xr) - thetaRadians;
    //printf("phi = %.2f\n", phi);

    if(d<=0.5){
        double dx = d * cos(phi);
        double dy = d * sin(phi);
        printf("%.2f,%.2f",dx,dy);
    }
    else{
        double dx = 0.5 * cos(phi);
        double dy = 0.5 * sin(phi);
        printf("%.2f,%.2f",dx,dy);
    }

}