/* Give your robot's coordinates and angle (xr, yr, theta).
 * Give robot's target coordinates (xr, yr).
 * Get robot's target robocentric coordinates. (robot's axes instead of global)
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

    printf("Robot's target in robocentric coordinates:\n");
    printf("%.1f , %.1f", xx, yy);
    return 0;
}