/* Representation of the environment of the robot.
 * Give the number of sensors of the robot (N) and the values of each sensor (val[i]).
 * Get the coordinates of the obstacles it detects in robocentric.
 * Get an image representation of the environment. '#' are the obstacles and 'R' is the robot.
 * Each cell of the environment is 0.25m x 0.25m.
 */
#include <stdio.h>
#include <math.h>
#include <malloc.h>

const double R=0.5;
const double RANGE=2.0;

// Function to find the coordinates (x,y), in robocentric, of a point given the sensor index and value.
double ** findObstacleCoordinates(double val[], int N) {
    // Allocate memory for a Nx2 table
    double **coordinates = malloc(N * sizeof(double *));;
    for (int i = 0; i < N; i++) {
        coordinates[i] = malloc(N * sizeof(double ));
    }

    // Initialize table to 0
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            coordinates[i][j]=0.0;
        }
    }

    int j=0;
    for(int i=0; i<N; i++) {
        // Ignore values out of range
        if (val[i] <= RANGE) {

            // Find angle of every sensor
            double angle = (double) i / N * 360.0;
            //printf("angle = %d,\n", (int)angle);

            // Deg to rad
            double angleRadians = angle * (M_PI / 180);

            // Find coordinates in robocentric
            double x = (val[i] + R) * cos(angleRadians);
            double y = (val[i] + R) * sin(angleRadians);

            // Insert the coordinates into an array
            coordinates[j][0] = x;
            coordinates[j][1] = y;
            j++;
        }
        else{
            coordinates[j][0] = 0.0;
            coordinates[j][1] = 0.0;
            j++;
        }
    }
    return coordinates;
}

void printEnv(char env[21][21]){
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++) {
            printf("%c", env[i][j]);
        }
        printf("\n");
    }
}

void printCoordinates(double **coordinates,int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++) {
            printf("%.1f\t", coordinates[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    // Initialize a table to represent the environment
    char env[21][21];
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++) {
            env[i][j]='-';
        }
    }
    // Insert hte robot to the center of the environment
    env[10][10]= 'R';

    // Print the environment
    // printEnv(env);

    int N;
    printf("Give number of sensors: ");
    scanf("%d",&N);

    double val[N], D;

    printf("Give data of each sensor: ");
    for(int i=0; i<N; i++){
        scanf("%lf",&D);
        val[i]=D;
    }

    // Allocate memory for the table which holds the coordinates of the obstacles (Nx2)
    double **coordinates = malloc(N * sizeof(double *));;
    for (int i = 0; i < N; i++) {
        coordinates[i] = malloc(2 * sizeof(double ));
    }

    // Get the coordinates of each obstacle in robocentric
    coordinates = findObstacleCoordinates(val, N);

    // Print the coordinates of the obstacles in robocentric
    // printCoordinates(coordinates, N);

    float num;
    for(int i=0;i<N;i++){
        if (coordinates[i][0]!=0 || coordinates[i][1]!=0){
            // Calculate how far the obstacle is from the robot in cells

            // y distance
            num = coordinates[i][1]/0.25;
            int num1 = (int)(num < 0 ? (num - 0.5) : (num + 0.5));
            //printf("%d\t", 10-num1);

            // x distance
            num = coordinates[i][0]/0.25;
            int num2 = (int)(num < 0 ? (num - 0.5) : (num + 0.5));
            //printf("%d\n", 10+num2);

            // Add '#' to the cell that each obstacle occupies
            env[10-num1][10+num2]='#';
        }
    }
    // Print the environment
    printEnv(env);

}
