import System.IO
import System.Environment
import System.IO.Error

main = catchIOError toTry handler

toTry :: IO ()
toTry = do
	(filename:_) <- getArgs
	content <- readFile filename
	putStrLn $ "This file has " ++ show (length $ lines content) ++ " lines!"

handler :: IOError -> IO ()
handler e 
	| isDoesNotExistError e = 
		case ioeGetFileName e of 
			Just path -> putStrLn $ "File doesn't exist at " ++ path
			Nothing -> putStrLn "File doesn't exist at unknown place!"
	| otherwise =  ioError e

--in newer version of ghci, catch is removed
--same catch in Control.Excetion package
-- catch :: Exception e => IO a -> (e -> IO a) -> IO a
-- IOError is the synonym of IOException, as an instance of Exception
-- System.IO.Error now has catchIOError :: IO a -> (IOError  -> IO a) -> IO a
