main = do
	strs <- sequence (replicate 3 getLine)
	mapM putStrLn strs
