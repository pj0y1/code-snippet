instance Functor IO where
	fmap f a = do
		result <- a 
		return (f a)
