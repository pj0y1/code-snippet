-- (,) 'a' :: b -> (Char, b)
-- (,) take type parameters as such order

newtype Pair b a = Pair {getPair :: (a,b)}

instance Functor (Pair c) where
	fmap f (Pair (x,y)) = Pair (f x, y)

