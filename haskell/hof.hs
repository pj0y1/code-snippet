comparewith100 :: (Num a, Ord a) => a -> Ordering
comparewith100 = compare 100
--pointless style (no paramater)

dividedby10 :: Fractional a => a -> a
dividedby10 = (/10)

isAlpha :: Char -> Bool
isAlpha = (`elem` ['a'..'z'] ++ ['A'..'Z'])

minus7 :: Num a => a -> a
minus7 = subtract 7
--no parenthesis seems ok?

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)

zipWith' :: (a -> a -> a) -> [a] -> [a] -> [a]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys
--zipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
--better!

flip' :: (a -> b -> c) -> (b -> a -> c)
flip' f b a = f a b
--can't call flip' f alone, must be with parameters a b

flip'' :: (a -> b -> c) -> (b -> a -> c)
flip'' f = g
	where g x y = f y x

flip''' :: (a -> b -> c) -> b -> a -> c
flip''' f x y = f y x

flip'''' :: (a -> b -> c) -> b -> a -> c
flip'''' f = \x y -> f y x

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = f x : map' f xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs) = if f x then x : filter' f xs else filter' f xs

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' _ [] = []
filter'' f (x:xs)
	| f x = x: filter' f xs
	| otherwise = filter' f xs

--filter version of qsort
qsort' :: Ord a => [a] -> [a]
qsort' [] = []
qsort' (x:xs) = qsort' (filter' (< x) xs) ++ [x] ++ qsort' (filter (>= x) xs)

collatz' :: Int -> [Int]
collatz' n
	| n <= 0 = []
	| n == 1 = [1]
	| otherwise = n: collatz' (if odd n then n * 3 + 1 else n `div` 2)

numLongChain :: Int -> Int
numLongChain n = length ( filter islong (map collatz' [1..100]))
	where islong xs = length xs > n

numLongChain' :: Int -> Int
numLongChain' n = length $ filter (\xs -> length xs > n ) $ map collatz' [1..100]

--fold
sum' :: Num a => [a] -> a
sum' = foldl (+) 0

sum_step :: Num a => [a] -> [a]
sum_step = scanl1 (+)

sum_step' :: Num a => [a] -> [a]
sum_step' = scanl (+) 0

elem' :: Eq a => a -> [a] -> Bool
elem' e = foldl (\acc x -> if x == e || acc == True then True else False ) False
--not better as
elem'' :: Eq a => a -> [a] -> Bool
elem'' e = foldl (\acc x -> if x == e then True else acc) False

map'' :: (a -> b) -> [a] -> [b]
map'' f = foldr (\x acc -> f x : acc) []

maximum' :: Ord a => [a] -> a
maximum' = foldr1 max
--foldl1 max works too, empty list will arise exception

reverse' :: [a] -> [a]
reverse' = foldl (\acc x -> x:acc) []
--foldr stays the same
reverse'' :: [a] -> [a]
reverse'' = foldl (flip (:)) []

product' :: Num a => [a] -> a
product' = foldl (*) 1
-- product' = foldl1 (*) doesn't work for empty list
-- foldr works as well

filter''' :: (a -> Bool) -> [a] -> [a]
filter''' f = foldr (\x acc -> if f x then x : acc else acc) [] 

head' :: [a] -> a
head' = foldr1 (\x _ -> x)

head'' :: [a] -> a
head'' = foldl1 (\acc _ -> acc)

last' :: [a] -> a
last' = foldl1 (\_ x -> x)

sqrtSums :: Int
sqrtSums = length $ takeWhile (<1000) $ scanl (+) 0 ( map sqrt [1..] ) 
-- filter (<10) $ scanl (\_ x -> x) 0 (map sqrt [1..]) seems never stop, though its displayed result is finite

last'' :: [a] -> a
last'' = foldr1 (\_ acc -> acc)
