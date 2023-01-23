import Control.Monad
main = do
	line <- getLine
	when (line /= "") $ do
		appendFile "todo.txt" (line ++ "\n")
		main
