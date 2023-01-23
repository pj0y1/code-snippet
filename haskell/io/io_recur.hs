import Data.Char
main = do
	line <- getLine
	if null line
		then return "hell!"
		else do
			putStrLn $ reversewords line
			main

reversewords = unwords . map reverse . words

putStr' :: String -> IO ()
putStr' [] = return ()
putStr' (x:xs) = do
	putChar x
	putStr' xs

putStrLn' :: String -> IO ()
putStrLn' str = do
	putStr' str
	putStr' "\n"

-- putChar '' errors
