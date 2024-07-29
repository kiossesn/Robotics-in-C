/* Give the number of robot's sensors (N).
 * Give the data of each sensor (D).
 * Get the coordinates of the found obstacle in robocentric (x,y).
 */
#include<stdio.h>
#include <math.h>
const double R=0.5;
const double RANGE=2.0;

void findObstacleCoordinates(int sensor_number, int total_sensors, double distance) {
    // Find angle between every sensor
    double angle = (double )sensor_number / total_sensors * 360.0;
    //printf("Angle= %f\n",angle);

    // Deg to rad
    double angleRadians=angle*(M_PI/180);

    // Find coordinates in robocentric
    double x = (distance+R) * cos(angleRadians);
    double y = (distance+R) * sin(angleRadians);

    printf("%.1f %.1f\n", x, y);
}

int main(){
    int N;
    printf("Give number of sensors: ");
    scanf("%d",&N);

    double val[N], D;

    printf("Give data of each sensor: ");
    for(int i=0; i<N; i++){
        scanf("%lf",&D);
        val[i]=D;
    }

    for (int i = 0; i < N; i++) {
        // Ignore values out of range
        if (val[i] < RANGE) {
            findObstacleCoordinates(i, N, val[i]);
        }
    }

}