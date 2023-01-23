doubleMe x = x + x
doubleUs x y = doubleMe x + doubleMe y
doubleSmallNumber x = if x > 100
then x
else x * 2

boomBangs xs = [if x > 10 then "BOOM!" else "BANG!" | x <- xs, even x]
length' xs = sum [1| _ <- xs]

elementAt xs num = xs!!(num-1)

maxG 0 y = y
maxG y 0 = y
maxG x y = if x > y then maxG (x-y) y else maxG x (y-x)

--removeUpper :: [Char] -> [Char]
removeUpper xs = [c| c <- xs, not (c `elem` ['A'..'Z'])]

addThree :: Int -> Int -> Int -> Int
addThree x y z  = x + y + z

--factorial :: Integer -> Integer
--factorial x = product [1..x]

sayMe :: Integral a => a -> String
sayMe 7 = "Lucky you!"
sayMe x = "You are not so lucky!"

factorial 0 = 1
factorial n = n * factorial (n-1)
-- so n must GT 0, or will error, worse than first one	

innerProduct :: Num a => [a] -> [a] -> a
innerProduct l1 l2 = if length l1 == length l2 then  sum [ a*b |(a,b) <- (zip l1 l2)] else error "invalid vector length!"

head' :: [a] -> a
head' [] = error "invalid!"
head' (x:_) = x

head'' :: [a] -> Either String a
head'' [] = Left "empty list!"
head'' (x:_) = Right x

guessSeason :: Integral a => a -> String
guessSeason n
	| n < 1 = "invalid input!"
	| n < 3 = "Winter!"
	| n < 6 = "Spring!"
	| n < 9 = "Summer!"
	| n < 12 = "Autumn!"
	| n == 12 = "Winter!"
	| otherwise = "invalid input!"

-- case unable to parse, parse error on `->'
{-tellOdd :: Int -> Bool
tellOdd n = case (mod n 2) of 0 -> False
							  1 -> True
-}
maximum' :: Ord a => [a] -> a
maximum' [] = error "empty list"
maximum' [x] = x
maximum' (x:xs) = max x (maximum xs)

replicate' :: Int -> a -> [a]
replicate' n x 
	| n <= 0    = []
	| otherwise = x: replicate' (n-1) x

take' :: Int -> [a] -> [a]
take' _ [] = []
take' n _
	| n <= 0 = []
take' n (x:xs) = x: take' (n-1) xs

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

repeat' :: a -> [a]
repeat' x = x:repeat' x

zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (x:xs) (y:ys) = (x,y): zip' xs ys

elem' :: Eq a => a -> [a] -> Bool
elem' _ [] = False
elem' q (x:xs) = q == x || elem' q xs

elem'' :: Eq a => a -> [a] -> Bool
elem'' _ [] = False
elem'' q (x:xs)
	| q == x    = True
	| otherwise = elem'' q xs

qsort' :: Ord a => [a] -> [a]
qsort' [] = []
qsort' (x:xs) =
	let smaller = qsort' [s| s <- xs, s <= x]; bigger = qsort' [b| b <- xs, b > x]
	in smaller ++ [x] ++ bigger

data Day = Sunday | Monday | Tuesday | Wednesday | Thursday | Friday | Saturday deriving (Eq, Enum, Show, Read, Bounded)
-- data keyword to define a type

tellWeekday :: Integral a => a -> Day
tellWeekday n = case n `mod` 7 of
				0 -> Sunday
				1 -> Monday
				2 -> Tuesday
				3 -> Wednesday
				4 -> Thursday
				5 -> Friday
				6 -> Saturday
