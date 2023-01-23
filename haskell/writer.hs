import Control.Monad.Trans.Writer.Lazy
import Data.Monoid

isBigBang :: Int -> (Bool,String)
isBigBang x = (,) (x>9) "Compare with size 9"

logCompare :: (a,String) -> (a -> (b,String)) -> (b,String)
logCompare (x,log) f = let (y,log') = f x in (y, log ++ log')

logCompare' :: Monoid w => (a,w) -> (a -> (b,w)) -> (b,w)
logCompare' (x,log) f = let (x',log') = f x in (x', log `mappend` log')

type ItemName = String
type Total = Sum Float

scanner :: ItemName -> (ItemName,Total)
scanner "pork" = ("pork", Sum 4.00)
scanner "milk" = ("milk", Sum 0.75)
scanner "pepper" = ("pepper", Sum 0.50)
scanner "tomato" = ("tomato", Sum 1.00)
scanner "cheese" = ("cheese", Sum 1.75)
scanner "bread" = ("bread", Sum 1.25)
scanner _ = ("end", Sum 0)

--newtype WriterT w m a = WriterT {runWriterT :: m (a, w)}
--instance (Monoid w, Monad m) => Monad (WriterT w m)
counter :: ItemName -> WriterT Total Maybe ItemName
counter str = WriterT (Just (scanner str))

logPlus :: Int -> Int -> WriterT (Sum Int) [] Int
logPlus x y = WriterT [(x, Sum y)]

multWithLog :: WriterT (Sum Int) [] Int
multWithLog = do
	a <- logPlus 1 2
	b <- logPlus 3 4
	--tell (Sum 100)
	return a

gcd' :: Int -> Int -> WriterT [String] [] Int
gcd' a b
	| b == 0 = do
		tell ["Finished with " ++ show a]
		return a
	| otherwise = do
		tell [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)]
		gcd' b (a `mod` b)


newtype DiffList a = DiffList {getDiffList :: [a] -> [a]}
instance (Show a) => Show (DiffList a) where
	show (DiffList f) = show $ fromDiffList (DiffList f)

toDiffList :: [a] -> DiffList a
toDiffList xs = DiffList (xs ++)

fromDiffList :: DiffList a -> [a]
fromDiffList (DiffList f) = f []

instance Monoid (DiffList a) where
	mempty = DiffList (\x -> [] ++ x)
	mappend (DiffList f) (DiffList g) = DiffList (\x -> f (g x))

gcdR :: Int -> Int -> WriterT (DiffList String) [] Int
gcdR a b
	| b == 0 = do
		tell (toDiffList ["Finished with " ++ show a])
		return a
	| otherwise = do
		result <- gcdR b (a `mod` b)
		tell (toDiffList [show a ++ " mod " ++ show b ++ " = " ++ show (a `mod` b)])
		return result

finalCountDown :: Int -> WriterT (DiffList String) [] ()
finalCountDown 0 = do
	tell (toDiffList ["0"])
finalCountDown x = do
	finalCountDown (x-1)
	tell (toDiffList [show x])

finalCountDown' :: Int -> WriterT [String] [] ()
finalCountDown' 0 = do
	tell (["0"])
finalCountDown' x = do
	finalCountDown' (x-1)
	tell ([show x])
