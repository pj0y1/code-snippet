import Data.List 
import Data.Function
import Data.Char
--import Data.Map

numUniques :: Eq a => [a] -> Int
numUniques = length . nub

search :: Eq a => [a] -> [a] -> Bool
search p xs = foldl (\acc x -> if take lp x == p then True else acc) False $ tails xs
	where lp = length p
-- and $ zipWith (==) x p, worse than comparing directly

huiwen :: Eq a => [a] -> Bool
huiwen [] = True
huiwen xs = if even (length xs) then (reverse $ take len xs) == drop len xs else (reverse $ take len xs) == drop (len + 1) xs
	where len = div (length xs) 2
-- anything simpler?
-- double fold possible?

sortList :: [[a]] -> [[a]]
--sortList = sortBy (\x y -> compare (length x) (length y))
sortList = sortBy (compare `on` length)

caesarEncode :: Int -> String -> String
caesarEncode n str
	| n < 0 = []
	| otherwise = map chr $ map (\x ->  mod (ord x - n - base x ) 26 + base x) str
	where base x
		| isUpper x = 65
		| isLower x = 97
		| otherwise = 0

caesarDecode :: Int -> String -> String
caesarDecode n str
	| n < 0 = []
	| otherwise = map chr $ map (\x -> mod (ord x + n - base x) 26 + base x) str
	where base x
		| isUpper x = 65
		| isLower x = 97
		| otherwise = 0
--base x could de independent
--only shifting the letters
--naming n as shift, str as msg is more readeable
--if no n>=0 constraint, decode n = encode (negate n)

findKey :: Eq k => k -> [(k,v)] -> [v]
findKey key dict = foldr (\(k,v) acc -> if k == key then v :acc else acc) [] dict
-- I use [v] here in case the same key has multiple values
--similar to Data.List.lookup :: Eq k => k -> [(k,v)] -> Maybe v
