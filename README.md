# Racing-Simulator
A terminal based racing simulator featuring customizable vehicles with different stats, performance mods, and two track types.

A simple racing game/simulator I developed this term in CS302. The project is centered around the use of a doubly linked list as a race track, 
with motorcycles, 4WD vehicles and super cars being available to race. Each vehicle is strong in a different stat, with motorcycles primarily being stronger off-road, 
super cars having high horsepower and being strong on the road, and 4WD vehicles being a mix of both. Additionally, different performance mods 
can be added to the vehicles to increase their various stats. The racing feature worked through an RNG system, where as a vehicle is traversing through the list, 
a stat would be randomly chosen at each node and then a random number would be rolled for that stat and compared against the vehicle currently racing the track 
(stats have a higher/lower chance to be chosen depending on whether the track is off-road or not). If the roll is lower than the vehicle's stat value, 
that section of the track is passed in normal time; otherwise, a bit of extra time is added. 
