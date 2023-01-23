import Control.Monad.State
import System.Random

type Stack = [Int]

pop :: Stack -> (Int,Stack)
pop (x:xs) = (x,xs)

push :: Int -> Stack -> ((),Stack)
push x xs = ((),x:xs)

stackManip :: Stack -> (Int,Stack)
stackManip stack = let
	((),newstk1) = push 3 stack
	(a, newstk2) = pop newstk1
	in pop newstk2

pop' :: StateT Stack [] Int
pop' = StateT $ \(x:xs) -> [(x,xs)]

push' :: Int -> StateT Stack [] ()
push' y = StateT $ \s -> [((),y:s)]

stackManip' :: StateT Stack [] Int
stackManip' = do
	push' 3
	pop'
--stackManip' can't end with push', because it has type StateT Stack [] Int!

stackStuff' :: StateT Stack [] ()
--this could end with push
stackStuff' = do
	a <- pop'
	if a == 5 
		then push' 6
		else do
			push' 5
			push' 24

moreStack :: StateT Stack [] ()
moreStack = do
	a <- stackManip'
	if a < 2
		then stackStuff'
		else return ()

stackyStack :: StateT Stack [] ()
stackyStack = do
	stackNow <- get
	if stackNow == [1,2,3]
		then put [9,4,5]
		else put [0,0,0]


randomSt :: (RandomGen g, Random a) => StateT g [] a
randomSt = StateT $ \g -> [random g]

threeCoins :: StateT StdGen [] (Bool,Bool,Bool)
threeCoins = do
	a <- randomSt
	b <- randomSt
	c <- randomSt
	return (a,b,c)
