import qualified Data.Foldable as F
import Data.Monoid
infixr 5  :-:
data List a = Empty | a :-: (List a) deriving (Eq, Show, Read, Ord)

data Tree a = Tip | Node a (Tree a) (Tree a) deriving (Eq, Ord, Show)

singleton :: a -> Tree a
singleton x = Node x Tip Tip

insertTree :: Ord a => Tree a -> a -> Tree a
insertTree Tip x = Node x Tip Tip
insertTree wholeT@(Node n left right) x
	| n == x = wholeT
	| x > n  = Node n left (insertTree right x)
	| x < n  = Node n (insertTree left x) right

elemTree :: Ord a => a -> Tree a -> Bool
elemTree _ Tip = False
elemTree x (Node n left right)
	| x == n = True
	| x > n = elemTree x right
	| x < n = elemTree x left

--since this file containing new data type, :l is not sufficient to run the script, we use :add

instance F.Foldable Tree where
	foldMap f Tip = mempty
	foldMap f (Node n left right) = F.foldMap f left `mappend` f n `mappend` F.foldMap f right

testTree :: Num a => Tree a
testTree = Node 5 
			(Node 3 
				(Node 1 Tip Tip)
				(Node 4 Tip Tip)
			)
			(Node 9
				(Node 8 Tip Tip)
				(Node 10 Tip Tip)
			)
