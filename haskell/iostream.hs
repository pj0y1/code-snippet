main = do
	putStrLn "What's your name?"
	name <- getLine
	putStrLn "What's your year of birth?"
	year <- getLine
	let age = 2016 - read year
	putStrLn ( name ++ ", you must be " ++ show age ++ " this year!")
-- use <- when want to take something out of the IO box
-- use let to deal with data already taken out of IO box
