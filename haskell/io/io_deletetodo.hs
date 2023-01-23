import Data.List
import System.IO
import System.Directory

main = do
	handle <- openFile "todo.txt" ReadMode
	(tempname, temphandle) <- openTempFile "." "temp"
	contents <- hGetContents handle
	let todolist = lines contents
	putStrLn "There are your todo list:"
	mapM putStrLn $ zipWith (\a b -> show a ++ " - " ++ b) [0..] todolist
	putStrLn "Please enter the number of item you want to delete:"
	num <- getLine
	let newtodolist = delete (todolist !! (read num :: Int)) todolist
	hPutStr temphandle $ unlines newtodolist
	hClose handle
	hClose temphandle
	removeFile "todo.txt"
	renameFile tempname "todo.txt"
