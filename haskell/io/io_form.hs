import Control.Monad
main = do
	names <- forM ["best", "second best", "third best"] (\a -> do
		putStrLn ("What's the name of your " ++ a ++ " friend?")
		getLine )
	putStrLn "So your best 3 friends are them:"
	mapM putStrLn names
