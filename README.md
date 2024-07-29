# Robotics-in-C

**ladyBug.c**
>Give the values of the 4 RSSI sensors of your robot (center, right, left, front).\
>Get the coordinates of the transmitter-target in robocentric (xs, ys, zs) based on Lady-Bug algorithm.

**findObstalces.c**
>Give the number of robot's sensors (N).\
>Give the data of each sensor (D).\
>Get the coordinates of the found obstacle in robocentric (x,y).

**environmentRepresentation.c**
>Representation of the environment of the robot.\
>Give the number of sensors of the robot (N) and the values of each sensor (val[i]).\
>Get the coordinates of the obstacles it detects in robocentric.\
>Get an image representation of the environment. '#' are the obstacles and 'R' is the robot.\
>Each cell of the environment is 0.25m x 0.25m.
<pre>
 ex:
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       #---------R-----#----
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
       ---------------------
</pre>

**distanceAndAngleFromTarget.c**
>Give your robot's coordinates and angle (xr,yr,theta).\
>Give robot's target coordinates (xt,yt).\
>Get the distance and the angle your robot needs to turn to face target.

**deadReckoningRobotLocate.c**
>Linear Dead Reckoning.\
>Give number of movements.\
>For each move give v (velocity m/sec), t (time of movement sec) and theta (degrees of move).\
>Get the position x, y, theta after each move.

**cyclicMovementFindVOfTheWheels.c**
>Two Wheels Differential Driving.\
>Give your robot's coordinates and angle (xr, yr, theta).\
>Give robot's target coordinates (xr, yr).\
>Get the velocity of each of the two wheels that must have in order to reach target.

**move2goalVector.c**
>MOVE2GOAL\
>Give the coordinates of your robot (xr,yr,theta) and the target (xt,yt) (in global system).\
>Get the vector of movement to the goal.\
>If the distance between robot and target is <= 0.5 the vector measure should be equal to the distance.\
>If the distance between robot and target is > 0.5 the vector measure should be equal to 0.5.

**pathDistances.c**
>Give your robot's coordinates and angle (xr, yr, theta).\
>Give coordinates (xA, yA) of point Ti of the path.\
>Give coordinates (xB, yB) of point Ti+1 of the path.\
>Get distances dn (normalized by v) and un (normalized by vn).

**robocentric.c**
>Give your robot's coordinates and angle (xr, yr, theta).\
>Give robot's target coordinates (xr, yr).\
>Get robot's target robocentric coordinates. (robot's axes instead of global)

**wallDetection.c**
>Wall detection.\
>Give the number of distance sensors (N) of a cylindrical robot (R=radius).\
>Give the value of each sensor (val[i]).\
>Get "YES" if the robot detects a wall, otherwise get "NO".
<pre>
"YES": 1) Two consecutive values are valid (< RANGE) and all the others are invalid (>= RANGE).
       2) Three values are valid and they show at points that are in the same line (Collinear).
</pre>

 
