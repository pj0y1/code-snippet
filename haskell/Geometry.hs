--should module name same as module name defined in this file?
module Geometry
( sphereVolume
, sphereArea
, cubeVolume
, cubeArea
, cuboidVolume
, cuboidArea  
) where
--rectangleArea as a function in module, is not exported

sphereVolume :: Float -> Float
sphereVolume radius
	| radius < 0 = error "invalid radius"
	| otherwise = (4.0 / 3.0 ) * pi * (radius ^ 3)

sphereArea :: Float -> Float
sphereArea radius = 4 * pi * (radius ^ 2)

cubeVolume :: Float -> Float
cubeVolume side = cuboidVolume side side side

cubeArea :: Float -> Float
cubeArea side = cuboidArea side side side

cuboidVolume :: Float -> Float -> Float -> Float
cuboidVolume a b c = rectangleArea a b * c

cuboidArea :: Float -> Float -> Float -> Float
cuboidArea a b c = rectangleArea a b * 2 + rectangleArea b c * 2 + rectangleArea a c * 2

rectangleArea :: Float -> Float -> Float
rectangleArea a b = a * b
