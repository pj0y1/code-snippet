--reverse polish notion

solveRPN :: (Num a,Read a) => String -> a
solveRPN = head . foldl foldingfun [] . words

foldingfun :: (Num a, Read a) => [a] -> String -> [a]
foldingfun (x:y:xs) "+" = (x + y):xs
foldingfun (x:y:xs) "-" = (y - x):xs
foldingfun (x:y:xs) "*" = (x * y):xs
foldingfun xs x = (read x):xs
