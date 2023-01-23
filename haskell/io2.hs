main = do
	line <- getLine
	if null line
		then return ()
		else do 
				putStrLn line
				main
-- return doesn't return a value, but put a value into an IO box
-- return takes (), resulting in an IO () type
