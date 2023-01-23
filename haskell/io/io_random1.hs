import System.Random
import Control.Monad(when)

main = do
	gen <- getStdGen
	askforNumber gen

askforNumber :: StdGen -> IO ()
askforNumber gen = do
	let (num, newgen) = randomR (1,10) gen :: (Int, StdGen)
	putStrLn "Guess the number:"
	line <- getLine
	let [(numread,str)] = reads line :: [(Int,String)]
	when (length line /= length str) $ do
		if num /= numread
			then putStrLn $ "Sorry, the number is " ++ show num
			else putStrLn "You are right!"
		askforNumber newgen
