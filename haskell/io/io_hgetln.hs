import System.IO
main = do
	handle <- openFile "noragami.txt" ReadMode
	content1 <- hGetLine handle
	putStrLn content1
	content2 <- hGetLine handle
	putStrLn content2
	hClose handle
