double' :: Num a => a -> a
double' x = x + x

sum' :: Num a => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs

product' :: Num a => [a] -> a
product' [] = 1
product' (x:xs) = x * product' xs

qsort' :: Ord a => [a] -> [a]

qsort' [] = []
qsort' [x] = [x]
qsort' (x:xs) = qsort' smaller ++ [x] ++ qsort' larger
	where smaller = [s| s <- xs, s < x]
	      larger = [l| l <- xs, l >= x]

--if drop "=", the returned list has no repeated elem

qsort'' :: Ord a => [a] -> [a]
qsort'' [] = []
qsort'' [x] = [x]
qsort'' (x:xs) = qsort'' larger ++ [x] ++ qsort'' smaller
	where smaller = [s| s <- xs, s < x]
	      larger = [l| l <- xs, l >= x]
