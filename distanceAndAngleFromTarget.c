/* Give your robot's coordinates and angle (xr,yr,theta).
 * Give robot's target coordinates (xt,yt).
 * Get the distance and the angle your robot needs to turn to face target.
 */
#include <stdio.h>
#include <math.h>
int main(){
    float xr,yr,xt,yt,theta;
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
    // Distance calculation
    float distance=sqrt(pow(dx,2)+pow(dy,2));
    // Angle calculation
    float angle_rad=atan2(dy,dx);
    // Rad to deg
    float angle_deg=angle_rad*(180/M_PI);
    // Find angle difference
    float turn= -(theta-angle_deg);

    printf("Distance and angle your robot needs to turn to face target:\n");
    printf("%.1f %.1f",distance,turn);

    return 0;
}