import Control.Monad

type Birds = Int
type Pole = (Birds, Birds)

landLeft :: Birds -> Pole -> Maybe Pole
landLeft n (l,r)
	| l + n < 0 = error "Number of birds must be non-negative."
	| abs (l + n -r) > 3 = Nothing
	| otherwise = Just (l+n,r)

landRight :: Birds -> Pole -> Maybe Pole
landRight n (l,r)
	| r + n < 0 = error "Number of birds must be non-negative."
	| abs (r + n - l) > 3 = Nothing
	| otherwise = Just (l, r+n)

x -: f = f x

banana :: Pole -> Maybe Pole
banana _ = Nothing

foo :: (Show a, Show b) => Maybe a -> Maybe b -> Maybe String
foo x y = do
	x' <- x
	y' <- y
	return ((show x') ++ (show y'))
--so do notation is taking value out of monadic context, not only in IO case

routine :: Maybe Pole
routine = do
	start <- return (0,0)
	step1 <- landRight 1 start
	Nothing --throwing a banana peel
	step2 <- landLeft 2 step1
	step3 <- landRight (-1) step2
	landRight 3 step3

justChar :: Maybe String -> Maybe Char
justChar x' = do
	(x:xs) <- x'
	return x

mlist :: [a] -> [b] -> [(a,b)]
mlist xs ys = do
	x <- xs
	y <- ys
	return (x,y)

--sevensOnly :: [Int]
sevensOnly = do	
	x <- [1..50]
	guard ('7' `elem` show x)
	return x
--if guard is False, means process fails, rest of lines will not be executed(?)
