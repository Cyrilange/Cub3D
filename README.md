What is Raycasting?
Raycasting is a technique used to turn a 2D map (like a top-down maze) into a 3D first-person view (as in Wolfenstein 3D).
The idea is:
For each vertical column of the screen, a ray is cast from the player’s position.
The ray moves forward until it hits a wall.
Depending on the distance, a vertical line is drawn taller (if close) or shorter (if far), creating the illusion of 3D.
Main Steps
Divide the screen into columns
Each screen column represents a ray.
Calculate the ray direction
Based on the player’s direction and the camera plane, the exact direction of each ray is computed.
Locate the player’s grid cell
Identify in which cell of the map grid (mapX, mapY) the player is currently.
Compute step distances
Calculate how far the ray must travel to cross a grid line in X or Y.
Decide step direction
Depending on the ray’s direction (left/right, up/down), determine whether to step negatively or positively in the grid.
DDA algorithm (Digital Differential Analysis)
Progress step by step through the grid until the ray intersects a wall.
Measure distance to the wall
Once a wall is hit, compute the perpendicular distance between the player and the wall.
Draw the wall slice
Using the distance, calculate the height of the vertical wall slice to draw on that column of the screen.
Near walls appear taller.
Distant walls appear shorter.
Simplified Summary
Each screen column corresponds to a ray.
The ray advances through the map until it hits a wall.
The wall’s distance determines the height of the line drawn.
Repeating this for all columns produces a 3D-like view from a 2D map.


<img width="1537" height="917" alt="image" src="https://github.com/user-attachments/assets/fb5f380f-7099-474c-8570-330a6a1275f8" />




<img width="1537" height="917" alt="image" src="https://github.com/user-attachments/assets/fda0e75b-345f-4a23-96b5-7360027e10c1" />


