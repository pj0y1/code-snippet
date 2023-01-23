main = do
	contents <- getContents
--	print contents
-- if using putStrLn, it forces program to take IO action line by line
-- print = putStrLn . show, thus the result will have extra "" outside
	putStrLn (shortLineOnly contents)


shortLineOnly :: String -> String
shortLineOnly input = 
	let allLines = lines input;
		shortLines = filter (\line -> length line < 10) allLines;
		result = unlines shortLines
	in result
