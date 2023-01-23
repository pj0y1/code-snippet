import Data.List
import System.IO
import System.Directory
import System.Environment
import Control.Monad (when)
main = do
	args <- getArgs
	when (args /= []) $ do
		whattodo args

--data TodoMode = View | Add | Delete deriving (Eq, Show, Read)
whattodo :: [String] -> IO ()
whattodo (action:xs) 
	| action == "add" = add xs
	| action == "view" = view xs
	| action == "delete" = del xs
	| action == "bump" = bump xs

add :: [String] -> IO ()
add [] = return ()
add xs = do
	appendFile (head xs) $ intercalate " " (tail xs) ++ "\n"

view :: [String] -> IO ()
view [] = return ()
view xs = do
	withFile (head xs) ReadMode (\h -> do
		contents <- hGetContents h
		mapM_ putStrLn $ zipWith (\n l -> show n ++ " - " ++ l) [0..] $ lines contents)

del :: [String] -> IO ()
del [] = return ()
del [_] = return ()
del [fileName, numStr] = do
	handle <- openFile fileName ReadMode
	contents <- hGetContents handle
	let todolist = lines contents
	let newlist = delete (todolist!!(read numStr)) todolist
	(tempName, tempHandle) <- openTempFile "." "temp"
	hPutStr tempHandle $ unlines newlist
	hClose handle
	hClose tempHandle
	removeFile fileName
	renameFile tempName fileName

bump :: [String] -> IO ()
bump [path, item] = do
	handle <- openFile path ReadWriteMode
	contents <- hGetContents handle
	let newcontents = item : lines contents
	hPutStr handle $ unlines newcontents
	hClose handle
