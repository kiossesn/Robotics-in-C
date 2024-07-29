# Robotics-in-C

**ladyBug.c**
[lady bug.pdf](https://github.com/user-attachments/files/16405803/lady.bug.pdf)
>Give the values of the 4 RSSI sensors of your robot (center, right, left, front).\
>Get the coordinates of the transmitter-target in robocentric (xs, ys, zs) based on Lady-Bug algorithm.

**findObstalces.c**
[find obstacles.pdf](https://github.com/user-attachments/files/16405802/find.obstacles.pdf)
>Give the number of robot's sensors (N).\
>Give the data of each sensor (D).\
>Get the coordinates of the found obstacle in robocentric (x,y).

**environmentRepresentation.c**
[environment representation.pdf](https://github.com/user-attachments/files/16405801/environment.representation.pdf)
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
[distance and angle from target.pdf](https://github.com/user-attachments/files/16405800/distance.and.angle.from.target.pdf)
>Give your robot's coordinates and angle (xr,yr,theta).\
>Give robot's target coordinates (xt,yt).\
>Get the distance and the angle your robot needs to turn to face target.

**deadReckoningRobotLocate.c**
[dead reckoning.pdf](https://github.com/user-attachments/files/16405799/dead.reckoning.pdf)
>Linear Dead Reckoning.\
>Give number of movements.\
>For each move give v (velocity m/sec), t (time of movement sec) and theta (degrees of move).\
>Get the position x, y, theta after each move.

**cyclicMovementFindVOfTheWheels.c**
[cyclic movement.pdf](https://github.com/user-attachments/files/16405798/cyclic.movement.pdf)
>Two Wheels Differential Driving.\
>Give your robot's coordinates and angle (xr, yr, theta).\
>Give robot's target coordinates (xr, yr).\
>Get the velocity of each of the two wheels that must have in order to reach target.

**move2goalVector.c**
[move2goal vector.pdf](https://github.com/user-attachments/files/16405797/move2goal.vector.pdf)
>MOVE2GOAL\
>Give the coordinates of your robot (xr,yr,theta) and the target (xt,yt) (in global system).\
>Get the vector of movement to the goal.\
>If the distance between robot and target is <= 0.5 the vector measure should be equal to the distance.\
>If the distance between robot and target is > 0.5 the vector measure should be equal to 0.5.

**pathDistances.c**
[path distances.pdf](https://github.com/user-attachments/files/16405796/path.distances.pdf)
>Give your robot's coordinates and angle (xr, yr, theta).\
>Give coordinates (xA, yA) of point Ti of the path.\
>Give coordinates (xB, yB) of point Ti+1 of the path.\
>Get distances dn (normalized by v) and un (normalized by vn).

**robocentric.c**
[robocentric.pdf](https://github.com/user-attachments/files/16405795/robocentric.pdf)
>Give your robot's coordinates and angle (xr, yr, theta).\
>Give robot's target coordinates (xr, yr).\
>Get robot's target robocentric coordinates. (robot's axes instead of global)

**wallDetection.c**
[wall detection.pdf](https://github.com/user-attachments/files/16405793/wall.detection.pdf)
>Wall detection.\
>Give the number of distance sensors (N) of a cylindrical robot (R=radius).\
>Give the value of each sensor (val[i]).\
>Get "YES" if the robot detects a wall, otherwise get "NO".
<pre>
"YES": 1) Two consecutive values are valid (< RANGE) and all the others are invalid (>= RANGE).
       2) Three values are valid and they show at points that are in the same line (Collinear).
</pre>

 
