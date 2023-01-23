-- record syntax
data Person = Person	{ firstname :: String
						, lastname :: String
						, age :: Int
						, height :: Float
						, flavor :: String
						} deriving (Eq, Show)
-- in this way we can have 2 ways to define a person:
--1> let pjl = Person "peijun" "li" 24 165 "yogurt"
--2> let mom = Person {age = 53, height = 155.0, lastname = "wang", firstname = "qinglin", flavor = "strawberry"}
-- 2> unordered, and show function works differently

{- equivalent as
data Person = Person String String Int Float String deriving (Show)

firstName :: Person -> String
firstName (Person fn _ _ _ _) = fn

lastName :: Person -> String
lastName (Person _ ln _ _ _) = ln

age :: Person -> Int
age (Person _ _ a _ _) = a

height :: Person -> Float
height (Person _ _ _ ht _) = ht

flavor :: Person -> String
flavor (Person _ _ _ _ flr) = flr
-}

data Vector a = Vector a a a deriving (Show)

vplus :: Num a => Vector a -> Vector a -> Vector a
vplus (Vector a b c) (Vector x y z) = Vector (a+x) (b+y) (c+z)

vmult :: Num a => Vector a -> a -> Vector a
vmult (Vector a b c) m = Vector (a*m) (b*m) (c*m)

type Name = String
type Phonenum = String
type Phonebook = [(Name, Phonenum)]
type AssocList k v = [(k,v)]

mapTo :: (a -> b) -> AssocList a v -> AssocList b v
mapTo f = foldr (\(a,v) acc -> (f a, v): acc) []
-- type not producing new data type, just for readability

