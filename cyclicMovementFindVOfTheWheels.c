/* Two Wheels Differential Driving.
 * Give your robot's coordinates and angle (xr, yr, theta).
 * Give robot's target coordinates (xr, yr).
 * Get the velocity of each of the two wheels that must have in order to reach target.
 */
#include <stdio.h>
#include <math.h>

int main(){
    float xr,yr,xt,yt,theta, thetaRadians, xx, yy;
    printf("Give the coordinates of the robot\n");
    scanf("%f",&xr);
    scanf("%f",&yr);
    printf("Give the angle of the robot\n");
    scanf("%f",&theta);
    printf("Give the coordinates of the target\n");
    scanf("%f",&xt);
    scanf("%f",&yt);

    float dx=xt-xr;
    float dy=yt-yr;
    // Deg to rad
    thetaRadians=theta*(M_PI/180);
    // Find robocentric coordinates of target
    xx = dx * cos(-thetaRadians) - dy * sin(-thetaRadians);
    yy = dy * cos(-thetaRadians) + dx * sin(-thetaRadians);
    // Round numbers
    float value1 = (int)(xx * 100 + .5);
    xx=(float)value1 / 100;
    float value2 = (int)(yy * 100 + .5);
    yy=(float)value2 / 100;

    // Find radius of the circle L
    float L = (pow(xx,2) + pow(yy,2))/(2*yy);
    // Find distance between robot and target
    float D = sqrt(pow(yy,2)+ pow(xx,2));
    // Find distance from left wheel to the center of the circle
    // 0.5 is the distance between two wheels
    float r = L - 0.5/2;
    // Find theta
    float th = 2 * atan2(yy,xx);
    // Find distance that left wheel will cover
    float SL = r * th;
    // Find distance that right wheel will cover
    float SR = (r + 0.5) * th;
    // Find time of the movement
    // 1.5m/s is the initial velocity of left wheel
    // -1.5m/s if moving backwards is better to reach to target
    float t;
    if(xx>=0) t = (r*th)/1.5;
    else t = -(r*th)/1.5;
    // Find velocity of the left wheel
    float VL=SL/t;
    // Find velocity of the right wheel
    float VR=SR/t;

    //printf("xx= %.1f , yy= %.1f\n", xx, yy);
    //printf("L= %.1f, D= %.1f\n", L, D);
    //printf("r= %.1f\n", r);
    //printf("SL= %.1f, SR= %.1f\n", SL, SR);
    //printf("th= %.1f, t= %.1f\n", th, t);

    printf("velocity of each of the two wheels that must have in order to reach target:\n");
    printf("Vl=%.1f, Vr=%.1f\n", VL, VR);

}
