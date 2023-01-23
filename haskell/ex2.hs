npp = a `div` length xs
	where 
		a = 10
		xs = [1,2,3,4,5]

last' :: [a] -> a
last' [] = error "empty list"
last' xs = xs!!(length xs -1)

last'' :: [a] -> a
last'' [] = error "empty list"
last'' xs = head (reverse xs)

last''' :: [a] -> a
last''' [] = error "empty list"
last''' (x:[]) = x
last''' xs = last''' (tail xs)

tail' :: [a] -> [a]
tail' [] = error "empty list"
tail' xs = drop 1 xs

tail'' :: [a] -> [a]
tail'' [] = error "empty list"
tail'' (_:xs) = xs

init' :: [a] -> [a]
init' [] = error "empty list"
init' xs = take ((length xs)-1) xs

init'' :: [a] -> [a]
init'' [] = error "empty list"
init'' (x:[]) = []
init'' (x:xs) = [x] ++ init'' xs

