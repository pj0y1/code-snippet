import Data.Monoid

lengthCompare :: String -> String -> Ordering
lengthCompare x y = let a = compare (length x) (length y);
						b = compare x y
					in if a == EQ then b else a

lengthCompare' :: String -> String -> Ordering
lengthCompare' x y = (length x `compare` length y) `mappend` (x `compare` y)

lengthCompare'' :: String -> String -> Ordering
lengthCompare'' x y = (length x `compare` length y) `mappend` (vowel x `compare` vowel y) `mappend` (x `compare` y)
	where vowel = length . filter (`elem` "aeiou")
--vowel can also be length . filter (flip elem "aeiou")
