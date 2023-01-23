import qualified Data.Map as Map

data Point = Point Float Float deriving (Show)
data Shape = Circle Point Float | Rectangle Point Point deriving (Show)


surface :: Shape -> Float
surface (Circle _ r ) = pi * r ^ 2
surface (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x1 - x2) * (abs $ y1 - y2)

nudge :: Float -> Float -> Shape -> Shape
nudge a b (Circle (Point x y) r) = Circle (Point (x + a) (y + b)) r
nudge a b (Rectangle (Point x1 y1) ( Point x2 y2 )) = Rectangle (Point (x1 + a) (y1 + b)) (Point (x2 + a) (y2 + b))

baseCircle :: Float -> Shape
baseCircle r = Circle (Point 0 0) r

baseRect :: Float -> Float -> Shape
baseRect a b = Rectangle (Point 0 0) ( Point a b)

{-
module Shapes
( Shape
) where
-- no Shape value constructor exported
( Shape(..)
) where
-- all Shape value constructor exported
( Shape (Circle)
) where
-- only Shape Circle value constructor exported
-}

type Code = String
type Locker = Map.Map Int (LockerSt, Code)

data LockerSt = Taken | Free deriving (Eq, Show)

lockerLookup :: Int -> Locker -> Either String Code
lockerLookup n lockermap = case Map.lookup n lockermap of
							Nothing -> Left "locker not existed!"
							Just (st, code) -> if st == Taken then Left "locker been taken!" else Right code 

lockers :: Locker
lockers = Map.fromList [(1,(Taken,"qwe")), (2,(Free,"asd"))]

