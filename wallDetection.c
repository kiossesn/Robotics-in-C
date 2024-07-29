/* Wall detection.
 * Give the number of distance sensors (N) of a cylindrical robot (R=radius).
 * Give the value of each sensor (val[i]).
 * Get "YES" if the robot detects a wall, otherwise get "NO".
 * "YES": 1) Two consecutive values are valid (< RANGE) and all the others are invalid (>= RANGE).
 *        2) Three values are valid and they show at points that are in the same line (Collinear)
 */
#include <stdio.h>
#include <math.h>
const double R=0.5;
const double RANGE=2.0;

// Function to check if three points are collinear.
int areCollinear(double x1, double y1, double x2, double y2, double x3, double y3) {
    //printf("x1 = %f, y1 = %f, x2 = %f, y2 = %f, x3 = %f, y3 = %f\n",x1, y1, x2, y2, x3, y3);
    // Calculate the area of the triangle using the determinant method
    double area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    //printf("area = %f\n", round(area*100)/100);
    // Round the area into the 2nd decimal point
    return round(area*100)/100 == 0.0;
}

// Function to find the coordinates (x,y), in robocentric, of a point given the sensor index and value.
double * findObstacleCoordinates(int validSensors[], double val[], int N) {
    static double coordinates[6];
    int j=0;
    for(int i=0; i<3; i++) {
        //printf("i = %d\t",validSensors[i]);
        //printf("val = %f,\t",val[validSensors[i]]);

        // Find angle of every valid sensor
        double angle = (double )validSensors[i] / N * 360.0;
        //printf("angle = %d,\n", (int)angle);

        // Deg to rad
        double angleRadians=angle*(M_PI/180);

        // Find coordinates in robocentric
        double x = (val[validSensors[i]]+R) * cos(angleRadians);
        double y = (val[validSensors[i]]+R) * sin(angleRadians);

        // Insert the coordinates into an array
        coordinates[j]=x;
        j++;
        coordinates[j]=y;
        j++;
    }
    return coordinates;
}

int main(){
    int N;
    printf("Give number of sensors:\n");
    scanf("%d",&N);

    double val[N], D;

    printf("Give data of each sensor:\n");
    for(int i=0; i<N; i++){
        scanf("%lf",&D);
        val[i]=D;
    }

    /*1*/
    char flag1=0;
    int count;

    for(int i=0; i<N-1; i++){
        // If two consecutive sensors have valid values
        if (val[i] < RANGE && val[i+1] < RANGE){
            // Initialize a counter
            count = 0;
            // Iterate through all sensor values
            for(int j=0; j<N; j++) {
                // Except the two consecutive sensors
                if(j!=i && j!=(i+1)){
                    // If the value is invalid
                    if(val[j] >= RANGE){
                        // Add one to the counter
                        count++;
                    }
                }
            }
            // If all the sensor values, except the two consecutive, are invalid
            if(count == (N-2)){
                flag1=1;
                break;
            }
        }
    }

    /*2*/
    int validSensors[3];
    char flag2=0;
    count = 0;

    // Iterate through all values and hold the indexes of the valid ones
    // Stop when you find 3 valid sensor values
    for(int i=0; i<N; i++) {
        if(val[i] < RANGE) {
            validSensors[count]=i;
            count++;
            if(count==3){
                break;
            }
        }
    }

    if(count==3){
        double *coordinates;
        // Calculate the coordinates from each of the 3 valid sensor values
        coordinates = findObstacleCoordinates(validSensors,val,N);
        // Check if the 3 points are in the same line (Collinear) --> it's a wall
        if(areCollinear(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5])){
            flag2=1;
        }
    }

    /*3*/
    printf("Is there a wall?\n");
    if(flag1==1 || flag2==1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    //printf("%d\t %d", flag1, flag2);

}